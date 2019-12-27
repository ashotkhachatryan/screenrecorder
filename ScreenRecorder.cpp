#include "ScreenRecorder.h"

#define class m_class
extern "C"
{
    #include <libfftools/ffmpeg.h>
}
#undef class

ScreenRecorder::ScreenRecorder()
    : m_framerate(30)
{
}

void ScreenRecorder::CreateArguments()
{
    m_arguments.push_back(m_executable);

    //m_arguments.push_back("-video_size");
    //m_arguments.push_back(m_video_size);
    
    m_arguments.push_back("-f");
    m_arguments.push_back(m_device);

    m_arguments.push_back("-framerate");
    m_arguments.push_back(std::to_string(m_framerate));

    m_arguments.push_back("-i");
    m_arguments.push_back(m_input);

    if (m_codec_is_set)
    {
        m_arguments.push_back("-vcodec");
        m_arguments.push_back(m_codec);
    }

    m_arguments.push_back(m_output_file);

    m_arguments.push_back("-v");
    m_arguments.push_back("trace");
}

void ScreenRecorder::SetVideoSize(std::string size)
{
    m_video_size = size;
}

void ScreenRecorder::SetFramerate(int framerate)
{
    m_framerate = framerate;
}

void ScreenRecorder::SetDevice(std::string device)
{
    m_device = device;
}

void ScreenRecorder::SetInput(std::string input)
{
    m_input = input;
}

void ScreenRecorder::SetCodec(std::string codec)
{
    m_codec = codec;
    m_codec_is_set = true;
}

void ScreenRecorder::SetOutputFile(std::string file)
{
    m_output_file = file;
}

#include <iostream>
void ScreenRecorder::Record()
{
    char* argv[m_arguments.size()];

    for (int i = 0; i < m_arguments.size(); i++)
    {
        std::cout << m_arguments[i] << std::endl;
        argv[i] = (char*)m_arguments[i].c_str();
    }

    int argc = m_arguments.size();
    main_wrapper(argc, argv);
}
