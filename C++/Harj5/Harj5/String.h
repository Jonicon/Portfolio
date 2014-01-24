#pragma once
#include <iostream>

class String
{
public:
	String();
	String(const char* s);
	String(const String &s);
	~String(void);

	String operator+(const String &s) const;
	const String& operator=(const String &s);
	friend std::ostream& operator<<(std::ostream& o, const String &s);
	String &operator++();
	String operator++(int);
	char &operator[](int i);
	operator const char*() const;

	void list();

private:
	char *c_string;
};

