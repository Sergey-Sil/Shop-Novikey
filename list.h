#pragma once
#include<iostream>
template <class T>
class List
{
private:
    T current;
    List<T>* next;
public:
    List()
    {
        this->next = nullptr;
    }

    List(T newObject)
    {
        this->current = T(newObject);
        this->next = nullptr;
    }

    List(const List& object)
    {
        this->current = object.current;
        if(object.next == nullptr)
        {
            this->next = nullptr;
        } else this->next = List(object.next);
    }

    void operator=(const List& object)
    {
        this->current = object.current;
        if(object.next)
        {
            this->next = object.next;
        } else this->next = nullptr;
    }

    T& getCurrent()
    {
        return current;
    }

    List<T>* getNext()
    {
        return this->next;
    }

    void setNext(T newObject)
    {
        this->next = new List<T>(newObject);
    }

    void setNext(List<T>* pointer)
    {
        this->next = pointer;
    }

    ~List()
    {
        List<T>* t = this->next;
        if(this->next != nullptr)
        {
            delete t;
        }
    }
};

