#include "section.h"
#include<cstring>

#include<QTextStream>
#include<QFile>

Section::Section()
{
    this->product = QList<Product>();
    this->name = QString("");
}

Section::Section(QString n)
{
    this->name = n;
    this->product = QList<Product>();
}

Section::Section(const Section& section)
{
    this->name = section.name;
    this->product = section.product;
}

void Section::operator=(const Section& section)
{
    this->name = section.name;
    this->product = section.product;
}

Section::~Section()
{

}

void Section::addProduct(Product pr)
{
    this->product.push_back(pr);
}

Product Section::getProduct(int i)
{
    return this->product.at(i);
}

int Section::getCount()
{
    return product.count();
}

QString Section::getName()
{
    return this->name;
}

void Section::deleteProduct(Product pr)
{
    this->product.removeOne(pr);
}

int Section::search(Product pr)
{
    return this->product.indexOf(pr);
}

QList<Product>& Section::getProductCollection()
{
    return this->product;
}

bool Section::operator==(const Section& t)
{
    if(this->name == t.name)
        return true;
    return false;
}

void Section::saveSection()
{
    QString nameSection = QString("./data/")+this->name + QString("/") + this->name + QString("collection.dat");
    QFile out(nameSection);
    if( out.open(QIODevice::WriteOnly ))
    {
        QTextStream f(&out);
        if(this->product.count() == 0)
        {
            out.close();
            return;
        }
        int i;
        for (i = 0; i < this->getCount()-1; i++)
        {
            f << this->getProduct(i).productToString()<< endl;
        }
        f << this->getProduct(i).productToString();
        out.close();
    }
}

void Section::loadSection()
{

    QString nameSection = QString("./data/")+this->name + QString("/") + this->name + QString("collection.dat");
    QFile file(nameSection);
    QTextStream out(&file);
    QString str;
    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        out >> str;
        while(!str.isEmpty())
        {
            Product temp(createProduct(str));
            this->addProduct(temp);
            out>>str;
        }
        file.close();
    }
}

Product Section::createProduct(QString str)
{
    QStringList lst = str.split(";");
    Product pr = Product(lst.at(0), lst.at(1), lst.at(2));
    return pr;
}

int Section::getCountType(QString t)
{
    int countPr = 0;
    for(int i = 0; i<product.count(); i++)
    {
        Product pr = product.at(i);
        countPr += pr.getCount();
    }
    return countPr;
}

double Section::getPriceType(QString t)
{
    double pr = 0;
    for(int i = 0; i<product.count(); i++)
    {
        Product object = product.at(i);
        double price = object.getPrice();
        int count = object.getCount();
        pr += price*count;
    }
    return pr;
}
