#include "pointsgenerator.h"
#include <QMutexLocker>
#include <QDebug>

static const int LIST_SIZE = 10;
static const int SLEEP_TIME_MS = 500;


void PointsGenerator::run()
{
    while (true) {
        if (isInterruptionRequested()) {
            break;
        }
        if (!is_paused) {
            QList<QPointF> points;
            for (int i = 0; i < LIST_SIZE; i++) {
                int x = std::rand() % max_value;
                int y = std::rand() % max_value;
                points << QPointF(x, y);
            }
            emit generated(points);
        }
        msleep(SLEEP_TIME_MS);
    }
    is_paused = false;
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

