//#pragma once

//#include"product.h"


//class Key:public Product
//{
//public:
//    Key(){}

//    Key(MyString n, double p, int c, MyString t)
//    {
//        this->name = n;
//        this->price = p;
//        this->count = c;
//        this->type = t;
//    }
//    Key(Product pr, MyString t):Product(pr.getName(), pr.getPrice(), pr.getCount()){
//        this->type = t;
//    }

//    Key(const Key& object)
//    {
//        this->name = object.name;
//        this->count= object.count;
//        this->price = object.price;
//        this->type = object.type;
//    }

//    Product* getProduct()
//    {
//        Product* pr = new Product(this->name, this->price, this->count);
//        return pr;
//    }

//    MyString getType(){
//        return type;
//    }
//    void setType(MyString t){
//        type = t;
//    }
//    void setData(Key k){
//        this->setCount(k.getCount());
//        this->setName(k.getName());
//        this->setPrice(k.getPrice());
//        this->setType(k.getType());
//    }
//    bool operator==(Key t)
//    {
//        //toUpper
//        if(this->getName()==t.getName() && this->getType()==t.getType() && this->getPrice()==t.getPrice())
//            return true;
//        return false;
//    }

//    bool operator!=(Key t);
//    bool compare(Product* t);
//    MyString productToChar();
//};
