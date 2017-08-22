//#include "key.h"





//bool Key::operator !=(Key t)
//{
//    //toUpper
//    if(this->getName()==t.getName() && this->getType()==t.getType() && this->getPrice()==t.getPrice())
//        return false;
//    return true;
//}

//MyString Key::productToChar()
//{
//    MyString product = MyString(this->getName()) + MyString(";");
//    char* buf;
//    int dec, sign;

//    buf = fcvt(price, 2, &dec, &sign);
//    MyString priceString = MyString(buf);
//    product = product + MyString(priceString(0, priceString.getCount() - 2)) + MyString(".") + MyString(priceString(priceString.getCount() - 2));

//    buf = fcvt(count, 0, &dec, &sign);
//    MyString countString = MyString(buf);
//    product = product + MyString(";") + countString + MyString(";") + this->type;


//    return product;
//}
