//******************************************************************************
#include "Digitalindicator.h"
//******************************************************************************
#include <QDebug>
//******************************************************************************
#define DEF_SEVENSEGMENT_NUMBER_SIGNS            8
#define DEF_WIDTH_SIGNS                         250
#define DEF_HEIGHT_SIGNS                        370
#define DEF_SIGNS_WIDTH_PLUS_GAP                250
//******************************************************************************
DigitalIndicator::DigitalIndicator()
{
    Label_Indicator = new QLabel(this);
    GridLayout_Indicator = new QGridLayout(this);
    GridLayout_Indicator->addWidget(Label_Indicator);
    IndicatorError = QColor(255, 37, 0, 250);
    IndicatorBackColor = QColor(0,0,0,250);
    IndicatorColorSigns = QColor(24, 245, 39, 250);
    IndicatorPointColor = QColor(0,0,0,250);
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
void DigitalIndicator::resizeEvent(QResizeEvent *) { painterIndicator(IndicatorColorSigns);}
//******************************************************************************
void DigitalIndicator::SetIndicatorBackColor(QColor Color)
{
    IndicatorBackColor = Color;
}
//******************************************************************************
void DigitalIndicator::SetIndicatorBackLEDColor(QColor Color)
{
    IndicatorBackLEDColor = Color;
}
//******************************************************************************
void DigitalIndicator::painterIndicator(QColor Color)
{
    IndicatorColorSigns = Color;
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
    Pixmap_void = QPixmap(DEF_WIDTH_SIGNS, DEF_HEIGHT_SIGNS);
    Pixmap_minus = QPixmap(DEF_WIDTH_SIGNS, DEF_HEIGHT_SIGNS);

    Pixmap_zero.fill(IndicatorBackColor);
    Pixmap_one.fill(IndicatorBackColor);
    Pixmap_two.fill(IndicatorBackColor);
    Pixmap_three.fill(IndicatorBackColor);
    Pixmap_four.fill(IndicatorBackColor);
    Pixmap_five.fill(IndicatorBackColor);
    Pixmap_six.fill(IndicatorBackColor);
    Pixmap_seven.fill(IndicatorBackColor);
    Pixmap_eight.fill(IndicatorBackColor);
    Pixmap_nine.fill(IndicatorBackColor);
    Pixmap_void.fill(IndicatorBackColor);
    Pixmap_minus.fill(IndicatorBackColor);

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
    Painter_void = new QPainter(&Pixmap_void);
    Painter_minus = new QPainter(&Pixmap_minus);

    //Элемент сегмента a
    QPointF points_a[6] = {
        QPointF(71.7478, 26.8979),
        QPointF(174.1256, 26.8979),
        QPointF(187.8857, 40.6580),
        QPointF(174.1256, 54.4181),
        QPointF(71.7478, 54.4181),
        QPointF(57.9877, 40.6580),
    };
    //Элемент сегмента f
    QPointF points_f[6] = {
        QPointF(35.0475, 63.5981),
        QPointF(48.8077, 49.8380),
        QPointF(62.5678, 63.5981),
        QPointF(62.5678, 165.9759),
        QPointF(48.8077, 179.7360),
        QPointF(35.0475, 165.9759),
    };
    //Элемент сегмента b
    QPointF points_b[6] = {
        QPointF(183.3056, 63.5981),
        QPointF(197.0657, 49.8380),
        QPointF(210.8258, 63.5981),
        QPointF(210.8258, 165.9759),
        QPointF(197.0657, 179.7360),
        QPointF(183.3056, 165.9759),
    };
    //Элемент сегмента g
    QPointF points_g[6] = {
        QPointF(71.7478, 175.1559),
        QPointF(174.1256, 175.1559),
        QPointF(187.8857, 188.9160),
        QPointF(174.1256, 202.6762),
        QPointF(71.7478, 202.6762),
        QPointF(57.9877, 188.9160),
    };
    //Элемент сегмента e
    QPointF points_e[6] = {
        QPointF(35.0475, 211.8562),
        QPointF(48.8077, 198.0961),
        QPointF(62.5678, 211.8562),
        QPointF(62.5678, 314.2340),
        QPointF(48.8077, 327.9941),
        QPointF(35.0475, 314.2340),
    };
    //Элемент сегмента d
    QPointF points_d[6] = {
        QPointF(71.7478, 323.4140),
        QPointF(174.1256, 323.4140),
        QPointF(187.8857, 337.1741),
        QPointF(174.1256, 350.9342),
        QPointF(71.7478, 350.9342),
        QPointF(57.9877, 337.1741),
    };
    //Элемент сегмента c
    QPointF points_c[6] = {
        QPointF(183.3056, 211.8562),
        QPointF(197.0657, 198.0961),
        QPointF(210.8258, 211.8562),
        QPointF(210.8258, 314.2340),
        QPointF(197.0657, 327.9941),
        QPointF(183.3056, 314.2340),
    };
    QRectF point(210, 320, 40, 40);
    //Ноль
    Painter_zero->setBrush(IndicatorColorSigns);
    Painter_zero->drawPolygon(points_a, 6);
    Painter_zero->drawPolygon(points_b, 6);
    Painter_zero->drawPolygon(points_c, 6);
    Painter_zero->drawPolygon(points_d, 6);
    Painter_zero->drawPolygon(points_e, 6);
    Painter_zero->drawPolygon(points_f, 6);
    Painter_zero->setBrush(IndicatorBackLEDColor);
    Painter_zero->drawPolygon(points_g, 6);
    Painter_zero->setBrush(IndicatorPointColor);
    Painter_zero->drawEllipse(point);
    Painter_zero->end();
    //Единица
    Painter_one->setBrush(IndicatorColorSigns);
    Painter_one->drawPolygon(points_b, 6);
    Painter_one->drawPolygon(points_c, 6);
    Painter_one->setBrush(IndicatorBackLEDColor);
    Painter_one->drawPolygon(points_a, 6);
    Painter_one->drawPolygon(points_e, 6);
    Painter_one->drawPolygon(points_f, 6);
    Painter_one->drawPolygon(points_d, 6);
    Painter_one->drawPolygon(points_g, 6);
    Painter_one->setBrush(IndicatorPointColor);
    Painter_one->drawEllipse(point);
    Painter_one->end();
    //Двойка
    Painter_two->setBrush(IndicatorColorSigns);
    Painter_two->drawPolygon(points_a, 6);
    Painter_two->drawPolygon(points_b, 6);
    Painter_two->drawPolygon(points_d, 6);
    Painter_two->drawPolygon(points_e, 6);
    Painter_two->drawPolygon(points_g, 6);
    Painter_two->setBrush(IndicatorBackLEDColor);
    Painter_two->drawPolygon(points_c, 6);
    Painter_two->drawPolygon(points_f, 6);
    Painter_two->setBrush(IndicatorPointColor);
    Painter_two->drawEllipse(point);
    Painter_two->end();
    //Тройка
    Painter_three->setBrush(IndicatorColorSigns);
    Painter_three->drawPolygon(points_a, 6);
    Painter_three->drawPolygon(points_b, 6);
    Painter_three->drawPolygon(points_c, 6);
    Painter_three->drawPolygon(points_d, 6);
    Painter_three->drawPolygon(points_g, 6);
    Painter_three->setBrush(IndicatorBackLEDColor);
    Painter_three->drawPolygon(points_e, 6);
    Painter_three->drawPolygon(points_f, 6);
    Painter_three->setBrush(IndicatorPointColor);
    Painter_three->drawEllipse(point);
    Painter_three->end();
    //Четвёрка
    Painter_four->setBrush(IndicatorColorSigns);
    Painter_four->drawPolygon(points_b, 6);
    Painter_four->drawPolygon(points_c, 6);;
    Painter_four->drawPolygon(points_f, 6);
    Painter_four->drawPolygon(points_g, 6);
    Painter_four->setBrush(IndicatorBackLEDColor);
    Painter_four->drawPolygon(points_a, 6);
    Painter_four->drawPolygon(points_d, 6);
    Painter_four->drawPolygon(points_e, 6);
    Painter_four->setBrush(IndicatorPointColor);
    Painter_four->drawEllipse(point);
    Painter_four->end();
    //Пятёрка
    Painter_five->setBrush(IndicatorColorSigns);
    Painter_five->drawPolygon(points_a, 6);
    Painter_five->drawPolygon(points_c, 6);
    Painter_five->drawPolygon(points_d, 6);
    Painter_five->drawPolygon(points_f, 6);
    Painter_five->drawPolygon(points_g, 6);
    Painter_five->setBrush(IndicatorBackLEDColor);
    Painter_five->drawPolygon(points_b, 6);
    Painter_five->drawPolygon(points_e, 6);
    Painter_five->setBrush(IndicatorPointColor);
    Painter_five->drawEllipse(point);
    Painter_five->end();
    //Шестёрка
    Painter_six->setBrush(IndicatorColorSigns);
    Painter_six->drawPolygon(points_a, 6);
    Painter_six->drawPolygon(points_c, 6);
    Painter_six->drawPolygon(points_d, 6);
    Painter_six->drawPolygon(points_e, 6);
    Painter_six->drawPolygon(points_f, 6);
    Painter_six->drawPolygon(points_g, 6);
    Painter_six->setBrush(IndicatorBackLEDColor);
    Painter_six->drawPolygon(points_b, 6);
    Painter_six->setBrush(IndicatorPointColor);
    Painter_six->drawEllipse(point);
    Painter_six->end();
    //Семёрка
    Painter_seven->setBrush(IndicatorColorSigns);
    Painter_seven->drawPolygon(points_a, 6);
    Painter_seven->drawPolygon(points_b, 6);
    Painter_seven->drawPolygon(points_c, 6);
    Painter_seven->setBrush(IndicatorBackLEDColor);
    Painter_seven->drawPolygon(points_d, 6);
    Painter_seven->drawPolygon(points_e, 6);
    Painter_seven->drawPolygon(points_f, 6);
    Painter_seven->drawPolygon(points_g, 6);
    Painter_seven->setBrush(IndicatorPointColor);
    Painter_seven->drawEllipse(point);
    Painter_seven->end();
    //Восьмёрка
    Painter_eight->setBrush(IndicatorColorSigns);
    Painter_eight->drawPolygon(points_a, 6);
    Painter_eight->drawPolygon(points_b, 6);
    Painter_eight->drawPolygon(points_c, 6);
    Painter_eight->drawPolygon(points_d, 6);
    Painter_eight->drawPolygon(points_e, 6);
    Painter_eight->drawPolygon(points_f, 6);
    Painter_eight->drawPolygon(points_g, 6);
    Painter_eight->setBrush(IndicatorPointColor);
    Painter_eight->drawEllipse(point);
    Painter_eight->end();
    //Девятка
    Painter_nine->setBrush(IndicatorColorSigns);
    Painter_nine->drawPolygon(points_a, 6);
    Painter_nine->drawPolygon(points_b, 6);
    Painter_nine->drawPolygon(points_c, 6);
    Painter_nine->drawPolygon(points_d, 6);
    Painter_nine->drawPolygon(points_f, 6);
    Painter_nine->drawPolygon(points_g, 6);
    Painter_nine->setBrush(IndicatorBackLEDColor);
    Painter_nine->drawPolygon(points_e, 6);
    Painter_nine->setBrush(IndicatorPointColor);
    Painter_nine->drawEllipse(point);
    Painter_nine->end();
    //Пустой индикатор, только фон
    Painter_void->setBrush(IndicatorBackLEDColor);
    Painter_void->drawPolygon(points_a, 6);
    Painter_void->drawPolygon(points_b, 6);
    Painter_void->drawPolygon(points_c, 6);
    Painter_void->drawPolygon(points_d, 6);
    Painter_void->drawPolygon(points_e, 6);
    Painter_void->drawPolygon(points_f, 6);
    Painter_void->drawPolygon(points_g, 6);
    Painter_void->end();
    //Минус
    Painter_minus->setBrush(IndicatorColorSigns);
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
    long double copyVariable_1 = saveVariable;
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
        }else PainterIn.drawPixmap(TargetObjects[count], Pixmap_void);
        count++;
    }
    count = 0;
    long double copyVariable_2 = saveVariable;
    long double Number;
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
void DigitalIndicator::SetValue(long double Variable)
{
    //qDebug() << Variable;
    printf("%1.25lf", (double)Variable);

    //printf("%l",&Variable);
    int NumRank = 1;
    //Условие поднятие флага отрицательного числа
    if(Variable < 0) {NumRank++; Variable = -Variable; flagMinus = true;}
    else flagMinus = false;
    //Подсёт количества знаков
    long double copyVariable_1 = Variable;
    while ((copyVariable_1/=10) > 0) NumRank++;
    //Условие возврата ошибки ERROR при количестве знаков превыщающих размер кол. знаков полотна
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
        }
        else PainterIn.drawPixmap(TargetObjects[count], Pixmap_void);
        count++;
    }
    count = 0;
    long double copyVariable_2 = Variable;
    long double Number;
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
    QRect target(0.0, 0.0, width(), height());
    Painter.drawPixmap(target, PixmapIn);
    Label_Indicator->setPixmap(Pixmap);
}
//******************************************************************************
