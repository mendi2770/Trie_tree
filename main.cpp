/*
Mendi Ben-Ezra 
Course Name: Data Structures 2
Exercise 2
Description: Program that use hash table for subjects and titles
*/

#include<list>
#include<iostream>
#include<vector>
#include"HSubject.h"
using namespace std;
int main()
{
	char ch;
	int n;
	HSubject hs(1000);			//starts hash table with 1000 places
	string subject, title;

	cout << "Hash Table\n";
	cout << "\nChoose one of the following" << endl;
	cout << "n: New hash table" << endl;
	cout << "a: Add a subject and a title" << endl;
	cout << "d: Del a subject " << endl;
	cout << "t: print all titles of the subject " << endl;
	cout << "s: print N first appearances of a subect " << endl;
	cout << "p: print all non-empty entries " << endl;
	cout << "e: Exit" << endl;
	do
	{
		cin >> ch;
		switch (ch)
		{
		case 'n':hs.startNewTable();  //starts hash
			break;
		case 'a':cout << "Enter a subject and a title\n";

			cin >> subject >> title;
			try {
				hs.addSubjectAndTitle(title, subject);		//add subject and title
			}
			catch (const char* massage) {
				cout << massage << endl;
			}
			break;
		case 'd':cout << "Enter a subject to remove\n";
			cin >> subject;
			try {
				hs.remove(subject);				//remov a sybject fro the hash
			}
			catch (const char* massage) {
				cout << massage << endl;
			}
			break;
		case 't':cout << "enter subject to print\n";
			cin >> subject;
			try {
				hs.printS(subject);			//ptint spesific subject
			}
			catch (const char* massage) {
				cout << massage << endl;
			}
			break;
		case 's':cout << "enter a subject and N\n"; cin >> subject >> n;
			try {
				hs.printN(subject, n);		//print titlse of subject from a specific place
			}
			catch (const char *massage) {
				cout << massage << endl;
			}
			break;
			
		case 'p':
			try{
			hs.printAll();			//print subject and titles in the hash table
			}
			catch (const char* massage) {
				cout << massage << endl;
			}
			break;
		case 'e':cout << "bye\n";
			break;
		
		default: cout << "ERROR\n";  break;
		}
	} while (ch != 'e');
	return 0;
}

/*
Example of the program:

Hash Table

Choose one of the following
n: New hash table
a: Add a subject and a title
d: Del a subject
t: print all titles of the subject
s: print N first appearances of a subect
p: print all non-empty entries
e: Exit
n
a
Enter a subject and a title
title1 sub1
a
Enter a subject and a title
title1 sub2
a
Enter a subject and a title
title1 sub3
a
Enter a subject and a title
title2 tit1
a
Enter a subject and a title
title2 tit2
a
Enter a subject and a title
title3 sub4
t
enter subject to print
title1
sub3 sub2 sub1
s
enter a subject and N
title1 1
sub3
p
title1:sub3 sub2 sub1
title2:tit2 tit1
title3:sub4
d
Enter a subject to remove
title2
p
title1:sub3 sub2 sub1
title3:sub4
e
bye
*/