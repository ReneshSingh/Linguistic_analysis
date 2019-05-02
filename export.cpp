#include "export.h"

Export::Export(QObject *Parent)
{
    setParent(Parent);
    fileDialog = new QFileDialog;
    file = new QFile;
    textStream.setDevice(file);
    lKey << ".csv" << ".tsv";
    fileDialog->setNameFilters(lKey );
}
//Returns true if the file has been outpou.
bool Export::selectFile(QHash<QString, int> *i)
{
    info = i;
    lKey =info->uniqueKeys();
    file->setFileName(fileDialog->getSaveFileName());
    temp = fileDialog->selectedNameFilter();
    if(temp == ".csv")
        return ToCSV();
    else
        return ToTSV();
}
bool Export::ToCSV( )
{
    file->open(QIODevice::WriteOnly);
    while (!lKey.isEmpty()){
        temp= QString("%1,%2").arg(lKey.front()). arg(info->value(lKey.front()));
        lKey.pop_front();
        textStream << temp;
    }
    file->close();
    return true;
}
bool Export::ToTSV( )
{
    file->open(QIODevice::WriteOnly);
    while (!lKey.isEmpty()){
        temp= QString("%1\t%2").arg(lKey.front()). arg(info->value(lKey.front()));
        lKey.pop_front();
        textStream << temp;
    }
    file->close();
    return true;
}
Export::~Export()
{
    delete fileDialog;
    delete file;
}
