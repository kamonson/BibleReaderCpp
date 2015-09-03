#include <iostream>
#include "Books.h"
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

Select_Book::Select_Book(){};
Bible::Bible(){};
void Bible::Bible_Select()
{ //Master Class-choose between saved data, Bibles, book
	system ("CLS");//for looking good
	int user_selection;
	v_verse.clear();//for each loop clear the stored data to reuse
	v_chapter.clear();//for each loop clear the stored data to reuse
	v_book.clear();//for each loop clear the stored data to reuse
	int s_born;
	cout << "Would you like to read from the Bible or Stored notes?\n" << endl ;//for 
	cout << "1)Bible\n" << endl ;
	cout << "2)Stored Notes\n" << endl ;
	cout << "3)Books of the Bible List\n" << endl;
	cout << "0)Exit Program\n" << endl ;
	cin >> s_born;
	cin.clear ( ) ; //ignore junk input
	cin.ignore ( INT_MAX, '\n' ) ;//ignore junk
	system ( "cls" ) ;

	switch (s_born)//switch menue for selection
	{
	case 1: //select how you want to read the bible
		{ 
			cout << "Would you like to search by:?\n" << endl;
			cout << "1)Book\n" << endl;
			cout << "2)Chapter\n" << endl;
			cout << "3)Verse\n" << endl;
			cin >> user_selection; //if statements selection instead of an additional switch menu
			if (user_selection == 1)
			{
							cin.clear ( ) ; //ignore junk input
			cin.ignore ( INT_MAX, '\n' ) ;//ignore junk
				system ("CLS");//for looking good
				cout << "Which book would you like to read?\n";
				cin >> s_book;
				Pcon();//run CHAPTER/PSALM search to create chapters in the vector
				read_book(); //read entire book function
				break;
			}
			if (user_selection == 2)//select chapters to read
			{
				cin.clear ( ) ; //ignore junk input
			cin.ignore ( INT_MAX, '\n' ) ;//ignore junk
				system ("CLS");//for looking good
				cout << "Which book would you like to read?\n";
				cin >> s_book;					
				Pcon();//run CHAPTER/PSALM search to create chapters in the vector
				cout << "Which chapter would you like to start with?\n";
				cin >> i_chapter_b;
				cout << "Which chapter would you like to end with?\n";
				cin >> i_chapter_e;
				read_chapter(); //read chapter function
				break;
			}
			if (user_selection == 3)//select chapter and verses to read
			{
							cin.clear ( ) ; //ignore junk input
			cin.ignore ( INT_MAX, '\n' ) ;//ignore junk
				system ("CLS");//for looking good
				cout << "Which book would you like to read?\n";
				cin >> s_book;
				Pcon();//run CHAPTER/PSALM search to create chapters in the vector
				cout << "Which Chapter would you like to read?\n";
				cin >> i_chapter;
				cout << "Which verse would you like to start at?\n";
				cin >> i_verse_b;
				cout << "Which verse would you like to end at?\n";
				cin >> i_verse_e;
				read_verses(); //read verse function
				break;
			}
			else 
			{			
				cin.clear ( ) ; //ignore junk input
			cin.ignore ( INT_MAX, '\n' ) ;//ignore junk
				system ("CLS");//for looking good
				cout << "Pelase make a valid selection\n";
				Bible_Select(); //wrong selection takes you to the begining
			}
			return;	
			break;
		}

	case 2: {
			
			Stored s1;
			s1.open();
		return;
		break;
			}
		break;
	case 0: return;
		break;
	default: 
		cout << "Please make a valid selection " ;
		Bible_Select();
		break;
	}
};

void Bible::Pcon()//changes if searches are for CHAPTER of VERSE depending on book
{	
	if (s_book == ("Psalms"))
	{c_or_p = "PSALM ";}
	else {c_or_p = "CHAPTER ";}
};

void Bible::read_book()//read out entire book
{
				cin.clear ( ) ; //ignore junk input
			cin.ignore ( INT_MAX, '\n' ) ;//ignore junk
	system ("CLS"); //formating, cosmetic only
	fstream file( "AV1611Text\\"+s_book+".txt", ios::in);  //open book
	if (file.fail())
	{
		cout << "Failed to open " << s_book << endl;
		Bible_Select();
	}

	//something here to read out from chapter to chapter assign a variable, then push back into vector

	while (!file.eof())   //go till there's no more.
	{
		string verses;
		while (getline (file, verses))  //get the whole verse line from the file
		{
			v_book.push_back (verses);
			cout << verses <<endl;  //cout the verse, end the line, restart the loop
		}
	}
	cout << endl << "That is the end of the book\n\nWould you like to go back to the menu (m) or exit (e)?\n"; //basic menu select
	char selection;
	cin >> selection;
	if (selection == 'm') //main menu
	{
		Bible_Select();
	}
	else
	{

	}
	file.close(); //close for space
};

void Bible::read_chapter()//need to close book still
{
	system ("CLS"); //formating only
	string format_space = "\n"; //add to vector store for proper format
	string verses; //string to hold the entire collection of verses
	string chapter;//sring to hold the chapter
	fstream file( "AV1611Text\\"+s_book+".txt", ios::in);//open book
	if (file.fail())//if book does not open
	{
		cout << "Failed to open " << s_book << ".txt"<< endl; //if broke recycle
		Bible_Select();
	}
	while (!file.eof())//search to end of file
	{
		while (getline(file, chapter))//add lines from book to chapter
		{
			if (chapter.find (c_or_p) != string::npos)//check to see if file contains CHAPTER of PSALM
			{		
				v_chapter.push_back (verses);//When CHAPTER/PSALM found add string to chapter vector
				verses.clear();//Empty verses string for next element of vector
				break;
			}
			verses += (chapter + format_space);//Add line from book and a new line to verses to be stored in chapter vector when CHAPTER/PSALM found
		}
	}
	for (int i = i_chapter_b; i < i_chapter_e + 1; i++) //cout put the begining and end points for chapter
	{
		cout << v_chapter[i] << endl;

	}
	cout << endl << "Would you like to go back to the menu (m), save to notes (s) or exit (e)?\n";  //menu to save or restart
	char selection;
	cin >> selection;
	if (selection == 'm') //menu
	{
		Bible_Select();
	}
	if (selection =='s') //save
	{
		cout << "Please assign a name for this file\n";
		cin >> schapters;
		fstream bfile(schapters + ".txt", ios::app);  //write to user named file
		if (bfile.fail())
		{
			cout << "Error saving " << schapters << endl;  //if broke return to main
			Bible_Select();
		}
		for (int i = i_chapter_b; i < i_chapter_e + 1; i++) //cout put the begining and end points for chapter
		{
			bfile << v_chapter[i] << endl;

		}
		bfile.close();
		cout << schapters << " saved to notes" << endl;
	}
	else
	{

	}
	file.close(); //close to save space
};

void Bible::read_verses()//need to close book still
{
	system ("CLS");
	string format_space = "\n"; //add to vector store for proper format
	string verses; //string to hold the entire collection of verses
	string chapter;//sring to hold the chapter
	fstream file( "AV1611Text\\"+s_book+".txt", ios::in);//open book
	if (file.fail())//if book does not open
	{
		cout << "Failed to open " << s_book << ".txt"<< endl; //start over if wrong selection
		Bible_Select();
	}

	while (!file.eof())//search to end of file
	{
		while (getline(file, chapter))//add lines from book to chapter
		{
			if (chapter.find (c_or_p) != string::npos)//check to see if file contains CHAPTER of PSALM
			{		
				v_chapter.push_back (verses);//When CHAPTER/PSALM found add string to chapter vector
				verses.clear();//Empty verses string for next element of vector
				break;
			}
			verses += (chapter + format_space);//Add line from book and a new line to verses to be stored in chapter vector when CHAPTER/PSALM found
		}
	}
	system("CLS");//clear screen
	s_chapter = v_chapter [i_chapter]; //set s_chapter to be the user selected chapter from chapter vector
	stringstream vfile (s_chapter , ios::in); //like fstream but for strings
	while (getline(vfile, s_verse)) //get lines from string and output as s_verse to be stored in vector
	{
		v_verse.push_back (s_verse); //store verses in vector
	}

	for (int k = i_verse_b -=1; k < i_verse_e; k++){
		cout << v_verse [k] << endl;//Output the verse (-1 to start in the correct location) from vector that the user searched for within the chapter
	}
	cout << endl << "Would you like to go back to the menu (m), save to notes (s) or exit (e)?\n";
	char selection;
	cin >> selection;
	if (selection == 'm') //main menu
	{
		Bible_Select();
	}
	if (selection =='s') //save selection to notes
	{

		cout << "Please assign a name for this file\n";
		cin >> sverses;
		fstream bfile(sverses + ".txt", ios::app);  //write to user named file without overwritng
		if (bfile.fail())
		{
			cout << "Error saving " << sverses << endl;
			Bible_Select();
		}

		for (int k =i_verse_b; k < i_verse_e; k++){
			bfile << endl << v_verse [k] << endl;//save the verse (-1 to start in the correct location) from vector that the user searched for within the chapter to user named file
		}
		cout << sverses << " saved to notes" << endl;
		bfile.close();
	}
	else
	{

	}
	file.close(); //restart
};