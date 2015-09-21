#define LOG_TAG "hellobinder"
#define HELLO_SERVICE "hello_service"

#include <utils/Log.h>
#include <binder/IServiceManager.h>
#include <binder/ProcessState.h>
#include <binder/IPCThreadState.h>

using namespace android;

class HelloService : public BBinder 
{
	virtual status_t onTransact( uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags = 0 );
};

status_t HelloService::onTransact(uint32_t code, const Parcel &data,
                                    Parcel* reply, uint32_t flags) {
	ALOGI( "Hello World!!");
	return 0;
}

int main(int argc, char** argv)
{
    sp<ProcessState> proc( ProcessState::self());
    int rv = defaultServiceManager()->addService( 
            String16( "hello_service"), 
            new HelloService()
            );

    if( rv != 0 ){
        ALOGE( "Failed to add %s",HELLO_SERVICE );
    }else{
        ProcessState::self()->startThreadPool();
        IPCThreadState::self()->joinThreadPool();
    }

    return rv;
} 
