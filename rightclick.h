#ifndef RIGHTCLICK_H
#define RIGHTCLICK_H

#include <QPushButton>
#include <QMouseEvent>
class QRightClickButton : public QPushButton
{
    Q_OBJECT

public:
    explicit QRightClickButton(QWidget *parent = 0);


private slots:
    void mousePressEvent(QMouseEvent *e);

signals:
    void rightClicked();
};

#endif // RIGHTCLICK_H
