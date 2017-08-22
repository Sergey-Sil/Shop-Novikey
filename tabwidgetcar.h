#pragma once
#include"tabwidget.h"
#include"formcar.h"
#include"car.h"

class TabWidgetCar: public TabWidget
{    
    Q_OBJECT
public:
    explicit TabWidgetCar(QWidget* parent = 0);
    void createTabWidget(QStringList lst);


    void loadProductInTable(Product car, int row);
    Product getProduct();
    void searchProduct(int n = 3);
};

