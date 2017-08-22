#pragma once
#include"product.h"
#include<fstream>

using namespace std;

class Section
{
protected:
    QString name;
    QList<Product> product;
public:
    Section();
    Section(QString n);
    Section(const Section& section);
    ~Section();

    virtual void addProduct(Product pr);
    virtual Product getProduct(int i);
    virtual int getCount();
    virtual QString getName();
    virtual void deleteProduct(Product pr);
    virtual int search(Product pr);
    virtual void loadSection();
    QList<Product>& getProductCollection();
    void operator=(const Section& section);
    bool operator==(const Section& t);
    virtual void saveSection();
    Product createProduct(QString str);
    virtual int getCountType(QString t);
    virtual double getPriceType(QString t);
};


