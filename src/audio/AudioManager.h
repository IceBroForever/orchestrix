#ifndef ORCHESTRIX_AUDIOPMANAGER_H
#define ORCHESTRIX_AUDIOPMANAGER_H

#include <AL/alc.h>
#include <AL/al.h>
#include <audio/AudioData.h>
#include <audio/OpenAL.h>
#include <map>
#include <vector>
#include <mutex>
#include <set>

class AudioManager {
private:
    std::recursive_mutex _sourceMutex;
    std::recursive_mutex _bufferMutex;

    AudioData *sound;
    ALCdevice *device;
    ALCcontext *context;
    float masterVolume;

    vector3f listenerVel;
    vector3f listenerPos;
    float listenerOri[6];

    std::set<ALuint> buffers;
    std::set<ALuint> sources;
    std::vector<ALuint> freeBuffers;
    std::vector<ALuint> freeSources;

    AudioManager(ALCdevice *device, ALCcontext *contex, int source, int buffer);

    static void print(const std::vector<std::string> vec);

    static void print(const std::set<ALuint> buffer);

    static std::vector<std::string> getAllDevices();

    ALuint generateBuffer();

    ALuint generateSource();

    void deleteBuffer(ALuint buffer);

    void deleteSource(ALuint source);

    void createBuffer();

    void createSource();

public:
    static AudioManager *init(int source = 8, int buffer = 64);

    virtual ~AudioManager();

    ALuint getFreeBuffer();

    ALuint getFreeSource();

    void clearBuffer(ALuint buffer);

    void clearSource(ALuint source);

    void print(const std::vector<ALuint> buffer);
};

#endif //ORCHESTRIX_AUDIOPLAYER_H
