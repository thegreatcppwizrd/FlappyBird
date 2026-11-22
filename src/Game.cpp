#include "Bird.h"
#include "Colors.h"
#include "Camera.h"
#include "Pipes.h"
#include "Game.h"
#include <iostream>;

extern GameCamera camera;
PipeManager pipeManager;
extern Game game;
extern Bird bird;

void Game::Update()
{
	if (currentState == States::Playing)
	{
		if (timer >= 2.5f)
		{
			pipeManager.SpawnPipe();
			timer = 0.0f;
		}
		else
		{
			timer += GetFrameTime();
		}

		if (IsKeyPressed(KEY_UP))
		{
			bird.Flap();
		}

		pipeManager.IsPipeOffBounds();;
		bird.MoveRight();
		camera.Update();
		bird.UpdateVelocity();

		if (bird.OutOffBounds() || bird.HitPipe())
		{
			bird.position = { 0.0f,  (float)GetScreenHeight() / 2 - bird.radius / 2 };
			pipeManager.pipePair.clear();
			currentState = States::GameOver;
		}

		if (bird.HasScoredPoint())
		{
			score++;
			std::cout << score << std::endl;
		}
	}
}

void Game::Draw() const
{
	pipeManager.DrawPipe();
	bird.Draw();
}

Game::Game()
{
	timer = 0.0f;
	bird.Intit();
	currentState = States::Menu;
	score = 0;
	font = LoadFontEx(RESOURCES_PATH "font.ttf", 256, NULL, 0);
}

Game::~Game()
{
	UnloadFont(font);
}

void Game::DrawUI()
{
	if (currentState == States::Menu || currentState == States::GameOver)
	{
		float playBtnWidth = 300.0f;
		float playBtnHeight = 100.0f;

		

		Rectangle playBtnRec = { GetScreenWidth() / 2 - playBtnWidth / 2, GetScreenHeight() / 2 - playBtnHeight / 2, playBtnWidth, playBtnHeight };
	
		DrawRectangleRounded(
			playBtnRec,
			0.5f,
			15,
			playBtn
		);
		const char* playBtnText = (currentState == States::Menu) ? "Play" : "Try Again";


		float playBtnFontSize = 64.0f;
		float playBtnFontSpacing = 2.0f;

		Vector2 playBtPosition = MeasureTextEx(font, playBtnText, playBtnFontSize, playBtnFontSpacing);

		DrawTextEx(font, playBtnText, { GetScreenWidth() / 2 - playBtPosition.x / 2, GetScreenHeight() / 2 - playBtPosition.y / 2 }, playBtnFontSize, playBtnFontSpacing, WHITE);

		// std::cout << GetScreenWidth() / 2 - playBtnWidth / 2 << ", " << GetScreenHeight() / 2 - playBtnHeight / 2 << std::endl;

		HasPlayBeenClicked(playBtnRec);
		bird.velocity = 0.0f;
		score = 0;
	}
	else
	{
		float scoreFontSize = 128.0f;
		float scoreFontSpacing = 2.0f;
		float border = 8.0f + scoreFontSize;
		Vector2 scoreTextSize = MeasureTextEx(font, TextFormat("%d", score), scoreFontSize, scoreFontSpacing);
		Vector2 scoretextBorder = MeasureTextEx(font, TextFormat("%d", score), border, scoreFontSpacing);
		DrawTextEx(font, TextFormat("%d", score), { GetScreenWidth() / 2 - scoreTextSize.x / 2, 20.0f }, border, scoreFontSpacing, BLACK);
		DrawTextEx(font, TextFormat("%d", score), { GetScreenWidth() / 2 - scoreTextSize.x / 2, 20.0f }, scoreFontSize, scoreFontSpacing, WHITE);
		
	}
}

void Game::HasPlayBeenClicked(Rectangle btn)
{
	if (CheckCollisionPointRec(GetMousePosition(), btn) && IsMouseButtonDown(MOUSE_BUTTON_LEFT))
	{
		currentState = States::Playing;
	}
}



