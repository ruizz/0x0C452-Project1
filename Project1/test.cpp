#include "test.h";


Lines* arms;


void Drawing::draw()
{
	fl_color(FL_BLACK);
	//draw_line(XX+0,0,0,150);
	draw_line(arms->lines[0]->x1, arms->lines[0]->y1, arms->lines[0]->x2, arms->lines[0]->y2);
	fl_color(FL_BLUE);
	//draw_line(XX+0,150,0,100);
	draw_line(arms->lines[1]->x1, arms->lines[1]->y1, arms->lines[1]->x2, arms->lines[1]->y2);
	fl_color(FL_RED);
	//draw_line(XX+0,250,0,75);
	draw_line(arms->lines[2]->x1, arms->lines[2]->y1, arms->lines[2]->x2, arms->lines[2]->y2);
	//fl_arc(point(0).x,point(0).y,r+r,r+r,0,360);
	//fl_arc(100, 100, 200, 200, 0, 360);
	//fl_pie(0,0,200,200,0,360);
	fl_end_line();
}
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




int main(int argc, char **argv) {
	Fl_Window *window = new Fl_Window(1000,800);
	
	
	//fl_line(1,1,2,2);
	//fl_line(1,1,2,2);
	Drawing d(1,1,4,5);
	//Matrix a;
	//Line* l1 = new Line(0,0,0,150);
	//l1->rot(1);
	arms = new Lines();
	arms->rotate(2,0);

	arms->rotate(-40,1);
	arms->rotate(22,2);
	/*
	Fl::redraw();
	arms->rotate(2,2);
	Sleep(100);
	Fl::check();
	Fl::redraw();
	arms->rotate(1,1);
	Sleep(100);
	Fl::check();
	Fl::redraw();
	arms->rotate(1,0);
	Sleep(100);
	Fl::check();
	*/
	window->end();
	window->show(argc, argv);
	/*
	for(int i=0; i<100; i++)
	{
		//XX=i;
		
		Fl::redraw();
		Sleep(100);
		Fl::check();
	}
	*/
	return Fl::run();
}
