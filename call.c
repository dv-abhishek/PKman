#include "declare.h"
struct tm *sttime;
time_t gamesttime;


void keypress(int k, int x, int y)
{
    switch(k)
    {
        case GLUT_KEY_LEFT: movleft=true,movright=false ;
                            break;
        case GLUT_KEY_RIGHT: movright=true,movleft=false;
                            break;

        case GLUT_KEY_UP: if( ljump == false && rjump == false )
                            movup=true,movdown=false;
                            break;
    
        case GLUT_KEY_DOWN: movup=false,movdown=true;
                            break;
    }
}


void keyrelease(int k, int x, int y)
{
    switch(k)
    {
    case GLUT_KEY_LEFT: movleft=false;
                        break;
    case GLUT_KEY_RIGHT:movright=false;
                        break;
    case GLUT_KEY_DOWN: movdown=false;
                        break;
    }
}


void otherkeypress(unsigned char k, int x, int y)
{
    time(&gamesttime);
    sttime = localtime(&gamesttime);

    switch(k)
    {

    case 'x':
    case 'X': if(gamestate == 2)
                {
                    if( ljump == false && movup == false )
                        rjump = true; // Jumping Diagonaly Right
                } 
              break;  

    case 'z':
    case 'Z': if(gamestate == 2)
                {
                    if( rjump == false && movup == false )
                        ljump = true; // Jumping Diagonaly Left
                }
              break;


    case 'q':
    case 'Q': if(gamestate == 1 || gamestate == 3)
                { 
                    gamestate=4;
                }
                break;
                

    case 's':
    case 'S': if(gamestate == 1)
                { 
                    gamestate=2;
                    ballcx = 25 + 2*ballrad;
                    ballcy = 35;
                    t = sttime->tm_sec;
                }
                break;

    case 'r':
    case 'R': if(gamestate == 3)
                { 
                    gamestate=2;
                }
                break;

    case 'p':
    case 'P': if(gamestate == 2)
                { 
                    gamestate=3;
                }
                break;

    case 'i':
    case 'I': if(gamestate == 1)
                { 
                    gamestate=5;
                }
                break;

    case 'b':
    case 'B': if(gamestate == 5)
                { 
                    gamestate=1;
                }
                break;
    


    }
}

void otherkeyrelease(unsigned char k,int x,int y)
{
    switch(k)
    {

    }
}

void mouseclick(int buttonpressed, int state, int x, int y)
{
    time(&gamesttime);
    sttime = localtime(&gamesttime);

    switch(gamestate)
    {
                   
        case 1: if(buttonpressed == GLUT_LEFT_BUTTON && state == GLUT_UP )
                {
                    if( x >= start_screen_start_button_left && x <= start_screen_start_button_right && y >= start_screen_start_button_bottom + SDISY && y <= start_screen_start_button_top + SDISY )
                       {
                            gamestate = 2;
                            ballcx = 25 + 2*ballrad;
                            ballcy = 35;
                            t = sttime->tm_sec;

                       } 
                    if( x >= start_screen_quit_button_left && x <= start_screen_quit_button_right && y >= start_screen_quit_button_bottom + SDISY && y <= start_screen_quit_button_top + SDISY )
                        {
                            gamestate = 4;
                        }

                    if( x >= start_screen_instruction_button_left && x <= start_screen_instruction_button_right && y >= start_screen_instruction_button_bottom + SDISY && y <= start_screen_instruction_button_top + SDISY )
                        {
                            gamestate = 5;
                        }
                }
                break;

        case 3: if(buttonpressed == GLUT_LEFT_BUTTON && state == GLUT_UP )
                {
                    if( x >= pause_screen_resume_button_left && x <= pause_screen_resume_button_right && y <= pause_screen_resume_button_bottom + PDISY && y >= pause_screen_resume_button_top + PDISUY)
                       {
                            gamestate = 2;
                       } 
                    if( x >= pause_screen_quit_button_left && x <= pause_screen_quit_button_right && y <= pause_screen_quit_button_bottom + PDISY && y >= pause_screen_quit_button_top +PDISUY )
                        {
                            gamestate = 4;
                        }
                }
                break;

        case 4: if(buttonpressed == GLUT_LEFT_BUTTON && state == GLUT_UP )
                {
                    printf("\nThanks for playing\n");
                    if(score >= highscore)
                        printf("\nCongratulations!!! You have made a new High Score!!!");
                    printf("\nYour Score : %lf",score);
                    printf("\nHigh Score : %lf\n",highscore);
                    printf("\nThis game is created by, \n");
                    printf("\n1. Pravalika A - 13IT127");
                    printf("\n2. Vaishakh K  - 13IT149");
                    printf("\n3. Abhishek DV - 13IT202\n");
                    printf("\nNATIONAL INSTITUTE OF TECHNOLOGY KARNATAKA , SURATHKAL\n\n");
                    exit(0);
                }

        case 5: if(buttonpressed == GLUT_LEFT_BUTTON && state == GLUT_UP )
                {
                    if( x >= ins_screen_back_button_left && x <= ins_screen_back_button_right && y <= ins_screen_back_button_top - IDISBY && y >= ins_screen_back_button_bottom - IDISBY)
                       {
                            gamestate = 1;
                       } 
                }
                break;
    }
}

void mousemotion(int x, int y)
{
    switch(gamestate)
    {
        case 1: if(x >= start_screen_start_button_left && x <= start_screen_start_button_right && y >= start_screen_start_button_bottom + SDISY && y <= start_screen_start_button_top + SDISY )
                    {
                        start_screen_mouse_start_button = true;
                    } 
                else
                    start_screen_mouse_start_button = false;

                if( x >= start_screen_quit_button_left && x <= start_screen_quit_button_right && y >= start_screen_quit_button_bottom + SDISY && y <= start_screen_quit_button_top + SDISY )
                    {
                        start_screen_mouse_quit_button = true;
                    } 
                else
                    start_screen_mouse_quit_button = false;

                if( x >= start_screen_instruction_button_left && x <= start_screen_instruction_button_right && y >= start_screen_instruction_button_bottom + SDISY && y <= start_screen_instruction_button_top + SDISY )
                    {
                        start_screen_mouse_instruction_button = true;
                    }
                else
                    start_screen_mouse_instruction_button = false;

                break;

        case 3: if(x >= pause_screen_resume_button_left && x <= pause_screen_resume_button_right && y <= pause_screen_resume_button_bottom + PDISY  && y >= pause_screen_resume_button_top + PDISUY )
                    {
                        pause_screen_mouse_resume_button = true;
                    } 
                else
                    pause_screen_mouse_resume_button = false;

                if(  x >= pause_screen_quit_button_left && x <= pause_screen_quit_button_right && y <= pause_screen_quit_button_bottom + PDISY && y >= pause_screen_quit_button_top + PDISUY )
                    {
                        pause_screen_mouse_quit_button = true;
                    } 
                else
                    pause_screen_mouse_quit_button = false;

                break;

        case 5: if( x >= ins_screen_back_button_left && x <= ins_screen_back_button_right && y <= ins_screen_back_button_top - IDISBY && y >= ins_screen_back_button_bottom - IDISBY)
                       {
                            ins_screen_mouse_back_button = true;
                       } 
                else
                    ins_screen_mouse_back_button = false;


                break;

    

    }
}


