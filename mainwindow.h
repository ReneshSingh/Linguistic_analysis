#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "LinguisticAnalysis.h"

/*!< \namespace Ui
 * \brief The UI tool box.
 */
namespace Ui {
class MainWindow;
}

/*! \class MainWindow
 * \brief User interface controler.
 *
 * Manages the UI and interactions with other classes in the program.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void AnalyseText(); //!< Sends text from the UI to the linguistic analysis class for processing.
    void CreateReport(); //!< Requests a report from the Linguistic analysis class.
    void ClearAll(); //!< \brief clears linguistic dataset.
    void pub_msg(QString msg); //!< \brief Publishes message to the UI.
private:
    Ui::MainWindow *ui; // The user interface.
    LinguisticAnalysis *pt; // Text analysis instance.
};

#endif // MAINWINDOW_H
