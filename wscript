srcdir = '.'
blddir = 'build'
VERSION = '1.0.0'
APPNAME = 'node-steve'

def set_options(opt):
    opt.tool_options('compiler_cxx')

def configure(conf):
    conf.check_tool('compiler_cxx')
    conf.check_tool('node_addon')

def build(bld):
    obj = bld.new_task_gen('cxx', 'shlib', 'node_addon')
    obj.target = 'node-steve'
    obj.source = 'node-steve.cc'
