#include"product.h"

Product::Product()
{
    name = QString("");
    price = 0;
    count = 0;
    type = QString("");
}

Product::Product(QString n, double p, int c, QString t)
    :name(n), price(p),count(c),type(t)
{}

Product::Product(QString n, QString p, QString c, QString t)
    :name(n), price(p.toDouble()), count(c.toInt()), type(t)
{}

Product::Product(Product product, QString t)
    :name(product.name), price(product.price),
      count(product.count), type(t)
{}

Product::Product(const Product &object)
{
    this->name = object.name;
    this->price = object.price;
    this->count = object.count;
    this->type = object.type;
}

void Product::operator =(const Product& object)
{
    this->name = object.name;
    this->price = object.price;
    this->count = object.count;
    this->type = object.type;
}

QString Product::getName()
{
    return name;
}

double Product::getPrice()
{
    return price;
}

int Product::getCount()
{
    return count;
}

QString Product::getType()
{
    return type;
}

bool Product::operator==(const Product &object)
{
    if(this->name == object.name && this->price == object.price
            && this->type == object.type)
        return true;
    return false;
}

bool Product::operator!=(const Product &object)
{
    if(this->name == object.name && this->price == object.price
            && this->type == object.type)
        return false;
    return true;
}

void Product::addCount(int k)
{
    this->count += k;
}

void Product::setName(QString newName)
{
    this->name = newName;
}

void Product::setPrice(double newPrice)
{
    this->price = newPrice;
}

void Product::setCount(int newCount)
{
    this->count = newCount;
}

void Product::setType(QString t)
{
    this->type = t;
}

QString Product::productToString()
{

    QString s = QString(";");
    QString product = name+ s + QString::number(price)+ s +
            QString::number(count) + s + type;
    return product;
}

