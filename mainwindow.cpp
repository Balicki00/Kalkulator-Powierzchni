#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cmath>
#include <iomanip>
#include <sstream>
#include <QFile>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    int selected = 0;
    int selected2 = 0;
    if(ui->radioButton->isChecked()){
        selected=0;
    }
    else if (ui->radioButton_2->isChecked()) {
        selected = 1;
}
else if (ui->radioButton_3->isChecked()) {
    selected = 2;
}
    else if (ui->radioButton_4->isChecked()) {
                selected=3;
    }


    if(ui->radioButton_5->isChecked()){
        selected2=0;
    }
    else if (ui->radioButton_6->isChecked()) {
        selected2 = 1;
}
else if (ui->radioButton_7->isChecked()) {
    selected2 = 2;
}
    else if (ui->radioButton_8->isChecked()) {
                selected2=3;
    }



QString s = ui->textEdit->toPlainText();
    double value = s.toDouble();

if(value<0){
    QMessageBox msgBox;
    msgBox.setWindowTitle("Błąd");
    msgBox.setText("Liczba musi być większa od 0");
    msgBox.exec();
    ui->textEdit->setText("");
}
else{
    std::string obiekty[4]= { "cale","mosty","jardy","stopy" };
        double ratio[4] = { 0.00065,2016,0.84,0.09};
        double result = Oblicz(ratio[selected], ratio[selected2], value);


         std::stringstream stream;
         stream << std::fixed << std::setprecision(2) << result;
         std::string resultString = stream.str();

         std::stringstream stream2;
         stream2 << std::fixed << std::setprecision(2) << value;
         std::string valueString = stream2.str();



         std::string stringResult =valueString +" " + obiekty[selected] +
                 "->" + obiekty[selected2] + " = " + resultString + "\n";


        QString res = QString::fromStdString(stringResult);
        ui->textEdit_2->append(res);
        ui->textEdit->setText("");
        QFile plik("result.txt");

        if (plik.open(QIODevice::WriteOnly | QIODevice::Append)) {
        QTextStream stream(&plik);
        stream<<res;

        }
    plik.close();


}

}


void MainWindow::on_pushButton_2_clicked()
{
    ui->textEdit->setText("");
    ui->textEdit_2->setText("");


}
double MainWindow::Oblicz(double ratio1, double ratio2, double value) {

    double result = (ratio1 * value) / ratio2;


    return result;
}
