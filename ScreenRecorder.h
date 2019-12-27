#ifndef SCREENRECORDER_H
#define SCREENRECORDER_H

#include <vector>
#include <string>

class ScreenRecorder
{
public:
    ScreenRecorder();
    void CreateArguments();
    void Record();
    void SetVideoSize(std::string size);
    void SetFramerate(int framerate);
    void SetDevice(std::string device);
    void SetInput(std::string input);
    void SetCodec(std::string codec);
    void SetOutputFile(std::string file);
private:
    std::string m_video_size;
    int m_framerate;
    std::string m_device;
    std::string m_input;
    std::string m_codec;
    std::string m_executable = "ffmp";
    std::string m_output_file;

    bool m_codec_is_set = false;
    std::vector<std::string> m_arguments;
};

#endif
