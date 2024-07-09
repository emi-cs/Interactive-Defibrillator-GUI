#include "heartrhythmwidget.h"
#include <QPainter>
#include <QPainterPath>
#include <cmath>

HeartRhythmWidget::HeartRhythmWidget(QWidget *parent)
    : QWidget(parent), currentRhythm(0), phase(0.0f)
{
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, QOverload<>::of(&QWidget::update));
    timer->start(1000);
}

HeartRhythmWidget::~HeartRhythmWidget()
{
    delete timer;
}

void HeartRhythmWidget::setRhythm(int rhythm)
{
    currentRhythm = rhythm;
    update();
}

void HeartRhythmWidget::drawNormalRhythm(QPainter &painter)
{
    QPainterPath path;
    int midY = height() / 2;
    int amplitude = 25;
    int waveLength = 4 * amplitude;

    int startX = -(static_cast<int>(phase) % waveLength);

    path.moveTo(startX, midY);

    for (int x = startX; x < width() + waveLength; x += waveLength) {
        path.quadTo(x + amplitude, midY - amplitude, x + 2*amplitude, midY);
        path.quadTo(x + 3*amplitude, midY + amplitude, x + 4*amplitude, midY);
    }

    QPen pen(Qt::green, 2);
    painter.setPen(pen);
    painter.drawPath(path);
}
void HeartRhythmWidget::drawVFibRhythm(QPainter &painter)
{
    QPainterPath path;
    int midY = height() / 2;
    int minAmplitude = 10;
    int maxAmplitude = 30;
    int stepSize = 10;

    int startX = static_cast<int>(phase) % stepSize;

    path.moveTo(startX, midY);

    for (int x = startX; x < width() + stepSize; x += stepSize) {
        int y = midY + (rand() %(maxAmplitude - minAmplitude + 1) + minAmplitude) * (rand() % 2 == 0 ? 1 : -1);
        path.lineTo(x, y);
    }

    QPen pen(Qt::red, 2);
    painter.setPen(pen);
    painter.drawPath(path);
}



void HeartRhythmWidget::drawVTachRhythm(QPainter &painter)
{
    QPainterPath path;
    int stepSize = 30;
    int midY = height() / 2;
    int spikeHeight = 25;

    int startX = static_cast<int>(phase) % stepSize;

    path.moveTo(startX, midY);

    bool goingUp = true;
    for (int x = startX; x < width() + stepSize; x += stepSize / 2) {
        int nextY = goingUp ? midY - spikeHeight : midY + spikeHeight;
        path.lineTo(x, nextY);
        goingUp = !goingUp;
    }

    QPen pen(Qt::red, 2);
    painter.setPen(pen);
    painter.drawPath(path);
}


void HeartRhythmWidget::drawAsystoleRhythm(QPainter &painter)
{
    painter.drawLine(0, height() / 2, width(), height() / 2);

}

void HeartRhythmWidget::clear(QPainter &painter)
{
    painter.setBrush(Qt::white);
    painter.setPen(Qt::NoPen);
    painter.drawRect(rect());
}


void HeartRhythmWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    switch (currentRhythm) {
        case 3:
            drawNormalRhythm(painter);
            break;
        case 0:
            drawVFibRhythm(painter);
            break;
        case 1:
            drawVTachRhythm(painter);
            break;
        case 2:
            drawAsystoleRhythm(painter);
            break;
        case 4:
            clear(painter);
    }

    phase += 20;
}
