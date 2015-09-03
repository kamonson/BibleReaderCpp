#include <iostream>

using namespace std;
#include <string>
#include <fstream>
#include <vector>

#include "Bible.h"
#include "Books.h"
#include "Chapter.h"
#include "Store.h"

int main ()
{
	char again = 'y'; //defalt yes 
	Bible c1;
	while (again == 'y') //loop untill user quits
	{
		c1.Bible_Select();
					cin.clear ( ) ; //ignore junk input
			cin.ignore ( INT_MAX, '\n' ) ;//ignore junk
		cout << "Would you like to return to the main menu?\n";
		cout << "yes (y), no (n);\n";
		cin >> again;
	}
	return 42;
}