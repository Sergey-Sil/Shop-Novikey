#pragma once
#include"formproduct.h"
#include"car.h"

class FormCar: public FormProduct
{
private:
    QLabel* idText;
    QLineEdit* id;

public:
    FormCar();
    FormCar(QString nameString, QString priceString, QString countString, QString idString);
    ~FormCar();
    void setProduct(Product t);
    void setProduct(QStringList lst);
    Product getProduct();
    bool checkInputProduct();

};
