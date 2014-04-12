#ifndef EXITSCREEN_H_ 
#define EXITSCREEN_H_

#include "Screen.h"
#include "TextHelper.h"

class ExitScreen: public Screen
{
	void Draw()
	{
		char* centerTitle = "Thanks for trying Bouncing Circles!!";
		glColor3f(1,.5,1);
		TextHelper::DrawCenteredString(ScreenManager::window_Height/2, GLUT_BITMAP_TIMES_ROMAN_24, centerTitle);
	}
	void GetKeyboardDownPress(int key)
	{
		if ( key == '\r' )
			exit(0);
	}
};
#endif