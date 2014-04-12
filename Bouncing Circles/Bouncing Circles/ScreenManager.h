#ifndef SCREENMANAGER_H_
#define SCREENMANAGER_H_

#include "AllIncludes.h"
#include "Screen.h"
using namespace std;
class ScreenManager
{
private: 
	static int elapsed_ticks;
	static stack <Screen*> active_screens;
public:
	static int window_XPos;
	static int window_YPos;
	static int window_Height;
	static int window_Width;
	static char* window_Title;
	static int update_Rate;

	static void Initialize(int,char* [],Screen*,int);
	static void AddScreen(Screen*);
	static void RemoveScreen();

	static void DrawScreen();
	static void UpdateScreen();

	static void GetKeyboardDownPress(unsigned char, int, int);
	static void GetKeyboardUpPress(unsigned char, int, int);
	static void GetSpecialDownPress(int, int, int);
	static void HandleWindowResize(int, int);
};
#endif