#ifndef VECTOR_H_
#define VECTOR_H_

class Vector
{
public:
	float X, Y;

	Vector ( float a , float b ) : X (a) , Y (b) {}
	Vector () : X (0.0) , Y (0.0) {}
	void Set ( float a , float b )
	{
		X = a;
		Y = b;
	}

	Vector operator + ( Vector other )
	{
		return Vector ( X + other.X , Y + other.Y );
	}
	Vector operator - ( Vector other )
	{
		return Vector ( X - other.X , Y - other.Y );
	}
	Vector operator * ( Vector other )
	{
		return Vector ( X * other.X , Y * other.Y );
	}
	Vector operator / ( Vector other )
	{
		return Vector ( X / other.X , Y / other.Y );
	}
	void operator += ( Vector other )
	{
		Set ( X + other.X , Y + other.Y );
	}
	void operator -= ( Vector other )
	{
		Set ( X - other.X , Y - other.Y );
	}
	void operator *= ( Vector other )
	{
		Set ( X * other.X , Y * other.Y );
	}
	void operator /= ( Vector other )
	{
		Set ( X / other.X , Y / other.Y );
	}
	float Dot_Product ( Vector other )
	{
		return ( X*other.X + Y*other.Y );
	}

	Vector operator * (float a )
	{
		return Vector ( X*a , Y*a );
	}
};

#endif