#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QKeyEvent>
#include <QDebug>
#include <QtMath>

#define elif else if

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    qApp->installEventFilter(this);

    connect(ui->pushButton_0,SIGNAL(clicked()),this,SLOT(Changed()));
    connect(ui->pushButton_1,SIGNAL(clicked()),this,SLOT(Changed()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(Changed()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(Changed()));
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(Changed()));
    connect(ui->pushButton_5,SIGNAL(clicked()),this,SLOT(Changed()));
    connect(ui->pushButton_6,SIGNAL(clicked()),this,SLOT(Changed()));
    connect(ui->pushButton_7,SIGNAL(clicked()),this,SLOT(Changed()));
    connect(ui->pushButton_8,SIGNAL(clicked()),this,SLOT(Changed()));
    connect(ui->pushButton_9,SIGNAL(clicked()),this,SLOT(Changed()));
    connect(ui->pushButton_plus,SIGNAL(clicked()),this,SLOT(Changed()));
    connect(ui->pushButton_minus,SIGNAL(clicked()),this,SLOT(Changed()));
    connect(ui->pushButton_multiply,SIGNAL(clicked()),this,SLOT(Changed()));
    connect(ui->pushButton_divide,SIGNAL(clicked()),this,SLOT(Changed()));
    connect(ui->pushButton_extent,SIGNAL(clicked()),this,SLOT(Changed()));
    connect(ui->pushButton_root,SIGNAL(clicked()),this,SLOT(Changed()));
    connect(ui->pushButton_root_n,SIGNAL(clicked()),this,SLOT(Changed()));
    connect(ui->pushButton_log,SIGNAL(clicked()),this,SLOT(Changed()));
    connect(ui->pushButton_log_n,SIGNAL(clicked()),this,SLOT(Changed()));
    connect(ui->pushButton_ln,SIGNAL(clicked()),this,SLOT(Changed()));
    connect(ui->pushButton_clear_all,SIGNAL(clicked()),this,SLOT(Changed()));
    connect(ui->pushButton_clear_last,SIGNAL(clicked()),this,SLOT(Changed()));
    connect(ui->pushButton_result,SIGNAL(clicked()),this,SLOT(Changed()));
    connect(ui->pushButton_dot,SIGNAL(clicked()),this,SLOT(Changed()));

    ui->show_result->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);

    if(keyEvent->modifiers() & Qt::ShiftModifier && keyEvent->key() == Qt::Key_Z)
    {
          undo();
          return true;
    }

    if(event->type() == QEvent::KeyPress)
    {
        switch(keyEvent->key())
        {
        case Qt::Key_0:
            add_0();
            return true;

        case Qt::Key_1:
            add_1();
            return true;

        case Qt::Key_2:
            add_2();
            return true;

        case Qt::Key_3:
            add_3();
            return true;

        case Qt::Key_4:
            add_4();
            return true;

        case Qt::Key_5:
            add_5();
            return true;

        case Qt::Key_6:
            add_6();
            return true;

        case Qt::Key_7:
            add_7();
            return true;

        case Qt::Key_8:
            add_8();
            return true;

        case Qt::Key_9:
            add_9();
            return true;

        case Qt::Key_Plus:
            add_plus();
            return true;

        case Qt::Key_Minus:
            add_minus();
            return true;

        case Qt::Key_Asterisk:
            add_multiply();
            return true;

        case Qt::Key_Slash:
            add_divide();
            return true;  

        case Qt::Key_Equal:
            result();
            return true;

        case Qt::Key_Delete:
            clear_all();
            return true;

        case Qt::Key_Backspace:
            clear_last();
            return true;
        }
    }

    QObject::eventFilter(watched, event);

    return QMainWindow::eventFilter(watched, event);
}

void MainWindow::undo()
{
    for(int i = 0; i < str2.size(); i++)
    {
        str[i] = str2[i];
    }
    ui->result_window->setText(str);
}

void MainWindow::clear_all()
{
    str = "";
    str2 = "";
    str_f = "";

    point = true;
    oper = true;

    ui->show_result->setText("");
    ui->result_window->setText("");    

    ui->show_result->hide();
    ui->result_window->show();
}

void MainWindow::clear_last()
{
    str.chop(1);
    str_f.chop(1);
    ui->result_window->setText(str);
}

void MainWindow::result()
{   
    bool FoundOp = true;

    if(ui->result_window->text().isEmpty())   
        return;

    ui->show_result->show();
    ui->result_window->hide();

    double n1,n2,ans;

    if(str.contains('+'))
    {
        n1 = str.split("+")[0].toDouble();
        n2 = str.split("+")[1].toDouble();

        ans = n1+n2;
    }
    elif(str.contains('-'))
    {
        n1 = str.split("-")[0].toDouble();
        n2 = str.split("-")[1].toDouble();

        ans = n1-n2;
    }
    elif(str.contains('*'))
    {
        n1 = str.split("*")[0].toDouble();
        n2 = str.split("*")[1].toDouble();

        ans = n1*n2;
    }
    elif(str.contains("÷"))
    {
        n1 = str.split("÷")[0].toDouble();
        n2 = str.split("÷")[1].toDouble();

        if(n2 == 0) //!        
            ui->show_result->setText("Err");

        else ans = n1/n2;

    }
    elif(str.contains('^'))
    {
        n1 = str.split("^")[0].toDouble();
        n2 = str.split("^")[1].toDouble();

        ans = qPow(n1, n2);
    }
    elif(str.contains("√")) //!
    {
        n1 = str.split("√")[1].toDouble();

        if(n1 < 0)        
            ui->show_result->setText("Err");

        else ans = sqrt(n1);

    }
    elif(str.contains("sqrtn")) //!
    {
        n1 = str.split("sqrtn")[1].toDouble();
        n2 = str.split("sqrtn")[0].toDouble();

        if(n2 == 0)
            ui->show_result->setText("Err");


        if(fmod(n1, 2) == 0)
        {

            if(n1 < 0)           
                ui->show_result->setText("Err");

            else ans = qPow(n1, (1/n2));

        }
        else ans = qPow(n1, (1/n2));

    }
    elif(str.contains("log")) //!
    {
        n1 = str.split("log")[1].toDouble();

        if(n1 < 1)        
            ui->show_result->setText("Err");

        else ans = qLn(n1) / qLn(2);

    }
    elif(str.contains("lgn")) //!
    {
        n1 = str.split("lgn")[1].toDouble();
        n2 = str.split("lgn")[0].toDouble();

        if(n1 < 1)
            ui->show_result->setText("Err");

        elif(n2 < 0 && n2 == 1)
                ui->show_result->setText("Err");

        else ans = qLn(n1) / qLn(n2);

    }
    elif(str.contains("ln")) //!
    {
        n1 = str.split("ln")[1].toDouble();

        if(n1 < 1)
            ui->show_result->setText("Err");

        else ans = qLn(n1);
    }
    else FoundOp = false;

    if(FoundOp)
        ui->show_result->setText(QString::number(ans));
}

void MainWindow::Changed()
{
    str2 = str;

    QObject *obj;
    obj = sender();

    if(obj == ui->pushButton_clear_all) clear_all();

    elif(obj == ui->pushButton_clear_last) clear_last();

    elif(obj == ui->pushButton_result) result();

    else setText(obj);

    ui->result_window->setText(str_f);
}

void MainWindow::add_0()
{
    if(str.contains("sqrtn"))
    {
        str.push_front("0");
        str_f.push_front("0");
    }
    elif(str.contains("lgn"))
    {
        str.push_front("0");
        str_f.insert(3 ,"<sub>0</sub>");
    }
    elif(str.contains("^"))
    {
        str.push_back("0");
        str_f.push_back("<sup>0</sup>");
    }
    else
    {
        str.push_back("0");
        str_f.push_back("0");
    }
    ui->result_window->setText(str_f);
}

void MainWindow::add_1()
{
    if(str.contains("sqrtn"))
    {
        str.push_front("1");
        str_f.push_front("<sup>1</sup>");
    }
    elif(str.contains("lgn"))
    {
        str.push_front("1");
        str_f.insert(3 ,"<sub>1</sub>");
    }
    elif(str.contains("^"))
    {
        str.push_back("1");
        str_f.push_back("<sup>1</sup>");
    }
    else
    {
        str.push_back("1");
        str_f.push_back("1");
    }
    ui->result_window->setText(str_f);
}

void MainWindow::add_2()
{
    if(str.contains("sqrtn"))
    {
        str.push_front("2");
        str_f.push_front("<sup>2</sup>");
    }
    elif(str.contains("lgn"))
    {
        str.push_front("2");
        str_f.insert(3 ,"<sub>2</sub>");
    }
    elif(str.contains("^"))
    {
        str.push_back("2");
        str_f.push_back("<sup>2</sup>");
    }
    else
    {
        str.push_back("2");
        str_f.push_back("2");
    }
    ui->result_window->setText(str_f);
}

void MainWindow::add_3()
{
    if(str.contains("sqrtn"))
    {
        str.push_front("3");
        str_f.push_front("<sup>3</sup>");
    }
    elif(str.contains("lgn"))
    {
        str.push_front("3");
        str_f.insert(3 ,"<sub>3</sub>");
    }
    elif(str.contains("^"))
    {
        str.push_back("3");
        str_f.push_back("<sup>3</sup>");
    }
    else
    {
        str.push_back("3");
        str_f.push_back("3");
    }

    ui->result_window->setText(str_f);
}

void MainWindow::add_4()
{
    if(str.contains("sqrtn"))
    {
        str.push_front("4");
        str_f.push_front("<sup>4</sup>");
    }
    elif(str.contains("lgn"))
    {
        str.push_front("4");
        str_f.insert(3 ,"<sub>4</sub>");
    }
    elif(str.contains("^"))
    {
        str.push_back("4");
        str_f.push_back("<sup>4</sup>");
    }
    else
    {
        str.push_back("4");
        str_f.push_back("4");
    }
    ui->result_window->setText(str_f);
}

void MainWindow::add_5()
{
    if(str.contains("sqrtn"))
    {
        str.push_front("5");
        str_f.push_front("<sup>5</sup>");
    }
    elif(str.contains("lgn"))
    {
        str.push_front("5");
        str_f.insert(3 ,"<sub>5</sub>");
    }
    elif(str.contains("^"))
    {
        str.push_back("5");
        str_f.push_back("<sup>5</sup>");
    }
    else
    {
        str.push_back("5");
        str_f.push_back("5");
    }
    ui->result_window->setText(str_f);
}

void MainWindow::add_6()
{
    if(str.contains("sqrtn"))
    {
        str.push_front("6");
        str_f.push_front("<sup>6</sup>");
    }
    elif(str.contains("lgn"))
    {
        str.push_front("6");
        str_f.insert(3 ,"<sub>6</sub>");
    }
    elif(str.contains("^"))
    {
        str.push_back("6");
        str_f.push_back("<sup>6</sup>");
    }
    else
    {
        str.push_back("6");
        str_f.push_back("6");
    }
    ui->result_window->setText(str_f);
}

void MainWindow::add_7()
{
    if(str.contains("sqrtn"))
    {
        str.push_front("7");
        str_f.push_front("<sup>7</sup>");
    }
    elif(str.contains("lgn"))
    {
        str.push_front("7");
        str_f.insert(3 ,"<sub>7</sub>");
    }
    elif(str.contains("^"))
    {
        str.push_back("7");
        str_f.push_back("<sup>7</sup>");
    }
    else
    {
        str.push_back("7");
        str_f.push_back("7");
    }
    ui->result_window->setText(str_f);
}

void MainWindow::add_8()
{
    if(str.contains("sqrtn"))
    {
        str.push_front("8");
        str_f.push_front("<sup>8</sup>");
    }
    elif(str.contains("lgn"))
    {
        str.push_front("8");
        str_f.insert(3 ,"<sub>8</sub>");
    }
    elif(str.contains("^"))
    {
        str.push_back("8");
        str_f.push_back("<sup>8</sup>");
    }
    else
    {
        str.push_back("8");
        str_f.push_back("8");
    }
    ui->result_window->setText(str_f);
}

void MainWindow::add_9()
{
    if(str.contains("sqrtn"))
    {
        str.push_front("9");
        str_f.push_front("<sup>9</sup>");
    }
    elif(str.contains("lgn"))
    {
        str.push_front("9");
        str_f.insert(3 ,"<sub>9</sub>");
    }
    elif(str.contains("^"))
    {
        str.push_back("9");
        str_f.push_back("<sup>9</sup>");
    }
    else
    {
        str.push_back("9");
        str_f.push_back("9");
    }
    ui->result_window->setText(str_f);
}

void MainWindow::add_dot()
{
    if(str.contains("sqrtn"))
    {
        str.push_front(".");
        str_f.push_front("<sup>.</sup>");
    }
    elif(str.contains("lgn"))
    {
        str.push_front(".");
        str_f.insert(3 ,"<sub>.</sub>");
    }
    elif(str.contains("^"))
    {
        str.push_back(".");
        str_f.push_back("<sup>.</sup>");
    }
    else
    {
        str.push_back(".");
        str_f.push_back(".");
    }
    ui->result_window->setText(str_f);
}

void MainWindow::add_multiply()
{
    str.push_back("*");
    str_f.push_back("*");
}

void MainWindow::add_divide()
{
    str.push_back("÷");
    str_f.push_back("÷");
}

void MainWindow::add_plus()
{
    str.push_back("+");
    str_f.push_back("+");
}

void MainWindow::add_minus()
{
    str.push_back("-");
    str_f.push_back("-");
}

void MainWindow::add_extent()
{
    str.push_back("^");
}

void MainWindow::setText(QObject *obj)
{     
    if(obj == ui->pushButton_0) add_0();
    elif(obj == ui->pushButton_1) add_1();
    elif(obj == ui->pushButton_2) add_2();
    elif(obj == ui->pushButton_3) add_3();
    elif(obj == ui->pushButton_4) add_4();
    elif(obj == ui->pushButton_5) add_5();
    elif(obj == ui->pushButton_6) add_6();
    elif(obj == ui->pushButton_7) add_7();
    elif(obj == ui->pushButton_8) add_8();
    elif(obj == ui->pushButton_9) add_9();
    elif(obj == ui->pushButton_dot && point)
    {
        add_dot();
        point = false;
    }
    elif(obj == ui->pushButton_multiply && oper)
    {
        add_multiply();
        oper = false;
    }
    elif(obj == ui->pushButton_divide && oper)
    {
        add_divide();
        oper = false;
    }
    elif(obj == ui->pushButton_extent && oper)
    {
        add_extent();
        oper = false;
    }
    elif(obj == ui->pushButton_plus && oper)
    {
        add_plus();
        oper = false;
    }
    elif(obj == ui->pushButton_minus && oper)
    {
        add_minus();
        oper = false;
    }
    elif(obj == ui->pushButton_root && oper)
    {
        str.push_front("√");
        str_f.push_front("√");
        oper = false;
    }
    elif(obj == ui->pushButton_root_n && oper)
    {
        str.push_front("sqrtn");
        str_f.push_front("√");
        oper = false;
    }
    elif(obj == ui->pushButton_log && oper)
    {
        str.push_front("log");
        str_f.push_front("log<sub>2</sub>");
        oper = false;
    }
    elif(obj == ui->pushButton_log_n && oper)
    {
        str.push_front("lgn");
        str_f.push_front("log");
        oper = false;
    }
    elif(obj == ui->pushButton_ln && oper)
    {
        str.push_front("ln");
        str_f.push_front("ln");
        oper = false;
    }
}
