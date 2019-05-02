#include "projectx.h"

ProjectX::ProjectX( ){
    submit = new QPushButton("Submit for analysis");
    info = new QHash<QString, int>;
    report = new QPushButton("Analysis and report");
    quit = new QPushButton("Quit");
    edit = new QTextEdit();
    edit->setPlaceholderText("Enter text for analysis here. Click'Submit for analysis' for multiple tex analysis.");
    vlayout = new QVBoxLayout;
    hlayout = new QHBoxLayout;
    edit->setFontPointSize(14);
    hlayout->addWidget(submit);
    hlayout->addWidget(quit);
    hlayout->addWidget(report);
    vlayout->addWidget(edit);
    vlayout->addLayout(hlayout);
    setLayout(vlayout);
    show();
}
void ProjectX::analysis(){
    temp = edit->toPlainText().toLower();
    temp = temp.simplified();
    temp = temp.remove('.').remove(',').remove('"').remove(')').remove(";");
    temp = temp.remove('?').remove('!').remove('-').remove('(').remove(":");
    lKey = temp.split(' ',QString::SkipEmptyParts,Qt::CaseInsensitive);
    while(!lKey.isEmpty()){
        info->insert(lKey.front(),info->value(lKey.front(),0)+1);
        lKey.pop_front();
    }
    edit->clear();
}
void ProjectX::results(){
    if (edit->toPlainText()!=""){
        analysis();
        edit->clear();
    }
    lKey =info->uniqueKeys();
    while (!lKey.isEmpty()){
        temp= QString("%1\t%2").arg(lKey.front()). arg(info->value(lKey.front()));
        lKey.pop_front();
        edit->append(temp);
    }
    info->clear();
}
ProjectX::~ProjectX(){
    delete submit;
    delete report;
    delete quit;
    delete edit;
    delete vlayout;
    delete hlayout;
    delete info;
}
