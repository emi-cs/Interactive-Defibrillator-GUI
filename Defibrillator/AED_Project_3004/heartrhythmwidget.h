#ifndef HEARTRHYTHMWIDGET_H
#define HEARTRHYTHMWIDGET_H

#include <QWidget>
#include <QTimer>
#include <QLabel>

class HeartRhythmWidget : public QWidget
{
    Q_OBJECT

public:
    explicit HeartRhythmWidget(QWidget *parent = nullptr);
    ~HeartRhythmWidget() override;
    void setRhythm(int rhythm);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    QTimer *timer;
    int currentRhythm;
    float phase;

    // These methods are private as they are only called internally in paintEvent
    void drawNormalRhythm(QPainter &painter);
    void drawVFibRhythm(QPainter &painter);
    void drawVTachRhythm(QPainter &painter);
    void drawAsystoleRhythm(QPainter &painter);
    void clear(QPainter &painter);
};

#endif // HEARTRHYTHMWIDGET_H
