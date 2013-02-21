#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Widget.H>
#include <FL/Fl_Button.H>
#include <../rotation.h>
#include <vector>

#define MIDDLEX 475


struct Pair{
	int x;
	int y;
	Pair(int x1, int y1) {
		x = x1;
		y = y1;
	}
};

int angle1 = 0;
int angle2 = 0;
int angle3 = 0;
bool painting = false;
std::vector<Pair> pairs;

Lines* arms;


void Drawing::draw()
{
	fl_color(FL_WHITE);
	//draw_line(XX+0,0,0,150);
	for (int i=0; i<pairs.size();i++){
		fl_pie(pairs[i].x, pairs[i].y, 10, 10, 0, 360);
	}
	draw_line(arms->lines[0]->x1, arms->lines[0]->y1, arms->lines[0]->x2, arms->lines[0]->y2);
	fl_color(FL_WHITE);
	//draw_line(XX+0,150,0,100);
	draw_line(arms->lines[1]->x1, arms->lines[1]->y1, arms->lines[1]->x2, arms->lines[1]->y2);
	fl_color(FL_WHITE);
	//draw_line(XX+0,250,0,75);
	draw_line(arms->lines[2]->x1, arms->lines[2]->y1, arms->lines[2]->x2, arms->lines[2]->y2);


	fl_color(255, 255, 255);
	//int x1 = (int)arms->lines[0]->x1, BY-arms->lines[0]->y1;
	//int y1 = y()-5;
	fl_pie(BX+arms->lines[0]->x1-5, BY-arms->lines[0]->y1-5, 10, 10, 0, 360);

	//int x1 = x()-5;
	//int y1 = y()-5;
	fl_pie(BX+arms->lines[1]->x1-5, BY-arms->lines[1]->y1-5, 10, 10, 0, 360);

	//int x1 = x()-5;
	//int y1 = y()-5;
	fl_pie(BX+arms->lines[2]->x1-5, BY-arms->lines[2]->y1-5, 10, 10, 0, 360);
	//fl_arc(point(0).x,point(0).y,r+r,r+r,0,360);
	//fl_arc(100, 100, 200, 200, 0, 360);
	//fl_pie(0,0,200,200,0,360);

	fl_pie(BX+arms->lines[2]->x2-5, BY-arms->lines[2]->y2-5, 10, 10, 0, 360);

	if(painting){
		pairs.push_back(Pair(BX+arms->lines[2]->x2-5, BY-arms->lines[2]->y2-5));
	}

	fl_end_line();
}


// Class that fills the entire window to a single color.
class FillBackground : public Fl_Widget {
public:
	FillBackground(int W, int Y) : Fl_Widget(0,0,W,Y,0) { }

	void draw() {
		fl_color(178, 207, 59); // Same color as the green on the website
		int x1 = w();
		int y1 = h();
		fl_rectf(0, 0, x1, y1);
	}
};

class FillBoxBackground : public Fl_Widget {
public:
	FillBoxBackground(int x, int y, int W, int H) : Fl_Widget(x, y, W, H,0) { }

	void draw() {
		fl_color(64, 79, 89);
		int w1 = w();
		int h1 = h();
		int x1 = x();
		int y1 = y();
		fl_rectf(x1, y1, w1, h1);
	}
};

class CreateBase : public Fl_Widget {
public:
	CreateBase(int x, int y, int W, int H) : Fl_Widget(x, y, W, H,0) { }

	void draw() {
		
		fl_color(255, 255, 255);
		int w1 = w();
		int h1 = h();
		int x1 = x();
		int y1 = y();
		fl_rectf(x1, y1, w1, h1);
	}
};

class CreateCircles : public Fl_Widget {
public:
	CreateCircles() : Fl_Widget(0, 0, 0, 0, 0) { }

	void draw() {
		//BX+arms->lines[0]->x1

		fl_color(255, 255, 255);
		//int x1 = (int)arms->lines[0]->x1, BY-arms->lines[0]->y1;
		//int y1 = y()-5;
		fl_pie(BX+arms->lines[0]->x1-5, BY-arms->lines[0]->y1-5, 10, 10, 0, 360);

		//int x1 = x()-5;
		//int y1 = y()-5;
		fl_pie(BX+arms->lines[1]->x1-5, BY-arms->lines[1]->y1-5, 10, 10, 0, 360);

		//int x1 = x()-5;
		//int y1 = y()-5;
		fl_pie(BX+arms->lines[2]->x1-5, BY-arms->lines[2]->y1-5, 10, 10, 0, 360);


	}
};

class CreateLine : public Fl_Widget {
public:
	CreateLine(int x1, int y1, int x2, int y2) : Fl_Widget(x1, y1, x2, y2,0) { }

	void draw() {
		fl_color(255, 255, 255);
		int x1 = x();
		int y1 = y();
		int x2 = w();
		int y2 = h();
		fl_line(x1, y1, x2, y2);
	}
};

class CreateBrush : public Fl_Widget {
public:
	CreateBrush(int x, int y) : Fl_Widget(x, y, 0, 0, 0) { }

	void draw() {
		fl_color(255, 255, 255);
		int x1 = x()-15;
		int y1 = y()-15;
		fl_pie(x1, y1, 30, 30, 0, 360);
	}
};

void Line::rot(double deg, double x_axis, double y_axis)
{
	Matrix* mat = new Matrix(4,1);
	mat->data[0][0] = x1-x_axis;
	mat->data[1][0] = y1-y_axis;
	mat->data[2][0] = 0;
	mat->data[3][0] = 1;
	Matrix* result = rotate(mat, deg, x_axis,y_axis);
	x1 = result->data[0][0];
	y1 = result->data[1][0];
	printf("=======================\n");
	for(int i=0; i<result->row; i++)
	{
		for(int j=0; j<result->col; j++)
		{
			printf("%f ", result->data[i][j]);
		}
		printf("\n");
	}

	Matrix* mat2 = new Matrix(4,1);
	mat2->data[0][0] = x2-x_axis;
	mat2->data[1][0] = y2-y_axis;
	mat2->data[2][0] = 0;
	mat2->data[3][0] = 1;
	Matrix* result2 = rotate(mat2, deg, x_axis,y_axis);
	x2 = result2->data[0][0];
	y2 = result2->data[1][0];
	printf("=======================\n");
	for(int i=0; i<result2->row; i++)
	{
		for(int j=0; j<result2->col; j++)
		{
			printf("%f ", result2->data[i][j]);
		}
		printf("\n");
	}
}

void j1_cc_callback(Fl_Widget*, void* v) {
	arms->rotate(1, 0);
}

void j1_cl_callback(Fl_Widget*, void* v) {
	arms->rotate(-1, 0);
}

void j2_cc_callback(Fl_Widget*, void* v) {
	arms->rotate(1, 1);
}

void j2_cl_callback(Fl_Widget*, void* v) {
	arms->rotate(-1, 1);
}

void j3_cc_callback(Fl_Widget*, void* v) {
	arms->rotate(1, 2);
}

void j3_cl_callback(Fl_Widget*, void* v) {
	arms->rotate(-1, 2);
}

void paint_callback(Fl_Widget*, void* v) {
	painting = !painting;
	if(painting){
		printf("Begin painting\n");

	}
	if(!painting){
		printf("End painting\n");
	}
}

int main(int argc, char **argv) {
	Fl_Window window(10, 10, 950, 700, "PaintBot");

	FillBackground fillBackground(window.w(), window.h());
	FillBoxBackground fillBoxBackground(31, 31, 888, 486);
	Fl_Box drawSpace(30, 30, 890, 488, ""); drawSpace.box(FL_DOWN_FRAME);
	Fl_Box controlPanel(30, 548, 890, 122, ""); controlPanel.box(FL_DOWN_BOX);

	Drawing d(1,1,4,5);

	CreateBase base(450,470, 50,30);

	arms = new Lines();

	CreateCircles joint1Circ();

	//CreateCircle joint2Circ(BX+arms->lines[1]->x1, BY-arms->lines[1]->y1);

	//CreateCircle joint3Circ(BX+arms->lines[2]->x1, BY-arms->lines[2]->y1);




	Fl_Box joint1_txt(215, 550, 30, 15, "Joint 1");
	Fl_Button j1_cc(150, 570, 60, 30, "-");
	Fl_Button j1_cl(250, 570, 60, 30, "+");

	j1_cc.callback(j1_cc_callback, NULL);
	j1_cl.callback(j1_cl_callback, NULL);

	Fl_Box joint2_txt(460, 550, 30, 15, "Joint 2");
	Fl_Button j2_cc(395, 570, 60, 30, "-");
	Fl_Button j2_cl(495, 570, 60, 30, "+");

	j2_cc.callback(j2_cc_callback, NULL);
	j2_cl.callback(j2_cl_callback, NULL);

	Fl_Box joint3_txt(705, 550, 30, 15, "Joint 3");
	Fl_Button j3_cc(640, 570, 60, 30, "-");
	Fl_Button j3_cl(740, 570, 60, 30, "+");

	j3_cc.callback(j3_cc_callback, NULL);
	j3_cl.callback(j3_cl_callback, NULL);

	Fl_Button paint(445, 610, 60, 30, "Paint");

	paint.callback(paint_callback, NULL);



	joint1_txt.show();
	joint2_txt.show();
	joint3_txt.show();

	j1_cc.show();
	j1_cl.show();

	j2_cc.show();
	j2_cl.show();

	j3_cc.show();
	j3_cl.show();

	paint.show();

	window.show();
	return Fl::run();
}
