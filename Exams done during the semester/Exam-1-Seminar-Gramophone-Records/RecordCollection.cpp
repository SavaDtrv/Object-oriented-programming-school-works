#include <iostream>
#include <string>
#include <fstream>
#include "RecordCollection.h"

using namespace std;

int const DEFFAULT_CAP = 0;
int const DEFFAULT_CURRENT = -1;

RecordCollection::RecordCollection() {
	GramophoneRecord();
	collectionCapacity = DEFFAULT_CAP;
	currentRecord = DEFFAULT_CURRENT;

}

RecordCollection& RecordCollection::operator+(const GramophoneRecord& other) {
	if (currentRecord + 1 == collectionCapacity)
	{
		resizeCollection();
	}
	else addRecord(other);

	return *this;
}

GramophoneRecord& RecordCollection::findRecordByGenre(char* _genre) {
	
	GramophoneRecord* collectionByGenre = new GramophoneRecord[collectionCapacity];
	int currentRec = 0;

	for (int i = 0; i < collectionCapacity; i++)
	{
		if (gramRecord[i].getGenre() == _genre)
		{
			collectionByGenre[currentRec] = gramRecord[i];
			currentRec++;
		}
	}

	return *collectionByGenre;
}
GramophoneRecord& RecordCollection::findRecordByName(char* _albumName) {
	
	GramophoneRecord* collectionByName = new GramophoneRecord[collectionCapacity];
	int currentRec = 0;

	for (int i = 0;i < collectionCapacity;i++)
	{
		if (gramRecord[i].getAlbumName()== _albumName)
		{
			collectionByName[currentRec] = gramRecord[i];
			currentRec++;
		}
	}

	return *collectionByName;
}

GramophoneRecord& RecordCollection::availableSongByDuration(int time) {

	GramophoneRecord* collectionByTime = new GramophoneRecord[collectionCapacity];
	int currentRec = 0;
	int tmpTime = 0;
	
	for (int i = 0; i < collectionCapacity && tmpTime < time;i++)
	{
		if (gramRecord[i].getTimeSong() < time)
		{
			collectionByTime[currentRec] = gramRecord[i];
			currentRec++;
			tmpTime += time;
		}
	}

	return *collectionByTime;
}

RecordCollection::~RecordCollection() {
	removeCollection();
}