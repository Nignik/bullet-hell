#pragma once

#include "Projectile.h"

#include <memory>
#include <functional>

class Weapon
{
public:
	using ShootFunction = std::function<std::unique_ptr<Projectile>(Vector2, Vector2)>;

	Weapon(ShootFunction shootFunc, Vector2 direction, float reloadTime);

	void Reload(float deltaTime);

	std::unique_ptr<Projectile> Shoot(Vector2 position);

protected:
	ShootFunction m_ShootFunc;
	Vector2 m_Direction;
	float m_ReloadTime;

	float m_TimeUntilShoot = 0.0f;
};