#include "shop.h"

Shop::Shop()
{
}

Shop::Shop(QString n)
{
    this->name = n;
    this->section = new QList<Section*>();
    cancel = stack<Action>();
}

void Shop::addSection(QString nsect)
{
    Section* newSect = new Section(nsect);
    this->section->push_back(newSect);
}

void Shop::addProduct(Product pr, int sect)
{
    this->section->at(sect)->addProduct(pr);
}

void Shop::deleteSection(int n)
{
    this->section->removeAt(n);
}

QList<Section*>* Shop::getSectionCollection()
{
    return this->section;
}

Section* Shop::getSection(int i)
{
    return this->section->at(i);
}

void Shop::loadShop()
{
    Section* key = new SectionCar("key");
    this->section->push_back(key);
    Section* chip = new Section("chip");
    this->section->push_back(chip);
    Section* car = new SectionCar("car");
    this->section->push_back(car);
    for(int i =0; i<3; i++)
    {
        this->section->at(i)->loadSection();
    }
}

void Shop::saveShop()
{
    for ( int i = 0; i < this->section->count() - 1 ; i++)
    {
        this->section->at(i)->saveSection();
    }
}

void Shop::addSection(QString newSection, Section* s)
{
    Section* temp = new Section(newSection);
    for(int i=0; i<s->getCount();i++)
    {
        Product t = s->getProductCollection().at(i);
        temp->addProduct(t);
    }
    this->section->push_back(temp);
}

double Shop::getAllPrice()
{
    double price = 0;
    for(int i = 0; i < this->section->count(); i++)
    {
        for(int j = 0; j<this->section->at(i)->getCount(); j++)
        {
            Product pr = this->section->at(i)->getProduct(j);
            price += pr.getCount()*pr.getPrice();
        }
    }
    return price;

}

int Shop::getAllCount()
{
    int count = 0;
    for(int i = 0; i < this->section->count(); i++)
    {
        count += this->section->at(i)->getCountType(QString(""));
//        for(int j = 0; j<this->section->at(i)->getCount(); j++)
//        {
//            Product pr = this->section->at(i)->getProduct(j);
//            price += pr.getCount()*pr.getPrice();
//        }
    }
    return count;
}

void Shop::pushAction(QString action, Product pr, int n)
{
    Action act;
    act.action = action;
    act.prod=pr;
    act.numberSection = n;
    cancel.push(act);
}

 void Shop::pushAction(QString action, Product pr, Product oldProduct, int n)
 {
     Action act;
     act.action = action;
     act.prod=pr;
     act.numberSection = n;
     act.oldProd = oldProduct;
     cancel.push(act);
 }

int Shop::popAction()
{
    if(cancel.empty()){
        return -1;
    }
    else{
        Action act = cancel.top();
        cancel.pop();
        int k;
        if(act.action == QString("addProduct")) k = 0;
        if(act.action == QString("deleteProduct")) k = 1;
        if(act.action == QString("changeProduct")) k = 2;
        switch(k){
            case 0:{
                this->getSection(act.numberSection)->deleteProduct(act.prod);
            }break;
            case 1:{
                this->getSection(act.numberSection)->addProduct(act.prod);
            }break;
            case 2:{
                int i = this->getSection(act.numberSection)->search(act.prod);
                this->getSection(act.numberSection)->getProductCollection().replace(i, act.oldProd);
            }break;
            default:return -1;
        }

        return act.numberSection;
    }
}
