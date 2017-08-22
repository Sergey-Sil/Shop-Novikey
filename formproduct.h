#pragma once
#include<QtWidgets>
#include"product.h"
#include<QStringList>
class FormProduct:public QWidget
{
protected:
    QGridLayout* layout;
    QLabel* name;
    QLabel* count;
    QLabel* price;

    QLineEdit* nameText;
    QLineEdit* countText;
    QLineEdit* priceText;
public:
    FormProduct();
    FormProduct(QString nameString, QString priceString, QString countString);

    ~FormProduct();
    virtual void setProduct(Product t);
    virtual void setProduct(QStringList lst);
    virtual Product getProduct();
    virtual bool checkInputProduct();

};
