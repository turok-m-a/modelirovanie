#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


double MainWindow::getRand(){
    Rprev = (a * Rprev + c) % m;
    double next = (double) Rprev / m;
    return next;
}

double MainWindow::getRandY(){
    RprevY = (a2 * RprevY + c2) % m2;
    double next = (double) RprevY / m2;
    return next;
}

double MainWindow::sumOfRand(int n){
    double sum =0 ;
    for(int i=0;i<n;i++){
        sum+=getRand();
    }
    return sum;
}

double MainWindow::mulOfRand(int n){
    double sum =1 ;
    for(int i=0;i<n;i++){
        sum*=getRand();
    }
    return sum;
}
void MainWindow::on_generateButton_clicked()
{
    unsigned period=0;
    bool ok1,ok2,ok3;
    a = ui->A->text().toInt(&ok1);
    m = ui->M->text().toInt(&ok2);
    c = ui->C->text().toInt(&ok3);
    if (!(ok1&&ok2&&ok3)) return;
    double first,next;
    period = 0;
    QVector<double> randomArray;
    randomArray.clear();
    //Rprev = (a * Rprev + c) % m;
    //first = (double) Rprev / m;
    randomArray.append(first);
    cout << first << endl;
    do {
        if  (ui->normal->isChecked()){
        Rprev = (a * Rprev + c) % m;
        next = (double) Rprev / m;
        }
        cout << next << endl;
        if (ui->gauss->isChecked()){
            next = 0.5 + 0.05*sqrt(2.0)*(sumOfRand(6)-3);
        }
        if (ui->exp->isChecked()){
            double lambda = ui->lambda->text().toDouble(&ok1);
            if(ok1){
                next = log(getRand())/(-lambda);
            }
        }
        if (ui->gamma->isChecked()){
            next = log(mulOfRand(2))/(-10);
        }
        if (ui->simp->isChecked()){
            next = getRand()/2 + (getRandY()/2);
        }
        randomArray.append(next);
        period++;
    } while (period<10000);
    cout <<period <<endl;
    StatOperations stats(randomArray);
    cout <<stats.mean() <<endl;
    cout <<stats.variance() <<endl;
    ////////
    QVector<double> histogrammData(60),x(60);

    for (int i=0;i<60;i++){
        x[i]=i;
        histogrammData[i]=0;
    }

    int maxY = 0;
    cout << "size "<< randomArray.size()<<endl;
    for (int i=0;i<randomArray.size()-2;i++){
        int interval = ((int)(randomArray[i]*100))/5;
        if (interval >= 20 || interval < 0) continue;
//        if (interval==20) {
//            interval=19;                            // 1.0 попадает в последний интервал
//        }
        histogrammData[interval*3+1]++;
    }
    for (int i=0;i<60;i++){
        if(histogrammData[i]>maxY){
            maxY=histogrammData[i];
        }
    }
    ui->histogramm->clearGraphs();
    ui->histogramm->addGraph();
    ui->histogramm->xAxis->setRange(0,59);
    ui->histogramm->yAxis->setRange(0,maxY);
    ui->histogramm->graph(0)->setData(x,histogrammData);
    ui->histogramm->replot();

    double kPar = 0;
    for(int i=0;i<randomArray.size()-2;i+=2){
        if(pow(randomArray[i],2)+pow(randomArray[i+1],2) < 1) {
            kPar++;
        }
    }
    cout << kPar/(randomArray.size()/2) <<endl;
    cout << M_PI/4 <<endl;

    ui->lineEdit->setText(QString::number((double)period));
    ui->mean->setText(QString::number(stats.mean()));
    ui->variation->setText(QString::number(stats.variance()));
    ui->sko->setText(QString::number(sqrt(stats.variance())));
    ui->kn2->setText(QString::number(kPar/(randomArray.size()/2)));
}

