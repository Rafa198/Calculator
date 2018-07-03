#include "mainwindow.h"
#include "ui_mainwindow.h"


double num_first;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_0,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_1,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_5,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_6,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_7,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_8,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_9,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_plus_minus,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_procent,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_minus,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_plus,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_slash,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_x,SIGNAL(clicked()),this,SLOT(math_operations()));
    ui->pushButton_x->setCheckable(true);
    ui->pushButton_minus->setCheckable(true);
    ui->pushButton_plus->setCheckable(true);
    ui->pushButton_slash->setCheckable(true);
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::digits_numbers()
{
    QPushButton *button = (QPushButton *)sender();
    double all_numbers;
    QString new_label;

    if(ui->reult_show->text().contains(".")&&button->text()=="0")
    {
        new_label=ui->reult_show->text()+ button->text();
    } else
    {
    all_numbers=(ui->reult_show->text()+ button->text()).toDouble();
  new_label = QString::number(all_numbers,'g',15);
    }
    ui->reult_show->setText(new_label);

}

void MainWindow::on_pushButton_dot_clicked()
{
    if(!(ui->reult_show->text().contains('.')))
    ui->reult_show->setText(ui->reult_show->text()+".");
}
void MainWindow::operations()
{
    QPushButton *button = (QPushButton *)sender();
    double all_numbers;
    QString new_label;
    if(button->text()=="+/-")
    {
    all_numbers=(ui->reult_show->text()).toDouble();
    all_numbers*=(-1);
  new_label = QString::number(all_numbers,'g',15);
    ui->reult_show->setText(new_label);

    }else if(button->text()=="%")
    {
    all_numbers=(ui->reult_show->text()).toDouble();
    all_numbers*=0.01;
  new_label = QString::number(all_numbers,'g',15);
    ui->reult_show->setText(new_label);

    }
}

void MainWindow::on_pushButton_ac_clicked()
{
  ui->pushButton_plus->setChecked(false);
  ui->pushButton_minus->setChecked(false);
  ui->pushButton_x->setChecked(false);
  ui->pushButton_slash->setChecked(false);
  ui->reult_show->setText("0");
}

void MainWindow::on_pushButton_result_clicked()
{
    double labelNumber,num_second;
    QString new_label;

    num_second = ui->reult_show->text().toDouble();


    if(ui->pushButton_plus->isChecked())
    {
        labelNumber = num_first + num_second;
        new_label = QString::number(labelNumber,'g',15);
        ui->reult_show->setText(new_label);
        ui->pushButton_plus->setChecked(false);

    } else if(ui->pushButton_minus->isChecked())
    {
        labelNumber = num_first - num_second;
        new_label = QString::number(labelNumber,'g',15);
        ui->reult_show->setText(new_label);
        ui->pushButton_minus->setChecked(false);
    } else if(ui->pushButton_slash->isChecked())
    {
       if(num_second==0)
       {
           ui->reult_show->setText("0");
       }
       else
        labelNumber = num_first / num_second;
        new_label = QString::number(labelNumber,'g',15);
        ui->reult_show->setText(new_label);
        ui->pushButton_slash->setChecked(false);
    } else if(ui->pushButton_x->isChecked())
    {
        labelNumber = num_first * num_second;
        new_label = QString::number(labelNumber,'g',15);
        ui->reult_show->setText(new_label);
        ui->pushButton_x->setChecked(false);
    }
}
void MainWindow::math_operations()
{
     QPushButton *button = (QPushButton *)sender();

     num_first= ui->reult_show->text().toDouble();
     ui->reult_show->setText("");

     button->setChecked(true);

}
