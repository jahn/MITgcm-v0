function [mdt, mdtt, mdtstd] = mit_globalmean(dt,rac3d)
% function [mdt, mdtt, mdtstd] = mit_globalmean(dt,rac3d)
  
% $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/verification/tutorial_global_oce_latlon/diags_matlab/mit_globalmean.m,v 1.3 2006/08/12 20:25:12 jmc Exp $
% $Name:  $

  denom = nansum(nansum(rac3d));
  mdt    = squeeze(nansum(nansum(dt.*rac3d))./denom);
  mdtt   = squeeze(nansum(nansum(abs(dt).*rac3d))./denom);
  mdtstd = sqrt(squeeze(nansum(nansum(dt.^2.*rac3d))./denom));

  return
