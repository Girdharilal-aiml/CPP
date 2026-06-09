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
};
