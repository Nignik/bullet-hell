#include "BulletHell.h"

#include <raylib.h>
#include <rlgl.h>
#include <raymath.h>

#include "Player.h"
#include "ProjectileManager.h"

using namespace std;

int main()
{
	const int screenWidth = 1000;
	const int screenHeight = 800;

	InitWindow(screenWidth, screenHeight, "bullet hell");

	Camera2D camera = { 0 };
	camera.zoom = 1.0f;

	SetTargetFPS(60);

	Player player(Vector2{ 100, 100 }, 100, 165, 0);
	ProjectileManager projectileManager(screenHeight, screenWidth);

	while (!WindowShouldClose())
	{
		Vector2 moveDirection = Vector2Normalize(Vector2(IsKeyDown(KEY_D) - IsKeyDown(KEY_A), IsKeyDown(KEY_S) - IsKeyDown(KEY_W)));

		if (IsKeyDown(KEY_SPACE))
		{
			auto proj = player.Attack();
			if (proj)
			{
				projectileManager.AddProjectile(std::move(proj));
			}
		}

		float deltaTime = GetFrameTime();
		player.Move(moveDirection, deltaTime);
		player.UpdateWeapon(deltaTime);
		projectileManager.UpdateProjectiles(deltaTime);

		BeginDrawing();
		ClearBackground(BLACK);

		BeginMode2D(camera);

		rlPushMatrix();
		rlTranslatef(0, 25 * 50, 0);
		rlRotatef(90, 1, 0, 0);
		rlPopMatrix();

		player.Draw();
		projectileManager.DrawProjectiles();

		EndMode2D();

		DrawText("Mouse right button drag to move, mouse wheel to zoom", 10, 10, 20, WHITE);

		EndDrawing();
	}

	CloseWindow();
	return 0;
}
