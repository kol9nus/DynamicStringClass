#include "stdafx.h"

size_t MyString::mystrlen_iteration( const char* str )
{
	size_t counter = 0;
	for ( ; *str != 0; ++str) ++counter;
	return counter;
}

char* MyString::createStringFrom( const char* str, size_t length )
{
	char* result = new char[ length + 1 ];
	strncpy_s( result, length + 1, str, length );
	result[ length ] = '\0';
	return result;
}

void MyString::append( const char* str, size_t length )
{
	size_t resultLength = this->length + length;
	char* resultStr = new char[ resultLength + 1 ];

	strncpy_s( resultStr, resultLength + 1, this->str, this->length );
	delete[] this->str;
	strncpy_s( resultStr + this->length, resultLength + 1, str, length );
	resultStr[ resultLength ] = '\0';

	this->length = resultLength;
	this->str = resultStr;
}

std::ostream& operator<<( std::ostream& os, const MyString& m )
{
	return os << m.str;
}

std::istream& operator>>( std::istream& is, MyString& m )
{
	size_t buffer_size = 100;
	m.length = 0;
	char* buffer = new char[ buffer_size ];
	is.get();
	while ( is.get( buffer, buffer_size ) )
	{
		auto num_read = is.gcount();
		m.append( buffer, num_read < buffer_size ? num_read : buffer_size );
	}
	is.clear();
	return is;
}

/* Оператор присваивания */
MyString& MyString::operator=( const MyString& other )
{
	this->length = other.length;
	str = createStringFrom( other.str, other.length );
	return *this;
}

/* Внешний оператор сложения */
MyString operator+( const MyString& first, const MyString& second )
{
	MyString result = first;
	result.append( second );
	return result;
}

bool MyString::compare( const MyString& first, const MyString& second )
{
	int length = std::min( first.GetLength(), second.GetLength() );
	for ( int i = 0; i < length; i++ )
	{
		char firstSymb = first[ i ];
		char secondSymb = second[ i ];
		if ( isalpha( first[ i ] ) && isalpha( second[ i ] ) )
		{
			firstSymb = toupper( first[ i ] );
			secondSymb = toupper( second[ i ] );
		}
		if ( firstSymb < secondSymb )
		{
			return false;
		}
		if ( firstSymb > secondSymb )
		{
			return true;
		}
	}
	return first.GetLength() > second.GetLength();
}
