#include "mainwindow.h"
#include "chartview.h"
#include "pointsgenerator.h"
#include <QPushButton>
#include <QLayout>
#include <QStyle>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // Create widgets
    auto chart_view = new ChartView();
    auto play_button = new QPushButton();
    auto pause_button = new QPushButton();
    auto stop_button = new QPushButton();
    play_button->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
    pause_button->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
    stop_button->setIcon(style()->standardIcon(QStyle::SP_MediaStop));
    connect(play_button, &QPushButton::clicked, this, &MainWindow::on_play_button_clicked);
    connect(pause_button, &QPushButton::clicked, this, &MainWindow::on_pause_button_clicked);
    connect(stop_button, &QPushButton::clicked, this, &MainWindow::on_stop_button_clicked);
    connect(stop_button, &QPushButton::clicked, chart_view, &ChartView::clear);

    // Add widgets to the window
    auto buttons_layout = new QHBoxLayout();
    buttons_layout->addWidget(play_button);
    buttons_layout->addWidget(pause_button);
    buttons_layout->addWidget(stop_button);
    buttons_layout->addStretch();

    auto main_layout = new QVBoxLayout();
    main_layout->addWidget(chart_view);
    main_layout->addLayout(buttons_layout);

    auto main_widget = new QWidget();
    main_widget->setLayout(main_layout);
    setCentralWidget(main_widget);

    // Create a points generating thread
    points_generator = new PointsGenerator(this);
    connect(points_generator, &PointsGenerator::generated, chart_view, &ChartView::update);
}


void MainWindow::on_play_button_clicked()
{
    qDebug() << "Play";
    if (points_generator->isRunning()) {
        points_generator->resume();
    } else {
        points_generator->start();
    }
}


void MainWindow::on_pause_button_clicked()
{
    qDebug() << "Pause";
    points_generator->pause();
}


void MainWindow::on_stop_button_clicked()
{
    qDebug() << "Stop";
    points_generator->quit();
    points_generator->requestInterruption();
    points_generator->wait();
}
