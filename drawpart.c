#include "declare.h"

struct tm *ptime;
time_t gametime;


void drawTriangles();
void drawFilledCircle(int,int,float);
void drawellipse(int,int);

void drawPattern(float x, float y)
{
	int angl,i;
	int brad;

	glBegin(GL_POINTS);
	for( brad = 0 ; brad <= 5 ; brad++ )
	{
		if (viewstate == 2)
			glColor3d(1,1,1);
		else
			glColor3d((rand()%255)/255.0,(rand()%255)/255.0,(rand()%255)/255.0);

		for( i=0 ; i < 360 ; i++ )
		{
			angl = rand()%360;
			glVertex2f(x+(brad*cos(M_PI*angl/180)),y+(brad*sin(M_PI*angl/180)));
		}
	}
	glEnd();
}

void drawStartScreen()
{
	float brad;
	int angl,i;

	glBegin(GL_POINTS);
	for( brad = 0 ; brad <= 800 ; brad +=2 )
	{
		if (viewstate == 2)
			glColor3d(1,1,1);
		else
			glColor3d((rand()%255)/255.0,(rand()%255)/255.0,(rand()%255)/255.0);
		for( angl=0 ; angl < 360 ; angl++ )
		{
			glVertex2f(width/2+(brad*cos(M_PI*angl/180)),height/2+(brad*sin(M_PI*angl/180)));
		}
		
	}
	glEnd();

	//Box for Date/Time
	glLineWidth(4);
	glColor3d(0.0,0.6,0.0);
	//glPolygonMode(GL_FRONT,GL_FILL);
	glBegin(GL_LINE_LOOP);
	glVertex2d(width - 330,height - 60);
	glVertex2d(width - 330,height - 25);
	glVertex2d(width - 80,height - 25);
	glVertex2d(width - 80,height - 60);
	glEnd();

	//Box for High score
	glLineWidth(4);
	glColor3d(0.0,0.6,0.0);
	//glPolygonMode(GL_FRONT,GL_FILL);
	glBegin(GL_LINE_LOOP);
	glVertex2d(30,height - 60);
	glVertex2d(30,height - 25);
	glVertex2d(235,height - 25);
	glVertex2d(235,height - 60);
	glEnd();

	glLineWidth(2);
	//Box for Start button
	if(start_screen_mouse_start_button)
	{
		glColor3f(0.584,0.596,0.612);
		glBegin(GL_POLYGON);
		glVertex2d(start_screen_start_button_left,start_screen_start_button_bottom);
		glVertex2d(start_screen_start_button_left,start_screen_start_button_top);
		glVertex2d(start_screen_start_button_right,start_screen_start_button_top);
		glVertex2d(start_screen_start_button_right,start_screen_start_button_bottom);
		glEnd();
	}
	glColor3f(0.357,0.631,0.97);
	glBegin(GL_LINE_LOOP);
	glVertex2d(start_screen_start_button_left,start_screen_start_button_bottom);
	glVertex2d(start_screen_start_button_left,start_screen_start_button_top);
	glVertex2d(start_screen_start_button_right,start_screen_start_button_top);
	glVertex2d(start_screen_start_button_right,start_screen_start_button_bottom);
	glEnd();

	//Box for Quit button
	glLineWidth(2);
	if(start_screen_mouse_quit_button)
	{
		glColor3f(0.584,0.596,0.612);
		glBegin(GL_POLYGON);
		glVertex2d(start_screen_quit_button_left,start_screen_quit_button_bottom);
		glVertex2d(start_screen_quit_button_left,start_screen_quit_button_top);
		glVertex2d(start_screen_quit_button_right,start_screen_quit_button_top);
		glVertex2d(start_screen_quit_button_right,start_screen_quit_button_bottom);
		glEnd();
	}
	glColor3f(0.357,0.631,0.97);
	glBegin(GL_LINE_LOOP);
	glVertex2d(start_screen_quit_button_left,start_screen_quit_button_bottom);
	glVertex2d(start_screen_quit_button_left,start_screen_quit_button_top);
	glVertex2d(start_screen_quit_button_right,start_screen_quit_button_top);
	glVertex2d(start_screen_quit_button_right,start_screen_quit_button_bottom);
	glEnd();

	//Box for Instructions button
	glLineWidth(2);
	if(start_screen_mouse_instruction_button)
	{
		glColor3f(0.584,0.596,0.612);
		glBegin(GL_POLYGON);
		glVertex2d(start_screen_instruction_button_left,start_screen_instruction_button_bottom);
		glVertex2d(start_screen_instruction_button_left,start_screen_instruction_button_top);
		glVertex2d(start_screen_instruction_button_right,start_screen_instruction_button_top);
		glVertex2d(start_screen_instruction_button_right,start_screen_instruction_button_bottom);
		glEnd();
	}
	glColor3f(0.357,0.631,0.97);
	glBegin(GL_LINE_LOOP);
	glVertex2d(start_screen_instruction_button_left,start_screen_instruction_button_bottom);
	glVertex2d(start_screen_instruction_button_left,start_screen_instruction_button_top);
	glVertex2d(start_screen_instruction_button_right,start_screen_instruction_button_top);
	glVertex2d(start_screen_instruction_button_right,start_screen_instruction_button_bottom);
	glEnd();

}

void drawPauseScreen()
{
	drawTriangles();

	

	//Box
	glLineWidth(4);
	glColor3d(0.5,1.0,0.5);
	glBegin(GL_LINE_LOOP);
	glVertex2d(width/4,height/4 - 20);
	glVertex2d(width/4,3*height/4 + 20);
	glVertex2d(3*width/4,3*height/4 + 20);
	glVertex2d(3*width/4,height/4 - 20);
	glEnd();

	//Box for Your score
	glLineWidth(3);
	glColor3d(0.0,0.6,0.0);
	//glPolygonMode(GL_FRONT,GL_FILL);
	glBegin(GL_LINE_LOOP);
	glVertex2d(width - 230,height - 60);
	glVertex2d(width - 230,height - 25);
	glVertex2d(width - 20,height - 25);
	glVertex2d(width - 20,height - 60);
	glEnd();

	
	//Box for Resume button
	glLineWidth(2);
	if(pause_screen_mouse_resume_button)
	{
		glColor3f(0.584,0.596,0.612);
		glBegin(GL_POLYGON);
		glVertex2d(pause_screen_resume_button_left,pause_screen_resume_button_bottom);
		glVertex2d(pause_screen_resume_button_left,pause_screen_resume_button_top);
		glVertex2d(pause_screen_resume_button_right,pause_screen_resume_button_top);
		glVertex2d(pause_screen_resume_button_right,pause_screen_resume_button_bottom);
		glEnd();
	}
	glColor3f(0.357,0.631,0.97);
	glBegin(GL_LINE_LOOP);
	glVertex2d(pause_screen_resume_button_left,pause_screen_resume_button_bottom);
	glVertex2d(pause_screen_resume_button_left,pause_screen_resume_button_top);
	glVertex2d(pause_screen_resume_button_right,pause_screen_resume_button_top);
	glVertex2d(pause_screen_resume_button_right,pause_screen_resume_button_bottom);
	glEnd();

	//Box for Quit button
	glLineWidth(2);
	if(pause_screen_mouse_quit_button)
	{
		glColor3f(0.584,0.596,0.612);
		glBegin(GL_POLYGON);
		glVertex2d(pause_screen_quit_button_left,pause_screen_quit_button_bottom);
		glVertex2d(pause_screen_quit_button_left,pause_screen_quit_button_top);
		glVertex2d(pause_screen_quit_button_right,pause_screen_quit_button_top);
		glVertex2d(pause_screen_quit_button_right,pause_screen_quit_button_bottom);
		glEnd();
	}
	glColor3f(0.357,0.631,0.97);
	glBegin(GL_LINE_LOOP);
	glVertex2d(pause_screen_quit_button_left,pause_screen_quit_button_bottom);
	glVertex2d(pause_screen_quit_button_left,pause_screen_quit_button_top);
	glVertex2d(pause_screen_quit_button_right,pause_screen_quit_button_top);
	glVertex2d(pause_screen_quit_button_right,pause_screen_quit_button_bottom);
	glEnd();


}

void drawFinalTYScreen()
{
	int i;
 
	//Outer Boundary
	glLineWidth(2);
	glColor3d(0.5,1.0,0.5);
	glBegin(GL_LINE_LOOP);
	glVertex2d(25,25);
	glVertex2d(25,height - 25);
	glVertex2d(width - 25,height - 25);
	glVertex2d(width - 25,25);
	glEnd();

	//Inner Box
	glLineWidth(2);
	glColor3d(0.5,1.0,0.5);
	glBegin(GL_LINE_LOOP);
	glVertex2d(width/4,height/4);
	glVertex2d(width/4,3*height/4);
	glVertex2d(3*width/4,3*height/4);
	glVertex2d(3*width/4,height/4);
	glEnd();

	glBegin(GL_LINES);
	glColor3d(0.5,1.0,0.5);
	glVertex2d(width/4,0.65*height);
	glVertex2d(3*width/4,0.65*height);
	glEnd();

	for( i = 0 ; i < 25 ; i++ )
	{
		drawPattern(rand()%width, rand()%height);
	}

}

void drawInstructionScreen()
{
	//Outer Boundary
	glLineWidth(2);
	glColor3d(0.5,1.0,0.5);
	glBegin(GL_LINE_LOOP);
	glVertex2d(25,25);
	glVertex2d(25,height - 25);
	glVertex2d(width - 25,height - 25);
	glVertex2d(width - 25,25);
	glEnd();


	//Box for Back button
	glLineWidth(2);
	if(ins_screen_mouse_back_button)
	{
		glColor3f(0.584,0.596,0.612);
		glBegin(GL_POLYGON);
		glVertex2d(ins_screen_back_button_left,ins_screen_back_button_bottom);
		glVertex2d(ins_screen_back_button_left,ins_screen_back_button_top);
		glVertex2d(ins_screen_back_button_right,ins_screen_back_button_top);
		glVertex2d(ins_screen_back_button_right,ins_screen_back_button_bottom);
		glEnd();
	}
	glColor3f(0.357,0.631,0.97);
	glBegin(GL_LINE_LOOP);
		glVertex2d(ins_screen_back_button_left,ins_screen_back_button_bottom);
		glVertex2d(ins_screen_back_button_left,ins_screen_back_button_top);
		glVertex2d(ins_screen_back_button_right,ins_screen_back_button_top);
		glVertex2d(ins_screen_back_button_right,ins_screen_back_button_bottom);
	glEnd();



}


void drawbase()
{
	glPointSize(1);
	glColor3d(0.0,0.6,0.0);
	glPolygonMode(GL_FRONT,GL_FILL);
	glBegin(GL_POLYGON);
	glVertex2d(25,0);
	glVertex2d(25,25);
	glVertex2d(width,25);
	glVertex2d(width,0);
	glEnd();
}

void drawleftend()
{
	glPointSize(1);
	glColor3d(0.6,0.6,0.0);
	glPolygonMode(GL_FRONT,GL_FILL);
	glBegin(GL_POLYGON);
	glVertex2d(0,0);
	glVertex2d(0,height);
	glVertex2d(25,height);
	glVertex2d(25,0);
	glEnd();
}


void drawball(float rad)
{
	int angl;
	int i;
  	float angle,x1,y1,x2,y2,x3,y3,len_antenna = 1.8*rad;
    float eye_rad = 0.1*rad,cx_eye,cy_eye,step;

	glLineWidth(2.5);


    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
        x2 = ballcx-len_antenna*sin(M_PI/8);
        y2 = ballcy+len_antenna*cos(M_PI/8);
        glVertex2f(ballcx,ballcy); glVertex2f(x2,y2);
        x2 = ballcx+len_antenna*sin(M_PI/8);
        y2 = ballcy+len_antenna*cos(M_PI/8);
        glVertex2f(ballcx,ballcy); glVertex2f(x2,y2);
    glEnd();


    glColor3f(1.0, 0.0, 0.0);
    step = 0.02;
    glBegin(GL_POLYGON);
        for(angle=0; angle <= M_PI; angle+=step)
          {
              x1  = ballcx +rad * cos(angle);
              y1  = ballcy +rad * sin(angle);
              glVertex3f(x1,y1,0.0f);
          }
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(ballcx-rad,ballcy+2,0);
        glVertex3f(ballcx+rad,ballcy+2,0);
        glVertex3f(ballcx+rad,ballcy-rad/4.0,0);
        glVertex3f(ballcx-rad,ballcy-rad/4.0,0);
        glVertex3f(ballcx-rad,ballcy,0);
    glEnd();

        x1=ballcx-rad;
        y1=ballcy-rad/4.0;
        x2=x1+rad/8;
        y2=y1- rad*cos(M_PI/6)/4;
        x3=x1+rad/4.0;
        y3=y1;

    glBegin(GL_TRIANGLES);
        for(i=0;i<8;i++)
        {
            glVertex3f(x1,y1,0);
            glVertex3f(x2,y2,0);
            glVertex3f(x3,y3,0);
            x1+=rad/4.0;x2+=rad/4.0;x3+=rad/4.0;
        }
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
        step=0.01; cx_eye=ballcx-rad*sin(M_PI/4)/2; cy_eye=ballcy+rad*cos(M_PI/4)/2;
        for(angle=-M_PI; angle <= M_PI; angle+=step)
          {
              x1  = cx_eye +eye_rad * cos(angle);
              y1  = cy_eye +eye_rad * sin(angle);
              glVertex3f(x1,y1,0.0f);
          }
    glEnd();

    glBegin(GL_POLYGON);
        step=0.01; cx_eye=ballcx + rad*sin(M_PI/4)/2; cy_eye=ballcy+rad*cos(M_PI/4)/2;
        for(angle=-M_PI; angle <= M_PI; angle+=step)
          {
              x1  = cx_eye +eye_rad * cos(angle);
              y1  = cy_eye +eye_rad * sin(angle);
              glVertex3f(x1,y1,0.0f);
          }
    glEnd();

}


void drawblock(float x1, float y1, float x2, float y2)
{
	int h = 350,i;
	float ty = (y2 - y1)/3;
	float tx = (x2 - x1)/3; 
	glPointSize(1);
	glColor3d(0.6,0.2,0.15);
	glPolygonMode(GL_FRONT,GL_FILL);
	glBegin(GL_POLYGON);
	glVertex2d(x1,y1);
	glVertex2d(x1,y2);
	glVertex2d(x2,y2);
	glVertex2d(x2,y1);
	glEnd();

	glBegin(GL_LINES);
	glLineWidth(0.5);
	glColor3f(0,0,0);
	for( i = y1 + 2 ; i <= y2 ; i += 15)
	{
		glVertex2d(x1, i);
		glVertex2d(x2, i);
	}
	glEnd();

}

void drawGrab(float x1, float y1, float x2, float y2)
{
	glPointSize(1);
	glColor3d(1.0,1.0,0.0);
	glPolygonMode(GL_FRONT,GL_FILL);
	glBegin(GL_POLYGON);
	glVertex2d(x1,y1);
	glVertex2d(x1,y2);
	glVertex2d(x2,y2);
	glVertex2d(x2,y1);
	glEnd();
}

void clearGrab(float x1, float y1, float x2, float y2)
{
	glPointSize(1);
	glColor3d(0.0,1.0,1.0);
	glPolygonMode(GL_FRONT,GL_FILL);
	glBegin(GL_POLYGON);
	glVertex2d(x1,y1);
	glVertex2d(x1,y2);
	glVertex2d(x2,y2);
	glVertex2d(x2,y1);
	glEnd();
}

void drawTrapTriangles(int x, int y)
{
	int i;
	glBegin(GL_TRIANGLES);
	glColor3f(0.3,0.3,0.3);
	for( i = 0 ; i < 5 ; i++ )
	{
		glVertex2d(x,y);
		glVertex2d(x+10,y+20);
		glVertex2d(x+20,y);
		x = x + 20;
	}
	glEnd();

}

void drawTriangles()
{

	triangle_current_angle += triangle_rotate_by;
	//Make sure angle doesn't cross 360
	if ( triangle_current_angle > 360 )
	{
		triangle_current_angle = triangle_current_angle - 360 * floor(triangle_current_angle/360.0);
	}
		
	//To Rotate the Triangle
	glMatrixMode( GL_MODELVIEW );
	glPushMatrix();			
	glLoadIdentity();						
	glTranslatef( centerx, centery, 0.0 );					//Translate axis to center of screen
	glRotatef( triangle_current_angle, 0.0, 0.0, 1.0 );		// Rotate through animation angle
	glTranslatef( -centerx, -centery, 0.0 );			// Translate back the axis

	// Draw three overlapping triangles of different colors
	glBegin(GL_TRIANGLES);

	glColor3f(1,0,0);
	glVertex2d(centerx,centery + 200);
	glVertex2d(centerx - 183,centery - 100);
	glVertex2d(centerx - 163,centery - 100);

	glColor3f(0,1,0);
	glVertex2d(centerx - 173,centery - 100);
	glVertex2d(centerx + 173,centery - 90); 
	glVertex2d(centerx + 173,centery - 110);

	glColor3f(0,0,1);
	glVertex2d(centerx + 173,centery - 100);
	glVertex2d(centerx - 10,centery + 200); 
	glVertex2d(centerx + 10,centery + 200);



	glEnd();	

	glPopMatrix();

	
}


void drawPendant(int x, int y)
{
 	glColor3d(0.0,0.0,0.0);
   	drawFilledCircle(x,y,16);
   	glColor3d(1.0,1.0,0.0);
   	drawFilledCircle(x,y,15);
   	glColor3d(0.0,0.0,0.0);
   	drawFilledCircle(x,y,9);
   	glColor3d(0.0,0.5,1.0);
   	drawFilledCircle(x,y,8);
   	glColor3d(0.0,0.0,0.0);
   	drawellipse(x,y + 25);
}


void drawellipse(int xo,int yo)
{
	int p,a,b;
	a=15; 
	b=10;
 
	p=4*(b*b-a*a*b)+(a*a);
 
	int x,y;
	x=0;
	y=b;
  	
  	glBegin(GL_POINTS);
  	glVertex2i(x+xo,y+yo);
  	glVertex2i(x+xo,-y+yo);
  	glVertex2i(-x+xo,y+yo);
  	glVertex2i(-x+xo,-y+yo);
  	glEnd();


	while((2*b*b*x)<=(2*a*a*y))
	{ 
  		if(p<0)
  		{
   			x=x+1;
   			y=y;
   			p=p+4*b*b*(2*x+3);
  		}
		else
		{
		   x=x+1;
		   y=y-1;
		   p=p+4*(b*b*(2*x+3)-(2*a*a*(y-1)));
  		}
  
  		glBegin(GL_POINTS);
  		glVertex2i(x+xo,-y+yo);
  		glVertex2i(-x+xo,-y+yo);
  		glEnd();

	}
	p=4*(b*b*(4*x+1)+(4*a*a*(1-2*y)));
	
	while(y>0)
	{ 
  		if(p>0)
  		{
  			x=x;
   			y=y-1;
   			p=p+(4*a*a*(-2*y+3));
  		}
		else
 		{ 
   			x=x+1;
   			y=y-1;
   			p=p+4*(2*b*b*(x+1)+a*a*(3-2*y));
  		}
  
  		glBegin(GL_POINTS);
  		//glVertex2i(x+xo,y+yo);
  		glVertex2i(x+xo,-y+yo);
  		//glVertex2i(-x+xo,y+yo);
  		glVertex2i(-x+xo,-y+yo);
  		glEnd();
	}
} 



void drawbattery(int x1,int y1)
{

  glPointSize(1);
  glColor3d(0.5,0.5,0.5);
  glPolygonMode(GL_FRONT,GL_FILL);
  glBegin(GL_TRIANGLES);
  glVertex2d(x1,y1);
  glVertex2d(x1,y1-30);
  glVertex2d(x1+20,y1-30);
  glEnd();
  glBegin(GL_TRIANGLES);
  glVertex2d(x1,y1);
  glVertex2d(x1+20,y1);
  glVertex2d(x1+20,y1-30);
  glEnd();

  glColor3d(0.1,0.0,0.1);
  glBegin(GL_TRIANGLES);
  glVertex2d(x1+6,y1);
  glVertex2d(x1+6,y1+5);
  glVertex2d(x1+15,y1);
  glEnd();
  
  glBegin(GL_TRIANGLES);
  glVertex2d(x1+6,y1+5);
  glVertex2d(x1+15,y1+5);
  glVertex2d(x1+15,y1);
  glEnd();
  glLineWidth(1.0);
  glColor3d(1.0,0.0,0.0);
  glBegin(GL_LINES);
  glVertex2d(x1,y1-15);
  glVertex2d(x1+20,y1-15);
  glEnd();

	// drawing +
  glColor3d(1.0,1.0,0.0);
   glBegin(GL_LINES);
  glVertex2d(x1+10,y1-13);
  glVertex2d(x1+10,y1-5);
  glEnd();
   glBegin(GL_LINES);
  glVertex2d(x1+6,y1-9);
  glVertex2d(x1+13,y1-9);
  glEnd();

	//drawing -
   glBegin(GL_LINES);
  glVertex2d(x1+6,y1-23);
  glVertex2d(x1+12,y1-23);
  glEnd();

}


void triangle(int x, int y)
{

	glBegin(GL_TRIANGLES);
	glVertex2d(x - 70, y - 50);
	glVertex2d(x - 60, y - 50);
	glVertex2d(x - 20, y - 15);
	glEnd();
 	glBegin(GL_TRIANGLES);
	glVertex2d(x + 70, y - 50);
	glVertex2d(x + 60, y - 50);
	glVertex2d(x + 20, y - 15);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex2d(x - 5, y - 50);
	glVertex2d(x + 5, y - 50);
	glVertex2d(x, y - 15);
	glEnd();

}



void drawSpaceShipEllipse(int xo, int yo, int a, int b)
{
	int p;

 
 	p=4*(b*b-a*a*b)+(a*a);

 
 	int x,y;
 	x=0;
 	y=b;
  	glBegin(GL_POINTS);
  	glVertex2i(x+xo,y+yo);
  	glVertex2i(x+xo,-y+yo);
  	glVertex2i(-x+xo,y+yo);
  	glVertex2i(-x+xo,-y+yo);
  	glEnd();


while((2*b*b*x)<=(2*a*a*y))
{ 
  if(p<0)
  {
   x=x+1;
   y=y;
   p=p+4*b*b*(2*x+3);
  }
else
 { 
   x=x+1;
   y=y-1;
   p=p+4*(b*b*(2*x+3)-(2*a*a*(y-1)));
  }
  glBegin(GL_POINTS);
  glVertex2i(x+xo,y+yo);
  glVertex2i(x+xo,-y+yo);
  glVertex2i(-x+xo,y+yo);
  glVertex2i(-x+xo,-y+yo);
  glEnd();
}
p=4*(b*b*(4*x+1)+(4*a*a*(1-2*y)));
while(y>0)
{ 
  if(p>0)
  {
   x=x;
   y=y-1;
   p=p+(4*a*a*(-2*y+3));
  }
else
 { 
   x=x+1;
   y=y-1;
   p=p+4*(2*b*b*(x+1)+a*a*(3-2*y));
  }
  glBegin(GL_POINTS);
  glVertex2i(x+xo,y+yo);
  glVertex2i(x+xo,-y+yo);
  glVertex2i(-x+xo,y+yo);
  glVertex2i(-x+xo,-y+yo);
  glEnd();
}
if(a>0)
{
	drawSpaceShipEllipse(xo,yo,a-1,b);
}


}


void drawCircle(int xo,int yo,float rad)
{
  float bradius = rad;
  int angl;
  int x=xo;
  int y=yo;
  glBegin(GL_POINTS);
    for( angl=0 ; angl < 360 ; angl++ )
    {
      glVertex2f(xo+(bradius*cos(M_PI*angl/180)),yo+(bradius*sin(M_PI*angl/180)));
    }

  glEnd();
}

void drawFilledCircle(int xo,int yo,float rad)
{
  float bradius = rad;
  int angl;
  int x=xo;
  int y=yo;
  glBegin(GL_POINTS);
  if(bradius >= 0)
  {
    for( angl=0 ; angl < 360 ; angl++ )
    {
      glVertex2f(xo+(bradius*cos(M_PI*angl/180)),yo+(bradius*sin(M_PI*angl/180)));
    }
    drawFilledCircle(x,y,bradius-1);
  }
  glEnd();
} 

void drawSpaceShip(int x, int y)
{
	glColor3f(0.0, 0.0,0.0);

   drawCircle(x, y + 20, 30);//semicircle Boundary
   glColor3f(0.97, 0.97,1.0);
   
   drawFilledCircle(x, y + 20, 29);//semicircle

   glColor3f(0.0, 0.0,0.0);//ellipse
   glColor3f(0.75, 0.75,0.75);//ellipse
   drawSpaceShipEllipse(x, y,80,20); 
   
   drawCircle(x - 50, y,10);
   drawCircle(x, y,10);
   drawCircle(x + 50, y,10);
   glColor3f(0.0, 0.0,1.0);
   drawFilledCircle(x - 50, y,9); 
   drawFilledCircle(x, y,9);
   drawFilledCircle(x + 50, y,9);
   
   glColor3f(0.0, 0.0,0.0);
   triangle(x, y);
}


void drawRadioComponents(int x1,int y1)
{
  glPointSize(1);
  glColor3d(1.0,1.0,0.0);
  glPolygonMode(GL_FRONT,GL_FILL);
  glBegin(GL_TRIANGLES);
  glVertex2d(x1,y1);
  glVertex2d(x1+75,y1);
  glVertex2d(x1,y1-35);
  glEnd();
  glBegin(GL_TRIANGLES);
  glVertex2d(x1+75,y1);
  glVertex2d(x1,y1-35);
  glVertex2d(x1+75,y1-35);
  glEnd();
  glLineWidth(1.0);
  glColor3d(0.0,0.0,0.0);
  glBegin(GL_LINES);
  //Plus 
  glVertex2d(x1+14,y1-20);
  glVertex2d(x1+26,y1-20);
  glEnd();
   glBegin(GL_LINES);
  glVertex2d(x1+20,y1-14);
  glVertex2d(x1+20,y1-26);
  glEnd();
  glBegin(GL_LINES);
  glVertex2d(x1+54,y1-20);
  glVertex2d(x1+66,y1-20);
  glEnd();
  glBegin(GL_LINES);
  glVertex2d(x1+60,y1-14);
  glVertex2d(x1+60,y1-26);
  glEnd();
  //antennae
  glColor3d(1.0,0.0,0.0);
  glBegin(GL_LINES);
  glVertex2d(x1+40,y1);
  glVertex2d(x1+60,y1+25);
  glEnd();
  glBegin(GL_LINES);
  glVertex2d(x1+40,y1);
  glVertex2d(x1+20,y1+25);
  glEnd();
   //knob
  glBegin(GL_TRIANGLES);
  glVertex2d(x1+75,y1-5);
  glVertex2d(x1+80,y1-5);
  glVertex2d(x1+75,y1-15);
  glEnd();
  glBegin(GL_TRIANGLES);
  glVertex2d(x1+80,y1-5);
  glVertex2d(x1+75,y1-15);
  glVertex2d(x1+80,y1-15);
  glEnd();
  //green line
  glColor3d(0.0,1.0,0.0);
  glBegin(GL_LINES);
  glVertex2d(x1+28,y1-13);
  glVertex2d(x1+52,y1-13);
  glEnd();
  glBegin(GL_LINES);
  glVertex2d(x1+32,y1-20);
  glVertex2d(x1+48,y1-20);
  glEnd();
  glColor3d(0.0,0.0,0.0);
  glLineWidth(1);
  glBegin(GL_LINE_LOOP);
  glVertex2d(x1,y1);
  glVertex2d(x1+75,y1);
  glVertex2d(x1+75,y1-35);
  glVertex2d(x1,y1-35);
  glEnd();

}


void drawRadio(int rx, int ry)
{
	drawRadioComponents(rx,ry);
	glColor3d(0,0,0);
	drawCircle(rx + 20, ry - 20, 7);
    drawCircle(rx + 60, ry - 20, 7);
    glColor3d(1,0,0);
    drawFilledCircle(rx + 20, ry + 25, 2);
    drawFilledCircle(rx + 60, ry + 25, 2);
}

void timerHand(int x, int y)
{
 
	glBegin(GL_TRIANGLES);
    glVertex2d( x + 4, y);
    glVertex2d( x - 4, y);
    glVertex2d( x , y + 45);
 	glEnd();

}

void drawCleanCircle(int x, int y, float rad)
{
 	float step=0.02,angle;
  	float x1,y1;
  	glPolygonMode(GL_FRONT,GL_FILL);
    glBegin(GL_POLYGON);
     for( angle = -M_PI ; angle <= M_PI ; angle += step)
          {
              x1  = ballcx + rad * cos(angle);
              y1  = ballcy + rad * sin(angle);
              glVertex2d(x,y);
          }
    glEnd();
}




void drawTimer(int cx,int cy)
{
	time(&gametime);
    ptime = localtime(&gametime);
	int i;
	glColor3d(0,0,0);
	glPointSize(2);
	drawCircle(cx, cy,53);
	glColor3d(0,0,1);
	drawCleanCircle(cx,cy,50);
	glColor3d(1,0,0);
	drawCleanCircle(cx,cy,6);


	
	glPointSize(2);
    glBegin(GL_POINTS);
    for( i = 0 ; i < 360 ; i += 6 )
 	{
    	glVertex2d( cx + 45 * cos(M_PI * i / 180.0), cy + 45 * sin(M_PI * i / 180) );
   
 	}
 	glEnd();

 	//Timer Hand
 	glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    glTranslatef(cx, cy, 0);
    if( tc < maxtime )
    {
    	glRotatef( -6 * tc, 0, 0, 1);
    }
    timerHand(0, 0);
    glTranslatef(-cx, -cy, 0);
    glPopMatrix();
   
	if(t != ptime->tm_sec)
	{
  		tc++;
   		t = ptime->tm_sec;
   	}


}

