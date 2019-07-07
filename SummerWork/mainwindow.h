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

    QString str, str1;
    bool formatFlag = false;
    void setText(QObject *);

private:
    Ui::MainWindow *ui;
    bool eventFilter(QObject *, QEvent *);

private slots:
    void Changed();
    void clear_last();
    void clear_all();
    void result();
};

#endif // MAINWINDOW_H
