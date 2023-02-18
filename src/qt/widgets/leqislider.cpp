#include "leqislider.h"
#include "constants.h"

#include <QMouseEvent>
#include <QCursor>
#include <QMessageBox>
#include <QApplication>

LeqiSlider::LeqiSlider(QWidget *parent)
    : QSlider(parent)
{
    initial();
}

LeqiSlider::~LeqiSlider()
{}

void LeqiSlider::enterEvent(QEnterEvent *event)
{
    setStyleSheet(SS_SLIDER_ENTER);
}

void LeqiSlider::leaveEvent(QEvent *event)
{
    setStyleSheet(SS_SLIDER_LEAVE);
}

void LeqiSlider::mousePressEvent(QMouseEvent *event)
{
    switch (event->button()) {
    case Qt::LeftButton:
    {
        int currentX = event->pos().x();
        qreal per = currentX * 1.0 / width();
        int value = per * (maximum() - minimum()) + minimum();
        setValue(value);
        emit seekPosition(value);
        event->accept();
    }
        break;
    default:
        QSlider::mousePressEvent(event);
        break;
    }
}

void LeqiSlider::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Right:
        QApplication::setActiveWindow(this);
        setFocus();
        emit forwardFive();
        event->accept();
        break;
    case Qt::Key_Left:
        QApplication::setActiveWindow(this);
        setFocus();
        emit backwardFive();
        event->accept();
        break;
    case Qt::Key_Up:
    case Qt::Key_Down:
        break;
    default:
        QSlider::keyPressEvent(event);
        break;
    }
}

void LeqiSlider::initial()
{
    setOrientation(Qt::Horizontal);
}
