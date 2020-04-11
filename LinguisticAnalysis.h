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
    void analysis(QString value); /*! < \br Counts unique words in the provided text.
\Pram [in] value The text to be analysed. */
    QString results(QString value); /*! \brief Checks if there is any text to analyse, then roports on the recorded values.

\pram [in] value Text to be analysed.
\pram [out] Tab separated values in the order words then occurances.
 */
    void clear(); /*! \brief  Clears the data model. */
signals:
    void message(QString msg); /*! \brief clears the data set. */
private:
    QHash<QString, int> *info; //Data set.
    QString temp;
    QStringList lKey;
};

#endif // LINGUISTICANALYSIS_H
