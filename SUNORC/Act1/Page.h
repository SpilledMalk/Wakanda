#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <iterator>

using namespace std;

class Page {

public:
	map <string, vector<string>> pageMap;

	virtual void printPage(const string & currentItem) {
		for (int i = 0; i <= 5; ++i) // page spacing
			cout << endl;
		for (auto & line : pageMap[currentItem])
			cout << line << endl;
	}

	// Takes an input array of Page Name / File Name pairs and groups them into a map
	void loadPages(int numberOfPages, string pageNamePairs[]) {
		int key = 0;
		int value = 1;
		for (int i = 0; i < numberOfPages; ++i, key += 2, value += 2)
		{
			pageMap[pageNamePairs[key]] = convertFileToVector(pageNamePairs[value]);
		}
	}

	// pure virtual function that is overloaded by each child page
	// used for receiving input for each Page child object
	virtual void getResponse(string & currentItem, int & pageNum, bool & terminate) = 0;

	// Takes a file, opens it, and stores it into a single vector
	static vector<string> convertFileToVector(string fileName) {
		ifstream pageContents(fileName);
		vector<string> pageLines;
		string lineHolder;
		while (getline(pageContents, lineHolder)) {
			pageLines.push_back(lineHolder);
		}
		return pageLines;
	}

};



