#include "sectionkey.h"
#include<QFile>
#include<QTextStream>


SectionKey::SectionKey()
{
    this->product = nullptr;
    this->name = MyString("");
}

SectionKey::SectionKey(MyString n)
{
    this->name = n;
    this->product = new Collection<Product*>();
}

SectionKey::SectionKey(const SectionKey& section)
{
    this->name = section.name;
    this->product = section.product;
}

void SectionKey::operator=(const SectionKey& section)
{
    this->name = section.name;
    this->product = section.product;
}

SectionKey::~SectionKey()
{
    if(this->getProductCollection() && this->getCount()!=0)
        delete product;
}

void SectionKey::addProduct(Product *pr)
{
    this->product->push(pr);
}

Product *SectionKey::getProduct(int i)
{
    return this->product->get(i);
}

int SectionKey::getCount()
{
    if(!this->product)
    {
        return 0;
    }
    return this->product->getCount();
}

MyString SectionKey::getName()
{
    return this->name;
}

void SectionKey::deleteProduct(Product *pr)
{
    this->product->deleteData(pr);
}

int SectionKey::search(Product *pr)
{
    return this->product->search(pr);
}

Collection<Product *> *SectionKey::getProductCollection()
{
    return this->product;
}

bool SectionKey::operator==(const SectionKey& t)
{
    if(this->name == t.name)
        return true;
    return false;
}

void SectionKey::saveSection()
{
    MyString nameSection = MyString("./data/")+this->name + MyString("/") + this->name + MyString("collection.txt");
    ofstream f;
    f.open(nameSection());
    int i;
    if(this->getCount() == 0){
        f.close();
        return;
    }
    for (i = 0; i < this->getCount()-1; i++)
    {
        f << this->getProduct(i)->productToChar()()<< endl;
    }
    f << this->getProduct(i)->productToChar()();
    f.close();
}

void SectionKey::loadSection()
{
    MyString nameSection = MyString("./data/")+this->name + MyString("/") + this->name + MyString("collection.dat");
    if (access(nameSection(), 0) != -1)
    {
       ifstream f;
       char s[256];
       f.open(nameSection());
       int m = f.peek();
       if(m == -1)
       {
           f.close();
           return;
       }
       while (!f.eof())
       {
           f.getline(s, 256);
           Car* pr = new Car(createProduct(s));
           this->addProduct(pr);
       }
       f.close();
   }

//    MyString nameSection = MyString("./data/")+this->name + MyString("/") + this->name + MyString("collection.dat");
//    QFile file(nameSection());
//    QTextStream out(&file);
//    QString str;
//    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
//    {
//        out>> str;
//        while(!str.isEmpty())
//        {
//            char* productString = const_cast<char*>(str.toStdString().c_str());
//            Car* pr = new Car(createProduct(productString));
//            this->addProduct(pr);
//            out>>str;
//        }
//        file.close();
//    }
}

Car SectionKey::createProduct(char *str)
{
    char* j = ";";
    char* pch = strtok(str, j);
    MyString name = MyString(pch);
    pch = strtok(NULL, j);
    double price = atof(pch);
    pch = strtok(NULL, j);
    int count = atoi(pch);

    pch = strtok(NULL, j);
    MyString type = MyString(pch);
    Car pr = Car(name, price, count, type);
    return pr;
}



