#include "tabwidget.h"

TabWidget::TabWidget(QWidget *parent):QWidget(parent)
{

}

void TabWidget::createTabWidget(QStringList lst)
{
    this->createTab(3);
    table->setHorizontalHeaderLabels(lst);
    formProduct = new FormProduct(lst.at(0), lst.at(1) , lst.at(2));
    layoutWidget->addWidget(formProduct, 1,2,1,2);

    this->setLayout(layoutWidget);
}

void TabWidget::createTab(int count)
{
    layoutWidget = new QGridLayout();
    sortProduct = new QComboBox();
    sortProduct->addItems(QStringList()<<"По названию"<<"По цене"<<"По количеству");
    productSearch = new QLineEdit();
    productSearch->setPlaceholderText("Поиск");
    addProduct = new QPushButton("Добавить");
    changeProduct = new QPushButton("Изменить");
    deleteProduct = new QPushButton("Удалить");

    table = new QTableWidget(0,count);
    table->setFixedSize(430,310);
    table->setStyleSheet(QString("QTableWidget{"
                                    "border: 2px solid black;"
                                    "border-radius: 0px;"
                                    "background-color: #fff;"
                                    "gridline-color: #770;"
                                    "selection-background-color: #ccdfff;"
                                    "color:#333;"
                                    "font-size:12px;"
                                    "}"
                                    "QTableWidget:item:hover { "
                                         "background-color: whitesmoke;"
                                         "color:black;"
                                     "} "));
    this->setStyleSheet(QString("QLineEdit{height:20px;}"
                                "QLineEdit:hover{"
                                "background:AliceBlue;}"));
    for(int i = 0; i<count; i++)
    {
        table->setColumnWidth(i,(table->width()-19)/count);
    }
    table->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    layoutWidget->addWidget(table,1,0,6,2);
    layoutWidget->addWidget(productSearch,0,2,1,2);
    layoutWidget->addWidget(sortProduct, 0,0);

    layoutWidget->addWidget(addProduct,3,2);
    layoutWidget->addWidget(changeProduct,2,2,1,2);
    layoutWidget->addWidget(deleteProduct,3,3);
    connect(this->table, SIGNAL(itemClicked(QTableWidgetItem*)),
            this, SLOT(clickedTableSlot()));
}

void TabWidget::loadProductInTable(Product pr, int row)
{
    QTableWidgetItem* n = new QTableWidgetItem(pr.getName());
    QTableWidgetItem* p = new QTableWidgetItem();
    p->setData(Qt::DisplayRole, pr.getPrice());
    QTableWidgetItem* c = new QTableWidgetItem();
    c->setData(Qt::DisplayRole, pr.getCount());
    n->setFlags(Qt::ItemIsEnabled|Qt::ItemIsSelectable);
    p->setFlags(Qt::ItemIsEnabled|Qt::ItemIsSelectable);
    c->setFlags(Qt::ItemIsEnabled|Qt::ItemIsSelectable);
    this->table->setItem(row,0,n);
    this->table->setItem(row,1,p);
    this->table->setItem(row,2,c);
}

void TabWidget::clickedTableSlot()
{
    int c = this->table->currentRow();
    QStringList lst;
    for(int i = 0; i<table->columnCount(); i++)
        lst<<table->item(c,i)->text();
    formProduct->setProduct(lst);
}

void TabWidget::addProductInTable(Product pr)
{
    table->insertRow(table->rowCount());
    loadProductInTable(pr, table->rowCount()-1);
}

Product TabWidget::getProduct()
{
    int cRow = table->currentRow();
    QString namePr = table->item(cRow,0)->text();
    double pricePr = table->item(cRow, 1)->text().toDouble();
    int countPr = table->item(cRow,2)->text().toInt();
    Product pr = Product(namePr, pricePr, countPr);
    return pr;
}

void TabWidget::deleteProductFromTable()
{
    table->removeRow(table->currentRow());
}

void TabWidget::sortTable()
{
    int cCol = sortProduct->currentIndex();
    table->sortItems(cCol);
}

void TabWidget::searchProduct(int n)
{
    QString find = productSearch->text().toUpper();
    int i = table->rowCount() - 1;
    for(i; i >=0; i--)
    {
        if(table->item(i,n)->text().toUpper().contains(find)){
            continue;
        }else{
            table->removeRow(i);
        }
    }
}

void TabWidget::clearTable()
{
    for(int i = table->rowCount() - 1; i>=0; i--)
    {
        table->removeRow(i);
    }
}

int TabWidget::checkCountProduct()
{
    int cRow = table->currentRow();
    if(table->item(cRow,2)->text().toInt() > 0)
    {
        return cRow;
    }
    return -1;
}
