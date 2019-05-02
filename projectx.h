#ifndef PROJECTX_H
#define PROJECTX_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTextEdit>
#include <QString>
#include <QHash>

class ProjectX : public QWidget
{
    Q_OBJECT
public:
    explicit ProjectX();
    QPushButton *submit, *report, *quit;
    ~ProjectX();
    QTextEdit *edit;
public slots:
    void analysis();
    void results();
private:
    QHash<QString, int> *info;
    QVBoxLayout *vlayout;
    QHBoxLayout *hlayout;
    QString temp;
    QStringList lKey;
};

#endif // PROJECTX_H
