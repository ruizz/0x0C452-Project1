#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Widget.H>

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
	Fl_Window window(10, 10, 950, 700);

	FillBackground fillBackground(window.w(), window.h());
	Fl_Box drawSpace(30, 30, 890, 488, ""); drawSpace.box(FL_DOWN_BOX);
	Fl_Box controlPanel(30, 548, 890, 122, ""); controlPanel.box(FL_DOWN_BOX);

	window.show();
	return Fl::run();
}
