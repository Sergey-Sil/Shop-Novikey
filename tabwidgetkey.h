#pragma once
#include"tabwidget.h"
#include"formkey.h"
#include"car.h"

class TabWidgetKey:public TabWidget
{
    Q_OBJECT
public:
    QComboBox* typeKeyBox;
public:
    explicit TabWidgetKey(QWidget* parent = 0);
    void createTabWidget(QStringList lst);

    void loadProductInTable(Product key, int row) override;
    void loadKeyType();
    Product getProduct();
    void changeKeyType();
};

