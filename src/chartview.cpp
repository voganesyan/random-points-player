#include "chartview.h"
#include <QtCharts/QScatterSeries>

ChartView::ChartView(QWidget *parent) :
    QChartView(new QChart(), parent)
{
    setRenderHint(QPainter::Antialiasing);
}


void ChartView::update(const QList<QPointF> &points)
{
    qDebug() << "Update";
    auto series = new QScatterSeries();
    series->setName("Random Points");
    series->append(points);
    chart()->removeAllSeries();
    chart()->addSeries(series);
    chart()->createDefaultAxes();
}


void ChartView::clear()
{
    chart()->removeAllSeries();
}
