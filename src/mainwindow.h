#pragma once
#include <QMainWindow>

class PointsGenerator;
class ChartView;
class QPushButton;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);

private slots:
    void on_play_button_clicked();
    void on_pause_button_clicked();
    void on_stop_button_clicked();

private:
    PointsGenerator *points_generator = nullptr;
    ChartView *chart_view = nullptr;
    QPushButton *play_button = nullptr;
    QPushButton *pause_button = nullptr;
    QPushButton *stop_button = nullptr;
};
