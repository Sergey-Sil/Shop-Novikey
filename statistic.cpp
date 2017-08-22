#include "statistic.h"

Statistic::Statistic(QWidget *parent):QWidget(parent)
{
    this->layoutWidget = new QGridLayout();
    this->setWindowTitle("Novikey");
    this->setWindowIcon(QIcon("./data/logo.jpg"));
    this->setLayout(this->layoutWidget);
    this->setStyleSheet(QString("QLabel{"
                                "font-size:14px;"
                                "}"));
}


Statistic::Statistic(const Statistic &object)
{
    this->layoutWidget = object.layoutWidget;
}

void Statistic::createStatictic(QStringList name, QStringList count, QStringList price)
{
    QLabel* info = new QLabel("Информация");
    info->setStyleSheet(QString("font-size: 16px;"
                                "color:red;"));
    layoutWidget->addWidget(info,0,0);

    QLabel* type = new QLabel("Вид продукта");
    layoutWidget->addWidget(type,1,0);

    QLabel* countLabel = new QLabel("Количество");
    layoutWidget->addWidget(countLabel,1,1);
    QLabel* priceLabel = new QLabel("Стоимость");
    layoutWidget->addWidget(priceLabel,1,2);

    for(int i = 0; i<name.count(); i++)
    {
        QLabel* n = new QLabel(name.at(i) + QString(":"));
        QLabel* c = new QLabel(count.at(i));
        QLabel* p = new QLabel(price.at(i));

        layoutWidget->addWidget(n,i+2,0);
        layoutWidget->addWidget(c,i+2,1);
//        layoutWidget->addWidget(n,i+1,2);
        layoutWidget->addWidget(p,i+2,2);
    }
}

Statistic::~Statistic()
{
    delete(this->layoutWidget);
}
