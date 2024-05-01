#pragma once

#include <raylib.h>
#include <rlgl.h>
#include <raymath.h>

class Projectile
{
public:
	Projectile(Vector2 position, Vector2 direction, float damage, float speed);

	void Move(float deltaTime);

	void Draw() const;
	Vector2 GetPosition() const;
	Vector2 GetDirection() const;

private:
	Vector2 m_Position;
	Vector2 m_Direction;
	float m_Damage;
	float m_Speed;
};