#include <fstream>
#include <iostream>
#include <string>
#include "Playlist.h"
#include "Song.h"
#include "StringHelper.h"


using namespace std;


struct songDetails
{
 string name;
 string filename;
};


void loadPlayList(vector<songDetails> &);
void displayPlaylists(vector<songDetails> &);
void addNewPlaylist(string, vector<songDetails> &);
bool Menu(Playlist &);
void deleteSong(Playlist &);
void addSong(Playlist &);
void modeChange();
Playlist playlistObject;


int main()
{
 vector<songDetails> vectorOfSongs;
 loadPlayList(vectorOfSongs);

 Playlist playlistObject;
 int menuChoice;
 int selection;
 string newplaylist;

 
 cout << "-------WELCOME to the AutoPlayer----------" << endl;
 do
 {
 do
 {
 cout << "1 - Open an exisiting playlist" << endl;
 cout << "2 - Create new list" << endl;
 cout << "3 - Exit" << endl;
 cout << "Selection: ";
 cin >> menuChoice;
 } while (menuChoice != 1 && menuChoice != 2 && menuChoice != 3);

 if (menuChoice == 1)
 {
 cout << "Please select a playlist from below: " << endl;
 displayPlaylists(vectorOfSongs);

 do
 {
 cout << "Selection: ";
 cin >> selection;
 if (selection < 1 || selection > vectorOfSongs.size())
 cout << "Invalid selection" << endl;
 } while (selection < 1 || selection > vectorOfSongs.size());
 cout << endl;
 Playlist p1(vectorOfSongs[selection - 1].name);

 Menu(p1);
 }
 else if (menuChoice == 2)
 {
 do
 {
 cout << "1 - Create new empty list" << endl;
 cout << "2 - Merge 2 exisitng playlists" << endl;
 cout << "3 - Intersect 2 exisinting playlists" << endl;
 cout << "Selection: ";
 cin >> selection;
 } while (selection != 1 && selection != 2 && selection != 3);

 cin.ignore();

 cout << "Name of new playlist (cannot contain underscores): ";
 getline(cin, newplaylist);

 switch (selection)
 {
 case 1:
 {
 Playlist p;
 p.setPName(newplaylist);
 addNewPlaylist(newplaylist, vectorOfSongs);
 Menu(p);
 }
 break;
 case 2:
 {
 cout << endl
 << "Which of the following playlists would you like to merge? " << endl;
 displayPlaylists(vectorOfSongs);
 int listOfSongs[2];

 for (int forLoopCounter = 0, j = 1; j < 3; j++, forLoopCounter++)
 {
 do
 {
 cout << "Playlist " << j << ": ";
 cin >> listOfSongs[forLoopCounter];
 if (listOfSongs[forLoopCounter] < 1 || listOfSongs[forLoopCounter] > vectorOfSongs.size())
 cout << "Invalid selection" << endl;

 } while (listOfSongs[forLoopCounter] < 1 || listOfSongs[forLoopCounter] > vectorOfSongs.size());
 }

 Playlist p1(vectorOfSongs[listOfSongs[0] - 1].name);
 Playlist p2(vectorOfSongs[listOfSongs[1] - 1].name);

 Playlist p3 = p1 + p2;

 p3.setPName(newplaylist);
 addNewPlaylist(newplaylist, vectorOfSongs);
 while (Menu(p3))
 ;
 }
 break;
 case 3:
 {
 cout << endl
 << "Which of the following playlists would you like to intersect? " << endl;
 displayPlaylists(vectorOfSongs);
 int listOfSongs[2];

 for (int forLoopCounter = 0, j = 1; j < 3; j++, forLoopCounter++)
 {
 do
 {
 cout << "Playlist " << j << ": ";
 cin >> listOfSongs[forLoopCounter];
 if (listOfSongs[forLoopCounter] < 1 || listOfSongs[forLoopCounter] > vectorOfSongs.size())
 cout << "Invalid selection" << endl;

 } while (listOfSongs[forLoopCounter] < 1 || listOfSongs[forLoopCounter] > vectorOfSongs.size());
 }

 Playlist p1(vectorOfSongs[listOfSongs[0] - 1].name);
 Playlist p2(vectorOfSongs[listOfSongs[1] - 1].name);

 Playlist p3 = p1.intersectPlaylist(p2);

 addNewPlaylist(newplaylist, vectorOfSongs);
 while (Menu(p3))
 ;
 }
 break;
 }

 cout << endl;
 }
 } while (menuChoice != 3);

 return 0; //terminates program
}


void displayPlaylists(vector<songDetails> &vectorOfSongs)
{
 for (int forLoopCounter = 0, j = 1; forLoopCounter < vectorOfSongs.size(); forLoopCounter++, j++)
 cout << j << " " << vectorOfSongs[forLoopCounter].name << endl;
}

void loadPlayList(vector<songDetails> &vectorOfSongs)
{

 ifstream in;
 in.open("Playlist.list");
 string filename;
 if (in)
 {

 while (in >> filename)
 {

 songDetails l = {StringHelper::utos(filename), filename};
 vectorOfSongs.push_back(l);
 }
 }
 else
 {
 cout << "Could not open Playlist.list" << endl;
 }
 in.close();
}
