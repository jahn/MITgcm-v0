% sq(A)  is similar to squeeze(A) except that elements =0 are set to NaN
%
% sq(A)             0   -> NaN
% sq(A,val1)       val1 -> NaN
% sq(A,val1,val2)  val1 -> val2

% $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/verification/tutorial_global_oce_latlon/diags_matlab/sq.m,v 1.1 2006/08/12 19:37:26 jmc Exp $
% $Name:  $

function [A] = sq(B,varargin);
A=squeeze(B);
if nargin>=2
 nodata=varargin{1};
else
 nodata=0;
end
if nargin==3
 newval=varargin{2};
else
 newval=NaN;
end
%A(find(A==nodata))=A(find(A==nodata))*NaN;
A(find(A==nodata))=newval;
