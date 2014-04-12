#ifndef CIRCLE_H_
#define CIRCLE_H_

#include "AllIncludes.h";
#include "ScreenManager.h"
#include "Vector.h"

using namespace std;
const float PI = 3.1415926535897932384626433832795;
class Circle
{
public:
	Vector _position;
	Vector _velocity;
	float _radius;

	Circle(){}
	Circle(Vector p, Vector v, float r): _position(p),_velocity(v),_radius(r){}
	void Draw_Circle(float r, float g , float b)
	{
		
		glColor3f(0,0,0);
		DrawCircleHelper(this->_position,this->_radius);
		glColor3f(r,g,b);
		DrawCircleHelper(this->_position,this->_radius-3);
	}
	void Update()
	{
		this->_position += this->_velocity;
		if ( this->_position.X - this->_radius<= 0 )
		{
			this->_position.X = this->_radius;
			this->_velocity.X *= -1;
		}
		else if (this->_position.X + this->_radius >= ScreenManager::window_Width )
		{
			this->_position.X = ScreenManager::window_Width - this->_radius;
			this->_velocity.X *= -1;
		}
		if ( this->_position.Y - this->_radius <= 0 )
		{
			this->_position.Y = this->_radius;
			this->_velocity.Y *= -1;
		}
		if ( this->_position.Y + this->_radius >= ScreenManager::window_Height )
		{
			this->_position.Y = ScreenManager::window_Height - this->_radius;
			this->_velocity.Y *= -1;
		}
	}

private:
	void DrawCircleHelper(Vector pos, float rad)
	{
		float angleInRad;
		glBegin(GL_POLYGON);
		for(int i =0 ; i < 360;i++)
		{
			angleInRad = i*PI/180;
			glVertex2f( cos(angleInRad)*rad+ pos.X , sin(angleInRad)*rad+ pos.Y );
		}
		glEnd();
	}
};
#endif
