#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class GramophoneRecord {
	int yearMade;
	char* genre;
	char* artist;
	char* albumName;
	int timeSong;

	void copyRecord(const GramophoneRecord& other) {
		setYearMade(other.yearMade);
		setGenre(other.genre);
		setArtist(other.artist);
		setAlbumName(other.albumName);
		setTimeSong(other.timeSong);
	}

	void removeRecord() {
		delete genre;
		genre = nullptr;
		delete artist;
		artist = nullptr;
		delete albumName;
		albumName = nullptr;
	}

public:
	GramophoneRecord();
	GramophoneRecord(int, char*, char*, char*, int);
	GramophoneRecord(const GramophoneRecord& other);
	GramophoneRecord& operator=(const GramophoneRecord& other);
	~GramophoneRecord();

	int getYearMade() const;
	const char* getGenre() const;
	const char* getArtist() const;
	const char* getAlbumName() const;
	int getTimeSong() const;

	void setYearMade(int);
	void setGenre(char*);
	void setArtist(char*);
	void setAlbumName(char*);
	void setTimeSong(int);

	friend ostream& operator<<(ostream os, const GramophoneRecord& other) {
		os << "Record characteristics: " << '\n';
		os << "Year made: " << other.getYearMade() << '\n'
			<< "Genre: " << other.getGenre() << '\n'
			<< "Artist: " << other.getArtist() << '\n'
			<< "Album name: " << other.getAlbumName() << '\n'
			<< "Length of the song: " << other.getTimeSong() << '\n';

		return os;
	}
};