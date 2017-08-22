#pragma once
#include"formproduct.h"
#include"car.h"

class FormKey: public FormProduct
{
private:
    QLabel* typeText;
    QComboBox* type;

public:
    FormKey();
    FormKey(QString nameString, QString priceString, QString countString, QString typeString);
    ~FormKey();
    void setProduct(Product t);
    void setProduct(QStringList lst);
    Product getProduct();
    void setType();
};

