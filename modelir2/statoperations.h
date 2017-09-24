#ifndef STATOPERATIONS_H
#define STATOPERATIONS_H
#include <QVector>

class StatOperations
{
public:
    StatOperations();
    StatOperations(QVector<double> a);
    QVector<double> r;
    double mean();
    double variance();
};

#endif // STATOPERATIONS_H
