#include"AllIncludes.h"
#include "ScreenManager.h"
using namespace std;
 
int ScreenManager::elapsed_ticks;
stack <Screen*> ScreenManager::active_screens;

int ScreenManager::window_XPos;
int ScreenManager::window_YPos;
int ScreenManager::window_Height;
int ScreenManager::window_Width;
char* ScreenManager::window_Title;
int ScreenManager::update_Rate;

//Screen Manager Utilities 
void ScreenManager::Initialize(int argc,char* argv [], Screen* newScreen, int updateRate)
{
	window_XPos   = 100;
	window_YPos   = 100;
	window_Height = 600;
	window_Width  = 800;
	window_Title  = "Bouncing Circles";
	update_Rate   = updateRate;
	AddScreen(newScreen);
	glutInit(&argc,argv);

	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(window_XPos,window_YPos);
	glutInitWindowSize(window_Width,window_Height);
	glutCreateWindow(window_Title);

	glutDisplayFunc(&ScreenManager::DrawScreen);
	glutKeyboardUpFunc(&ScreenManager::GetKeyboardUpPress);
	glutSpecialFunc(&ScreenManager::GetSpecialDownPress);
	glutKeyboardFunc(&ScreenManager::GetKeyboardDownPress);
	glutReshapeFunc(&ScreenManager::HandleWindowResize);
	glutMainLoop();


}
void ScreenManager::AddScreen(Screen* newScreen)
{
	newScreen->Initialize();
	active_screens.push(newScreen);
	elapsed_ticks = 0;
}
void ScreenManager::RemoveScreen()
{
	Screen* current = active_screens.top();
	active_screens.pop();
}
void ScreenManager::DrawScreen()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);	

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0,0,window_Width,window_Height);
	gluOrtho2D(0,window_Width,0,window_Height);

	UpdateScreen();
	active_screens.top()->Draw();
	glFlush();

	glutSwapBuffers();
	glutPostRedisplay();
}
void ScreenManager::UpdateScreen()
{
	int current =  glutGet(GLUT_ELAPSED_TIME);
	if(current - elapsed_ticks > update_Rate)
	{
		active_screens.top()->Update();
		elapsed_ticks = current;
	}
}


//Keyboard Handler
void ScreenManager::GetSpecialDownPress(int key, int x, int y)
{
	active_screens.top()->GetSpecialDownPress(key);
}
void ScreenManager::GetKeyboardUpPress(unsigned char key, int x, int y)
{
	active_screens.top()->GetKeyboardUpPress(key);
}
void ScreenManager::GetKeyboardDownPress(unsigned char key, int x, int y)
{
	active_screens.top()->GetKeyboardDownPress(key);
}
void ScreenManager::HandleWindowResize(int width, int height)
{
	window_Height = height;
	window_Width = width;
}