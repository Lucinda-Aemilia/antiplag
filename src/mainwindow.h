#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include "antiplag.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_processButton_clicked();

    void on_resultButton_clicked();

    void on_quitButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
