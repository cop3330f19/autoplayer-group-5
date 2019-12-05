#include <iostream>
#include <string>
#include "Playlist.h"

Playlist::Playlist(const std::string& name_love)
    : name {name_love}
{}


void Playlist::addSong(Song&& song)
{
    length += song.songLength;
    song_list.push_back(song);
}

void Playlist::deleteSong(Song && song)
{
    length 
}


std::ostream& operator<<(std::ostream& os, const Playlist& value)
{
    os << "Playlist '" << value.name << "':\n";
    for(const auto& s : value.song_list) {
        os << "title: " << s.songTitle << "; artist: " << s.artistName
           << "; genre: " << s.songGenre << "; duration " << s.songLength 
           << '\n';
    }
    return os;
}
