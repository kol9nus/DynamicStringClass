#pragma once
class MyString
{
public:
	/// ctors/dtor
				MyString() : MyString( "", 0 )																			{};
	explicit	MyString( const char str[] ) : MyString( str, mystrlen_iteration( str ) )								{};
				MyString( const char str[], size_t length ) : length( length ), str( createStringFrom( str, length ) )	{};

				MyString( const MyString & other ) : MyString( other.str, other.length )								{};
				~MyString()																								{	delete[] str;	};

	/// operators
	friend		std::ostream&	operator <<( std::ostream& os, const MyString& m );
	friend		std::istream&	operator >>( std::istream& is, MyString& m );
	friend		MyString		operator +( const MyString& first, const MyString& second );
				MyString&		operator=( const MyString& other );
				char&			operator[]( size_t i ) const									{	return str[i];	};

	/// 
	static		size_t		mystrlen_iteration( const char* str );
	static		char*		createStringFrom( const char* str, size_t length );
				size_t		GetLength() const										{	return this->length;	};
	static		bool		compare( const MyString &first, const MyString &second );


private:
	void		append( const MyString &appendix )			{	append( appendix.str, appendix.length );	};
	void		append( const char* str, size_t length );

	size_t		length;
	char*		str;

};

