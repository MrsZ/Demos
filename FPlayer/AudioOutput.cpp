#include <AudioOutput.h>
//#include <portaudio.h>

namespace QtAV {
AudioOutput::AudioOutput()
    :AVOutput()
{
    //outputParameters = new PaStreamParameters;
    //Pa_Initialize();

    stream = NULL;
    sample_rate = 0;
//     memset(outputParameters, 0, sizeof(PaStreamParameters));
//     outputParameters->device = Pa_GetDefaultOutputDevice();
//     outputParameters->sampleFormat = paFloat32;
//     outputParameters->hostApiSpecificStreamInfo = NULL;
//     outputParameters->suggestedLatency = Pa_GetDeviceInfo(outputParameters->device)->defaultHighOutputLatency;

}


AudioOutput::~AudioOutput()
{
    close();
//     Pa_Terminate();
//     if (outputParameters) {
//         delete outputParameters;
//         outputParameters = 0;
//     }
}

void AudioOutput::setSampleRate(int rate)
{
    sample_rate = rate;
}

void AudioOutput::setChannels(int channels)
{
    //outputParameters->channelCount = channels;
}

int AudioOutput::write(const QByteArray &data)
{
//     if (Pa_IsStreamStopped(stream))
//         Pa_StartStream(stream);


//     PaError err = Pa_WriteStream(stream, data.data(), data.size() / outputParameters->channelCount / sizeof(float));
//     if (err == paUnanticipatedHostError) {
//         qWarning("Write portaudio stream error: %s", Pa_GetErrorText(err));
//         return 0;
//     }

    return data.size();
}

bool AudioOutput::open()
{
//     PaError err = Pa_OpenStream(&stream, NULL, outputParameters, sample_rate, 0, paNoFlag, NULL, NULL);
//     if (err == paNoError)
//         outputLatency = Pa_GetStreamInfo(stream)->outputLatency;
//     else
//         qWarning("Open portaudio stream error: %s", Pa_GetErrorText(err));
//     return err == paNoError;

	return false;
}

bool AudioOutput::close()
{
//     PaError err = paNoError;
//     if (!stream) {
//         return true;
//     }
//     err = Pa_StopStream(stream);
//     if (err != paNoError)
//         qWarning("Stop portaudio stream error: %s", Pa_GetErrorText(err));
//     err = Pa_CloseStream(stream);
//     stream = NULL;
//     if (err != paNoError)
//         qWarning("Close portaudio stream error: %s", Pa_GetErrorText(err));
//     return err == paNoError;

	return false;
}
}
