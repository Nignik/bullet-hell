#include "ProjectileManager.h"

#include <iostream>

ProjectileManager::ProjectileManager(int screenHeight, int screenWidth)
	: m_ScreenHeight(screenHeight),
	m_ScreenWidth(screenWidth)
{
}

void ProjectileManager::UpdateProjectiles(float deltaTime)
{
	for (auto it = m_Projectiles.begin(); it != m_Projectiles.end(); )
	{
		(*it)->Move(deltaTime);
		Vector2 pos = (*it)->GetPosition();
		if (pos.y > m_ScreenHeight || pos.y < 0 || pos.x > m_ScreenWidth || pos.x < 0)
		{
			it = m_Projectiles.erase(it);
		}
		else
		{
			++it;
		}
	}
	std::cout << "number of projectiles: " << m_Projectiles.size() << std::endl;
}

void ProjectileManager::DrawProjectiles()
{
	for (auto it = m_Projectiles.begin(); it != m_Projectiles.end(); it++)
	{
		(*it)->Draw();
	}
}

void ProjectileManager::AddProjectile(std::unique_ptr<Projectile> projectile)
{
	m_Projectiles.push_back(std::move(projectile));
}
