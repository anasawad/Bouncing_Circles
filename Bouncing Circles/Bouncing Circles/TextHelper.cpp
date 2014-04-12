#include <windows.h>
#include <gl/gl.h>
#include <gl/glut.h>
#include "TextHelper.h"
#include "ScreenManager.h"

float TextHelper::MeasureStringWidth(void* font, char* text)
{
	float width = 0;
	for (char* c = text ; *c != '\0' ; c ++ )
		width += glutBitmapWidth(font,*c);
	return width;
}

void TextHelper::DrawString(float x, float y, void* font, char* text)
{
	glRasterPos2f(x,y);
	for ( char* c = text ; *c != '\0' ; c ++ )
		glutBitmapCharacter(font, *c);
}

void TextHelper::DrawCenteredString(float y, void* font, char* text)
{
	float StringWidth = MeasureStringWidth(font, text);
	float x = (ScreenManager::window_Width - StringWidth) / 2;
	DrawString(x, y, font, text);
}