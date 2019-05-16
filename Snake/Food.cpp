#include "Food.h"
#include <QPainter>
#include "constants.h"

static const qreal FOOD_RADIUS = 3;

//设置元素的坐标
Food::Food(qreal x, qreal y)
{
	setPos(x, y);
	//为元素添加额外的数据信息
	setData(GD_Type, GO_Food);
}

Food::~Food()
{
}

//返回元素的范围
QRectF Food::boundingRect() const
{
	return QRectF(-TILE_SIZE, -TILE_SIZE, TILE_SIZE * 2, TILE_SIZE * 2);
}

void Food::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
	painter->save();

	painter->setRenderHint(QPainter::Antialiasing);
	//填充路径
	painter->fillPath(shape(), Qt::red);

	painter->restore();
}

//绘制元素路径
QPainterPath Food::shape() const
{
	QPainterPath p;
	p.addEllipse(QPointF(TILE_SIZE / 2, TILE_SIZE / 2), FOOD_RADIUS, FOOD_RADIUS);
	return p;
}
