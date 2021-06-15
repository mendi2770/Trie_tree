/*
Mendi Ben-Ezra
Course Name: Data Structures 2
Exercise 2
Description: Program that use hash table for subjects and titles
*/

#pragma once
#include<string>
#include<iostream>
#include<vector>
using namespace std;

//function to find the next prime number from the size of the table
static int primeNumber(int num) {
	num++;
	for (int i = 2; i < num; i++) {
		if (num % i == 0) {
			num++;
			i = 2;
		}
		else {
			continue;
		}
	}
	return num;
}   

//function to convet the key string to number 
static int convertStringToNumbers(string letter)
{
	int num = 0;
	for (int i = 0; i < letter.length(); i++)
	{
		char x = letter.at(i);
		num += int(x);
	}
	return num;
}

template <class T, class K>
class HashTable {
protected:
	enum state { empty1, full, deleted };  //status of spesic place inr the table
	class Item			//present an item for each value in the hash table
	{
	public:
		T data;
		K key;
		state flag;
		Item() { flag = empty1; }
		Item(T d, K k, state f) { data = d; key = k; flag = f; }
	};
	int capacity;								//size of the hash table
	vector<Item> items;							//create vector of "Item" for hash table
public:
	HashTable(int capacity1) {					//ctor 
		int i = 0;	
		capacity = primeNumber(capacity1);		//update the size to the prime number
		while (i < capacity)					//create empty hash table
		{
			Item temp;
			items.push_back(temp);
			i++;
		}
	}


	~HashTable() { items.clear(); }			//dtor

	int virtual h1(K k) = 0;		//virtual mixing function H1
	int virtual  h2(K k) = 0;		//virtual mixing function H2
	int hash(K k, int i) { return (h1(k) + i * h2(k)) % this->items.size(); }  //double hashing
	int search(K k);				//search element
	void insert(T t, K k);			//insert element
	void remove(K k);				//remove element	
	void update(T t, K k);			//update element
	void print();					//print all elements
};

template <class T, class K>
int HashTable<T, K>::search(K k) {			//search key in the table
	int i = 0;
	int x = hash(k, i);						//get the first key
	while (i != items.size()) {				//loop for searching the key
		if (items[x].flag == empty1)		//in case the key is empty
			return -1;
		x = hash(k, i);						//get the next key
		if (items[x].key == k)
			return x;						//in case the key eas found
		i++;
	}
	return -1;
};

template <class T, class K>
void HashTable<T, K>::insert(T t, K k) {			//insert value to the table
	int i = 0;
	int x;
	while (i != this->items.size())					//loop for find an empty place
	{
		x = hash(k, i);
		if (items[x].flag == empty1) {				//update the new key and value
			items[x].key = k;
			items[x].flag = full;
			items[x].data = t;
			return;
		}
		i++;
	}
	cout << "Error: over flow" << endl;			//in case the table is full
}

template <class T, class K>
void HashTable<T, K>::remove(K k) {				//remove element from the table
	int i = 0;
	int x = hash(k, i);
	while (i != items.size() && this->items[x].flag != empty1) {		//as long the key is not empty
		x = hash(k, i);
		if (items[x].key == k)						//in case the key was found
		{
			this->items[x].flag = deleted;			//put flag delete in the place that removed
			return;
		}
		i++;
	}
}

template <class T, class K>
void HashTable<T, K>::update(T t, K k) {		//update a value in the table
	int x = search(k);
	if (x == -1)
		throw "ERROR";
	items[x].data = t;						//update
}

template <class T, class K>
void HashTable<T, K>::print() {			//print the table
	int i = 0;
	while (i < items.size())		//loop as long the i small then the size
	{
		if (!(items[i].flag == deleted)) {			//if the element is not deleted print it
			cout << "Key: " << items[i].key << endl;
			cout << "Data: " << items[i].data << endl;
		}
		i++;
	}
}
