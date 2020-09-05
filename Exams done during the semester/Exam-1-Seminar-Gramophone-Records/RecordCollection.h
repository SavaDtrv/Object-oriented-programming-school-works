#pragma once
#include <iostream>
#include <string>
#include "GramophoneRecord.h"

using namespace std;

const double RESIZE_NUM_COLLECTION = 1.5;

class RecordCollection {
	
	GramophoneRecord* gramRecord;
	int collectionCapacity;
	int currentRecord;


	void resizeCollection() {
		
		collectionCapacity = collectionCapacity * RESIZE_NUM_COLLECTION;
		GramophoneRecord* gramRecord2 = new GramophoneRecord[collectionCapacity];
		for (int i = 0;i < collectionCapacity;i++)
		{
			gramRecord2[i] = gramRecord[i];
		}

		removeCollection();
		gramRecord = gramRecord2;
	}

	void addRecord(const GramophoneRecord& record) {
		
		if (currentRecord == collectionCapacity - 1)
		{
			resizeCollection();
		}
		currentRecord++;
		gramRecord[currentRecord] = record;
	}

	void removeCollection(){
		delete[] gramRecord;
	}

public:
	RecordCollection();
	RecordCollection& operator+(const GramophoneRecord& other);
	~RecordCollection();

	GramophoneRecord& findRecordByGenre(char* _genre);
	GramophoneRecord& findRecordByName(char* _albumName);
	
	GramophoneRecord& availableSongByDuration(int time);
};