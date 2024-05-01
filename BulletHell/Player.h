#pragma once

#include <raylib.h>
#include <rlgl.h>
#include <raymath.h>
#include <memory>

#include "Weapon.h"
#include "Projectile.h"

class Player
{
public:
	Player(Vector2 position, int health, int speed, int score);

	void Move(Vector2 direction, float deltaTime);
	void UpdateWeapon(float deltaTime);
	void SwapWeapon(std::unique_ptr<Weapon> weapon);

	[[nodiscard]] std::unique_ptr<Projectile> Attack();

	void Draw() const;

	Vector2 GetPosition() const;
	int GetHealth() const;
	int GetScore() const;

private:
	Vector2 m_Position;
	int m_Health;
	int m_Score;
	int m_Speed;

	std::unique_ptr<Weapon> m_Weapon;
};