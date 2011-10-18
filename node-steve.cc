#include "node-steve.h"     //interface file
#include <v8.h>
#include <node.h>

using namespace v8;
using namespace node;

static int showDebugMessages = 1;
static Persistent<String> sym_emit;

SteveNode::SteveNode() : ObjectWrap() {
    if (showDebugMessages==1) printf("\nSteveNode - Constructor");
    this->steve = new Steve();
    this->steve->setSteveEmitter(this);
}

SteveNode::~ SteveNode() {    if (showDebugMessages==1) printf("\nSteveNode - Destructor");
    delete steve;
    steve = NULL;}

void SteveNode::Initialize(Handle<Object> target) {
    if (showDebugMessages==1) printf("\nSteveNode - Initialize");
    HandleScope scope;
    Local<FunctionTemplate> t = FunctionTemplate::New(New);
    t->InstanceTemplate()->SetInternalFieldCount(1);
    NODE_SET_PROTOTYPE_METHOD(t, "Start", Start);
    sym_emit = NODE_PSYMBOL("emit");
    target->Set(String::NewSymbol("SteveNode"), t->GetFunction());
}

Handle<Value> SteveNode::New(const Arguments& args) {
    if (showDebugMessages==1) printf("\nSteveNode - New()");
    HandleScope scope;
    SteveNode *localNode = new SteveNode();  //this calls the constructor
    localNode->Wrap(args.This());
    return args.This();
}

Handle<Value> SteveNode::Start(const Arguments& args) {
   if (showDebugMessages==1) printf("\nSteveNode - Start()");
    HandleScope scope;
    SteveNode *localNode = ObjectWrap::Unwrap<SteveNode>(args.This());
    localNode->steve->startHeartbeat(3);
}

void SteveNode::myEmit(int argc, Handle<Value> argv[]) {
    char emitType[256];
    argv[0]->ToString()->WriteAscii(emitType,0,-1);  
    if (showDebugMessages==1) printf("\nnode-steve.node - myEmit: %s", emitType);
    HandleScope scope;
    
    //  ** complete this method such that the 'success' event is received in JavaScript by the registered listener **
    
} 

extern "C"  void init(Handle<Object> target) {
    if (showDebugMessages==1) printf("node-steve.node - init");
    HandleScope scope;
    SteveNode::Initialize(target);
    NODE_MODULE(SteveNode, init);
}
