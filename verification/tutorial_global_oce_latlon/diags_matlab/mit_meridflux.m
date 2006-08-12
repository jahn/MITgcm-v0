function T = mit_meridflux(surface_flux,dx,dy)
% function T = mit_meridflux(surface_flux,dx,dy)
  
% $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/verification/tutorial_global_oce_latlon/diags_matlab/mit_meridflux.m,v 1.1 2006/08/12 19:37:25 jmc Exp $
% $Name:  $

  if nargin == 2
    area = dx;
  elseif nargin == 3
    area = dx.*dy;
  else
    error('need two or three input parameters')
  end
  [nx ny nt] = size(surface_flux);
  for kt=1:nt
    fdxdy(:,:,kt) = change(surface_flux(:,:,kt),'==',NaN,0).*area;
  end

  T = squeeze(sum(cumsum(fdxdy,2),1));
  
  return
