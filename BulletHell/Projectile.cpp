#include "Projectile.h"


Projectile::Projectile(Vector2 position, Vector2 direction, float damage, float speed)
	: m_Position(position),
	m_Direction(direction),
	m_Damage(damage),
	m_Speed(speed)
{
}

void Projectile::Move(float deltaTime)
{
	Vector2 movePosition = Vector2Scale(Vector2Normalize(m_Direction), m_Speed * deltaTime);
	m_Position = Vector2Add(m_Position, movePosition);
}

void Projectile::Draw() const
{
	DrawCircle(m_Position.x, m_Position.y, 5, RED);
}

Vector2 Projectile::GetPosition() const
{
	return m_Position;
}

Vector2 Projectile::GetDirection() const
{
	return m_Direction;
}
