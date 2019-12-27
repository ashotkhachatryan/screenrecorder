#include <iostream>
#include "ScreenRecorder.h"

#undef _WIN32_WINNT
#define _WIN32_WINNT 0x0602

int main()
{
    ScreenRecorder r;
    //r.SetVideoSize("1360x768");
    r.SetFramerate(25);
    r.SetDevice("gdigrab");
    r.SetInput("desktop");
    //r.SetCodec("libx264");
    r.SetOutputFile("output.mkv");

    r.CreateArguments();
    r.Record();

    return 0;
}
