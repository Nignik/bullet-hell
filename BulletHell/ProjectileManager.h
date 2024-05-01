#pragma once

#include <memory>
#include <list>

#include "Projectile.h"

class ProjectileManager
{
public:
	ProjectileManager(int screenHeight, int screenWidth);
	void UpdateProjectiles(float deltaTime);
	void DrawProjectiles();

	void AddProjectile(std::unique_ptr<Projectile> projectile);

private:
	std::list<std::unique_ptr<Projectile>> m_Projectiles;

	int m_ScreenHeight;
	int m_ScreenWidth;
};