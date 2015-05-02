#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include"s1031434_string.h"
using namespace std;

typedef unsigned int size_t;

String::String(){
	str.push_back(' ');
}

String::String(const String& str){
	this->str=str.str;
}

String::String(const String& str, size_t pos, size_t len){
	vector<char>temp;
	for (int i = pos; i <= len; i++)
		temp.push_back(str.str[i]);
	this->str = temp;
}

String::String(const char *s){
	int length = strlen(s);
	for (int i = 0; i < length; i++)
		this->str.push_back(s[i]);
}

String::~String(){
}
String& String::erase(size_t subpos, size_t sublen){
	char s1[100];
	for (int i = 0; i <this->str.size(); i++)
		s1[i] = this->str[i];
	string str1(s1);
	str1.erase(subpos,sublen);
	this->str.clear();
	for (int i = 0; i < str1.length(); i++)
		this->str.push_back(str1[i]);

	return *this;

}

ostream& operator<<(ostream& output, const String& str){
	int length = str.str.size();
	for (int i = 0; i < length; i++)
		output << str.str[i];
	return output;
}

char& String::begin(){ // pointer
	return str[0];
}

char& String::end(){
	int length = str.size();
	return str[length-1];
}

size_t String::getSize()const{
	return str.size();
}

/*reserve shrink_to_fit */
void String::resize(size_t n){
	int length = this->str.size();
	if (length > n)
		for (int i = 0; i < length - n; i++)
			this->str.pop_back();
	else
		for (int i = 0; i < n - length; i++)
			this->str.push_back('\0');
}


size_t String::getCapacity()const{
	return this->str.size();
}

void String::resize(size_t n, char c){
	if (n>str.size())
		for (int i = 0; i < n - str.size(); i++)
			this->str.push_back(c);
}

void String::reserve(size_t n){

}

void String::shrink_to_fit(){

}

char& String::operator[] (size_t pos){
	return this->str[pos-1];
}

const char& String::operator[] (size_t pos) const{
	return this->str[pos - 1];
}


void String::clear(){
	str.clear();
}

bool String::empty()const{
	return str.size() == 0;
}

char& String::front(){
	return str.front();
}

char& String::back(){
	return str.back();
}

void String::push_back(char c){
	str.push_back(c);
}

void String::pop_back(){
	str.pop_back();
}

String& String::append(const String& str){
	int length = str.str.size();
	for (int i = 0; i < length; i++)
		this->str.push_back(str[i]);
	return *this;
}

String& String::substr(size_t pos, size_t len)const{
	char s1[100];
	for (int i = 0; i <this->str.size(); i++)
		s1[i] = this->str[i];
	string str1(s1);
	str1.erase(pos,len);
	String test;
	for (int i = 0; i < str1.length(); i++)
		test.str.push_back(str1[i]);
	return test;
}





String& String::insert(size_t pos, const String &right){
	char s1[100];
	for (int i = 0; i <this->str.size(); i++)
		s1[i] = this->str[i];
	char s2[100];
	for (int i = 0; i < right.str.size(); i++)
		s2[i] = right.str[i];
	string str1(s1);
	string str2(s2);
	str1.insert(pos, s2);
	this->str.clear();
	for (int i = 0; i < str1.length(); i++)
		this->str.push_back(str1[i]);

	return *this;
}
String& String::insert(size_t pos, const String &right, size_t subpos, size_t sublen){
	char s1[100];
	for (int i = 0; i <this->str.size(); i++)
		s1[i] = this->str[i];
	char s2[100];
	for (int i = 0; i < right.str.size(); i++)
		s2[i] = right.str[i];
	string str1(s1);
	string str2(s2);
	str1.insert(pos, s2,subpos,sublen);
	this->str.clear();
	for (int i = 0; i < str1.length(); i++)
		this->str.push_back(str1[i]);

	return *this;

}
String String::operator+ (const char* rhs){
	char s1[100];
	for (int i = 0; i <this->str.size(); i++)
		s1[i] = this->str[i];
	strcat_s(s1, rhs);
	this->str.clear();
	for (int i = 0; i < strlen(s1); i++)
		this->str[i] = s1[i];

	return *this;
}


String String::operator+(const String& rhs){
	int length = rhs.str.size();
	for (int i = 0; i < length; i++)
		this->str.push_back(rhs[i]);
	return *this;
}

String& String::operator= (const String& right){
	this->str.clear();
	int length = right.str.size();
	for (int i = 0; i < length; i++)
		this->str.push_back(right.str[i]);
	return *this;
}
String& String::operator= (const char* s){
	this->str.clear();
	int len = strlen(s);
	for (int i = 0; i < len; i++)
		this->str.push_back(s[i]);
	return *this;
}

bool String::operator==(const String &right){
	int r_size = right.str.size();
	int t_size = this->str.size();
	if (r_size != t_size) return false;
	for (int i = 0; i < r_size;i++)
		if (this->str[i] != right.str[i])
			return false;

	return true;
}


bool String::operator!=(const String &str){
	return !(*this == str);
}

size_t String::find(const String &right, size_t pos) const{
	char s1[100];
	for (int i = 0; i <this->str.size(); i++)
		s1[i] = this->str[i];
	char s2[100];
	for (int i = 0; i < right.str.size(); i++)
		s2[i] = right.str[i];
	string str1(s1);
	string str2(s2);
	int search = str1.find(str2);

	return search;
}


size_t String::find_first_of(const String right, size_t pos) const{
	char s1[100];
	for (int i = 0; i <this->str.size(); i++)
		s1[i] = this->str[i];
	char s2[100];
	for (int i = 0; i < right.str.size(); i++)
		s2[i] = right.str[i];
	string str1(s1);
	string str2(s2);
	int search = str1.find(str2);
	return search;
}





