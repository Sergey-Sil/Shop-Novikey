#include "formchip.h"

FormChip::FormChip()
{
    artikul = new QLabel("Artikul");
    artikulText = new QLineEdit();

    this->layout->addWidget(artikul, 3,0);
    this->layout->addWidget(artikulText, 3,1);

}
