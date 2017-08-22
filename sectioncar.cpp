#include "sectioncar.h"

SectionCar::SectionCar():Section()
{

}

SectionCar::SectionCar(QString n):Section(n)
{

}

SectionCar::SectionCar(const SectionCar& section)
{
    this->name = section.name;
    this->product = section.product;
}

SectionCar::~SectionCar()
{

}

void SectionCar::saveSection()
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

void SectionCar::loadSection()
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

Product SectionCar::createProduct(QString str)
{
    QStringList lst = str.split(";");
    Product pr = Product(lst.at(0), lst.at(1), lst.at(2), lst.at(3));
    return pr;
}

int SectionCar::getCountType(QString t)
{
    int countPr = 0;
    for(int i = 0; i<product.count(); i++)
    {
        Product pr = product.at(i);
        if(pr.getType().contains(t))
        {
            countPr += pr.getCount();
        }
    }
    return countPr;
}

double SectionCar::getPriceType(QString t)
{
    if(t.count()==0)
        return Section::getPriceType(t);
    double pricePr = 0;
    for(int i = 0; i<product.count(); i++)
    {
        Product pr = product.at(i);
        if(pr.getType() == t)
        {
            pricePr += pr.getPrice()*pr.getCount();
        }
    }
    return pricePr;
}

