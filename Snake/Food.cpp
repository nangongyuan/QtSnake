#include "Food.h"
#include <QPainter>
#include "constants.h"

static const qreal FOOD_RADIUS = 3;

//����Ԫ�ص�����
Food::Food(qreal x, qreal y)
{
	setPos(x, y);
	//ΪԪ����Ӷ����������Ϣ
	setData(GD_Type, GO_Food);
}

Food::~Food()
{
}

//����Ԫ�صķ�Χ
QRectF Food::boundingRect() const
{
	return QRectF(-TILE_SIZE, -TILE_SIZE, TILE_SIZE * 2, TILE_SIZE * 2);
}

void Food::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
	painter->save();

	painter->setRenderHint(QPainter::Antialiasing);
	//���·��
	painter->fillPath(shape(), Qt::red);

	painter->restore();
}

//����Ԫ��·��
QPainterPath Food::shape() const
{
	QPainterPath p;
	p.addEllipse(QPointF(TILE_SIZE / 2, TILE_SIZE / 2), FOOD_RADIUS, FOOD_RADIUS);
	return p;
}
