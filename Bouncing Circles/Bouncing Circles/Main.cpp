#include <iostream>
#include "AllIncludes.h"
#include "Screen.h"
#include "ScreenManager.h"
#include "WelcomingScreen.h"


using namespace std;
int main(int argc, char* argv[])
{
	ScreenManager::Initialize(argc,argv,new WelcomingScreen(),10);
}
