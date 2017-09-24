#include "statoperations.h"

StatOperations::StatOperations()
{

}
StatOperations::StatOperations(QVector<double> a)
{
    r=a;
}
double StatOperations::mean(){
    int n = r.length();
    double sum = 0;
    for (int i=0;i<n;i++){
        sum+=r[i];
    }
    return sum/(double)n;
}

double StatOperations::variance(){
    double sum=0;
    int n = r.length();
    double meanSqr = pow(mean(),2);
    for (int i=0;i<n;i++){
        sum+=pow(r[i],2)-meanSqr;
    }
    return sum/((double)n-1); //несмещенная оценка
}
