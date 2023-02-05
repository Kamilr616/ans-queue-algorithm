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
    from = ui->inputFrom->value();
    to = ui->inputTo->value();

    Steps Analize(lambda, mikro, m , N);

    ui->output_1->setText(QString::fromStdString(Analize.printRo()));
    ui->output_2->setText(QString::fromStdString(Analize.printP0()));
    ui->output_3->setText(QString::fromStdString(Analize.probabilitesAtRange(from, to)));
    ui->output_4->setText(QString::fromStdString(Analize.printP0dm()));
    ui->output_5->setText(QString::fromStdString(Analize.printM0sr()));
    ui->output_6->setText(QString::fromStdString(Analize.printMznsr()));
    ui->output_7->setText(QString::fromStdString(Analize.printVsr()));
    ui->output_8->setText(QString::fromStdString(Analize.printNsr()));
    ui->output_9->setText(QString::fromStdString(Analize.printTf()));
    ui->output_10->setText(QString::fromStdString(Analize.printTs()));
}
