#ifndef BOOKS_H_
#define BOOKS_H_
#include <string>
#include <vector>
using namespace std;


class Select_Book { //Master Class-choose between saved data, Bibles, books
public:
	string schapters;//stored chapters
	string sverses; //stored verses
	string snotes; //future option
	string sbooks;//stored to books
	vector<string> v_chapter; //store chapters
	vector<string> v_verse; //store verses
	vector<string> v_book; //store books
	string s_book; //store book as string
	string s_verse; //store verses as a string
	string s_chapter; //store chapter as string
	int i_chapter; //number for chapter
	int i_chapter_b; //chapter start
	int i_chapter_e; //last chapter
	int i_verse_b; //first verse
	int i_verse_e; //last verse
	string s_notes;	//for notes
	string new_testament; //future option prob not use
	string old_testament; //future prob not use
	Select_Book();
};

class Bible:public Select_Book {
public:
	Bible();
	string c_or_p; //variable for CHAPTER or PSALM in Pcon function
	void Bible_Select(); //Menu
	void save_chapter(); //text io
	void save_verse(); //text io	
	void read_book();	//read book
	void read_chapter(); //read chapter
	void read_verses(); //vector and/or search function
	void Pcon(); //convert to CHAPTER or PSALM for searching
};

class Stored: public Select_Book { //Saved verses/notes
public:
	string schapters;//stored chapters
	string sverses; //stored verses
	string snotes; //future option
	string sbooks;//stored to books
	void open (); //text io
	Stored();
};
#endif