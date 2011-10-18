#include "interface-node-steve-emitter.h"
#include <node.h>
using namespace node;
#include "unistd.h"  //sleep()

class Steve {

public:

Steve() {
	printf("\nSteve - Constructor()");
}

~Steve() {
	printf("\nSteve - Destructor()");
}

SteveEmitter *steveEmitter;

void setSteveEmitter(SteveEmitter *paramEmitter){
	printf("\nSteve - setSteveEmitter()");
    steveEmitter = paramEmitter;
}

void startHeartbeat(int loopCount) {
    Local<Value> argv[1];
    argv[0] = Local<Value>::New(String::New("success"));
    int x = 0;
    while (x < loopCount) {
        printf("\nSteve - HeartBeat: %i",x+1);
        sleep(3);
        this->steveEmitter->myEmit(1, argv);
        x++;
    }
    printf("\n\n");
}

};
