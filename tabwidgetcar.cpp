#include "tabwidgetcar.h"

TabWidgetCar::TabWidgetCar(QWidget* parent):TabWidget(parent)
{

}

void TabWidgetCar::createTabWidget(QStringList lst)
{
    this->createTab(4);
    formProduct = new FormCar(lst.at(0), lst.at(1), lst.at(2), lst.at(3));

    table->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    table->setHorizontalHeaderLabels(lst);

    layoutWidget->addWidget(formProduct, 1,2,1,2);

    this->setLayout(layoutWidget);
}

void TabWidgetCar::loadProductInTable(Product car, int row)
{
    TabWidget::loadProductInTable(car,row);
    QTableWidgetItem* n = new QTableWidgetItem(car.getType());
    this->table->setItem(row,3,n);
}

Product TabWidgetCar::getProduct()
{
    int cRow = table->currentRow();
    Product pr = TabWidget::getProduct();
    QString typePr = table->item(cRow,3)->text();
    Product prod = Product(pr, typePr);
    return prod;
}

void TabWidgetCar::searchProduct(int n)
{
    TabWidget::searchProduct(3);
}
