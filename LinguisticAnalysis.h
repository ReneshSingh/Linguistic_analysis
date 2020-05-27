#ifndef LINGUISTICANALYSIS_H
#define LINGUISTICANALYSIS_H

#include <QObject>
#include <QString>
#include <QHash>

/*! \namespace Linguistic Analysis Tools
 * \brief A collection of tools used to perform the analysis
 */
namespace LinguisticAnalysis_Tools
{
class LinguisticAnalysis;
}

/*! \clas Linguistic Analysis
 * \brief Determines the frequencies of unique word in a text.
 *
 * Provides functions to count the number of unique words in a text, and provides functions to manage that data. */
class LinguisticAnalysis : public QObject
{
    Q_OBJECT
public:
    explicit LinguisticAnalysis();
    ~LinguisticAnalysis();
    void analysis(QString value); //!< \brief Counts unique words in the provided text.
    QString results(QString value); //!< \brief Checks if there is any text to analyse, then reports on the recorded values.
    void clear(); //!< \brief Clears the data model.
signals:
    void emmitMessage(QString msg); //!< \brief Publishes messages from this class to the event stream in the msg value.
private:
    QHash<QString, int> *info; //Data set.
    QString temp;
    QStringList lKey;
};

#endif // LINGUISTICANALYSIS_H
