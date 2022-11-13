#include "pointsgenerator.h"
#include <QMutexLocker>
#include <QDebug>

static const int LIST_SIZE = 10;
static const int MAX_NUM = 100;
static const int SLEEP_TIME_MS = 500;


void PointsGenerator::run()
{
    while (true) {
        msleep(SLEEP_TIME_MS);
        if (isInterruptionRequested()) {
            break;
        }
        if (is_paused) {
            continue;
        }
        QList<QPointF> points;
        for (int i = 0; i < LIST_SIZE; i++) {
            int x = std::rand() % MAX_NUM;
            int y = std::rand() % MAX_NUM;
            points << QPointF(x, y);
        }
        emit generated(points);

    }
    qDebug() << "Finish";
}


void PointsGenerator::pause()
{
    is_paused = true;
}


void PointsGenerator::resume()
{
    is_paused = false;
}

