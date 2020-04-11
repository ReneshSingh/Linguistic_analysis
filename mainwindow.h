#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "LinguisticAnalysis.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void AnalyseText();
    void CreateReport();
    void ClearAll();
    void pub_msg(QString msg);
private:
    Ui::MainWindow *ui;
    LinguisticAnalysis *pt;
};

#endif // MAINWINDOW_H
