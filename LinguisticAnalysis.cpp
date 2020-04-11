#include "LinguisticAnalysis.h"

LinguisticAnalysis::LinguisticAnalysis( ){
    info = new QHash<QString, int>;
}
void LinguisticAnalysis::analysis(QString value){
    message("Processing text");
    temp = value;
    temp = temp.simplified();
    temp = temp.remove('.').remove(',').remove('"').remove(')').remove(";");
    temp = temp.remove('?').remove('!').remove('-').remove('(').remove(":");
    lKey = temp.split(' ',QString::SkipEmptyParts,Qt::CaseInsensitive);
    while(!lKey.isEmpty()){
        info->insert(lKey.front(),info->value(lKey.front(),0)+1);
        lKey.pop_front();
    }
    message("Text processed");
}
QString LinguisticAnalysis::results(QString value){
    QString result = "";
    if (value !=""){
        analysis(value);
    }
    lKey =info->uniqueKeys();
    while (!lKey.isEmpty()){
        temp = QString("%1\t%2\n").arg(lKey.front()). arg(info->value(lKey.front()));
        lKey.pop_front();
        result += temp;
    }
    info->clear();
    return result;
}
void LinguisticAnalysis::clear(){
    info->clear();
    message("Data cleared");
}
LinguisticAnalysis::~LinguisticAnalysis(){
    delete info;
}
