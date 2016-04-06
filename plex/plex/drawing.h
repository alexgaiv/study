#ifndef _DRAWING_H_
#define _DRAWING_H_

#include <string>
#include <vcclr.h>

using namespace std;
using namespace System::Drawing;

class PlexNode
{
public:
	int refCount;
	int passCount;
	int size;
	bool isVisible;
	gcroot<Color> color;
	static const int epsilon = 10;
	string name;


	PlexNode()
	{
		refCount = passCount = 0;
		size = 1;
		isVisible = true;
		color = Color::Black;
		name = "";
	}

	virtual void Draw(Graphics ^g) = 0;
};

class PointNode : public PlexNode
{
public:
	int x, y;

	PointNode() {
		size = 3;
		x = y = 0;
	}

	PointNode(int x, int y) : x(x), y(y)
		{ size = 3; }

	void Draw(Graphics ^g)
	{
		SolidBrush ^b = gcnew SolidBrush(color);
		g->FillEllipse(b, x, y, size, size);
	}
};

class LineNode : public PlexNode
{
public:
	PointNode *p1, *p2;

	LineNode(PointNode *p1, PointNode *p2) {
		this->p1 = p1;
		this->p2 = p2;
	}

	void Draw(Graphics ^g)
	{
		Pen ^p = gcnew Pen(color);
		p->Width = (float)size;
		g->DrawLine(p, p1->x, p1->y, p2->x, p2->y);
	}
};

class RectangleNode	: public PlexNode
{
public:
	PointNode *p1, *p2, *p3, *p4;

	void Draw(Graphics ^g)
	{
	
	}
};

class ArcNode : public PlexNode
{
public:
	PointNode *center;
	int radius;
	int startAngle, endAngle;

	ArcNode(PointNode *center, int radius, int startAngle, int endAngle) {
		this->center = center;
		this->radius = radius;
		this->startAngle = startAngle;
		this->endAngle = endAngle;
	}

	void Draw(Graphics ^g)
	{
		Pen ^p = gcnew Pen(color);
		p->Width = (float)size;
		g->DrawArc(p, center->x, center->y, radius*2, radius*2, startAngle, endAngle);
	}
};

#endif // _DRAWING_H_