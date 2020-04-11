#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    pt = new LinguisticAnalysis();
    ui->setupUi(this);
    ui->label->setText("");
    ui->textEdit->setPlaceholderText("Enter text for analysis here. Click'Submit for analysis' for multiple tex analysis.");
    connect(pt, SIGNAL(message(QString)), this, SLOT(pub_msg(QString)));
    connect(ui->actionAnalyse_text, SIGNAL(triggered()), this, SLOT(AnalyseText()));
    connect(ui->actionReport, SIGNAL(triggered()), this, SLOT(CreateReport()));
    connect(ui->actionClear, SIGNAL(triggered()), this, SLOT(ClearAll()));
}
void MainWindow::ClearAll(){
    pt->clear();
    ui->textEdit->clear();
}
void MainWindow::AnalyseText(){
    pt->analysis(ui->textEdit->toPlainText());
    pub_msg("Text submitted for analysis.");
    ui->textEdit->clear();
}
void MainWindow::CreateReport(){
    QString outPut;
    ui->label->setText("Generating the report.");
    outPut = pt->results(ui->textEdit->toPlainText());
    ui->textEdit->setText(outPut);
}
void MainWindow::pub_msg(QString msg){
    ui->label->setText(msg);
    ui->label->setAccessibleDescription(msg);
}
MainWindow::~MainWindow()
{
    delete ui;
    delete pt;
}
