//Group Members
//Samantha Lafrance, Taris Green, Darrell Brown
//File Name: Song.cpp
//Purpose: Implementation of Song.h
//Date Last Edited: 12/5/19

#include<iostream>
#include <string>
#include "Song.h"

using namespace std;

//Default
Song::Song()
{
    this->title = "";
    this->artist = "";
}

//Song Constructor with parameters
Song::Song(string title, string artist, string album, int length, int year)
{
    this->title = title;
    this->artist = artist;
    this->album = album;
    this->length = length;
    this->year = year;
}

//Song Title
void Song::setTitle(string title)
{
    this->title = title;
}

void Song::getTitle() const
{
    return title;
}

//Song Artist
void Song::setArtist(string artist)
{
    this->artist = artist;
}

void Song::getArtist() const
{
    return artist;
}

//Song Album
void Song::setAlbum(string album)
{
    this->album = album;
}

void Song::getAlbum() const
{
    return album;
}

//Song Length
void Song::setLength(int length)
{
    this->length = length;
}

void Song::getLength() const
{
    return length;
}

//Song Year
void Song::setYear(int year)
{
    this->year = year;
}

void Song::getYear() const
{
    return year;
}

//Display Song
friend bool operator==(const Song& lhs, const Song& rhs)
{
   return lhs.getTitle() == rhs.getTitle() && lhs.getArtist() == rhs.getArtist() && lhs.getAlbum() == rhs.getAlbum();
}
