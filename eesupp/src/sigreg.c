/*
 * $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/eesupp/src/sigreg.c,v 1.4 2006/05/23 14:55:19 edhill Exp $
 * $Name:  $

//BOP
// !ROUTINE: sigreg
// !INTERFACE:
   sigreg()

// !DESCRIPTION:
// Register a signal handler

//EOP

*/

/*  Here, we get the definition of the FC_NAMEMANGLE() macro. */
#include "FC_NAMEMANGLE.h"

/* #define FC_NAMEMANGLE(X) X ## _ */

#ifdef HAVE_SIGREG
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <errno.h>
#include <ucontext.h>
#endif

int * ip;

#ifdef HAVE_SIGREG
static void killhandler(
    unsigned int sn, siginfo_t  si, struct ucontext *sc )
{
    *ip = *ip + 1;
    return;
}
#endif

/* int main( int argc, char ** argv ) */
void FC_NAMEMANGLE(sigreg) (int * aip)
{
#ifdef HAVE_SIGREG
    struct sigaction s;
    ip = aip;
    s.sa_flags = SA_SIGINFO;
    s.sa_sigaction = (void *)killhandler;
    if(sigaction (SIGTERM,&s,(struct sigaction *)NULL)) {
	printf("Sigaction returned error = %d\n", errno);
	exit(0);
    }
#endif
    return;
}


