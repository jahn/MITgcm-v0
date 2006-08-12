function h = mit_readfield(fname,dims,accuracy)
%function h = mit_readfield(fname,dims,accuracy)
  
% $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/verification/tutorial_global_oce_latlon/diags_matlab/mit_readfield.m,v 1.1 2006/08/12 19:37:26 jmc Exp $
% $Name:  $

  ieee='ieee-be';

  [fid message] = fopen(fname,'r',ieee);
  if fid <= 0
    error([message ', filename: ', [fname]])
  end

  v = fread(fid,accuracy);
  if length(v) == prod(dims)
    h = reshape(v,dims);
  elseif length(v) == prod(dims(1:end-1))
    h = reshape(v,dims(1:end-1));
  else
    error('dimensions do not match')
  end
  fclose(fid);
  
  return
