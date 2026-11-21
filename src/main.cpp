#include "raylib.h"
#include "Bird.h"
#include "Colors.h"
#include "Camera.h"
#include "Pipes.h"
#include <ctime>

extern GameCamera camera;

int main(void)
{
	srand(time(0));
	float timer = 0.0f;
	PipeManager pipeManager;
	InitWindow(450, 800, "Flappy Bird");

	SetTargetFPS(60);

	bird.Intit();

	while (!WindowShouldClose())
	{
		BeginDrawing();
		BeginMode2D(camera.gameCamera);

		if (timer >= 2.5f)
		{
			pipeManager.SpawnPipe();
			timer = 0.0f;
		}
		else
		{
			timer += GetFrameTime();
		}
	
		ClearBackground(sky);
		pipeManager.DrawPipe();
		bird.Draw();
		bird.MoveRight();
		camera.Update();
		bird.UpdateVelocity();

		if (IsKeyPressed(KEY_UP))
		{
			bird.Flap();
		}

		EndMode2D();
		EndDrawing();
	}


	CloseWindow();

	return 0;
}