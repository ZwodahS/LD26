#include <stdlib.h>
#include <time.h>
#include "framework/zf_framework.h"
int main(int argc , char * argv[])
{
    // init the rng
    srand(time(NULL));
    // init framework
    Display d = Display();
    d.frameworkInit();
    // sound stuffs
    SoundControl sc = SoundControl();
    sc.init();
    d.init(640,640,640,640,32);
    

}
