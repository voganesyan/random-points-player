#include "chartview.h"
#include <QtCharts/QScatterSeries>

ChartView::ChartView(QWidget *parent) :
    QChartView(new QChart(), parent)
{
    QList<QPointF> points = {{2, 4}, {3, 8}, {7, 4}};

    auto series = new QScatterSeries();
    series->setName("Random Points");
    series->append(points);

    setRenderHint(QPainter::Antialiasing);
    chart()->addSeries(series);
    chart()->createDefaultAxes();
}

