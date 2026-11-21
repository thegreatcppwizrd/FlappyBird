#include "raylib.h"
#include "Bird.h"
#include "Colors.h"
#include "Camera.h"

int main(void)
{
	InitWindow(450, 800, "Flappy Bird");

	GameCamera camera = GameCamera();
	bird.Intit();

	while (!WindowShouldClose())
	{
		BeginDrawing();
		BeginMode2D(camera.camera);

		ClearBackground(sky);
		bird.Draw();
		bird.MoveRight();
		camera.Update();
		DrawRectangle(100.0f, 0, 200, 200, RED);

		EndMode2D();
		EndDrawing();
	}


	CloseWindow();

	return 0;
}