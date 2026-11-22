#include "raylib.h"
#include "Game.h"
#include <ctime>
#include <cstdlib>
#include "Colors.h"
#include "Camera.h"
extern GameCamera camera;

int main(void)
{
	srand(time(0));

	InitWindow(450, 800, "Flappy Bird");

	SetTargetFPS(60);

	
	Game game;
	while (!WindowShouldClose())
	{
		BeginDrawing();
		BeginMode2D(camera.gameCamera);

		
	
		ClearBackground(sky);
		
		game.Update();
		game.Draw();
	
		EndMode2D();
		game.DrawUI();

		EndDrawing();
	}


	CloseWindow();

	return 0;
}