# coding=utf-8

###### Options ######

options={}

options["<config>"]=ur'Default'
options["<os>"]=ur'wp8'
options["appdata"]=ur'C:/Users/Pietro/AppData/Roaming/MarmaladeTools'
options["build"]=ur'WP8-ARM Release'
options["cmdline"]=['C:/Marmalade/6.3/s3e/makefile_builder/mkb.py', '--buildenv=VC11XWP', '--buildenv-toolset=WP8DEV', 'c:/Users/Pietro/Documents/GitHub/Patriot-Missile-Defense/PatriotMissileDefense.mkb', '--deploy-only']
options["device"]=ur'"{"localdir}/Deploy.py" device "{"tempdir}/DeployOpts.py" {hasmkb}'
options["dir"]=ur'C:/Users/Pietro/Documents/GitHub/Patriot-Missile-Defense/build_patriotmissiledefense_vc11xwp_wp8devtoolset'
options["excluded_deploy_platforms"]=ur'NONE'
options["expires"]=ur'Thu Nov  7 15:55:01 2013'
options["folder"]=ur'"{"localdir}/Deploy.py" folder "{"tempdir}/DeployOpts.py" {hasmkb}'
options["generated"]=ur'Mon Oct 28 15:55:01 2013'
options["hasmkb"]=ur''
options["helpfile"]=ur'../docs/Deployment.chm'
options["helppage"]=ur'0'
options["license_type"]=ur'Evaluation'
options["licensed_platforms"]=ur'NONE'
options["mac_address"]=ur'2c41385e2cd0'
options["mkb"]=ur'c:/Users/Pietro/Documents/GitHub/Patriot-Missile-Defense/PatriotMissileDefense.mkb'
options["mkbdir"]=ur'c:/Users/Pietro/Documents/GitHub/Patriot-Missile-Defense'
options["mkbfile"]=ur'PatriotMissileDefense.mkb'
options["outdir"]=ur'C:/Users/Pietro/Documents/GitHub/Patriot-Missile-Defense/build_patriotmissiledefense_vc11xwp_wp8devtoolset'
options["renew"]=ur'Tue Oct 29 15:55:01 2013'
options["required_splashscreen"]=ur'FALSE'
options["resdir"]=ur'C:/Marmalade/6.3/tools/DeployTool/'
options["s3edir"]=ur'C:/Marmalade/6.3/s3e/'
options["sdk_version"]=ur'6.3.2 [347778q] (Win32)'
options["stage"]=ur'build'
options["target"]=ur'PatriotMissileDefense'
options["task"]=ur'Default'
options["tasktype"]=ur'Package'
options["username"]=ur'pietro.lorefice@gmail.com'

###### Tasks ######

tasks=[]

### Task Default:wp8 ###

t={}
tasks.append(t)
t["tasktype"]="Package"
t["<config>"]="Default"
t["os"]="wp8"
t["endDir"]="C:/Users/Pietro/Documents/GitHub/Patriot-Missile-Defense/build_patriotmissiledefense_vc11xwp_wp8devtoolset/deployments/default/wp8/release/wp8"
