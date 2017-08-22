#pragma once
#include<iostream>

class MyString
{
private:
    char* str;
    int n;
public:
    MyString();
    MyString(const MyString& s);
    MyString(char* s);
    ~MyString();
    MyString operator+(MyString s);
    void operator=(MyString s);
    bool operator==(MyString s);
    char operator[](int k);
    MyString operator()(int l, int r);
    MyString operator()(int l);
    char* operator()();
    int getCount();
};
