#pragma once
#include <QThread>
#include <QPointF>

QT_USE_NAMESPACE

class PointsGenerator : public QThread
{
    Q_OBJECT
public:
    PointsGenerator(int max_value, QObject *parent = nullptr) :
        max_value(max_value), QThread(parent) {};
    void run() override;
    void pause();
    void resume();

signals:
    void generated(const QList<QPointF> &points);

protected:
    std::atomic_bool is_paused = false;
    int max_value;
};
