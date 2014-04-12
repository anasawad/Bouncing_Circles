#ifndef WELCOMINGSCREEN_H_
#define WELCOMINGSCREEN_H_
#include "AllIncludes.h"
#include "Screen.h"
#include "ExitScreen.h"
#include "MainGameScreen.h"
struct MenuItems
{
	Screen* _ptrScreen;
	char* title;
};

class WelcomingScreen: public Screen
{
	static const int MenuSize = 2;
	MenuItems menuItemsArray[MenuSize];
	int select_index;

	void Initialize()
	{
		select_index = 0;
		menuItemsArray[0]._ptrScreen = new MainGameScreen();
		menuItemsArray[0].title = "Normal Circles Screen";
		menuItemsArray[1]._ptrScreen= new ExitScreen();
		menuItemsArray[1].title = "Exit";
	}
	void Draw()
	{

		char* CenterTitle = "*** Welcome to Bouncing Circles Project ***";
		glColor3f(0,.5,1);
		TextHelper::DrawCenteredString(ScreenManager::window_Height - 200, GLUT_BITMAP_TIMES_ROMAN_24, CenterTitle);
		for ( int i = 0 ; i < MenuSize ; i ++ )
		{
			if ( select_index == i )
				glColor3f(0,.5,1);
			else
				glColor3f(0,0,0);
			int pos = ScreenManager::window_Height - 300 - i * 30;
			TextHelper::DrawCenteredString(pos, GLUT_BITMAP_TIMES_ROMAN_24, menuItemsArray[i].title);

		}
	}
	void GetSpecialDownPress(int key)
	{
		if ( key == GLUT_KEY_DOWN )
			select_index = min(MenuSize-1, select_index+1);
		else if ( key == GLUT_KEY_UP )
			select_index = max(0, select_index-1);
	}
	void GetKeyboardDownPress(int key)
	{
		if ( key == '\r' )
			ScreenManager::AddScreen(menuItemsArray[select_index]._ptrScreen);
	}
};
#endif