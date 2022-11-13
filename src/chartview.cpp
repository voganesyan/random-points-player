#include "chartview.h"
#include <QtCharts/QScatterSeries>
#include <QValueAxis>

ChartView::ChartView(int max_value, QWidget *parent) :
    QChartView(new QChart(), parent)
{
    setRenderHint(QPainter::Antialiasing);

    auto axis_x = new QValueAxis();
    auto axis_y = new QValueAxis();
    axis_x->setMax(max_value);
    axis_y->setMax(max_value);
    chart()->addAxis(axis_x, Qt::AlignBottom);
    chart()->addAxis(axis_y, Qt::AlignLeft);
    chart()->legend()->hide();
}


void ChartView::update(const QList<QPointF> &points)
{
    qDebug() << "Update";
    auto series = new QScatterSeries();
    series->append(points);
    chart()->removeAllSeries();
    chart()->addSeries(series);
}


void ChartView::clear()
{
    chart()->removeAllSeries();
}
