#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QCursor>
#include<memory>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    this->setWindowTitle("Novikey");
    this->setWindowIcon(QIcon("./data/logo.jpg"));
    shop = new Shop("shop");
    shop->loadShop();
    this->setFixedSize(680,440);

    QMenu* file = menuBar()->addMenu("&Меню");
    file->addAction("Информация", this, SLOT(productStatisticSlot()), Qt::ALT + Qt::Key_S);
    file->addAction("Exit", this, SLOT(close()), Qt::ALT + Qt::Key_F4);

    file = menuBar()->addMenu("&Правка");
    file->addAction("Отменить", this, SLOT(cancelActionSlot()), Qt::CTRL + Qt::Key_Z);

    this->setStyleSheet(QString("QLineEdit{height:20px;}"
                                "QLineEdit:hover{"
                                "background:AliceBlue;}"
                                "QComboBox{"
                                "height:20px;"
                                "}"
                                ));
    tabWidget = new QTabWidget();
    this->setStyleSheet(QString("QTabWidget, QStackedWidget {background: none; font-size:12px;}"
                               "QTabWidget:tab-bar { left: 0.3em;} "
                             "  QTabWidget:pane { "
                                "   border: 0px;"
                                   "top: 0.1em;  "
                                   "background-repeat: no repeat;} "
                               "QTabBar:tab { "
                                    "height:18px; width:80px;"
                                    " border: 1px solid #7a7a7a; "
                                    " border-bottom-color: #ffffff; "
                                    " border-top-left-radius: 4px; "
                                    " border-top-right-radius: 4px; "
                                    " padding: 5px 7px 5px 7px;"
                                    " background-color: white;}"
                              " QTabBar:tab:selected { "
                                   "background-color: lightblue;"
                               "} "
                               "QTabBar:tab:hover { "
                                    "background-color: whitesmoke;"
                                "} "
                               "QTabBar:tab:!selected { margin-top: 2px;} "
                              " QTabBar:tab:selected {"
                                    "margin-left: -4px; "
                                    "margin-right: -4px;"
                                    "height:20px; width:80px;"
                               "}"
                               "QTabBar:tab:first:selected { margin-left: 0;} "
                               "QTabBar:tab:last:selected { margin-right: 0;} "
                               "QTabBar:tab:only-one { 	margin: 0;}")
                       );
    TabWidgetKey* key = new TabWidgetKey();
    TabWidget* chip = new TabWidget();
    TabWidgetCar* car = new TabWidgetCar();

    key->createTabWidget(QStringList()<<"Артикул"<<"Цена"<<"Количество"<<"Тип");
    chip->createTabWidget(QStringList()<<"Название"<<"Цена"<<"Количество");
    car->createTabWidget(QStringList()<<"Название"<<"Цена"<<"Количество"<<"ID");

    connect(key->typeKeyBox, SIGNAL(currentIndexChanged(int)),
            this, SLOT(changeTypeKey()));

    tabs.append(key);
    tabs.append(chip);
    tabs.append(car);
    loadTable();
    tabWidget->addTab(tabs.at(0),QIcon("./data/key/keyicon.jpg"),QString("Ключи"));
    tabWidget->addTab(tabs.at(1),QIcon("./data/chip/chipicon.jpg"),QString("Чипы"));
    tabWidget->addTab(tabs.at(2),QIcon("./data/car/caricon.jpg"),QString("Авточипы"));

    for(int i = 0; i<3;i++)
    {
        connect(tabs.at(i)->addProduct, SIGNAL(clicked(bool)),
                this, SLOT(addProductSlot()));
        connect(tabs.at(i)->deleteProduct, SIGNAL(clicked(bool)),
                this, SLOT(deleteProductSlot()));
        connect(tabs.at(i)->changeProduct,SIGNAL(clicked(bool)),
                this, SLOT(changeProductSlot()));
        connect(tabs.at(i)->sortProduct, SIGNAL(currentIndexChanged(int)),
                this, SLOT(sortProductSlot()));
        connect(tabs.at(i)->productSearch,SIGNAL(textChanged(QString)),
                this, SLOT(searchProductSlot()));
        connect(tabs.at(i)->table, SIGNAL(itemDoubleClicked(QTableWidgetItem*)),
                this, SLOT(purchaseOneProduct()));
    }


    this->setCentralWidget(tabWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete tabWidget;
    delete shop;
}

void MainWindow::loadTable()
{
    for(int i = 0; i<this->shop->getSectionCollection()->count(); i++)
    {   
        loadTableSection(i);
        tabs.at(i)->sortTable();
    }
}

void MainWindow::loadTableSection(int n)
{
    int count = this->shop->getSectionCollection()->at(n)->getCount();
    for(int j = 0; j < count; j++)
    {
        this->tabs.at(n)->table->insertRow(j);
        this->tabs.at(n)->loadProductInTable(this->shop->getSection(n)->getProduct(j), j);
    }
}

void MainWindow::addProductSlot()
{
    int cTab = tabWidget->currentIndex();
    if(tabs.at(cTab)->formProduct->checkInputProduct())
    {
        Product t = tabs.at(cTab)->formProduct->getProduct();
        if(shop->getSection(cTab)->search(t)==-1)
        {
            tabs.at(cTab)->addProductInTable(t);
            shop->getSection(cTab)->addProduct(t);
            shop->getSection(cTab)->saveSection();
            shop->pushAction(QString("addProduct"),t,cTab);
            sortProductSlot();
        }
        else{
            QToolTip::showText(tabs.at(cTab)->addProduct->mapToGlobal(QPoint(0,0)),"Данный продукт уже существует");
        }
    }else{
        QToolTip::showText(tabs.at(cTab)->addProduct->mapToGlobal(QPoint(0,0)),"Заполните недостающие данные");
    }
}

void MainWindow::deleteProductSlot()
{
    int cTab = tabWidget->currentIndex();
    if(tabs.at(cTab)->table->currentRow()!=-1){
        Product pr = tabs.at(cTab)->getProduct();
        shop->getSection(cTab)->deleteProduct(pr);
        tabs.at(cTab)->deleteProductFromTable();
        shop->getSection(cTab)->saveSection();
        shop->pushAction(QString("deleteProduct"),pr,cTab);
    }else{
        QToolTip::showText(tabs.at(cTab)->deleteProduct->mapToGlobal(QPoint(0,0)),"Выберите продукт");
    }
}

void MainWindow::changeProductSlot()
{
    int cTab = tabWidget->currentIndex();
    if(tabs.at(cTab)->formProduct->checkInputProduct())
    {
        Product newProduct = tabs.at(cTab)->formProduct->getProduct();
        int cRow = tabs.at(cTab)->table->currentRow();
        if(cRow!=-1)
        {
            Product oldProduct = tabs.at(cTab)->getProduct();
            int numberProduct = shop->getSection(cTab)->search(oldProduct);
            shop->getSection(cTab)->getProductCollection().replace(numberProduct, newProduct);
            tabs.at(cTab)->loadProductInTable(newProduct,cRow);
            shop->getSection(cTab)->saveSection();
            shop->pushAction(QString("changeProduct"),newProduct,oldProduct,cTab);
            sortProductSlot();
        }
        else{
            QToolTip::showText(tabs.at(cTab)->changeProduct->mapToGlobal(QPoint(0,0)),"Продукт не выбран в таблице");
        }
    }else{
        QToolTip::showText(tabs.at(cTab)->changeProduct->mapToGlobal(QPoint(0,0)),"Заполните недостающие данные");
    }
}

void MainWindow::sortProductSlot()
{
    int cTab = tabWidget->currentIndex();
    tabs.at(cTab)->sortTable();
}

void MainWindow::searchProductSlot()
{
    int cTab = tabWidget->currentIndex();
    tabs.at(cTab)->clearTable();
    loadTableSection(cTab);
    tabs.at(cTab)->searchProduct();
    sortProductSlot();
}

void MainWindow::changeTypeKey()
{
    int cTab = tabWidget->currentIndex();
    tabs.at(cTab)->clearTable();
    loadTableSection(cTab);
    tabs.at(cTab)->changeKeyType();
    sortProductSlot();
}

void MainWindow::purchaseOneProduct()
{
    int cTab = tabWidget->currentIndex();
    int currentProd = tabs.at(cTab)->checkCountProduct();
    if(currentProd!=-1)
    {
        Product pr = tabs.at(cTab)->getProduct();
        Product oldProduct = tabs.at(cTab)->getProduct();
        int cPr = shop->getSection(cTab)->search(pr);
        shop->getSection(cTab)->getProduct(cPr).addCount(-1);
        pr.addCount(-1);
        tabs.at(cTab)->loadProductInTable(pr,currentProd);
        shop->getSection(cTab)->saveSection();
        shop->pushAction(QString("changeProduct"),pr,oldProduct,cTab);
    }else{
        QToolTip::showText(QCursor::pos(),"Недостаточное количество");
    }
}

void MainWindow::productStatisticSlot()
{
    QStringList name = QStringList();
    QStringList count = QStringList();
    QStringList price = QStringList();

//    QListWidget* stat = new QListWidget();

//    stat->setStyleSheet(QString("QListView{"
//                                "font-size:14px;"
//                                "}"
//                                "QListView::item {"
//                                    "border-bottom: 1px solid gray;"
//                                    "border-top-color: transparent;"
//                                    "}"
//                                 "QListView::item:selected:active {"
//                                   "  background: qlineargradient(x1: 1, y1: 0, x2: 0, y2: 3, stop: 0 #cbdaf1, stop: 1 #bfcde4);"
//                                "}"
//                                 "QListView::item:hover {"
//                                 "    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #e7effd, stop: 1 #cbdaf1);"
//                                 "    border: 1px solid #bfcde4;"
//                                "}"));
//    stat->addItem("Стоимость всех товаров : " + QString::number(shop->getAllPrice()));



    for(int i = 0; i< tabs.count(); i++)
    {
        name.append(tabWidget->tabText(i));
        count.append(QString::number(shop->getSection(i)->getCountType(QString(""))));
        price.append(QString::number(shop->getSection(i)->getPriceType(QString(""))));

    }

    QStringList lst;
    QFile file("./data/key/type.dat");
    QTextStream out(&file);
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QString str = out.readAll();
        lst = str.split("\n");
        file.close();
    }

    for (int i = 0; i < lst.count();i++){
        QString type = lst.at(i);
        int cn = shop->getSection(0)->getCountType(type);
        double pr = shop->getSection(0)->getPriceType(type);

        name.append(type);
        count.append(QString::number(cn));
        price.append(QString::number(pr));
    }

    name.append(QString("Итого"));
    count.append(QString::number(this->shop->getAllCount()));
    price.append(QString::number(this->shop->getAllPrice()));

    Statistic* stat = new Statistic();
    stat->createStatictic(name, count, price);
    stat->show();

}

void MainWindow::cancelActionSlot()
{
    int n = shop->popAction();
    if(n != -1)
    {
        tabs.at(n)->clearTable();
        loadTableSection(n);
        sortProductSlot();
    }
}

