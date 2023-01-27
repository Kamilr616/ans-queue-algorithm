#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "Steps.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_calc_clicked()
{
    lambda = ui->inputLambda->value();
    mikro = ui->inputMikro->value();
    m = ui->inputM->value();
    N = ui->inputN->value();

    Steps Analize(lambda, mikro, m , N);

    ui->output_1->setText(QString::number(5));
}
