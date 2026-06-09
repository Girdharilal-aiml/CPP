// 17. The Media Player: A MediaFile has a filePath. AudioTrack and VideoTrack are MediaFiles.
// Rule: A Movie combines both an AudioTrack and a VideoTrack. Design the classes so Movie has only one filePath.
// Rule: Implement a play() method in Movie that specifically calls the individual play() methods of both the AudioTrack and VideoTrack.

#include "iostream"
using namespace std;

class MediaFile{
protected:
    string FilePath;
    
public:
    MediaFile(string FP) : FilePath(FP){}
    string getFile(){
        return FilePath;
    }
};

class AudioTrack : virtual public MediaFile{
public:
    AudioTrack(string FP) : MediaFile(FP){}
    void PlayAudio(){
        cout << "Playing AudioTrack..." << endl;
    }
};

class VideoTrack : virtual public MediaFile{
public:
    VideoTrack(string FP) : MediaFile(FP){}
    void PlayVideo(){
        cout << "Playing VideoTrack..." << endl;
    }
};

class Movie : public AudioTrack, VideoTrack{
public:
    Movie(string FP) : MediaFile(FP), AudioTrack(FP), VideoTrack(FP){}
    void Play(){
        cout << "Playing..." << endl;
        AudioTrack::PlayAudio();
        VideoTrack::PlayVideo();
    }
};

int main(){
}