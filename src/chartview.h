#pragma once
#include <QtCharts/QChartView>

QT_USE_NAMESPACE

class ChartView : public QChartView
{
    Q_OBJECT
public:
    ChartView(QWidget *parent = nullptr);
};
