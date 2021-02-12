//******************************************************************************
#include "Digitalindicator.h"
//******************************************************************************
#include <QDebug>
//******************************************************************************
#define DEF_SEVENSEGMENT_NUMBER_SIGNS            8
#define DEF_WIDTH_SIGNS                         32
#define DEF_HEIGHT_SIGNS                        50
#define DEF_SIGNS_WIDTH_PLUS_GAP                32
//******************************************************************************
DigitalIndicator::DigitalIndicator()
{
    Label_Indicator = new QLabel(this);
    GridLayout_Indicator = new QGridLayout(this);
    GridLayout_Indicator->addWidget(Label_Indicator);
    IndicatorError = QColor(255, 37, 0, 250);
    IndicatorColor = QColor(24, 245, 39, 250);
    IndicatorBackLEDColor = QColor(50, 50, 50, 150);
    flagMinus = false;
    int Left, Top, Right, Bottom;
    GridLayout_Indicator->getContentsMargins(&Left, &Top, &Right, &Bottom);
    Left = 0;
    Top = 0;
    Right = 0;
    Bottom = 0;
    GridLayout_Indicator->setContentsMargins(Left, Top, Right, Bottom);
}

//******************************************************************************
void DigitalIndicator::resizeEvent(QResizeEvent *) { painterIndicator(IndicatorColor);}
//******************************************************************************
void DigitalIndicator::SetIndicatorBackLEDColor(QColor Color)
{
    IndicatorBackLEDColor = Color;
}
//******************************************************************************
void DigitalIndicator::painterIndicator(QColor Color)
{
    IndicatorColor = Color;
    Pixmap_zero = QPixmap(DEF_WIDTH_SIGNS, DEF_HEIGHT_SIGNS);
    Pixmap_one = QPixmap(DEF_WIDTH_SIGNS, DEF_HEIGHT_SIGNS);
    Pixmap_two = QPixmap(DEF_WIDTH_SIGNS, DEF_HEIGHT_SIGNS);
    Pixmap_three = QPixmap(DEF_WIDTH_SIGNS, DEF_HEIGHT_SIGNS);
    Pixmap_four = QPixmap(DEF_WIDTH_SIGNS, DEF_HEIGHT_SIGNS);
    Pixmap_five = QPixmap(DEF_WIDTH_SIGNS, DEF_HEIGHT_SIGNS);
    Pixmap_six = QPixmap(DEF_WIDTH_SIGNS, DEF_HEIGHT_SIGNS);
    Pixmap_seven = QPixmap(DEF_WIDTH_SIGNS, DEF_HEIGHT_SIGNS);
    Pixmap_eight = QPixmap(DEF_WIDTH_SIGNS, DEF_HEIGHT_SIGNS);
    Pixmap_nine = QPixmap(DEF_WIDTH_SIGNS, DEF_HEIGHT_SIGNS);
    Pixmap_minus = QPixmap(DEF_WIDTH_SIGNS, DEF_HEIGHT_SIGNS);

    Pixmap_zero.fill(QColor(0,0,0,250));
    Pixmap_one.fill(QColor(0,0,0,250));
    Pixmap_two.fill(QColor(0,0,0,250));
    Pixmap_three.fill(QColor(0,0,0,250));
    Pixmap_four.fill(QColor(0,0,0,250));
    Pixmap_five.fill(QColor(0,0,0,250));
    Pixmap_six.fill(QColor(0,0,0,250));
    Pixmap_seven.fill(QColor(0,0,0,250));
    Pixmap_eight.fill(QColor(0,0,0,250));
    Pixmap_nine.fill(QColor(0,0,0,250));
    Pixmap_minus.fill(QColor(0,0,0,250));

    Painter_zero = new QPainter(&Pixmap_zero);
    Painter_one = new QPainter(&Pixmap_one);
    Painter_two = new QPainter(&Pixmap_two);
    Painter_three = new QPainter(&Pixmap_three);
    Painter_four = new QPainter(&Pixmap_four);
    Painter_five = new QPainter(&Pixmap_five);
    Painter_six = new QPainter(&Pixmap_six);
    Painter_seven = new QPainter(&Pixmap_seven);
    Painter_eight = new QPainter(&Pixmap_eight);
    Painter_nine = new QPainter(&Pixmap_nine);
    Painter_minus = new QPainter(&Pixmap_minus);

    //Элемент сегмента a
    QPointF points_a[6] = {
        QPointF(5.0, 5.0),
        QPointF(3.0, 3.0),
        QPointF(5.0, 1.0),
        QPointF(21.0, 1.0),
        QPointF(23.0, 3.0),
        QPointF(21.0, 5.0),
    };
    //Элемент сегмента f
    QPointF points_f[6] = {
        QPointF(4.0, 6.0),
        QPointF(2.0, 4.0),
        QPointF(0.0, 6.0),
        QPointF(0.0, 22.0),
        QPointF(2.0, 24.0),
        QPointF(4.0, 22.0),
    };
    //Элемент сегмента b
    QPointF points_b[6] = {
        QPointF(26.0, 6.0),
        QPointF(24.0, 4.0),
        QPointF(22.0, 6.0),
        QPointF(22.0, 22.0),
        QPointF(24.0, 24.0),
        QPointF(26.0, 22.0),
    };
    //Элемент сегмента g
    QPointF points_g[6] = {
        QPointF(5.0, 27.0),
        QPointF(3.0, 25.0),
        QPointF(5.0, 23.0),
        QPointF(21.0, 23.0),
        QPointF(23.0, 25.0),
        QPointF(21.0, 27.0),
    };
    //Элемент сегмента e
    QPointF points_e[6] = {
        QPointF(4.0, 28.0),
        QPointF(2.0, 26.0),
        QPointF(0.0, 28.0),
        QPointF(0.0, 44.0),
        QPointF(2.0, 46.0),
        QPointF(4.0, 44.0),
    };
    //Элемент сегмента d
    QPointF points_d[6] = {
        QPointF(5.0, 49.0),
        QPointF(3.0, 47.0),
        QPointF(5.0, 45.0),
        QPointF(21.0, 45.0),
        QPointF(23.0, 47.0),
        QPointF(21.0, 49.0),
    };
    //Элемент сегмента c
    QPointF points_c[6] = {
        QPointF(26.0, 28.0),
        QPointF(24.0, 26.0),
        QPointF(22.0, 28.0),
        QPointF(22.0, 44.0),
        QPointF(24.0, 46.0),
        QPointF(26.0, 44.0),
    };

    //Ноль
    Painter_zero->setBrush(IndicatorColor);
    Painter_zero->drawPolygon(points_a, 6);
    Painter_zero->drawPolygon(points_b, 6);
    Painter_zero->drawPolygon(points_c, 6);
    Painter_zero->drawPolygon(points_d, 6);
    Painter_zero->drawPolygon(points_e, 6);
    Painter_zero->drawPolygon(points_f, 6);
    Painter_zero->setBrush(IndicatorBackLEDColor);
    Painter_zero->drawPolygon(points_g, 6);
    Painter_zero->end();
    //Единица
    Painter_one->setBrush(IndicatorColor);
    Painter_one->drawPolygon(points_b, 6);
    Painter_one->drawPolygon(points_c, 6);
    Painter_one->setBrush(IndicatorBackLEDColor);
    Painter_one->drawPolygon(points_a, 6);
    Painter_one->drawPolygon(points_e, 6);
    Painter_one->drawPolygon(points_f, 6);
    Painter_one->drawPolygon(points_d, 6);
    Painter_one->drawPolygon(points_g, 6);
    Painter_one->end();
    //Двойка
    Painter_two->setBrush(IndicatorColor);
    Painter_two->drawPolygon(points_a, 6);
    Painter_two->drawPolygon(points_b, 6);
    Painter_two->drawPolygon(points_d, 6);
    Painter_two->drawPolygon(points_e, 6);
    Painter_two->drawPolygon(points_g, 6);
    Painter_two->setBrush(IndicatorBackLEDColor);
    Painter_two->drawPolygon(points_c, 6);
    Painter_two->drawPolygon(points_f, 6);
    Painter_two->end();
    //Тройка
    Painter_three->setBrush(IndicatorColor);
    Painter_three->drawPolygon(points_a, 6);
    Painter_three->drawPolygon(points_b, 6);
    Painter_three->drawPolygon(points_c, 6);
    Painter_three->drawPolygon(points_d, 6);
    Painter_three->drawPolygon(points_g, 6);
    Painter_three->setBrush(IndicatorBackLEDColor);
    Painter_three->drawPolygon(points_e, 6);
    Painter_three->drawPolygon(points_f, 6);
    Painter_three->end();
    //Четвёрка
    Painter_four->setBrush(IndicatorColor);
    Painter_four->drawPolygon(points_b, 6);
    Painter_four->drawPolygon(points_c, 6);;
    Painter_four->drawPolygon(points_f, 6);
    Painter_four->drawPolygon(points_g, 6);
    Painter_four->setBrush(IndicatorBackLEDColor);
    Painter_four->drawPolygon(points_a, 6);
    Painter_four->drawPolygon(points_d, 6);
    Painter_four->drawPolygon(points_e, 6);
    Painter_four->end();
    //Пятёрка
    Painter_five->setBrush(IndicatorColor);
    Painter_five->drawPolygon(points_a, 6);
    Painter_five->drawPolygon(points_c, 6);
    Painter_five->drawPolygon(points_d, 6);
    Painter_five->drawPolygon(points_f, 6);
    Painter_five->drawPolygon(points_g, 6);
    Painter_five->setBrush(IndicatorBackLEDColor);
    Painter_five->drawPolygon(points_b, 6);
    Painter_five->drawPolygon(points_e, 6);
    Painter_five->end();
    //Шестёрка
    Painter_six->setBrush(IndicatorColor);
    Painter_six->drawPolygon(points_a, 6);
    Painter_six->drawPolygon(points_c, 6);
    Painter_six->drawPolygon(points_d, 6);
    Painter_six->drawPolygon(points_e, 6);
    Painter_six->drawPolygon(points_f, 6);
    Painter_six->drawPolygon(points_g, 6);
    Painter_six->setBrush(IndicatorBackLEDColor);
    Painter_six->drawPolygon(points_b, 6);
    Painter_six->end();
    //Семёрка
    Painter_seven->setBrush(IndicatorColor);
    Painter_seven->drawPolygon(points_a, 6);
    Painter_seven->drawPolygon(points_b, 6);
    Painter_seven->drawPolygon(points_c, 6);
    Painter_seven->setBrush(IndicatorBackLEDColor);
    Painter_seven->drawPolygon(points_d, 6);
    Painter_seven->drawPolygon(points_e, 6);
    Painter_seven->drawPolygon(points_f, 6);
    Painter_seven->drawPolygon(points_g, 6);
    Painter_seven->end();
    //Восьмёрка
    Painter_eight->setBrush(IndicatorColor);
    Painter_eight->drawPolygon(points_a, 6);
    Painter_eight->drawPolygon(points_b, 6);
    Painter_eight->drawPolygon(points_c, 6);
    Painter_eight->drawPolygon(points_d, 6);
    Painter_eight->drawPolygon(points_e, 6);
    Painter_eight->drawPolygon(points_f, 6);
    Painter_eight->drawPolygon(points_g, 6);
    Painter_eight->end();
    //Девятка
    Painter_nine->setBrush(IndicatorColor);
    Painter_nine->drawPolygon(points_a, 6);
    Painter_nine->drawPolygon(points_b, 6);
    Painter_nine->drawPolygon(points_c, 6);
    Painter_nine->drawPolygon(points_d, 6);
    Painter_nine->drawPolygon(points_f, 6);
    Painter_nine->drawPolygon(points_g, 6);
    Painter_nine->setBrush(IndicatorBackLEDColor);
    Painter_nine->drawPolygon(points_e, 6);
    Painter_nine->end();
    //Минус
    Painter_minus->setBrush(IndicatorColor);
    Painter_minus->drawPolygon(points_g, 6);
    Painter_minus->setBrush(IndicatorBackLEDColor);
    Painter_minus->drawPolygon(points_a, 6);
    Painter_minus->drawPolygon(points_b, 6);
    Painter_minus->drawPolygon(points_c, 6);
    Painter_minus->drawPolygon(points_d, 6);
    Painter_minus->drawPolygon(points_e, 6);
    Painter_minus->drawPolygon(points_f, 6);
    Painter_minus->end();

    Label_Indicator-> setFixedSize(width(), height());
    Pixmap = QPixmap(width(), height());
    Pixmap.fill(QPalette().window().color());
    PixmapIn = QPixmap(DEF_SEVENSEGMENT_NUMBER_SIGNS*DEF_SIGNS_WIDTH_PLUS_GAP, DEF_HEIGHT_SIGNS);

    PixmapIn.fill(QPalette().window().color());
    QPainter Painter(&Pixmap);
    QPainter PainterIn(&PixmapIn);
    int NumRank = 1;
    if(flagMinus) NumRank++;
    long long copyVariable_1 = saveVariable;
    while ((copyVariable_1/=10) > 0) NumRank++;
    int count = 0;
    //Позиционирование слева направо
    for(int i = (DEF_SEVENSEGMENT_NUMBER_SIGNS - 1); i >= 0; i--)
    {
        QRect target(DEF_SIGNS_WIDTH_PLUS_GAP*i, 0.0, DEF_WIDTH_SIGNS, DEF_HEIGHT_SIGNS);
        TargetObjects.append(target);

        if(saveVariable == 0)
        {
            PainterIn.drawPixmap(TargetObjects[count], Pixmap_zero);
        }count++;
    }
    count = 0;
    long long copyVariable_2 = saveVariable;
    long long Number;
    if(flagMinus)
    {
        PainterIn.drawPixmap(TargetObjects[NumRank-1], Pixmap_minus);
        NumRank--;
    }
    for(int i = 0; i < NumRank; i++)
    {
        Number = copyVariable_2 % 10;
        copyVariable_2/=10;
        if(Number == 0) PainterIn.drawPixmap(TargetObjects[i], Pixmap_zero);
        else if (Number == 1) PainterIn.drawPixmap(TargetObjects[i], Pixmap_one);
        else if(Number == 2) PainterIn.drawPixmap(TargetObjects[i], Pixmap_two);
        else if(Number == 3) PainterIn.drawPixmap(TargetObjects[i], Pixmap_three);
        else if(Number == 4) PainterIn.drawPixmap(TargetObjects[i], Pixmap_four);
        else if(Number == 5) PainterIn.drawPixmap(TargetObjects[i], Pixmap_five);
        else if(Number == 6) PainterIn.drawPixmap(TargetObjects[i], Pixmap_six);
        else if(Number == 7) PainterIn.drawPixmap(TargetObjects[i], Pixmap_seven);
        else if(Number == 8) PainterIn.drawPixmap(TargetObjects[i], Pixmap_eight);
        else PainterIn.drawPixmap(TargetObjects[i], Pixmap_nine);
        count++;
    }
    QRect target(0.0, 0.0, width(), height());
    Painter.drawPixmap(target, PixmapIn);
    Label_Indicator->setPixmap(Pixmap);
}
//******************************************************************************
void DigitalIndicator::SetValue(long long Variable)
{
    int NumRank = 1;
    if(Variable < 0) {NumRank++; Variable = -Variable; flagMinus = true;}
    else flagMinus = false;
    long long copyVariable_1 = Variable;
    while ((copyVariable_1/=10) > 0) NumRank++;
    if(NumRank > DEF_SEVENSEGMENT_NUMBER_SIGNS) {flagMinus = false; painterIndicator(IndicatorError); return;}
    saveVariable = Variable;
    Label_Indicator-> setFixedSize(width(), height());
    Pixmap = QPixmap(width(), height());
    Pixmap.fill(QPalette().window().color());
    PixmapIn = QPixmap(DEF_SEVENSEGMENT_NUMBER_SIGNS*DEF_SIGNS_WIDTH_PLUS_GAP, DEF_HEIGHT_SIGNS);
    PixmapIn.fill(QPalette().window().color());
    QPainter Painter(&Pixmap);
    QPainter PainterIn(&PixmapIn);
    int count = 0;
    for(int i = (DEF_SEVENSEGMENT_NUMBER_SIGNS - 1); i >= 0; i--)
    {
        QRect target(DEF_SIGNS_WIDTH_PLUS_GAP*i, 0.0, DEF_WIDTH_SIGNS, DEF_HEIGHT_SIGNS);
        TargetObjects.append(target);

        if(Variable == 0)
        {
            PainterIn.drawPixmap(TargetObjects[count], Pixmap_zero);
        }count++;
    }
    count = 0;
    long long copyVariable_2 = Variable;
    long long Number;
    if(flagMinus)
    {
        PainterIn.drawPixmap(TargetObjects[NumRank-1], Pixmap_minus);
        NumRank--;
    }
    for(int i = 0; i < NumRank; i++)
    {
        Number = copyVariable_2 % 10;
        copyVariable_2/=10;
        if(Number == 0) {PainterIn.drawPixmap(TargetObjects[i], Pixmap_zero);}
        else if (Number == 1) PainterIn.drawPixmap(TargetObjects[i], Pixmap_one);
        else if(Number == 2) PainterIn.drawPixmap(TargetObjects[i], Pixmap_two);
        else if(Number == 3) PainterIn.drawPixmap(TargetObjects[i], Pixmap_three);
        else if(Number == 4) PainterIn.drawPixmap(TargetObjects[i], Pixmap_four);
        else if(Number == 5) PainterIn.drawPixmap(TargetObjects[i], Pixmap_five);
        else if(Number == 6) PainterIn.drawPixmap(TargetObjects[i], Pixmap_six);
        else if(Number == 7) PainterIn.drawPixmap(TargetObjects[i], Pixmap_seven);
        else if(Number == 8) PainterIn.drawPixmap(TargetObjects[i], Pixmap_eight);
        else PainterIn.drawPixmap(TargetObjects[i], Pixmap_nine);
        count++;
    }
    //    if(flagMinus)

    QRect target(0.0, 0.0, width(), height());
    Painter.drawPixmap(target, PixmapIn);
    Label_Indicator->setPixmap(Pixmap);
}
//******************************************************************************
