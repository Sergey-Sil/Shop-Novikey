#pragma once
#include"section.h"
#include"car.h"


class SectionKey:public Section
{

public:
    SectionKey();
    SectionKey(MyString n);
    SectionKey(const SectionKey& section);
    ~SectionKey();

    void addProduct(Product* pr);
    Product* getProduct(int i);
    int getCount();
    MyString getName();
    void deleteProduct(Product* pr);
    int search(Product* pr);
    void loadSection();
    Collection<Product*>* getProductCollection();
    void operator=(const SectionKey& section);
    bool operator==(const SectionKey& t);

    void saveSection();
    Car createProduct(char* str);
};

