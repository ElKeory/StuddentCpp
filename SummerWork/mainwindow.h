#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QString str, str_f, str2;
    bool e, point = true, oper = true;

private:
    Ui::MainWindow *ui;
    void setText(QObject *);
    bool eventFilter(QObject *, QEvent *);

private slots:
    void Changed();
    void clear_last();
    void clear_all();
    void result();
    void add_0();
    void add_1();
    void add_2();
    void add_3();
    void add_4();
    void add_5();
    void add_6();
    void add_7();
    void add_8();
    void add_9();
    void add_dot();
    void add_multiply();
    void add_divide();
    void add_plus();
    void add_minus();
    void add_extent();
    void undo();
};

#endif // MAINWINDOW_H
