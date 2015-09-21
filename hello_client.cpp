#define LOG_TAG "hellobinder"
#define HELLO_SERVICE "hello_service"

#include <utils/Log.h>
#include <binder/Parcel.h>
#include <binder/IServiceManager.h>

using namespace android;
int main(int argc, char** argv)
{
    sp<IBinder> binder = defaultServiceManager()->getService( 
            String16( HELLO_SERVICE ));

    if( binder == 0 ) {
        ALOGE( "Failed to get binder by service name: %s", HELLO_SERVICE );
        return 1;
    } else{
        Parcel send, reply;
        binder->transact( 0, send, &reply, 0);
        return 0;
    }
} 
