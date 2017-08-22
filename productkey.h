//#pragma once
//#include"product.h"


//class ProductKey:public Product
//{
//public:
//    ProductKey(){}

//    ProductKey(MyString n, double p, int c, MyString t): Product(n, p, c)
//    {
//        this->type = t;
//    }
//    ProductKey(Product pr, MyString t):Product(pr.getName(), pr.getPrice(), pr.getCount()){
//        this->type = t;
//    }

//    ProductKey(const ProductKey& object)
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
//    void setData(ProductKey k){
//        this->setCount(k.getCount());
//        this->setName(k.getName());
//        this->setPrice(k.getPrice());
//        this->setType(k.getType());
//    }
//    bool operator==(ProductKey t)
//    {
//        //toUpper
//        if(this->getName()==t.getName() && this->getType()==t.getType() && this->getPrice()==t.getPrice())
//            return true;
//        return false;
//    }

//    bool operator!=(ProductKey t);
//    bool compare(Product* t);
//    MyString productToChar();
//};
