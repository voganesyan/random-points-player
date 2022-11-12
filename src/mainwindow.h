#pragma once
#include <QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);

private slots:
    void on_play_button_clicked();
    void on_pause_button_clicked();
    void on_stop_button_clicked();
};
