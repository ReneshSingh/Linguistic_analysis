#ifndef LINGUISTICANALYSIS_H
#define LINGUISTICANALYSIS_H

#include <QWidget>
#include <QString>
#include <QHash>

/*! \clas LinguisticAnalysis
 * \brief Determins the frequencies of unique word in a text.
 *
 * Provides functions to count the number of unique words in a text, and provides functions to manage that data. */

class LinguisticAnalysis : public QWidget
{
    Q_OBJECT
public:
    explicit LinguisticAnalysis();
    ~LinguisticAnalysis();
    void analysis(QString value); // Counts unique words in the provided text.
    QString results(QString value); // Checks if there is any text to analyse, then roports on the recorded values.
    void clear(); // Clears the data model.
signals:
    void emmitMessage(QString msg); //clears the data set.
private:
    QHash<QString, int> *info; //Data set.
    QString temp;
    QStringList lKey;
};

#endif // LINGUISTICANALYSIS_H
