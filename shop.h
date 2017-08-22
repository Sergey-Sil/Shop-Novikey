#pragma once
#include"section.h"
#include<fstream>
#include<iostream>

#include<stack>
#include"sectioncar.h"
using namespace std;

struct Action{
    QString action;
    int numberSection;
    Product prod;
    Product oldProd;
};

class Shop
{
private:
    stack<Action> cancel;
    QString name;
    QList<Section*>* section;
public:
    Shop();
    Shop(QString n);
    Shop(const Shop &object)
    {
        this->name = object.name;
        this->section = object.section;
    }
    Shop operator=(const Shop &object)
    {
        this->name = object.name;
        this->section = object.section;
        return *this;
    }
    ~Shop()
    {
        delete section;
    }
    void addSection(QString nsect);
    void addProduct(Product pr, int sect);
    void deleteSection(int n);
    QList<Section*>* getSectionCollection();
    Section* getSection(int i);
    void addSection(QString newSection, Section* s);
    void loadShop();
    void saveShop();
    double getAllPrice();
    int getAllCount();
    void pushAction(QString action, Product pr, int n);
    void pushAction(QString action, Product pr, Product oldProduct, int n);
    int popAction();
};
