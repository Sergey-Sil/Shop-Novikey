#include<locale.h>
#include<cstring>
#include "mystring.h"


MyString::MyString()
{
    this->n = 0;
}

MyString::MyString(const MyString &s)
{
    this->n = s.n;
    str = new char[n + 1];
    for (int i = 0; i < n; i++)
    {
        str[i] = s.str[i];
    }
    str[n] = '\0';
}


MyString::MyString(char* s)
{
    this->n = strlen(s);
    str = new char[this->n + 1];
    for (int i = 0; i < n; i++)
    {
        str[i] = s[i];
    }
    str[n] = '\0';
}

MyString::~MyString()
{
    if(this->str)
        delete[] str;
}

MyString MyString::operator+(MyString s)
{
    int count = n + s.n + 1;
    char* arr = new char[count];
    for (int i = 0; i < n; i++)
    {
        arr[i] = str[i];
    }
    for (int j = 0; j < s.n; j++)
    {
        arr[n + j] = s.str[j];
    }
    arr[count - 1] = '\0';
    return MyString(arr);
}

void MyString::operator=(MyString s)
{
    if (this == &s)
    {
        return;
    }
    n = s.n;

    str = new char[n + 1];
    for (int i = 0; i < n; i++)
        str[i] = s.str[i];
    str[n] = '\0';
}

bool MyString::operator==(MyString s)
{
    return strcmp(str, s.str) == 0 ? true : false;
}

char MyString::operator[](int k)
{
    return str[k];
}

MyString MyString::operator()(int l, int r)
{
    int count = r - l + 1;
    char* s = new char[count];
    for (int i = 0; i < count - 1; i++)
    {
        s[i] = str[l + i];
    }
    s[count - 1] = '\0';
    return MyString(s);
}

MyString MyString::operator()(int l)
{
    int r = n;
    int count = r - l + 1;
    char* s = new char[count];
    for (int i = 0; i < count - 1; i++)
    {
        s[i] = str[l + i];
    }
    s[count - 1] = '\0';
    return MyString(s);
}

char* MyString::operator()()
{
    return str;
}

int MyString::getCount()
{
    return this->n;
}
