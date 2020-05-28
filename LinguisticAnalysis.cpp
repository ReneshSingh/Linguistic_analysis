#include "LinguisticAnalysis.h"

LinguisticAnalysis::LinguisticAnalysis( ){
    ds.info = new QHash<QString, int>;
}
void LinguisticAnalysis::analysis(QString value){
    emmitMessage("Processing text ... ");
    temp = value;
    temp = temp.simplified();
    temp = temp.remove('.').remove(',').remove('"').remove(')').remove(";");
    temp = temp.remove('?').remove('!').remove('-').remove('(').remove(":");
    lKey = temp.split(' ',QString::SkipEmptyParts,Qt::CaseInsensitive);
    while(!lKey.isEmpty())
    {
        ds.info->insert(lKey.front(),ds.info->value(lKey.front(),0)+1);
        lKey.pop_front();
        ds.wordCount++;
    }
    emmitMessage("Text processed");
}
QString LinguisticAnalysis::results(QString value){
    QString result = "";
    if (value !=""){
        analysis(value);
    } else if (ds.info->isEmpty()){
        emmitMessage("No text has been processed yet.");
        return "";
    }
    lKey = ds.info->uniqueKeys();
    result = QString("Total words:\t%1\n Unique words:\t%2\n \n").arg(ds.wordCount).arg(ds.info->size());
    while (!lKey.isEmpty())
    {
        temp = QString("%1\t%2\n").arg(lKey.front()).arg(ds.info->value(lKey.front()));
        lKey.pop_front();
        result += temp;
    }
    ds.info->clear();
    return result;
}
void LinguisticAnalysis::clear(){
    ds.info->clear();
    ds.wordCount = 0;
    emmitMessage("Data cleared");
}
LinguisticAnalysis::~LinguisticAnalysis(){
    delete ds.info;
}
