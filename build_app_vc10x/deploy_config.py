# -*- coding: utf-8 -*-
# Deployment settings for app.
# This file is autogenerated by the mkb system and used by the s3e deployment
# tool during the build process.

config = {}
cmdline = ['C:/Marmalade/6.3/s3e/makefile_builder/mkb.py', '--buildenv=VC10X', 'c:/Users/Pietro/Documents/GitHub/Patriot-Missile-Defense/app.mkb', '--deploy-only']
mkb = 'c:/Users/Pietro/Documents/GitHub/Patriot-Missile-Defense/app.mkb'
mkf = ['c:\\marmalade\\6.3\\modules\\iw2d\\iw2d.mkf', 'c:\\marmalade\\6.3\\modules\\iwgx\\iwgx.mkf', 'c:\\marmalade\\6.3\\modules\\iwgeom\\iwgeom.mkf', 'c:\\marmalade\\6.3\\modules\\iwutil\\iwutil.mkf', 'c:\\marmalade\\6.3\\modules\\third_party\\libjpeg\\libjpeg.mkf', 'c:\\marmalade\\6.3\\modules\\third_party\\libpng\\libpng.mkf', 'c:\\marmalade\\6.3\\modules\\third_party\\zlib\\zlib.mkf', 'c:\\marmalade\\6.3\\modules\\iwresmanager\\iwresmanager.mkf', 'c:\\marmalade\\6.3\\modules\\iwgl\\iwgl.mkf', 'c:\\marmalade\\6.3\\modules\\iwgxfont\\iwgxfont.mkf', 'c:\\marmalade\\6.3\\modules\\third_party\\tiniconv\\tiniconv.mkf', 'c:\\users\\pietro\\documents\\github\\patriot-missile-defense\\app.mkf']

class DeployConfig(object):
    pass

######### ASSET GROUPS #############

assets = {}

assets['Default'] = [
    ('c:/Users/Pietro/Documents/GitHub/Patriot-Missile-Defense\data', '.', 0),
]

assets['default'] = [
    ('c:/users/pietro/documents/github/patriot-missile-defense/data/splashscreen.jpg', 'splashscreen.jpg', 0),
    ('c:/users/pietro/documents/github/patriot-missile-defense/data-ram/data-gles2-dx11/resources.group.bin', 'resources.group.bin', 0),
]

assets['artbuild'] = [
    ('c:/users/pietro/documents/github/patriot-missile-defense/data', '.', 0),
]

######### DEFAULT CONFIG #############

class DefaultConfig(DeployConfig):
    embed_icf = -1
    name = 'app'
    pub_sign_key = 0
    priv_sign_key = 0
    caption = 'app'
    long_caption = 'app'
    version = [0, 0, 1]
    config = ['c:/Users/Pietro/Documents/GitHub/Patriot-Missile-Defense/data/app.icf']
    data_dir = 'c:/Users/Pietro/Documents/GitHub/Patriot-Missile-Defense/data'
    iphone_link_lib = []
    linux_ext_lib = []
    android_extra_application_manifest = []
    iphone_link_libdir = []
    iphone_link_libdirs = []
    iphone_link_opts = []
    android_external_jars = []
    android_external_res = []
    android_supports_gl_texture = []
    android_extra_manifest = []
    icon = 'c:/users/pietro/documents/github/patriot-missile-defense/icons'
    win32_ext_dll = []
    android_so = []
    osx_ext_dll = []
    iphone_link_libs = []
    target = {
         'gcc_x86' : {
                   'debug'   : r'c:/Users/Pietro/Documents/GitHub/Patriot-Missile-Defense/build_app_vc10x/Debug_app_VC10X_gcc_x86/app.so',
                   'release' : r'c:/Users/Pietro/Documents/GitHub/Patriot-Missile-Defense/build_app_vc10x/Release_app_VC10X_gcc_x86/app.so',
                 },
         'mips_gcc' : {
                   'debug'   : r'c:/Users/Pietro/Documents/GitHub/Patriot-Missile-Defense/build_app_vc10x/Debug_app_VC10X_gcc_mips/app.so',
                   'release' : r'c:/Users/Pietro/Documents/GitHub/Patriot-Missile-Defense/build_app_vc10x/Release_app_VC10X_gcc_mips/app.so',
                 },
         'arm_gcc' : {
                   'debug'   : r'c:/Users/Pietro/Documents/GitHub/Patriot-Missile-Defense/build_app_vc10x/Debug_app_VC10X_gcc_arm/app.s3e',
                   'release' : r'c:/Users/Pietro/Documents/GitHub/Patriot-Missile-Defense/build_app_vc10x/Release_app_VC10X_gcc_arm/app.s3e',
                 },
         'mips' : {
                   'debug'   : r'c:/Users/Pietro/Documents/GitHub/Patriot-Missile-Defense/build_app_vc10x/Debug_app_VC10X_gcc_mips/app.so',
                   'release' : r'c:/Users/Pietro/Documents/GitHub/Patriot-Missile-Defense/build_app_vc10x/Release_app_VC10X_gcc_mips/app.so',
                 },
         'gcc_x86_android' : {
                   'debug'   : r'c:/Users/Pietro/Documents/GitHub/Patriot-Missile-Defense/build_app_vc10x/Debug_app_VC10X_gcc_x86_android/app.so',
                   'release' : r'c:/Users/Pietro/Documents/GitHub/Patriot-Missile-Defense/build_app_vc10x/Release_app_VC10X_gcc_x86_android/app.so',
                 },
         'arm' : {
                   'debug'   : r'c:/Users/Pietro/Documents/GitHub/Patriot-Missile-Defense/build_app_vc10x/Debug_app_VC10X_arm/app.s3e',
                   'release' : r'c:/Users/Pietro/Documents/GitHub/Patriot-Missile-Defense/build_app_vc10x/Release_app_VC10X_arm/app.s3e',
                 },
         'x86' : {
                   'debug'   : r'c:/Users/Pietro/Documents/GitHub/Patriot-Missile-Defense/build_app_vc10x/Debug_app_VC10X_x86/app.s86',
                   'release' : r'c:/Users/Pietro/Documents/GitHub/Patriot-Missile-Defense/build_app_vc10x/Release_app_VC10X_x86/app.s86',
                 },
        }
    assets = assets['default']

default = DefaultConfig()

######### Configuration: artbuild

c = DeployConfig()
config['artbuild'] = c
c.os = ['win32']
c.target_folder = 'artbuild'
c.assets = assets['artbuild']