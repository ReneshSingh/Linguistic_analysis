#ifndef EXPORT_H
#define EXPORT_H

#include <QObject>
#include <QFileDialog>
#include <QHash>
#include <QFile>
#include <QTextStream>

class Export : public QObject
{
    Q_OBJECT
public:
    Export(QObject *Parent);
    bool selectFile(QHash<QString, int> *i);
    ~Export();
private:
    bool ToCSV( );
    bool ToTSV( );
    QFileDialog *fileDialog;
    QHash<QString, int> *info;
    QTextStream textStream;
    QFile *file;
    QString temp;
    QStringList lKey;
};

#endif // EXPORT_H
