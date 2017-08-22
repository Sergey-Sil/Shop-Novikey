#pragma once
#include<QtWidgets>
class Statistic:public QWidget
{
    Q_OBJECT
private:
    QGridLayout* layoutWidget;
public:
    explicit Statistic(QWidget* parent = 0);
    Statistic(const Statistic &object);
    void createStatictic(QStringList name,QStringList count, QStringList price);
    ~Statistic();
};
