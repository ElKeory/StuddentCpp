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
    str = ui->result_window->text();

    if(event->type() == QEvent::KeyPress)
    {
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);

        switch(keyEvent->key())
        {
        case Qt::Key_0:
            str.push_back("0");
            ui->result_window->setText(str);
            return true;

        case Qt::Key_1:
            str.push_back("1");
            ui->result_window->setText(str);
            return true;

        case Qt::Key_2:
            str.push_back("2");
            ui->result_window->setText(str);
            return true;

        case Qt::Key_3:
            str.push_back("3");
            ui->result_window->setText(str);
            return true;

        case Qt::Key_4:
            str.push_back("4");
            ui->result_window->setText(str);
            return true;

        case Qt::Key_5:
            str.push_back("5");
            ui->result_window->setText(str);
            return true;

        case Qt::Key_6:
            str.push_back("6");
            ui->result_window->setText(str);
            return true;

        case Qt::Key_7:
            str.push_back("7");
            ui->result_window->setText(str);
            return true;

        case Qt::Key_8:
            str.push_back("8");
            ui->result_window->setText(str);
            return true;

        case Qt::Key_9:
            str.push_back("9");
            ui->result_window->setText(str);
            return true;

        case Qt::Key_Plus:
            str.push_back("+");
            ui->result_window->setText(str);
            return true;

        case Qt::Key_Minus:
            str.push_back("-");
            ui->result_window->setText(str);
            return true;

        case Qt::Key_multiply: //!
            str.push_back("*");
            ui->result_window->setText(str);
            return true;

        case Qt::Key_division: //!
            str.push_back("÷");
            ui->result_window->setText(str);
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

        default:
            return true;
        }
    }

    QObject::eventFilter(watched, event);

    return QMainWindow::eventFilter(watched, event);
}

void MainWindow::clear_all()
{
    formatFlag = false;

    str = "";

    ui->result_window->setText("");
    ui->show_result->setText("");

    ui->show_result->hide();
    ui->result_window->show();
}

void MainWindow::clear_last()
{
    str.truncate(str.length() - 1);
    ui->result_window->setText(str);
}

void MainWindow::result()
{
    bool FoundOp = true;

    if(ui->result_window->text().isEmpty())
    {
        return;
    }

    ui->show_result->show();
    ui->result_window->hide();

    formatFlag = true;

    double n1,n2,ans;

    str = ui->result_window->text();

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
        {
            ui->show_result->setText("Err");
        }
        else
        {
            ans = n1/n2;
        }
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
        {
            ui->show_result->setText("Err");
        }
        else
        {
            ans = sqrt(n1);
        }
    }
    elif(str.contains("sqrtn")) //!
    {
        n1 = str.split("sqrtn")[1].toDouble();
        n2 = str.split("sqrtn")[0].toDouble();

        if(n2 == 0)
        {
            ui->show_result->setText("Err");
        }

        if(fmod(n1, 2) == 0)
        {

            if(n1 < 0)
            {
                ui->show_result->setText("Err");
            }
            else
            {
                ans = qPow(n1, (1/n2));
            }
        }
        else
        {
            ans = qPow(n1, (1/n2));
        }
    }
    elif(str.contains("log")) //!
    {
        n1 = str.split("log")[1].toDouble();

        if(n1 < 1)
        {
            ui->show_result->setText("Err");
        }
        else
        {
            ans = qLn(n1) / qLn(2);
        }
    }
    elif(str.contains("lgn")) //!
    {
        n1 = str.split("lgn")[1].toDouble();
        n2 = str.split("lgn")[0].toDouble();

        if(n1 < 1)
        {
            ui->show_result->setText("Err");
        }
        elif(n2 < 0 && n2 == 1)
        {
            ui->show_result->setText("Err");
        }
        else
        {
            ans = qLn(n1) / qLn(n2);
        }
    }
    elif(str.contains("ln")) //!
    {
        n1 = str.split("ln")[1].toDouble();

        if(n1 < 1)
        {
            ui->show_result->setText("Err");
        }
        else
        {
            ans = qLn(n1);
        }
    }
    else
    {
        FoundOp = false;
    }
    if(FoundOp)
    {
        ui->show_result->setText(QString::number(ans));
    }
    else
    {
        ui->show_result->setText(str);
    }
}

void MainWindow::Changed()
{
    str = ui->result_window->text();

    QObject *obj;
    obj = sender();

    if(obj == ui->pushButton_clear_all)
    {
        clear_all();
    }
    elif(obj == ui->pushButton_clear_last)
    {
        clear_last();
    }
    elif(obj == ui->pushButton_result)
    {
        result();
    }
    elif(obj == ui->pushButton_dot)
    {
        str.push_back(".");
    }
    else
    {
        setText(obj);
    }

    ui->result_window->setText(str);
}

void MainWindow::setText(QObject *obj)
{
    if(obj == ui->pushButton_0)
    {
        if(str.contains("sqrtn") || str.contains("lgn"))
        {
            str.push_front("0");
        }
        else
        {
            str.push_back("0");
        }
    }
    elif(obj == ui->pushButton_1)
    {
        if(str.contains("sqrtn") || str.contains("lgn"))
        {
            str.push_front("1");
        }
        else
        {
            str.push_back("1");
        }
    }
    elif(obj == ui->pushButton_2)
    {
        if(str.contains("sqrtn") || str.contains("lgn"))
        {
            str.push_front("2");
        }
        else
        {
            str.push_back("2");
        }
    }
    elif(obj == ui->pushButton_3)
    {
        if(str.contains("sqrtn") || str.contains("lgn"))
        {
            str.push_front("3");
        }
        else
        {
            str.push_back("3");
        }
    }
    elif(obj == ui->pushButton_4)
    {
        if(str.contains("sqrtn") || str.contains("lgn"))
        {
            str.push_front("4");
        }
        else
        {
            str.push_back("4");
        }
    }
    elif(obj == ui->pushButton_5)
    {
        if(str.contains("sqrtn") || str.contains("lgn"))
        {
            str.push_front("5");
        }
        else
        {
            str.push_back("5");
        }
    }
    elif(obj == ui->pushButton_6)
    {
        if(str.contains("sqrtn") || str.contains("lgn"))
        {
            str.push_front("6");
        }
        else
        {
            str.push_back("6");
        }
    }
    elif(obj == ui->pushButton_7)
    {
        if(str.contains("sqrtn") || str.contains("lgn"))
        {
            str.push_front("7");
        }
        else
        {
            str.push_back("7");
        }
    }
    elif(obj == ui->pushButton_8)
    {
        if(str.contains("sqrtn") || str.contains("lgn"))
        {
            str.push_front("8");
        }
        else
        {
            str.push_back("8");
        }
    }
    elif(obj == ui->pushButton_9)
    {
        if(str.contains("sqrtn") || str.contains("lgn"))
        {
            str.push_front("9");
        }
        else
        {
            str.push_back("9");
        }
    }
    elif(obj == ui->pushButton_multiply)
    {
        str.push_back("*");
    }
    elif(obj == ui->pushButton_divide)
    {
        str.push_back("÷");;
    }
    elif(obj == ui->pushButton_extent)
    {
        str.push_back("^");
    }
    elif(obj == ui->pushButton_plus)
    {
        str.push_back("+");
    }
    elif(obj == ui->pushButton_minus)
    {
        str.push_back("-");
    }
    elif(obj == ui->pushButton_root)
    {
        str.push_front("√");
    }
    elif(obj == ui->pushButton_root_n)
    {
        str.push_front("sqrtn");
    }
    elif(obj == ui->pushButton_log)
    {
        str.push_front("log");
    }
    elif(obj == ui->pushButton_log_n)
    {
        str.push_front("lgn");
    }
    elif(obj == ui->pushButton_ln)
    {
        str.push_front("ln");
    }
}
