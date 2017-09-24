#include "statoperations.h"

StatOperations::StatOperations()
{

}
StatOperations::StatOperations(QVector<double> a)
{
    r=a;
}
double StatOperations::mean(){
    int n = r.size();
    double sum = 0;
    for (int i=0;i<n;i++){
        long double tmp = ((int)(r[i] * 1000000000.0 )) / 1000000000.0;
        sum+=tmp;
    }
    return sum/(double)n;
}

double StatOperations::variance(){
    long double sum=0;
    int n = r.size();
    double meanSqr = pow(mean(),2);
    for (int i=0;i<n;i++){
        double tmp = ((int)(r[i] * 1000000000.0 )) / 1000000000.0;
        sum+=pow(tmp,2)-meanSqr;
    }
    return sum/((double)n-1); //несмещенная оценка
}
