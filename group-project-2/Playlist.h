#ifndef MY_PLAYLIST
#define MY_PLAYLIST

#include <string>
#include <vector>
#include "Song.h"

class Playlist {
public:
    Playlist(const std::string& name_love = "default");
    void addSong(Song&& song);
    friend std::ostream& operator<<(std::ostream& os, const Playlist& value);
private:
    std::string name;
    double length {0.0};
    std::vector<Song> song_list;
};


#endif // MY_PLAYLIST 
