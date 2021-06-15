/*
Mendi Ben-Ezra
Course Name: Data Structures 2
Exercise 2
Description: Program that use hash table for subjects and titles
*/

#pragma once
#include"HashTable.h"

class HSubject : public HashTable<list<string>, string> {    //class "HSubject" uses list for subjects
public:
	HSubject(int capa) :HashTable(capa) {}					//ctor
	int h1(string key);										//mixing function H1
	int h2(string key);										//mixing function H2	
	void printS(string key);								//prints subjects
	void printN(string key, int n);							//print subject from specific place
	void printAll();										//print all subjects and titles
	void addSubjectAndTitle(string data, string key);		//add new subject an title
	void startNewTable();									//restart the table
};
//mixing function H1
int HSubject::h1(string key) {				
	int k = convertStringToNumbers(key);			//convert string to number
	return ((k) % HashTable::capacity);				//return the key using "mod size"
}	

//mixing function H2
int HSubject::h2(string key) {
	return (primeNumber(HashTable::capacity));		//return the next prime of the size
}													//because we wnt that H2 number will be strange to the size number

//add new subject an title
void HSubject::addSubjectAndTitle(string data, string key) {
	int x = HashTable::search(key);							//find place to entertd the new subject
	if (x == -1) {											//in case the place is empty
		list<string> temp;									//temp list
		temp.push_front(data);								//start the temp list with the new subject
		HashTable::insert(temp, key);						//insert to th table the new title and sybject
	}
	else {
		items[x].data.push_front(data);						//in case the title is exist so just insert the subject
	}
}

//restart the table
void HSubject::startNewTable() {
	list<string> tempData;							//create empty list
	Item tempItem(tempData, "/0", empty1);			//create an empty "Item1"
	for (int i = 0; i < items.size(); i++)			//loop to start the table with empty elements
	{
		items[i] = tempItem;
	}
}

//print subject from specific place
void HSubject::printN(string key, int n) {
	int x = HashTable::search(key);					//find the place of the key to print
	int i = 0;
	if (x == -1)									//in case key was not found
		throw "ERROR";
	if (n > items[x].data.size()) {					//if N > size print all subjects
		for (list<string>::iterator it = items[x].data.begin(); it != items[x].data.end(); ++it)
			cout << *it << " ";
		cout << endl;
	}
	else {											//in case N <size print until place N
		list<string>::iterator it = items[x].data.begin();
		while (i < n)
		{
			cout << *it << " ";
			it++;
			i++;
		}
		cout << endl;
	}
}

//prints subjects
void HSubject::printS(string key) {
	int x = HashTable::search(key);			//find the subject to print
	if (x == -1)							//in case key not found
		throw "ERROR";
	else {									//print subjects
		for (list<string>::iterator it = items[x].data.begin(); it != items[x].data.end(); ++it)
			cout << *it << " ";
	}
	cout << endl;
}

//print all subjects and titles
void HSubject::printAll() {
	if (items.empty())				//in case the table is empty
		throw "ERORR";

	for (int i = 0; i < items.size(); i++)		//loop for printing 
	{
		if (items[i].flag != empty1 && items[i].flag != deleted) {	//if the key is not empty and also not deleted, then print
			cout << items[i].key << ":";			//print the title
			for (list<string>::iterator it = items[i].data.begin(); it != items[i].data.end(); ++it)	//loop for printing the subjects
				cout << *it << " ";			//print the subject
			cout << endl;
		}
	}
}



