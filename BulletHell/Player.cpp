#include "Player.h"

Player::Player(Vector2 position, int health, int speed, int score)
	: m_Position(position),
	m_Health(health),
	m_Speed(speed),
	m_Score(score)
{
	m_Weapon = std::make_unique<Weapon>([](Vector2 position, Vector2 direction) -> std::unique_ptr<Projectile> {
		return std::make_unique<Projectile>(position, direction, 10.0f, 250.0f);
		}, Vector2(0.0f, -1.0f), 0.5f);
}

void Player::Move(Vector2 direction, float deltaTime)
{
	Vector2 newPosition = Vector2Scale(Vector2Normalize(direction), m_Speed * deltaTime);
	m_Position = Vector2Add(m_Position, newPosition);
}

std::unique_ptr<Projectile> Player::Attack()
{
	return m_Weapon->Shoot(m_Position);
}

void Player::UpdateWeapon(float deltaTime)
{
	m_Weapon->Reload(deltaTime);
}

void Player::SwapWeapon(std::unique_ptr<Weapon> weapon)
{
	m_Weapon = std::move(weapon);
}

void Player::Draw() const
{
	DrawCircle(m_Position.x, m_Position.y, 10, GREEN);
}

Vector2 Player::GetPosition() const
{
	return m_Position;
}

int Player::GetHealth() const
{
	return m_Health;
}

int Player::GetScore() const
{
	return m_Score;
}
