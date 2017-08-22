#pragma once
#include"formproduct.h"
#include"formkey.h"
#include <QMainWindow>
#include"tabwidget.h"
#include"tabwidgetkey.h"
#include"tabwidgetcar.h"
#include"collection.h"
#include"shop.h"
#include"statistic.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    QList<TabWidget*> tabs;
    QTabWidget* tabWidget;
    Shop* shop;
    Ui::MainWindow *ui;
public:
    explicit MainWindow(QWidget *parent = 0);
    void loadTable();
    void loadTableSection(int n);
    ~MainWindow();

public slots:
    void addProductSlot();
    void deleteProductSlot();
    void changeProductSlot();
    void sortProductSlot();
    void searchProductSlot();
    void changeTypeKey();
    void purchaseOneProduct();
    void productStatisticSlot();
    void cancelActionSlot();
};

