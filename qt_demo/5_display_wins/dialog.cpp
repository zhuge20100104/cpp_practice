#include "dialog.h"
#include "./ui_dialog.h"


Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    connect(ui->OK, SIGNAL(clicked()), this, SLOT(close()));
}



Dialog::~Dialog()
{
    delete ui;
}

