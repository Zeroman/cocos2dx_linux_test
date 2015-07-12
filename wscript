#! /usr/bin/env python

import os

top = '.'
out = 'build'

libs_dir = '/work/src/game/cocos2d-x/lib'
srcs_dir = '/work/src/game/cocos2d-x/src'

def options(opt):
	opt.load('compiler_cxx')

def configure(conf):
	conf.load('compiler_cxx')
	conf.env.append_value('CXXFLAGS_COCOS2D', ['-O2', '-g'])
	conf.env.append_value('CXXFLAGS_COCOS2D', ['-fno-exceptions', '-std=c++11'])
	conf.env.append_value('CXXFLAGS_COCOS2D', ['-Wno-unused-parameter'])
	conf.env.append_value('CXXFLAGS_COCOS2D', ['-Wno-unused-variable'])
	conf.env.append_value('CXXFLAGS_COCOS2D', ['-Wno-ignored-qualifiers'])
	conf.env.append_value('CXXFLAGS_COCOS2D', ['-Wno-deprecated-declarations'])
	conf.env.append_value('CXXFLAGS_COCOS2D', ['-Wno-reorder'])
	# conf.env.append_value('CXXFLAGS_COCOS2D', ['-Wextra'])
	conf.env.append_value('CXXFLAGS_COCOS2D', ['-Wall'])
	# conf.env.append_value('CXXFLAGS_COCOS2D', [''])
	# conf.env.append_value('CXXFLAGS_COCOS2D', ['-include', '_debug.h'])

	conf.env.append_value('DEFINES_COCOS2D', ['CC_ENABLE_BOX2D_INTEGRATION=0'])
	conf.env.append_value('DEFINES_COCOS2D', ['CC_ENABLE_BULLET_INTEGRATION=1'])
	conf.env.append_value('DEFINES_COCOS2D', ['CC_ENABLE_CHIPMUNK_INTEGRATION=1'])
	conf.env.append_value('DEFINES_COCOS2D', ['CC_USE_NAVMESH=1'])
	conf.env.append_value('DEFINES_COCOS2D', ['CC_USE_PHYSICS=1'])
	conf.env.append_value('DEFINES_COCOS2D', ['LINUX'])
	conf.env.append_value('DEFINES_COCOS2D', ['_BSD_SOURCE'])
	conf.env.append_value('DEFINES_COCOS2D', ['_POSIX_C_SOURCE=200809L'])
	conf.env.append_value('DEFINES_COCOS2D', ['COCOS2D_DEBUG=1'])
	# conf.env.append_value('DEFINES_COCOS2D', [''])

	conf.env.append_value('INCLUDES', ['/usr/include/GLFW', '/usr/local/include/GLFW'])
	conf.env.append_value('INCLUDES', [srcs_dir])
	conf.env.append_value('INCLUDES', [os.path.join(srcs_dir, 'cocos')])

	conf.env.append_value('LIBPATH_COCOS2D', [conf.path.abspath()])
	conf.env.append_value('LIBPATH_COCOS2D', [libs_dir])

	conf.env.append_value('LINKFLAGS_COCOS2D', ['-rdynamic'])

	conf.env.append_value('LIB_COCOS2D', ['cocos2d'])
	# conf.env.append_value('LIBS_COCOS2D', os.path.join(libs_dir, 'libcocos2d.a'))

	conf.env.append_value('LIB_COCOS2D', ['curl', 'GLU', 'GL', 'SM', 'ICE'])
	conf.env.append_value('LIB_COCOS2D', ['X11', 'Xext'])
	conf.env.append_value('LIB_COCOS2D', ['GLEW', 'glfw'])
	conf.env.append_value('LIB_COCOS2D', ['fmodex64', 'fmodexL64'])
	conf.env.append_value('LIB_COCOS2D', ['fontconfig'])
	conf.env.append_value('LIB_COCOS2D', ['freetype'])
	conf.env.append_value('LIB_COCOS2D', ['unzip'])
	conf.env.append_value('LIB_COCOS2D', ['xxhash'])
	conf.env.append_value('LIB_COCOS2D', ['chipmunk', 'bullet'])
	conf.env.append_value('LIB_COCOS2D', ['flatbuffers'])
	conf.env.append_value('LIB_COCOS2D', ['websockets', 'webp', 'recast'])
	conf.env.append_value('LIB_COCOS2D', ['png12', 'jpeg', 'tiff'])
	conf.env.append_value('LIB_COCOS2D', [ 'z', 'm'])
	conf.env.append_value('LIB_COCOS2D', ['pthread'])


def build(bld):
	srcs = bld.srcnode.ant_glob('*.cpp') + ['../src/external/tinyxml2/tinyxml2.cpp']
	bld.program(source = srcs, target = 'main', use='COCOS2D')

# vim:ft=python:noet
