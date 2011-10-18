#include <node.h> 
using namespace v8;

#ifndef EMITTER_INTERFACE_H
#define EMITTER_INTERFACE_H

class SteveEmitter  {    
  public: 
    virtual void myEmit(int argc, Handle<Value> argv[])=0;
};
#endif