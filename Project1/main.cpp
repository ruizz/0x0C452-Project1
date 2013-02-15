#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>

int main(int argc, char **argv) {
  Fl_Window *window = new Fl_Window(1020,765);
  Fl_Box *ctl = new Fl_Box(720,40,200,250,"");
  Fl_Box *drw_spc = new Fl_Box(20,40,600,500,"");

  ctl->box(FL_UP_BOX);
  drw_spc->box(FL_UP_BOX);

  window->end();
  window->show(argc, argv);
  return Fl::run();
}
