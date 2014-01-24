#include "String.h"
#include <iostream>

String::String()
{
	c_string = new char;
}

String::String(const char* s)
{
	c_string = new char[strlen(s) + 1];
	strcpy(c_string, s);
}

String::String(const String &s)
{
	c_string = new char[strlen(s.c_string) + 1];
	strcpy(c_string, s.c_string);
} 

String::~String(void)
{
	delete c_string;
	std::cout << "Destructor called!" << std::endl;
}

	

String String::operator+(const String &s) const
{
        String result;
        int a;
           
        a = strlen(c_string) + strlen(s.c_string);
           
        result.c_string = new char[a+1];
           
        strcpy(result.c_string, c_string);
        strcat(result.c_string, s.c_string);
		// std::cout << "Summa funktiossa: " << result;
           
        return result;
}
     
const String& String::operator=(const String &s)
{
        if(this != &s)
		{
			delete c_string;
			c_string = new char[strlen(s.c_string) + 1];
			strcpy(c_string, s.c_string);
		}
     
        return *this;
}



std::ostream& operator<<(std::ostream& o,const String &s)
{
	o << s.c_string;
	return o;
}

String &String::operator++()
{
	String addThis = "x";
	*this = *this + addThis;
	return *this;
}

String String::operator++(int)
{
	String old = *this;
	String addThis = "x";
	*this = *this + addThis;
	return old;
}

char &String::operator[](int i)
{
	return c_string[i];
}

String::operator const char*() const
{
	return c_string;
}

void String::list()
{
	std::cout << c_string << std::endl;
}
