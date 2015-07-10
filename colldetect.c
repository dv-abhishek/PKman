#include "declare.h"



int detectCollision(float a, float b)
{
	float color[3];
	glReadPixels(a,b,1,1,GL_RGB,GL_FLOAT,color);

	if ( color[0] >= 0.59 && color[0] <= 0.61 && color[1] >= 0.19 && color[1] <= 0.21 && color[2] >= 0.14 && color[2] <= 0.16 )
		return 1;
	else
		return 0;
}

void detectTrap()
{
	float color[3];
	int x,y;
	for ( x = ballcx - ballrad + 5 ; x <= ballcx + ballrad - 5 ; x++ )
	{
		for( y = ballcy - ballrad ; y <= ballcy ; y++ )
		{
			glReadPixels(x,y,1,1,GL_RGB,GL_FLOAT,color);
			if ( color[0] >= 0.29 && color[0] <= 0.31 && color[1] >= 0.29 && color[1] <= 0.31 && color[2] >= 0.29 && color[2] <= 0.31 )
			{
				if(!(trapped))
				{
					trapped = true;
					traptime = tc;
				}
			}
		}
	}
	
} 

bool detectRadioCollision()
{
	if (radionotcollected == false ) return false;

    if(ballcx < (radiox - ballrad )) return true;
    if(ballcx > (radiox + 75 + ballrad )) return true;
    if(ballcy < (radioy - 35  - ballradup )) return true;
    if(ballcy > (radioy + ballraddown ))return true;
    score += 100;
    maxtime += 15;
    collecttime = tc;
    return false;

}

bool detectPendant()
{
	if (pendantnotcollected == false ) return false;

    if(ballcx < (pendantx - 16 - ballrad - GBCOL )) return true;
    if(ballcx > (pendantx + 16 + ballrad + GBCOL )) return true;
    if(ballcy < (pendanty - 16  - ballradup - GBCOL )) return true;
    if(ballcy > (pendanty + 16 + ballraddown + GBCOL ))return true;
    score += 200;
    return false;

}

bool collisionWithSpaceship()
{ 
   if(spaceshipnotcollected == false) return false;
   if(ballcx  < (spaceshipx - ballrad - 65)) return true;
   if(ballcx > (spaceshipx+  ballrad + 65)) return true;
   if((ballcy) < (spaceshipy - ballradup - 40)) return true;
   if((ballcy) > (spaceshipy  + ballraddown + 40)) return true;
   score += (maxtime - tc)*2;
   return false;


}

