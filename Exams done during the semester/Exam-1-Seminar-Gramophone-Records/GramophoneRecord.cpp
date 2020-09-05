#include <iostream>
#include <string>
#include "GramophoneRecord.h"

using namespace std;


int const DEFFAULT_YEAR_MADE = 0;
int const DEFFAULT_LENGTH = 0;
int const DEFFAULT_TIME = 0;
int const MIN_YEAR_MADE = 1500;
int const MIN_SONG_LENGTH = 60;

GramophoneRecord::GramophoneRecord() {
	yearMade = DEFFAULT_YEAR_MADE;
	genre = new char[DEFFAULT_LENGTH + 1];
	strcpy(genre, "");
	artist = new char[DEFFAULT_LENGTH + 1];
	strcpy(artist, "");
	albumName =new char[DEFFAULT_LENGTH + 1];
	strcpy(albumName, "");
	timeSong = DEFFAULT_TIME;

}
GramophoneRecord::GramophoneRecord(int _yearMade, char* _genre, char* _artist, char* _albumName, int _timeSong) {
	this->setYearMade(_yearMade);
	this->setGenre(_genre);
	this->setArtist(_artist);
	this->setAlbumName(_albumName);
	this->setTimeSong(_timeSong);

}
GramophoneRecord::GramophoneRecord(const GramophoneRecord& other) {
	copyRecord(other);
}
GramophoneRecord& GramophoneRecord::operator=(const GramophoneRecord& other) {
	if (this != &other)
	{
		removeRecord();
		copyRecord(other);
	}

	return *this;
}

int GramophoneRecord::getYearMade() const {
	return this->yearMade;
}
const char* GramophoneRecord::getGenre() const {
	return this->genre;
}
const char* GramophoneRecord::getArtist() const {
	return this->artist;
}
const char* GramophoneRecord::getAlbumName() const {
	return this->albumName;
}
int GramophoneRecord::getTimeSong() const {
	return this->timeSong;
}

void GramophoneRecord::setYearMade(int newYearMade) {
	if (newYearMade > MIN_YEAR_MADE)
	{
		yearMade = newYearMade;
	}
	cout << "There were no gramophone record before " << MIN_YEAR_MADE << '\n';
}
void GramophoneRecord::setGenre(char* newGenre) {
	if (genre != nullptr)
	{
		delete genre;
		genre = nullptr;
	}

	int length = strlen(newGenre);
	genre = new char[length + 1];
	strcpy(genre, newGenre);
}
void GramophoneRecord::setArtist(char* newArtist) {
	if (artist != nullptr) 
	{
		delete artist;
		artist = nullptr;
	}

	int length = strlen(newArtist);
	artist = new char[length + 1];
	strcpy(artist, newArtist);
}
void GramophoneRecord::setAlbumName(char* newAlbumName) {
	if (albumName != nullptr) 
	{
		delete albumName;
		albumName = nullptr;
	}

	int length = strlen(newAlbumName);
	albumName = new char[length + 1];
	strcpy(albumName, newAlbumName);
}
void GramophoneRecord::setTimeSong(int newTimeSong) {
	if (newTimeSong > MIN_SONG_LENGTH)
	{
		timeSong = newTimeSong;
	}
	else cout << "The length of the song is too short." << '\n';
}

GramophoneRecord::~GramophoneRecord() {
	removeRecord();
}