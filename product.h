#pragma once

#include<QtWidgets>
class Product
{
private:
    QString name;
    double price;
    int count;
    QString type;
public:
    Product();
    Product(QString n, double p, int c, QString t = "");
    Product(QString n, QString p, QString c, QString t = "");
    Product(Product product, QString t);
    Product(const Product& object);
    ~Product(){}

    void operator =(const Product& object);
    QString getName();
    double getPrice();
    int getCount();
    QString getType();
    bool operator==(const Product& object);
    bool operator!=(const Product& object);

    void addCount(int k = 1);

    void setType(QString t);
    void setName(QString newName);
    void setPrice(double newPrice);
    void setCount(int newCount);
    QString productToString();
};
