#pragma once
#include"list.h"
using namespace std;
template <class T>
class Collection
{
private:
    int count;
    List<T>* current;
public:
    Collection()
    {
        this->count = 0;
        this->current = nullptr;
    }
    Collection (const Collection &object)
    {
        this->count = object.count;
        this->current = new List<T>(object.current);
    }
    ~Collection(){
        delete current;
    }

    void operator=(const Collection& object)
    {
        this->count = object.count;
        this->current = new List<T>(object.current);
    }

    void push(T element)
    {
        try{
           if(this->current == nullptr)
           {
               this->current = new List<T>(element);
           }else{
               List<T>* temp = this->current;
               while(temp->getNext() != nullptr)
               {
                   temp = temp->getNext();
               }
               temp->setNext(element);
           }
            this->count++;
        }
        catch(bad_alloc)
        {
            return;
        }
    }

    int search(T findT)
    {
        int i = 0;
        List<T>* temp = this->current;
        if(this->count == 0) return -1;
        while(temp != nullptr){
            if(findT->compare(temp->getCurrent()))
            {
                return i;
            }
            i++;
           temp = temp->getNext();
        }
        return -1;
    }

    void deleteData(T element)
    {
        List<T>* temp = this->current;
        if(temp->getCurrent()->compare(element))
        {
            this->current = this->current->getNext();
            this->count--;
            T nPtr = nullptr;
            temp->setNext(nPtr);
            delete temp;
            return;
        }
        while(temp != nullptr)
        {
            if(temp->getNext()->getCurrent()->compare(element))
            {
                List<T>* deleteT = temp->getNext();
                T nPtr = nullptr;
                temp->setNext(temp->getNext()->getNext());
                deleteT->setNext(nPtr);
                delete deleteT;
                break;
            }
            temp = temp->getNext();
        }
        this->count--;
    }

    void setData(int i, T find)
    {
        if(i>this->count) return;
        int number = 0;
        List<T>* temp = this->current;
        while(number != i){
            temp = temp->getNext();
            number++;
        }
        temp->getCurrent() = find;
    }

    T& operator[] (int i)
    {
        int n = 0;
        List<T>* temp = this->current;
        while(n!=i)
        {
            temp = temp->getNext();
            n++;
        }
        return temp->getCurrent();
    }

    T& get(int i)
    {
        int n = 0;
        List<T>* temp = this->current;
        while(n!=i)
        {
            temp = temp->getNext();
            n++;
        }
        return temp->getCurrent();
    }

    int getCount()
    {
        if(!this) return 0;
        return this->count;
    }
};

