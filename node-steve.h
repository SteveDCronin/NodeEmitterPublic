#include <node.h>
using namespace v8;
using namespace node;
#include "steve.h"

class SteveNode : public ObjectWrap, SteveEmitter {

public:

    SteveNode();  
    ~SteveNode();
    
    static void Initialize(Handle<Object> target);
    static Handle<Value> New(const Arguments& args);  

    static Handle<Value> Start(const Arguments& args);

protected:

    void myEmit(int argc, Handle<Value> argv[]);  
    
    Steve *steve; 
};
