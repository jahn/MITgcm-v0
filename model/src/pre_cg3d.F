C $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/model/src/pre_cg3d.F,v 1.6 2016/05/04 22:10:37 jmc Exp $
C $Name:  $

#include "PACKAGES_CONFIG.h"
#include "CPP_OPTIONS.h"

CBOP
C     !ROUTINE: PRE_CG3D
C     !INTERFACE:
      SUBROUTINE PRE_CG3D(
     I                     oldFreeSurfTerm,
     I                     cg2d_x,
     U                     cg3d_b,
     I                     myTime, myIter, myThid )

C     !DESCRIPTION:
C     Called from SOLVE_FOR_PRESSURE, before 3-D solver (cg3d):
C     Finish calculation of 3-D RHS after 2-D inversionis done.

C     !USES:
      IMPLICIT NONE
C     == Global variables
#include "SIZE.h"
#include "EEPARAMS.h"
#include "PARAMS.h"
#include "GRID.h"
#include "SURFACE.h"
#include "FFIELDS.h"
#include "DYNVARS.h"
#ifdef ALLOW_NONHYDROSTATIC
#include "NH_VARS.h"
#endif

C     === Functions ====
c     LOGICAL  DIFFERENT_MULTIPLE
c     EXTERNAL DIFFERENT_MULTIPLE

C     !INPUT/OUTPUT PARAMETERS:
C     == Routine arguments ==
C     oldFreeSurfTerm :: Treat free-surface term in the old way (no exactConserv)
C     cg2d_x          :: Solution vector of the 2-D solver equation a.x=b
C     cg3d_b          :: Right Hand side vector of the 3-D solver equation A.X=B
C     myTime          :: Current time in simulation
C     myIter          :: Current iteration number in simulation
C     myThid          :: My Thread Id number
      LOGICAL oldFreeSurfTerm
      _RL     cg2d_x(1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL     cg3d_b(1-OLx:sNx+OLx,1-OLy:sNy+OLy,Nr,nSx,nSy)
      _RL     myTime
      INTEGER myIter
      INTEGER myThid

#ifdef ALLOW_NONHYDROSTATIC
C     !LOCAL VARIABLES:
C     == Local variables ==
C     wSurfP2d :: surface vertical velocity after 2-D solver
      INTEGER i,j,k,bi,bj
      INTEGER ks, kp1
c     CHARACTER*10 sufx
c     CHARACTER*(MAX_LEN_MBUF) msgBuf
      _RL     locGamma, surfFac, tmpFac
      _RL     wFacKm, wFacKp
      _RL     uf(1-OLx:sNx+OLx,1-OLy:sNy+OLy)
      _RL     vf(1-OLx:sNx+OLx,1-OLy:sNy+OLy)
      _RL     wSurfP2d(1-OLx:sNx+OLx,1-OLy:sNy+OLy)
CEOP

c     IF ( use3Dsolver ) THEN

C--   Solve for a three-dimensional pressure term (NH or IGW or both ).
C     see CG3D.h for the interface to this routine.
       DO bj=myByLo(myThid),myByHi(myThid)
        DO bi=myBxLo(myThid),myBxHi(myThid)

C--   Calculate updated (after 2-D solver) vertical velocity at the surface
         IF ( oldFreeSurfTerm .OR. implicDiv2DFlow.EQ.zeroRL ) THEN
           DO j=1-OLy,sNy+OLy
            DO i=1-OLx,sNx+OLx
              wSurfP2d(i,j) = 0. _d 0
            ENDDO
           ENDDO
         ELSE
           DO j=1-OLy,sNy+OLy
            DO i=1-OLx,sNx+OLx
               wSurfP2d(i,j) = ( etaN(i,j,bi,bj)-etaH(i,j,bi,bj) )
     &                       / ( implicDiv2DFlow*deltaTFreeSurf )
            ENDDO
           ENDDO
         ENDIF

C--   Add EmPmR contribution to top level cg3d_b or to wSurfP2d:
C      (has been done for cg2d_b ; and addMass was added by CALC_DIV_GHAT)
         IF ( useRealFreshWaterFlux.AND.fluidIsWater ) THEN
          IF ( oldFreeSurfTerm .OR. usingPCoords ) THEN
           tmpFac = freeSurfFac*mass2rUnit*implicDiv2DFlow/deltaTMom
           ks = 1
           IF ( usingPCoords ) ks = Nr
           DO j=1,sNy
            DO i=1,sNx
              cg3d_b(i,j,ks,bi,bj) = cg3d_b(i,j,ks,bi,bj)
     &          + tmpFac*_rA(i,j,bi,bj)*EmPmR(i,j,bi,bj)
     &                                 *maskInC(i,j,bi,bj)
            ENDDO
           ENDDO
          ELSE
           DO j=1-OLy,sNy+OLy
            DO i=1-OLx,sNx+OLx
              wSurfP2d(i,j) = wSurfP2d(i,j)
     &                      + EmPmR(i,j,bi,bj)*mass2rUnit
     &                                 *maskInC(i,j,bi,bj)
            ENDDO
           ENDDO
          ENDIF
         ENDIF

C--   Update or Add free-surface contribution to cg3d_b:
         surfFac = 0.
         IF ( selectNHfreeSurf.GE.1 ) THEN
           tmpFac = freeSurfFac*implicDiv2DFlow/deltaTMom
           DO j=1,sNy
            DO i=1,sNx
              locGamma = drC(1)*recip_Bo(i,j,bi,bj)
     &                 /( deltaTMom*deltaTFreeSurf
     &                   *implicitNHPress*implicDiv2DFlow )
              ks = 1
c             ks = kSurfC(i,j,bi,bj)
c             IF ( ks.LE.Nr ) THEN
               cg3d_b(i,j,ks,bi,bj) = cg3d_b(i,j,ks,bi,bj)
     &                      + tmpFac*( wSurfP2d(i,j)
     &                               + locGamma*wVel(i,j,ks,bi,bj) )
     &                              /( 1. _d 0 + locGamma )
     &                              *_rA(i,j,bi,bj)*deepFac2F(ks)
c             ENDIF
C-    Save wSurfP2d (used in POST_CG3D) into dPhiNH :
              dPhiNH(i,j,bi,bj) = wSurfP2d(i,j)
            ENDDO
           ENDDO
         ELSEIF ( .NOT.oldFreeSurfTerm ) THEN
           tmpFac = freeSurfFac*implicDiv2DFlow/deltaTMom
           DO j=1,sNy
            DO i=1,sNx
              ks = kSurfC(i,j,bi,bj)
              IF ( ks.LE.Nr ) THEN
               cg3d_b(i,j,ks,bi,bj) = cg3d_b(i,j,ks,bi,bj)
     &                      + tmpFac*wSurfP2d(i,j)
     &                              *_rA(i,j,bi,bj)*deepFac2F(ks)
              ENDIF
            ENDDO
           ENDDO
         ELSEIF ( uniformFreeSurfLev ) THEN
C-       Z coordinate: assume surface @ level k=1
           surfFac = freeSurfFac*deepFac2F(1)
         ELSE
C-       Other than Z coordinate: no assumption on surface level index
           DO j=1,sNy
            DO i=1,sNx
              ks = kSurfC(i,j,bi,bj)
              IF ( ks.LE.Nr ) THEN
               cg3d_b(i,j,ks,bi,bj) = cg3d_b(i,j,ks,bi,bj)
     &              +freeSurfFac*etaN(i,j,bi,bj)/deltaTFreeSurf
     &                  *_rA(i,j,bi,bj)*deepFac2F(ks)/deltaTMom
              ENDIF
            ENDDO
           ENDDO
         ENDIF

C---+----1----+----2----+----3----+----4----+----5----+----6----+----7-|--+----|

C--   Finish updating cg3d_b: 1) increment in horiz velocity due to new cg2d_x
C                             2) add vertical velocity contribution.
         DO j=1,sNy+1
          DO i=1,sNx+1
           uf(i,j) = -_recip_dxC(i,j,bi,bj)
     &             * implicSurfPress*implicDiv2DFlow
     &             *(cg2d_x(i,j,bi,bj)-cg2d_x(i-1,j,bi,bj))
#ifdef ALLOW_OBCS
     &             *maskInC(i,j,bi,bj)*maskInC(i-1,j,bi,bj)
#endif
           vf(i,j) = -_recip_dyC(i,j,bi,bj)
     &             * implicSurfPress*implicDiv2DFlow
     &             *(cg2d_x(i,j,bi,bj)-cg2d_x(i,j-1,bi,bj))
#ifdef ALLOW_OBCS
     &             *maskInC(i,j,bi,bj)*maskInC(i,j-1,bi,bj)
#endif
          ENDDO
         ENDDO

C Note: with implicDiv2DFlow < 1, wVel contribution to cg3d_b is similar to
C       uVel,vVel contribution to cg2d_b when exactConserv=T, since wVel is
C       always recomputed from continuity eq (like eta when exactConserv=T)
         k=1
         kp1 = MIN(k+1,Nr)
         wFacKp = implicDiv2DFlow*deepFac2F(kp1)*rhoFacF(kp1)
         IF (k.GE.Nr) wFacKp = 0.
         DO j=1,sNy
          DO i=1,sNx
            cg3d_b(i,j,k,bi,bj) = cg3d_b(i,j,k,bi,bj)
     &       +drF(k)*dyG(i+1,j,bi,bj)*_hFacW(i+1,j,k,bi,bj)*uf(i+1,j)
     &       -drF(k)*dyG( i ,j,bi,bj)*_hFacW( i ,j,k,bi,bj)*uf( i ,j)
     &       +drF(k)*dxG(i,j+1,bi,bj)*_hFacS(i,j+1,k,bi,bj)*vf(i,j+1)
     &       -drF(k)*dxG(i, j ,bi,bj)*_hFacS(i, j ,k,bi,bj)*vf(i, j )
     &       +( surfFac*etaN(i,j,bi,bj)/deltaTFreeSurf
     &         -wVel(i,j,kp1,bi,bj)*wFacKp
     &        )*_rA(i,j,bi,bj)/deltaTMom
          ENDDO
         ENDDO
         DO k=2,Nr
          kp1 = MIN(k+1,Nr)
C-       deepFac & rhoFac cancel with the ones in uf[=del_i(Phi)/dx],vf ;
C        both appear in wVel term, but at 2 different levels
          wFacKm = implicDiv2DFlow*deepFac2F( k )*rhoFacF( k )
          wFacKp = implicDiv2DFlow*deepFac2F(kp1)*rhoFacF(kp1)
          IF (k.GE.Nr) wFacKp = 0.
          DO j=1,sNy
           DO i=1,sNx
            cg3d_b(i,j,k,bi,bj) = cg3d_b(i,j,k,bi,bj)
     &       +drF(k)*dyG(i+1,j,bi,bj)*_hFacW(i+1,j,k,bi,bj)*uf(i+1,j)
     &       -drF(k)*dyG( i ,j,bi,bj)*_hFacW( i ,j,k,bi,bj)*uf( i ,j)
     &       +drF(k)*dxG(i,j+1,bi,bj)*_hFacS(i,j+1,k,bi,bj)*vf(i,j+1)
     &       -drF(k)*dxG(i, j ,bi,bj)*_hFacS(i, j ,k,bi,bj)*vf(i, j )
     &       +( wVel(i,j, k ,bi,bj)*wFacKm*maskC(i,j,k-1,bi,bj)
     &         -wVel(i,j,kp1,bi,bj)*wFacKp
     &        )*_rA(i,j,bi,bj)/deltaTMom
           ENDDO
          ENDDO
         ENDDO

#ifdef ALLOW_OBCS
C- Note: solver matrix is trivial outside OB region (main diagonal only)
C     => no real need to reset RHS (=cg3d_b) & cg3d_x, except that:
C    a) normalisation is fct of Max(RHS), which can be large ouside OB region
C      (would be different if we were solving for increment of phi_nh
C       instead of directly for phi_nh).
C       => need to reset RHS to ensure that interior solution does not depend
C       on ouside OB region.
C    b) provide directly the trivial solution cg3d_x == 0 for outside OB region
C      (=> no residual => no effect on solver convergence and interior solution)
         IF (useOBCS) THEN
          DO k=1,Nr
           DO j=1,sNy
            DO i=1,sNx
              cg3d_b(i,j,k,bi,bj) = cg3d_b(i,j,k,bi,bj)
     &                            *maskInC(i,j,bi,bj)
              phi_nh(i,j,k,bi,bj) = phi_nh(i,j,k,bi,bj)
     &                            *maskInC(i,j,bi,bj)
            ENDDO
           ENDDO
          ENDDO
         ENDIF
#endif /* ALLOW_OBCS */

C-    end bi,bj loops
        ENDDO
       ENDDO

c     ENDIF
#endif /* ALLOW_NONHYDROSTATIC */

      RETURN
      END
