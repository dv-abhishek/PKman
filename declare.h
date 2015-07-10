
//Ball Movement
extern bool movleft,movright,movup,movdown,rjump,ljump;
extern int width,height;
extern int angl;
//Parameters of Ball
extern float ballcx,ballcy,ballrad;
extern int gamestate;
//extern float rad,x1,y1,x2,y2;

//score variable
extern float highscore, s, score;
extern char strscore[LEN];

//time variable
extern time_t present_time;

//mouse location boolean
extern bool start_screen_mouse_start_button,start_screen_mouse_quit_button,start_screen_mouse_instruction_button;
extern bool pause_screen_mouse_resume_button,pause_screen_mouse_quit_button;
extern bool ins_screen_mouse_back_button;

//Button bounds
extern int start_screen_start_button_left, start_screen_start_button_right, start_screen_start_button_bottom, start_screen_start_button_top;
extern int start_screen_quit_button_left, start_screen_quit_button_right, start_screen_quit_button_bottom, start_screen_quit_button_top;
extern int pause_screen_resume_button_left, pause_screen_resume_button_right, pause_screen_resume_button_bottom, pause_screen_resume_button_top;
extern int pause_screen_quit_button_left, pause_screen_quit_button_right, pause_screen_quit_button_bottom, pause_screen_quit_button_top;
extern int start_screen_instruction_button_left, start_screen_instruction_button_right,start_screen_instruction_button_bottom ,start_screen_instruction_button_top;
extern int ins_screen_back_button_left, ins_screen_back_button_right,ins_screen_back_button_bottom ,ins_screen_back_button_top;

//Colors
extern float colorblack[3],colorgreen[3],colorred[3],coloryellow[3],colorsnow[3],colorsandybrown[3],colortomato[3],colorgold[3],colorteal[3];

extern int viewstate;

extern float triangle_current_angle, triangle_rotate_by;

extern float centerx, centery;

//Radio
extern bool radionotcollected;
extern int radiox, radioy;
//Pendant
extern bool pendantnotcollected;
extern int pendantx, pendanty;

//Spaceship
extern bool spaceshipnotcollected;
extern int spaceshipx, spaceshipy;

//Timer
extern int tc, t , maxtime, collecttime, traptime;

//Trap
extern bool trapped;
