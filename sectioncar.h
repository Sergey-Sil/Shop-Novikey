#pragma once
#include"section.h"
#include"product.h"
class SectionCar:public Section
{
public:
    SectionCar();
    SectionCar(QString n);
    SectionCar(const SectionCar& section);
    ~SectionCar();

    void loadSection();

    void saveSection();
    Product createProduct(QString str);
    int getCountType(QString t);
    double getPriceType(QString t);
};

