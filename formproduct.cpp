#include "formproduct.h"

FormProduct::FormProduct()
{
    name = new QLabel("Name");
    count = new QLabel("Count");
    price = new QLabel("Price");
    nameText = new QLineEdit();
    nameText->setValidator(new QRegExpValidator(QRegExp("[ A-Za-zА-Яа-я0-9,]{100}")));
    nameText->setPlaceholderText("Name");
    countText = new QLineEdit();
    countText->setValidator(new QRegExpValidator(QRegExp("^([0-9]{10})"), this));
    countText->setPlaceholderText("Count");
    priceText = new QLineEdit();
    priceText->setValidator(new QRegExpValidator(QRegExp("^([0-9]*|0)[.]{1}[0-9]{2}"), this));
    priceText->setPlaceholderText("Price");

    layout = new QGridLayout();
    layout->addWidget(name, 0,0);
    layout->addWidget(nameText, 0,1);
    layout->addWidget(price, 1,0);
    layout->addWidget(priceText,1,1);
    layout->addWidget(count, 2,0);
    layout->addWidget(countText,2,1);

    this->setLayout(layout);
}

FormProduct::FormProduct(QString nameString, QString priceString, QString countString)
{
    name = new QLabel(nameString);
    count = new QLabel(countString);
    price = new QLabel(priceString);
    nameText = new QLineEdit();
    nameText->setValidator(new QRegExpValidator(QRegExp("[ A-Za-zА-Яа-я0-9,-]{100}")));
    nameText->setPlaceholderText(nameString);
    countText = new QLineEdit();
    countText->setValidator(new QRegExpValidator(QRegExp("^([0-9]{10})"), this));
    countText->setPlaceholderText(countString);
    priceText = new QLineEdit();
    priceText->setValidator(new QRegExpValidator(QRegExp("^(([0-9]*|10)[.]{1}[0-9]{2})"), this));
    priceText->setPlaceholderText(priceString);

    this->setStyleSheet(QString("QLineEdit{height:20px;}"
                                "QLineEdit:hover{"
                                "background:AliceBlue;}"
                                ));
    layout = new QGridLayout();
    layout->addWidget(name, 0,0);
    layout->addWidget(nameText, 0,1);
    layout->addWidget(price, 1,0);
    layout->addWidget(priceText,1,1);
    layout->addWidget(count, 2,0);
    layout->addWidget(countText,2,1);

    this->setLayout(layout);
}

FormProduct::~FormProduct()
{
    delete layout;
    delete name;
    delete count;
    delete price;

    delete nameText;
    delete countText;
    delete priceText;
}

void FormProduct::setProduct(Product t)
{
    nameText->setText(QString(t.getName()));
    countText->setText(QString::number(t.getCount()));
    priceText->setText(QString::number(t.getPrice()));
}

Product FormProduct::getProduct()
{
    QString namePr = nameText->text();
    int countPr = countText->text().toInt();
    double pricePr = priceText->text().toDouble();
    Product pr = Product(namePr, pricePr, countPr);
    return pr;
}

bool FormProduct::checkInputProduct()
{
    if(this->nameText->text()!=QString("")
            && this->priceText->text()!=QString("")
            && this->countText->text()!=QString(""))
        return true;
    return false;
}

void FormProduct::setProduct(QStringList lst)
{
    nameText->setText(lst.at(0));
    countText->setText(lst.at(1));
    priceText->setText(lst.at(2));
}
