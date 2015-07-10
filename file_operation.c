#include "declare.h"


void setHighScore()
{
	if(highscore > score)
		return;

	highscore = score;
	FILE *fptr;
	fptr = fopen("Highscore","w");
	if(fptr==NULL)
    {
        return;
    }
    fwrite(&highscore,1,sizeof(int),fptr);
    fclose(fptr);
}

void getHighScore()
{
	FILE *fptr;
	fptr = fopen("Highscore","r");
	if(fptr == NULL)
	{
		highscore = 0;
		setHighScore();
	}
	else
	{
		fread(&highscore,1,sizeof(int),fptr);
        fclose(fptr);
	}
}


