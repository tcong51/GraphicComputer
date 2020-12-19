#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_bt_clicked()
{
    ui->GraphicsPresenter->mode=1;
    ui->GraphicsPresenter->repaint();
    ui->GraphicsPresenter->mode=0;
}
