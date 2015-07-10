#include "declare.h"


void printscore(int score, int xcod, int ycod, float clr[3])
{
	int slength,i;
	snprintf(strscore, LEN, "%d", score);
	glColor3f(clr[0],clr[1],clr[2]);
	glRasterPos2f(xcod,ycod);
	slength = strlen(strscore);
	for( i = 0 ; i < slength ; i++ )
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,strscore[i]);

}

void printname(char *name, int xcod, int ycod, float clr[3])
{
	int slength,i;
	glColor3f(clr[0],clr[1],clr[2]);
	glRasterPos2f(xcod,ycod);
	slength = strlen(name);
	for( i = 0 ; i < slength ; i++ )
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,name[i]);
}

void changeDTFormat(char *pt)
{
	int i,j=0;
	char presdt[30];
	presdt[j++]=pt[8];
	presdt[j++]=pt[9];
  	for( i = 3 ; i <= 7 ; i++ )
  		presdt[j++]=pt[i];
  	for( i = 20 ; i <= 23 ; i++ )
  		presdt[j++]=pt[i];
  	presdt[j++] = ' ';
  	presdt[j++] = '-';
  	for( i = 10 ; i <= 19 ; i++ )
  		presdt[j++]=pt[i];
  	
  		
  	presdt[j] = '\0';
  	printname(presdt,width - 320,height - 50,coloryellow);
}

void setBounds()
{
	centerx = width/2, centery = height/2;

	start_screen_start_button_left = width/3 - 15;
	start_screen_start_button_right = width/3 + 85;
	start_screen_start_button_bottom = height/2 - 170;
	start_screen_start_button_top = height/2 - 135;

	start_screen_quit_button_left = width/3 + 365;
	start_screen_quit_button_right = width/3 + 465;
	start_screen_quit_button_bottom = height/2 - 170;
	start_screen_quit_button_top = height/2 - 135;

	start_screen_instruction_button_left = width/3 + 135;
	start_screen_instruction_button_right = width/3 + 315;
	start_screen_instruction_button_bottom = height/2 - 170;
	start_screen_instruction_button_top = height/2 - 135;

	pause_screen_resume_button_left = width/4 + 20;
	pause_screen_resume_button_right = width/4 + 140;
	pause_screen_resume_button_bottom = height/2 - 140;
	pause_screen_resume_button_top = height/2 - 105;

	pause_screen_quit_button_left = 3*width/4 - 140;
	pause_screen_quit_button_right = 3*width/4 - 20;
	pause_screen_quit_button_bottom = height/2 - 140;
	pause_screen_quit_button_top = height/2 - 105;

	ins_screen_back_button_left = 3*width/4 - 20;
	ins_screen_back_button_right = 3*width/4 + 80;
	ins_screen_back_button_bottom = 3*height/4;
	ins_screen_back_button_top = 3*height/4 + 35;
	
}

void reshape(int w, int h)
{
	width = (GLdouble) w;
	height = (GLdouble) h;
	setBounds();
	glViewport(0, 0, (GLsizei)width, (GLsizei)height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, width, 0.0, height);
	glMatrixMode(GL_MODELVIEW);
}
