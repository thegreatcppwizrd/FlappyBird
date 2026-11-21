#include "Bird.h"
#include "Colors.h"
#include <iostream>
Bird bird;

Bird::Bird()
{
	radius = 30.0f;
	position = { 0.0f, 0.0f };
}

void Bird::Draw()
{
	DrawCircle(position.x, position.y, radius, YELLOW);
}

void Bird::MoveRight()
{
	bird.position.x += 100.0f * GetFrameTime();
	std::cout << bird.position.x << ", " << bird.position.y << std::endl;
}

void Bird::Intit()
{
	position = { 0.0f,  (float)GetScreenHeight() / 2 - radius / 2 };
}
