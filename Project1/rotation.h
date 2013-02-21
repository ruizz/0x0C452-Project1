#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/fl_draw.H>
#include <math.h>
#define PI 3.14159265

int BX = 500;
int BY = 750;
int XX = 200;	//

struct Pos{
	double x1;
	double y1;
	double x2;
	double y2;
	Pos(double x_1, double y_1,double x_2, double y_2) {
		x1 = x_1;
		y1 = y_1;
		x2 = x_2;
		y2 = y_2;
	}
};
class Matrix
{
public:
	int row;
	int col;
	double data[4][4];	//**
	Matrix(int r, int c)
	{
		row=r;
		col=c;
		//initialize data with row, col
		for(int i=0; i<row; i++)
		{
			for(int j=0; j<col; j++)
			{
				data[i][j] = 0;
			}
		}
	}
	Matrix* multiply(Matrix* mat)
	{
		Matrix* result = new Matrix(row, mat->col);
		for(int i=0; i<row; i++)
		{
			for(int j=0; j<mat->col; j++)
			{
				//result.data[i][j]
				for(int k=0; k<row; k++)
				{
					result->data[i][j] += data[i][k]*mat->data[k][j];
					//printf("i = %d, j = %d, mat : %f, line : %f, result = %f\n", i, j, data[i][k], mat->data[k][j], data[i][k]*mat->data[k][j]);
				}
			}
		}

		return result;
	}
};
Matrix* rotate(Matrix* line, double degree, double orx, double ory)	
{
	printf("aaaaaaaaa %f\n", degree);
	Matrix* Rot = new Matrix(4,4);
	Rot->data[0][0] = cos(degree*PI/180);
	Rot->data[0][1] = -sin(degree*PI/180);
	Rot->data[0][2] = 0;
	Rot->data[1][0] = sin(degree*PI/180);
	Rot->data[1][1] = cos(degree*PI/180);
	Rot->data[1][2] = 0;
	Rot->data[2][0] = 0;
	Rot->data[2][1] = 0;
	Rot->data[2][2] = 1;
	Rot->data[0][3] = orx;	//x,y,z the actual fixel positions
	Rot->data[1][3] = ory;
	Rot->data[2][3] = 0;	//in this program, orz is always 0
	Rot->data[3][0] = 0;
	Rot->data[3][1] = 0;
	Rot->data[3][2] = 0;
	Rot->data[3][3] = 1;

	return Rot->multiply(line);
}
class Drawing: public Fl_Widget
{
	void draw();
	/*
	{
		
		fl_color(FL_BLACK);
		//draw_line(XX+0,0,0,150);
		//draw_line(
		fl_color(FL_BLUE);
		draw_line(XX+0,150,0,100);
		fl_color(FL_RED);
		draw_line(XX+0,250,0,75);
		//fl_arc(point(0).x,point(0).y,r+r,r+r,0,360);
		//fl_arc(100, 100, 200, 200, 0, 360);
		fl_pie(0,0,200,200,0,360);
		fl_end_line();

	}
	*/
	void draw_line(int x1, int y1, int x2, int y2)
	{
		//fl_line(BX+x1, BY-y1, BX+x1+x2, BY-y1-y2);
		fl_line(BX+x1, BY-y1, BX+x2, BY-y2);
	}
	public:
	Drawing(int X, int Y, int W, int H):Fl_Widget(X,Y,W,H){}
};
class Line
{
public:
	int ln;
	double x1;
	double y1;
	double x2;
	double y2;
	Line(double a1,double b1,double a2,double b2, int l)
	{
		x1 = a1;
		x2 = a2;
		y1 = b1;
		y2 = b2;
		ln = l;
	}
	Pos* rot(double deg, double x_axis, double y_axis);
};


class Lines
{

public:
	Line* lines[3];

	Lines()
	{
		lines[0] = new Line(-25,280,-25,430,0);
		lines[1] = new Line(-25,430,-25,530,1);
		lines[2] = new Line(-25,530,-25,605,2);
	}
	void rotate(double degree, int axis)
	{
		switch(axis)
		{
			case 0:
				{
				//printf("AFEADSFASDFADSGFDSFADSF%d\n", lines[0]->rot(degree, lines[axis]->x1, lines[axis]->y1));
				Pos* p0=lines[0]->rot(degree, lines[axis]->x1, lines[axis]->y1);
				Pos* p1=lines[1]->rot(degree, lines[axis]->x1, lines[axis]->y1);
				Pos* p2=lines[2]->rot(degree, lines[axis]->x1, lines[axis]->y1);
				/*
				if(lines[2]->rot(degree, lines[axis]->x1, lines[axis]->y1) != 1)
				{
					printf("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee\n");
					break;
				}
				if(lines[1]->rot(degree, lines[axis]->x1, lines[axis]->y1) == 1)
				{
					printf("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee\n");
					break;
				}
				if(lines[0]->rot(degree, lines[axis]->x1, lines[axis]->y1) == 1)
				{
					printf("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee\n");
					break;
				}
				*/
				if(p0 !=0 && p1 != 0 && p2 != 0)
				{
					lines[0]->x1 = p0->x1;
					lines[0]->y1 = p0->y1;
					lines[0]->x2 = p0->x2;
					lines[0]->y2 = p0->y2;

					lines[1]->x1 = p1->x1;
					lines[1]->y1 = p1->y1;
					lines[1]->x2 = p1->x2;
					lines[1]->y2 = p1->y2;

					lines[2]->x1 = p2->x1;
					lines[2]->y1 = p2->y1;
					lines[2]->x2 = p2->x2;
					lines[2]->y2 = p2->y2;
				}
				break;
				}
			case 1:
				{
				Pos* p1=lines[1]->rot(degree, lines[axis]->x1, lines[axis]->y1);
				Pos* p2=lines[2]->rot(degree, lines[axis]->x1, lines[axis]->y1);
				if(p1 != 0 && p2 != 0)
				{

					lines[1]->x1 = p1->x1;
					lines[1]->y1 = p1->y1;
					lines[1]->x2 = p1->x2;
					lines[1]->y2 = p1->y2;

					lines[2]->x1 = p2->x1;
					lines[2]->y1 = p2->y1;
					lines[2]->x2 = p2->x2;
					lines[2]->y2 = p2->y2;
				}
				break;
				}
			case 2:
				{
				
				Pos* p2=lines[2]->rot(degree, lines[axis]->x1, lines[axis]->y1);
				if(p2 != 0)
				{

					
					lines[2]->x1 = p2->x1;
					lines[2]->y1 = p2->y1;
					lines[2]->x2 = p2->x2;
					lines[2]->y2 = p2->y2;
				}
				break;
				}
		}
		Fl::redraw();
		Fl::check();
	}
};
