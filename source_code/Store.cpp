#include <iostream>
#include "Books.h"
#include <string>
#include <fstream>
#include <sstream>

Stored::Stored()
{ //Saved verses/notes
};

void Stored::open(){
	system("CLS");//to look good
	cout << "Which note would you like to open?\n"; //
	string note;
	cin >> note;
	fstream onote( note + ".txt", ios::in);
	if (onote.fail())
	{
		cout << "Failed to open " << s_book << endl;  //retry 
		open();
	}
	while (!onote.eof())   //go till there's no more.
	{
		string line;
		while (getline (onote, line))  //get the whole line from the file
		{
			cout << line << endl; //cout the line, restart the loop until end
		}
	}
	onote.close();
	cout << endl << "Would you like to append this note? (a), view another (v), return to main (m) or exit (e);" << endl;
	char choice;
	char again = 'y';  //defalt is y to prevent loop unless selected
	cin >> choice;
	if (choice == 'a')
	{
		cin.clear ( ) ; //ignore junk input
		cin.ignore ( INT_MAX, '\n' ) ;//ignore junk
		while (again == 'y')  //user must enter y to enter new line
		{
			cout << "Type what you would like added to the note, press enter to continue" << endl;
			fstream onote( note + ".txt", ios::app);  //open note for appending
			if (onote.fail())
			{
				cout << "Failed to open " << s_book << endl;  //retry not likely in this case but is one of the steps
				open();
			}
			string line;
			getline (cin, line);  //allow user to free text line by line will loop if user enters y
			onote << endl << line;  //add to note with a new line prior
			cout << endl << "Would you like to add another line to this note?\n";
			cin >> again;
			cin.clear ( ) ; //ignore junk input
			cin.ignore ( INT_MAX, '\n' ) ;//ignore junk
		}
	}
	if (choice == 'v')
	{
		open();
				cin.clear ( ) ; //ignore junk input
			cin.ignore ( INT_MAX, '\n' ) ;//ignore junk
	}
	if (choice == 'm')
	{
		Bible b2;
		b2.Bible_Select();
				cin.clear ( ) ; //ignore junk input
			cin.ignore ( INT_MAX, '\n' ) ;//ignore junk
	}
	else 
	{

	}
};