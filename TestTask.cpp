// TestTask.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

using namespace std;

int getNumberOfStrings()
{
	cout << "Enter number of strings: ";
	int numberOfStrings;
	cin >> numberOfStrings;
	return numberOfStrings;
}

vector< MyString > getStrings( int numberOfStrings )
{
	cout << "Enter strings: " << endl;
	vector< MyString > strings;
	for ( int i = 0; i < numberOfStrings; i++ )
	{
		MyString string;
		cin >> string;
		strings.push_back( string );
	}
	return strings;
}

void printStrings(vector< MyString > strings)
{
	for ( int i = 0; i < strings.size(); i++ )
	{
		cout << strings[ i ] << endl;
	}
}

int main()
{
	int numberOfStrings = getNumberOfStrings();
	vector< MyString > strings = getStrings( numberOfStrings );
	sort( strings.begin(), strings.end(), MyString::compare );
	printStrings( strings );

	system( "pause" );
    return 0;
}