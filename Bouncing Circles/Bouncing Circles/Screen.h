#ifndef SCREEN_H_
#define SCREEN_H_

#include "KeyboardHandler.h"
class Screen:public KeyboardHandler
{
protected:
	
public:
	
	virtual void Initialize();
	virtual void Draw();
	virtual void Update();
	void GetKeyboardDownPress(int key){}
	void GetKeyboardUpPress(int key){}
	void GetSpecialDownPress(int key){}
};
#endif