#include "Weapon.h"
#include "Projectile.h"

Weapon::Weapon(ShootFunction shootFunc, Vector2 direction, float reloadTime)
	: m_ShootFunc(shootFunc),
	m_Direction(direction),
	m_ReloadTime(reloadTime)
{
}

void Weapon::Reload(float deltaTime)
{
	m_TimeUntilShoot -= deltaTime;
}

std::unique_ptr<Projectile> Weapon::Shoot(Vector2 position)
{
	if (m_TimeUntilShoot <= 0.0f)
	{
		m_TimeUntilShoot = m_ReloadTime;
		return m_ShootFunc(position, m_Direction);
	}
	else
	{
		return nullptr;
	}
}

