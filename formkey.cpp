#include "formkey.h"

FormKey::FormKey():FormProduct()
{
    typeText = new QLabel("Type");
    type = new QComboBox();
    setType();
    this->layout->addWidget(typeText, 3,0);
    this->layout->addWidget(type, 3,1);
}

FormKey::FormKey(QString nameString, QString priceString, QString countString, QString typeString)
    :FormProduct(nameString, priceString, countString)
{
    typeText = new QLabel(typeString);
    type = new QComboBox();
    setType();
    this->layout->addWidget(typeText, 3,0);
    this->layout->addWidget(type, 3,1);
}

FormKey::~FormKey()
{
    delete typeText;
    delete type;
}

void FormKey::setProduct(Product t)
{
    FormProduct::setProduct(t);
    int c = type->findText(QString(t.getType()));
    type->setCurrentIndex(c);
}

Product FormKey::getProduct()
{
    Product t = FormProduct::getProduct();
    QString typ = type->currentText();
    Product key = Product(t.getName(),t.getPrice(),t.getCount(), typ);
    return key;
}

void FormKey::setProduct(QStringList lst)
{
    FormProduct::setProduct(lst);
    int c = type->findText(lst.at(3));
    type->setCurrentIndex(c);
}

void FormKey::setType()
{
    QFile file("./data/key/type.dat");
    QTextStream out(&file);
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QString str = out.readAll();
        QStringList lst = str.split("\n");
        type->addItems(lst);
        file.close();
    }
}
