#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Widget.H>
#include <FL/Fl_Button.H>

#define MIDDLEX 475

int angle1 = 0;
int angle2 = 0;
int angle3 = 0;


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

class CreateCircle : public Fl_Widget {
public:
	CreateCircle(int x, int y) : Fl_Widget(x, y, 0, 0, 0) { }

	void draw() {
		fl_color(255, 255, 255);
		int x1 = x()-5;
		int y1 = y()-5;
		fl_pie(x1, y1, 10, 10, 0, 360);
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
		int x1 = x();
		int y1 = y();
		fl_circle(x1, y1, 5);
	}
};

void j1_cc_callback(Fl_Widget*, void* v) {

}

void j1_cl_callback(Fl_Widget*, void* v) {

}

void j2_cc_callback(Fl_Widget*, void* v) {

}

void j2_cl_callback(Fl_Widget*, void* v) {

}

void j3_cc_callback(Fl_Widget*, void* v) {

}

void j3_cl_callback(Fl_Widget*, void* v) {

}

int main(int argc, char **argv) {
	Fl_Window window(10, 10, 950, 700, "PaintBot");

	FillBackground fillBackground(window.w(), window.h());
	FillBoxBackground fillBoxBackground(31, 31, 888, 486);
	Fl_Box drawSpace(30, 30, 890, 488, ""); drawSpace.box(FL_DOWN_FRAME);
	Fl_Box controlPanel(30, 548, 890, 122, ""); controlPanel.box(FL_DOWN_BOX);
	
	CreateBase base(450,460, 50,30);

	CreateCircle joint1Circ(475, 460);
	CreateLine link1(475, 460, 475, 325);
	
	CreateCircle joint2Circ(475, 330);
	CreateLine link2(475, 325, 475, 225);

	CreateCircle joint3Circ(475, 230);
	CreateLine link3(475, 225, 475, 150);

	CreateBrush brush(475, 150);
	
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
