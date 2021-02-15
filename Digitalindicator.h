//******************************************************************************
#ifndef DIGITALINDICATOR_H
#define DIGITALINDICATOR_H
//******************************************************************************
#include <QLabel>
#include <QGridLayout>
#include <QPainter>
#include <QTimer>
#include <QTime>
//******************************************************************************

class DigitalIndicator: public QLabel
{
    Q_OBJECT
public:
    DigitalIndicator();
    void SetIndicatorBackLEDColor(QColor Color);

public slots:
    void SetValue(long long Variable);
    void painterIndicator(QColor Color);
protected:
    void resizeEvent(QResizeEvent *);
    void paintEvent(QResizeEvent *);
private slots:

private:
    QLabel *Label_Indicator;
    QGridLayout *GridLayout_Indicator;
    QColor IndicatorColor, IndicatorBackLEDColor, IndicatorError;
    long long Variable;
    long long saveVariable;
    QList <QRect> TargetObjects;
    bool flagMinus;

    QPixmap Pixmap;
    QPixmap PixmapIn;
    QPixmap Pixmap_zero;
    QPixmap Pixmap_one;
    QPixmap Pixmap_two;
    QPixmap Pixmap_three;
    QPixmap Pixmap_four;
    QPixmap Pixmap_five;
    QPixmap Pixmap_six;
    QPixmap Pixmap_seven;
    QPixmap Pixmap_eight;
    QPixmap Pixmap_nine;
    QPixmap Pixmap_void;
    QPixmap Pixmap_minus;

    QPointF points_a[6];
    QPointF points_f[6];
    QPointF points_b[6];
    QPointF points_g[6];
    QPointF points_e[6];
    QPointF points_d[6];
    QPointF points_c[6];
    QRectF point;

    QPainter *Painter_zero;
    QPainter *Painter_one;
    QPainter *Painter_two;
    QPainter *Painter_three;
    QPainter *Painter_four;
    QPainter *Painter_five;
    QPainter *Painter_six;
    QPainter *Painter_seven;
    QPainter *Painter_eight;
    QPainter *Painter_nine;
    QPainter *Painter_void;
    QPainter *Painter_point;
    QPainter *Painter_minus;
    public:
};
//******************************************************************************
#endif // DIGITALINDICATOR_H
//******************************************************************************
