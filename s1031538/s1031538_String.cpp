#include<iostream>
#include<string>
#include"s1031538_String.h"

String::String()// Constructs an empty string, with a length of zero characters. ***default capacity = 10
{
	string s = string();
}
void String::resize(size_t n, char c)
{
	string s;
	s.resize(c);
}
String& String::erase(size_t subpos, size_t sublen)
{
	string s;
	s.erase(subpos,sublen);
}
size_t String::find(const String &str, size_t pos = 0) const
{
	string s;
	s.find(str);
}
size_t String::find_first_of(const String str, size_t pos = 0) const
{
	string s;
	s.find_first_of(str, pos);
}

bool String::operator==(const String &str)//< (equal to) true: two identical String
{
	string s;
	int compare(const string& str);
	s.compare(str);
	return true;
}
bool String::operator!=(const String &str) //< (not equal to)
{
	string s;
	int compare(const string& str);
	s.compare(str);
	return false;
}
String& String::insert(size_t pos, const String &str)
{
	string s;
	s.insert(pos, str);
}


String& String::insert(size_t pos, const String &str, size_t subpos, size_t sublen)
{
	string s;
	s.insert(pos, str, subpos, sublen);
}