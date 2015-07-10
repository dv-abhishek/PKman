#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <GL/glut.h>

#define UNIT_MOVE 3
#define UNIT_JMP 3
#define LEN 8
#define FPS 200
#define freeangle 90
#define GRAB 12
#define BLK 19
#define SDISY 305
#define PDISY 280
#define PDISUY 210
#define IDISBY 418
#define GBCOL 2
#define ballradup 20
#define ballraddown 11


#include "declare.h"
#include "drawpart.c"
#include "call.c"
#include "colldetect.c"
#include "file_operation.c"
#include "extras.c"

time_t present_time;

struct batterygrab
{
	float batteryx,batteryy;
	bool batteryvisible;
}battery[GRAB];

struct squareblock
{
	float blockx1,blockx2,blocky1,blocky2;
}block[BLK];

bool movleft=false,movright=false,movup=false,movdown=false,rjump=false,ljump=false;
int width = 1250, height = 700;
int gamestate,collisionstate=0;

char strscore[LEN];

float highscore, score = 0, scr = 0 ;

//Ball Center co-ordinates
float ballcx, ballcy;
float ballrad = 20;

float bx,by;

//Projectile
float inivel=50,g = 9.8;
float angle=70;
float delt,tof;

bool collide,ffall=false;

//mouse location boolean check
bool start_screen_mouse_start_button,start_screen_mouse_quit_button,start_screen_mouse_instruction_button;
bool pause_screen_mouse_resume_button,pause_screen_mouse_quit_button;
bool ins_screen_mouse_back_button;

//Button bounds
int start_screen_start_button_left, start_screen_start_button_right, start_screen_start_button_bottom, start_screen_start_button_top;
int start_screen_quit_button_left, start_screen_quit_button_right, start_screen_quit_button_bottom, start_screen_quit_button_top;
int pause_screen_resume_button_left, pause_screen_resume_button_right, pause_screen_resume_button_bottom, pause_screen_resume_button_top;
int pause_screen_quit_button_left, pause_screen_quit_button_right, pause_screen_quit_button_bottom, pause_screen_quit_button_top;
int start_screen_instruction_button_left, start_screen_instruction_button_right,start_screen_instruction_button_bottom ,start_screen_instruction_button_top;
int ins_screen_back_button_left, ins_screen_back_button_right,ins_screen_back_button_bottom ,ins_screen_back_button_top;

//Color rgb value
float colorblack[3],colorgreen[3],colorred[3],coloryellow[3],colorsnow[3],colorsandybrown[3],colortomato[3],colorgold[3],colorteal[3];

int viewstate = 1;

float triangle_current_angle = 0, triangle_rotate_by = 3;

float centerx, centery;

//Radio collect
bool radionotcollected = true;
int radiox = 1275, radioy = 450;

//Pendant
bool pendantnotcollected = true;
int pendantx = 130, pendanty = 420;

//SpaceShip
bool spaceshipnotcollected = true;
int spaceshipx = 1100, spaceshipy = 75;

//Timer
int tc = 0, t, maxtime = 60, collecttime = 200, traptime = 200;

//Trap
bool trapped = false;

//Start Screen
float ss,alp;
static float sa = 0;


void ballmove();
void freefall();

void myinit()
{
	int i;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,width,0,height);
	colorblack[0] = colorblack[1] = colorblack[2] = colorred[1] = colorred[2] = colorgreen[0] = colorgreen[2] = coloryellow[2] = colorteal[0] = 0;
	colorred[0] = colorgreen[1] = coloryellow[0] = coloryellow[1] = colorteal[1] = colorteal[2] = 1;
	colortomato[0] = 1, colortomato[1] = 63/255.0, colortomato[2] = 47/255.0;
	colorsnow[0] = 1, colorsnow[1] = 251/255.0, colorsnow[2] = 251/255.0;
	colorsandybrown[0] = 244/255.0, colorsandybrown[1] = 164/255.0, colorsandybrown[2] = 60/255.0;
	colorgold[0] = 1, colorgold[1] = 215/255.0, colorgold[2] = 0;

	start_screen_mouse_start_button = start_screen_mouse_quit_button = start_screen_mouse_instruction_button = false;
	pause_screen_mouse_resume_button = pause_screen_mouse_quit_button = false;
	ins_screen_mouse_back_button = false;

	for( i = 0 ; i < GRAB ; i++ )
	{
		battery[i].batteryvisible = true;
	}

	battery[0].batteryx = 600, battery[0].batteryy=55;
	battery[1].batteryx = 525, battery[1].batteryy=330; 
	battery[2].batteryx = 95, battery[2].batteryy=60;
	battery[3].batteryx = 255, battery[3].batteryy=205;
	battery[4].batteryx = 375, battery[4].batteryy=255;
	battery[5].batteryx = 1300, battery[5].batteryy=6400;
	battery[6].batteryx = 1240, battery[6].batteryy=660;
	battery[7].batteryx = 960, battery[7].batteryy=650;
	battery[8].batteryx = 800, battery[8].batteryy=630;
	battery[9].batteryx = 560, battery[9].batteryy=500;
	battery[10].batteryx = 330, battery[10].batteryy=530;
	battery[11].batteryx = 740, battery[11].batteryy=230;


	block[0].blockx1 = 130,block[0].blocky1 = 25,block[0].blockx2 = 190,block[0].blocky2 = 75;
	block[1].blockx1 = 190,block[1].blocky1 = 75,block[1].blockx2 = 250,block[1].blocky2 = 125;
	block[2].blockx1 = 250,block[2].blocky1 = 125,block[2].blockx2 = 310,block[2].blocky2 = 175;
	block[3].blockx1 = 310,block[3].blocky1 = 175,block[3].blockx2 = 370,block[3].blocky2 = 225;
	block[4].blockx1 = 370,block[4].blocky1 = 175,block[4].blockx2 = 430,block[4].blocky2 = 225;
	block[5].blockx1 = 490,block[5].blocky1 = 245,block[5].blockx2 = 550,block[5].blocky2 = 295;
	block[6].blockx1 = 700,block[6].blocky1 = 550,block[6].blockx2 = 1155,block[6].blocky2 = 600;
	block[7].blockx1 = 270,block[7].blocky1 = 350,block[7].blockx2 = 320,block[7].blocky2 = 550;
	block[8].blockx1 = 90,block[8].blocky1 = 500,block[8].blockx2 = 270,block[8].blocky2 = 550;
	block[9].blockx1 = 580,block[9].blocky1 = 345,block[9].blockx2 = 640,block[9].blocky2 = 395;
	block[10].blockx1 = 470,block[10].blocky1 = 445,block[10].blockx2 = 530,block[10].blocky2 = 495;
	block[11].blockx1 = 320,block[11].blocky1 = 425,block[11].blockx2 = 370,block[11].blocky2 = 475;
	block[12].blockx1 = 1225,block[12].blocky1 = 550,block[12].blockx2 = 1375,block[12].blocky2 = 600;
 	block[13].blockx1 = 800,block[13].blocky1 = 350,block[13].blockx2 = 1375,block[13].blocky2 = 400;
	block[14].blockx1 = 25,block[14].blocky1 = 395,block[14].blockx2 = 90,block[14].blocky2 = 445;
	block[15].blockx1 = 70,block[15].blocky1 = 345,block[15].blockx2 = 155,block[15].blocky2 = 395;
	block[16].blockx1 = 640,block[16].blocky1 = 500,block[16].blockx2 = 740,block[16].blocky2 = 550;
	block[17].blockx1 = 720,block[17].blocky1 = 150,block[17].blockx2 = 780,block[17].blocky2 = 200;

}

bool collisionWithGrab(struct batterygrab sq)
{
    if(sq.batteryvisible == false) return false;
    if(ballcx < (sq.batteryx - ballrad - GBCOL )) return true;
    if(ballcx > (sq.batteryx + 20 + ballrad + GBCOL )) return true;
    if(ballcy < (sq.batteryy - 30  - ballradup - GBCOL )) return true;
    if(ballcy > (sq.batteryy + ballraddown + GBCOL ))return true;
    return false;
}

bool collisionWithBlock(struct squareblock bk)
{
    if(ballcx < (bk.blockx1 - ballrad - 1 )) return true;
    if(ballcx > (bk.blockx2 + ballrad  + 1)) return true;
    if(ballcy < (bk.blocky1 - ballradup - 1)) return true;
    if(ballcy > (bk.blocky2 + ballraddown + 1))return true;
    return false;
}

void detectCollect()
{

	bool presentstateofgrab;
	int i;
	for( i = 0 ; i < GRAB ; i++ )
		{
			presentstateofgrab = battery[i].batteryvisible;
			battery[i].batteryvisible = collisionWithGrab(battery[i]);
			if(presentstateofgrab == true && battery[i].batteryvisible == false)
				{
					score = score + 50; 
					scr  = 1;
				}
		}
}

void drawString(char *str, int x, int y)
{
	int i;
	glLineWidth(7);
	glPointSize(3);
	glPushMatrix();
	glLoadIdentity();
	glTranslatef(x,y,0);
	glScalef(ss,ss,1);
    for( i = 0 ; i < strlen(str) ; i++ )
    {
        glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, *(str+i));
    }
    glPopMatrix();
    glLineWidth(1);
    glPointSize(1);
}


void maindisp()
{
	int i;
	int x,y;
	glClear(GL_COLOR_BUFFER_BIT );
	
	if(gamestate == 1)//Start Screen
	{
		drawStartScreen();
		glClearColor(0,0,0,0);
		ballcx = width/2, ballcy = height/2  - 10;

		time(&present_time); // Get presenttime
		changeDTFormat(ctime(&present_time));
		drawball(35);
		ss = 0.05 * sin( M_PI*sa*3/180.0 ) + 0.9;
		alp = 127 * sin( M_PI*sa*3/180.0 ) + 127;

		glColor4ub(255,255,255,alp);

		drawString("PKMAN",width / 2 - 230,height/2 + 80);
		printname("High Score : ",40,height - 50,coloryellow);
		printscore(highscore,170,height - 50,coloryellow);
		printname("START",start_screen_start_button_left + 10, start_screen_start_button_bottom + 10,colorgreen);
		printname("QUIT",start_screen_quit_button_left + 20, start_screen_quit_button_bottom + 10,colorred);
		printname("INSTRUCTION",start_screen_instruction_button_left + 7, start_screen_quit_button_bottom + 10,colorgold);

		sa++;

	}

	if(gamestate == 2)//Game
	{
		glClearColor(0.0,1,1,0);
		drawbase();
		if((spaceshipnotcollected))
		{
			drawball(ballrad);
		}
		drawleftend();

		for( i = 0 ; i < BLK ; i++ )
		{
			drawblock(block[i].blockx1,block[i].blocky1,block[i].blockx2,block[i].blocky2);
		}	
	
	
		for( i = 0 ; i < GRAB ; i++ )
		{
			if(battery[i].batteryvisible == true )
			{
				drawbattery(battery[i].batteryx, battery[i].batteryy);
			}
			else
			{
				clearGrab(battery[i].batteryx, battery[i].batteryy - 30 , battery[i].batteryx + 20 ,battery[i].batteryy + 3);
			}

		}

		drawTrapTriangles(440,25);
		drawTrapTriangles(500,25);
		drawTrapTriangles(700,25);
		drawTrapTriangles(1000,600);
		drawTrapTriangles(1155,400);



		


		if( radionotcollected )
		{
			drawRadio(radiox,radioy);
			radionotcollected = detectRadioCollision();
		}
		
		if( pendantnotcollected )
		{
			drawPendant(pendantx,pendanty);
			pendantnotcollected = detectPendant();
		}

		if (!(pendantnotcollected))
		{
			drawSpaceShip(spaceshipx,spaceshipy);
			spaceshipnotcollected = collisionWithSpaceship();
		}

		if(!(spaceshipnotcollected))
        {
        	if( spaceshipy - 65 > height)
            {
                gamestate = 4;
            }
            else
            {
                spaceshipy += 2;
                glColor3d(0,0,0);
				printname("MISSION ACCOMPLISHED!!!",500, height/2 + 20, colorgreen);
            }
        }

		if(movup == false && rjump == false && ljump == false)
		{
			freefall();
		}
		
		if((spaceshipnotcollected))
		{
			drawball(ballrad);
		}

		if( tc > maxtime && spaceshipnotcollected )
		{
			printname("TIME UP",600, height/2 + 70,colorblack);
			if( tc > maxtime + 2)
			{
				gamestate = 4;
			}
		}

		if( tc > collecttime && tc <= collecttime + 2)
		{
			printname(" +15 SECS ",600, height/2 + 70,colorred);
		}

		if(tc > traptime - 1 && tc <= traptime + 2 )
		{
			printname("OOPS!!! YOU ARE TRAPPED! ",600, height/2 + 70,colorred);	

			if( tc == traptime + 2 )
			{
				gamestate = 4;
			}
		}
		
		printname("HIGH SCORE", 50, height - 75, colorblack);
		printscore(highscore, 250, height - 75, colorblack);
		printname("YOUR SCORE", 50, height - 120, colorblack);
		printscore(score, 250, height - 120,colorblack);

		drawTimer(350, height - 70);
	}

	if(gamestate == 3)//Pause Screen
	{
		drawPauseScreen();
		glClearColor(0,0,0,0);
		printname("RESUME",pause_screen_resume_button_left + 10, pause_screen_resume_button_bottom + 10,coloryellow);
		printname("QUIT",pause_screen_quit_button_left + 30, pause_screen_quit_button_bottom + 10,colorred);
		printname("Game Paused",2.25*width/5, 0.55*height ,colorsnow);
		printname("Your Score : ",width - 220,height - 50,colorsandybrown);
		printscore(score,width - 90,height - 50,colorsandybrown);
	}

	if(gamestate == 4)//Thank You Screen
	{
		glClearColor(0,0,0,0);
		drawFinalTYScreen();		
		printname("Thanks for playing :) ",2.1*width/5,4*height/5,colorsandybrown);
		printname("CREATED BY",2.2*width/5,0.69*height,colorgold);
		printname("Pravalika A",2.2*width/5,0.55*height,colortomato);
		printname("Vaishakh K",2.2*width/5,0.45*height,colortomato);
		printname("Abhishek DV",2.2*width/5,0.35*height,colortomato);
		printname("NATIONAL INSTITUTE OF TECHNOLOGY KARNATAKA , SURATHKAL",width/5,height/6,colorteal);
		setHighScore();
	}

	if(gamestate == 5)//Instruction Page
	{
		drawInstructionScreen();
		printname("BACK",ins_screen_back_button_left + 15 , ins_screen_back_button_bottom + 10,colorteal);
		printname(" INSTRUCTIONS ",550,670,colorsnow);
        printname(" -> Help the lost PKman find his spacecraft",110,600,colorred);
        printname(" -> Collect all the items on the way ",110,560,colorred);
        printname(" -> Left Key = Move the ship left",110,520,colorred);
        printname(" -> Right Key =  Move the ship right",110,480,colorred);
        printname(" -> Up Key =  Move the ship right",110,440,colorred);
        printname(" -> 'X'/'x' = Jump Right",110,400,colorred);
        printname(" -> 'Z'/'z' = Jump Left",110,360,colorred);
        printname(" -> 'R'/'r' = Resume Game (Only in Pause Game Screen)",110,320,colorred);
        printname(" -> 'Q' = Quit Game (Only in Pause Screen and Main menu) ",110,280,colorred);
        printname(" -> Mouse Movement = To select the options in the Menu ",110,240,colorred);
        printname(" -> Right Click = Change background options (Works only in the Main Menu and Quit Screen)",110,200,colorred);
        printname(" 1. Locket - Collect the locket for the spaceship to appear, and to get 200 points.",110,160,colorred);
        printname(" 2. Battery - Collect batteries to get 50 points.",110,120,colorred);
        printname(" 3. Radio - Collect the radio to reset the clock and to get 100 points.",110,80,colorred);
        printname(" 4. Reach the spacecraft after collecting the locket, before the time runs out.",110,40,colorred);

	}
	
	glutSwapBuffers();
}





void ballmove()
{
	int lp,t,i;
	float bx,by,tempcy,tempcx;
	float color[3];
	bool presentstateofgrab;
	bx=ballcx;
	by=ballcy;
	
	if ( scr == 1 )
		{
			scr = 0;
		}

	if(movleft)
	{
		if(bx>=UNIT_MOVE+25+ballrad)
		{
			bx -= UNIT_MOVE;
			
			for(tempcy=by-ballraddown;tempcy<=by+ballrad;tempcy++)
			{
				collisionstate = detectCollision(ballcx - ballrad - UNIT_MOVE,tempcy);
				if(collisionstate==1)
					break;
			}
			if(collisionstate == 0)
			{
				ballcx = bx;
				ballcy = by;
			}
			
		}	
		
	}


	if(movright)
	{
		if(bx<=width - UNIT_MOVE -15)
		{
			bx += UNIT_MOVE;
			
			for(tempcy=by-ballraddown;tempcy<=by+ballrad;tempcy++)
			{
				collisionstate = detectCollision(ballcx + ballrad + UNIT_MOVE,tempcy);
				if(collisionstate==1)
					break;
			}
			if(collisionstate == 0)
			{
				ballcx = bx;
				ballcy = by;
			}

		}
		
	}
		

	
	if(movdown)
	{
		if(by >= 25 + UNIT_JMP + 15)
		{
			by -= UNIT_JMP;
			for(tempcx=bx-ballrad;tempcx<=bx+ballrad;tempcx++)
			{
				collisionstate = detectCollision(tempcx,by-ballrad);
				if(collisionstate==1)
					break;
			}
			if(collisionstate == 0)
			{
				ballcx = bx;
				ballcy = by;
			}
		}

		
		
		
	}

}

void calcprojectile(int jumpdirection)
{
	
	float y = ballcy;
	float x = ballcx;
	int i,j;
	float tempc,color[3],color1[3],color2[3];

		if(jumpdirection == 1)
		{
			glReadPixels(x + ballrad + 2, y - ballraddown + 1, 1, 1, GL_RGB,GL_FLOAT,color);
			glReadPixels(x + ballrad + 2, y + ballrad + 1, 1, 1, GL_RGB,GL_FLOAT,color1);
			glReadPixels(x - 1.5*ballrad, y - ballraddown + 1, 1, 1, GL_RGB,GL_FLOAT,color2);
		}

		else
		{
			glReadPixels(x - ballrad - 2, y - ballraddown + 1, 1, 1, GL_RGB,GL_FLOAT,color);
			glReadPixels(x - ballrad - 2, y + ballrad + 1, 1, 1, GL_RGB,GL_FLOAT,color1);
			glReadPixels(x + 1.5*ballrad, y - ballraddown + 1, 1, 1, GL_RGB,GL_FLOAT,color2);
		}
		
	if (( color[0] == 0 && color[1] == 1 && color[2] == 1 ) && ( color1[0] == 0 && color1[1] == 1 && color1[2] == 1 ) && ( color2[0] == 0 && color2[1] == 1 && color[2] == 1 ))
	{
		if(jumpdirection == 1)
		{
			rjump = true;
			ljump = false;
			movup = false;
		}

		else
		{
			ljump = true;
			rjump = false;
			movup = false;
		}
	}

	
	else
	{
		ballcy += UNIT_JMP;
		if(jumpdirection == 1)
		{
			rjump = false;
		}

		else
		{
			ljump = false;
		}

		
	}
			
}

void calcmovup()
{
	float y = ballcy;
	float x = ballcx;
	int i,j;
	float tempc,colorl[3],colorr[3],color[3];
	
	glReadPixels(x, y + ballrad + 2, 1, 1, GL_RGB, GL_FLOAT, color);
	glReadPixels(x - ballrad, y + ballrad + 2, 1, 1, GL_RGB, GL_FLOAT, colorl);
	glReadPixels(x + ballrad, y + ballrad + 2, 1, 1, GL_RGB, GL_FLOAT, colorr);
	if (( colorl[0] == 0 && colorl[1] == 1 && colorl[2] == 1 ) && ( colorr[0] == 0 && colorr[1] == 1 && colorr[2] == 1 ) && ( color[0] == 0 && color[1] == 1 && color[2] == 1))
	{
		movup = true;
		rjump = false;
		ljump = false;
	}
	else
	{
		ballcy += UNIT_JMP;
		movup = false;
	}
}


void freefall()
{
	float colorr[3],colorl[3];
	glReadPixels(ballcx + ballrad,ballcy - ballraddown -2,1,1,GL_RGB,GL_FLOAT,colorr);
	glReadPixels(ballcx - ballrad,ballcy - ballraddown -2,1,1,GL_RGB,GL_FLOAT,colorl);

	if (( colorr[0] == 0 && colorr[1] == 1 && colorr[2] == 1 )&&( colorl[0] == 0 && colorl[1] == 1 && colorl[2] == 1 ))
	{
		ffall = true;
		ballcy = ballcy - UNIT_MOVE;
	}
	else
	{
		ballcy += 1;
		ffall = false;
	}
}

void timer_func(int v)
{
	if(gamestate == 2)
	{
		ballmove();
    	glutPostRedisplay();
    	detectCollect();
    	detectTrap();
    	if(rjump)
    	{
    		ballcx = bx + inivel*delt*cos(M_PI*angle/180);
			ballcy = by + inivel*delt*sin(M_PI*angle/180) - 0.5*g*delt*delt;
    		calcprojectile(1);
    		delt = delt + tof/100;
    	}

    	else if(ljump)
    	{
    		ballcx = bx - inivel*delt*cos(M_PI*(angle)/180);
			ballcy = by + inivel*delt*sin(M_PI*(angle)/180) - 0.5*g*delt*delt;
    		calcprojectile(2);
    		delt = delt + tof/100;
    	}

    	else if(movup)
    	{
    		ballcx = bx + inivel*delt*cos(M_PI*freeangle/180);
			ballcy = by + inivel*delt*sin(M_PI*freeangle/180) - 0.5*g*delt*delt;
    		calcmovup();
    		delt = delt + tof/100;
    	}

    	
    	else
    	{
    		bx = ballcx;
    		by = ballcy;
    		delt = 0;
    	}

	}

 	glutPostRedisplay();
    glutTimerFunc(1, timer_func, v);
}

void viewOptions(int id)
{
	switch(id)
	{
		case 1: viewstate = 1;
				break;
		case 2: viewstate = 2;
				break;
	}
}


int main(int argc, char *argv[])
{
	glutInit(&argc,argv);
	tof = 2*inivel*sin(M_PI*angle/180)/g;
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowPosition(100,80);
    glutInitWindowSize((int) width, (int) height);
    glutCreateWindow("PKMAN");
    gamestate = 1;
    glutFullScreen();
    myinit();
    glutReshapeFunc(reshape);
    getHighScore();
    glutDisplayFunc(maindisp);
    glutSpecialFunc(keypress);
    glutSpecialUpFunc(keyrelease);
    glutKeyboardFunc(otherkeypress);
    glutKeyboardUpFunc(otherkeyrelease);
    glutPassiveMotionFunc(mousemotion);
    glutMouseFunc(mouseclick);
    glutCreateMenu(viewOptions);
    glutAddMenuEntry("BackGround 1",1);
    glutAddMenuEntry("BackGround 2",2);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glutTimerFunc(1, timer_func, 0);
    glutMainLoop();

    return 0;
}
