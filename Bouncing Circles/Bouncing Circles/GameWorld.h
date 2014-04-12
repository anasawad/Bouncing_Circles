#ifndef GAMEWORLD_H_
#define GAMEWORLD_H_

#include "Circle.h"
class GameWorld
{
private:
	int num_of_circles;
	Circle* allCircles;

	int Ranomdize(int start, int end)
	{
		return ( ( rand() % ( end - start ) ) + start ) ;
	}

public:
	Circle player_circle;
	Vector _gravity;
	Vector _speed;
	bool withGravity;
	bool withSpeed;

	GameWorld(){}
	GameWorld(int count, int minRadius, int maxRadius, int VelocityBound, int PlayerCircleRadius)
	{
		float radius;
		_gravity    = Vector(0,-0.5f);
		withGravity = false;
		withSpeed   = false;
		num_of_circles = count;
		allCircles = new Circle[num_of_circles];
		Vector Position;
		for(int i =0 ; i< num_of_circles;i++)
		{
			radius = Ranomdize(minRadius,maxRadius);
			if ( i <= num_of_circles/2)
				Position.Set(0,0);
			else
				Position.Set(ScreenManager::window_Width-radius,ScreenManager::window_Height-radius);


			//Ranomdize(radius, ScreenManager::window_Width-radius),
			//Ranomdize(radius, ScreenManager::window_Height-radius));
			Vector Velocity (
				Ranomdize(-VelocityBound, VelocityBound),
				Ranomdize(-VelocityBound, VelocityBound));
			allCircles[i] = Circle(Position, Velocity, radius);
		}
		player_circle = Circle (
			Vector(ScreenManager::window_Width/2,ScreenManager::window_Height/2),
			Vector(0,0),
			PlayerCircleRadius);
	}
	void Draw()
	{
		for ( int i = 0 ; i < num_of_circles ; i ++ )
			allCircles[i].Draw_Circle(0.57,0.59,0.57);
		player_circle.Draw_Circle(0,0,0);
	}
	

	void Electric()
	{
		for(int i =0 ; i < num_of_circles;i++)
		{
			allCircles[i]._position.Set(ScreenManager::window_Width/2,ScreenManager::window_Height/2+allCircles[i]._radius);
			allCircles[i]._velocity.Set(0,0);
		}
	}
	void Update()
	{
		player_circle._velocity.Set(
			min(4,player_circle._velocity.X),
			min(4,player_circle._velocity.Y));
		player_circle.Update();

		for ( int i = 0 ; i < num_of_circles; i ++ )
		{
			if ( withGravity )
			{
				allCircles[i]._velocity += _gravity;
			}
			allCircles[i].Update();
			Check_Collision(player_circle,allCircles[i]);
			for ( int j = i+1 ; j < num_of_circles ; j ++ )
				Check_Collision(allCircles[i],allCircles[j]);
		}
	}	
	bool Check_Collision(Circle& a , Circle& b)
	{
		/*
		vector bwteen two points is the difference bwteen 2 points
		to squaring the values of the vector we use dot product
		*/
		Vector distance_vector= b._position - a._position;
		float distance_squared = distance_vector.Dot_Product(distance_vector);
		float distance = sqrt(distance_squared);

		float radiuse = a._radius +b._radius;
		float radiuse_squared = radiuse*radiuse;

		if(distance_squared > radiuse_squared)
			return false;

		Vector NormalOfCollision (distance_vector.X / distance , distance_vector.Y / distance);
		float distanceOfCollision = radiuse-distance;
		float inverseAMass = 1.0f/a._radius;
		float inverseBMass = 1.0f/b._radius;

		Vector SeparationVector =  NormalOfCollision * ( distanceOfCollision / ( inverseAMass+inverseBMass));

		a._position -= SeparationVector * inverseAMass;
		b._position += SeparationVector * inverseBMass;


		Vector VelocityOfCollision = b._velocity - a._velocity;
		float ImpactSpeed = VelocityOfCollision.Dot_Product(NormalOfCollision); 

		if ( ImpactSpeed > 0.0f )
			return false;

		const float CoofficientOfRestitution = 0.5f;
		float CollisionImpulse = -(1.0f + CoofficientOfRestitution) * ImpactSpeed / ( inverseAMass+inverseBMass);
		Vector ImpulseVector = NormalOfCollision* CollisionImpulse;

		a._velocity -= ImpulseVector * inverseAMass;
		b._velocity += ImpulseVector * inverseBMass;
		return true;




	}



};
#endif