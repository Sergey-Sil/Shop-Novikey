#include "formcar.h"

FormCar::FormCar():FormProduct()
{
    idText = new QLabel("ID");
    id = new QLineEdit();
    id->setPlaceholderText("ID");
    id->setValidator(new QRegExpValidator(QRegExp("[^;]*|0"), this));

    this->layout->addWidget(idText, 3,0);
    this->layout->addWidget(id, 3,1);
}

FormCar::FormCar(QString nameString, QString priceString, QString countString, QString idString)
    :FormProduct(nameString, priceString,countString)
{
    idText = new QLabel(idString);
    id = new QLineEdit();
    id->setPlaceholderText(idString);
    id->setValidator(new QRegExpValidator(QRegExp("[^;]*|0"), this));

    this->layout->addWidget(idText, 3,0);
    this->layout->addWidget(id, 3,1);
}

FormCar::~FormCar()
{
    delete idText;
    delete id;
}

void FormCar::setProduct(Product t)
{
    FormProduct::setProduct(t);
    id->setText(t.getType());
}

Product FormCar::getProduct()
{
    Product t = FormProduct::getProduct();
    QString type = id->text();
    Product carProduct = Product(t, type);
    return carProduct;
}

bool FormCar::checkInputProduct()
{
    if(FormProduct::checkInputProduct() && id->text()!=QString(""))
        return true;
    return false;
}

void FormCar::setProduct(QStringList lst)
{
    FormProduct::setProduct(lst);
    id->setText(lst.at(3));
}

