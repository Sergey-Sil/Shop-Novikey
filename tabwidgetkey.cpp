#include "tabwidgetkey.h"
#include<QFile>
#include<QTextStream>
TabWidgetKey::TabWidgetKey(QWidget* parent):TabWidget(parent)
{

}

void TabWidgetKey::createTabWidget(QStringList lst)
{
    this->createTab(4);
    typeKeyBox = new QComboBox();
    loadKeyType();
    formProduct = new FormKey(lst.at(0), lst.at(1), lst.at(2), lst.at(3));

    table->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    table->setHorizontalHeaderLabels(lst);

    layoutWidget->addWidget(typeKeyBox,0,1);
    layoutWidget->addWidget(formProduct, 1,2,1,2);

    this->setLayout(layoutWidget);
}

void TabWidgetKey::loadProductInTable(Product key, int row)
{
    TabWidget::loadProductInTable(key, row);
    QTableWidgetItem* n = new QTableWidgetItem(key.getType());
    this->table->setItem(row,3,n);
}

void TabWidgetKey::loadKeyType()
{
    QFile file("./data/key/type.dat");
    QTextStream out(&file);
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
        typeKeyBox->addItem("Выбрать тип");
        QString str = out.readAll();
        QStringList lst = str.split("\n");
        typeKeyBox->addItems(lst);
        file.close();
    }
}

Product TabWidgetKey::getProduct()
{
    int cRow = table->currentRow();
    Product pr = TabWidget::getProduct();
    QString idPr = table->item(cRow,3)->text();
    Product prod = Product(pr, idPr);
    return prod;
}

void TabWidgetKey::changeKeyType()
{
    QString find = typeKeyBox->currentText();
    if(find == QString("Выбрать тип"))
        return;
    int i = table->rowCount() - 1;
    for(i; i >=0; i--)
    {
        if(table->item(i,3)->text() == find){
            continue;
        }else{
            table->removeRow(i);
        }
    }
}
