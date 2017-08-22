#pragma once
#include"formproduct.h"
#include<QtWidgets>
#include<QWidget>
#include"car.h"
#include<QStringList>
class TabWidget:public QWidget
{
    Q_OBJECT
public:
    QGridLayout* layoutWidget;
    QComboBox* sortProduct;
    QLineEdit* productSearch;
    QPushButton* addProduct;
    QPushButton* changeProduct;
    QPushButton* deleteProduct;
    QTableWidget* table;
    FormProduct* formProduct;
public:
    explicit TabWidget(QWidget* parent = 0);
    virtual void createTabWidget(QStringList lst);
    void createTab(int count);

    virtual void loadProductInTable(Product pr, int row);
    virtual void addProductInTable(Product pr);
    virtual Product getProduct();
    virtual void sortTable();
    virtual void deleteProductFromTable();

    virtual void searchProduct(int n = 0);
    virtual void clearTable();
    virtual int checkCountProduct();
    virtual void changeKeyType(){}
public slots:
    void clickedTableSlot();
};

