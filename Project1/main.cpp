#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Widget.H>
#include <FL/Fl_Button.H>

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

int main(int argc, char **argv) {
	Fl_Window window(10, 10, 950, 700, "PaintBot");

	FillBackground fillBackground(window.w(), window.h());
	Fl_Box drawSpace(30, 30, 890, 488, ""); drawSpace.box(FL_DOWN_BOX);
	Fl_Box controlPanel(30, 548, 890, 122, ""); controlPanel.box(FL_DOWN_BOX);


	Fl_Box joint1_txt(215, 550, 30, 15, "Joint 1");
	Fl_Button j1_cc(150, 570, 60, 30, "-");
	Fl_Button j1_cl(250, 570, 60, 30, "+");
	
	Fl_Box joint2_txt(460, 550, 30, 15, "Joint 2");
	Fl_Button j2_cc(395, 570, 60, 30, "-");
	Fl_Button j2_cl(495, 570, 60, 30, "+");

	Fl_Box joint3_txt(705, 550, 30, 15, "Joint 3");
	Fl_Button j3_cc(640, 570, 60, 30, "-");
	Fl_Button j3_cl(740, 570, 60, 30, "+");

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
