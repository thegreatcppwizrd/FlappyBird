#include "Bird.h"
#include "Colors.h"
#include "Game.h"
#include "Pipes.h"
#include <iostream>
Bird bird;
extern PipeManager pipeManager;

Bird::Bird()
{
	radius = 20.0f;
	position = { 0.0f, 0.0f };
	velocity = 0.0f;
	gravity = 600.0f;
}

void Bird::Draw()
{
	DrawCircle(position.x, position.y, radius, birdColor);
}

void Bird::MoveRight()
{
	bird.position.x += 100.0f * GetFrameTime();
	//std::cout << bird.position.x << ", " << bird.position.y << std::endl;
}

void Bird::Intit()
{
	position = { 0.0f,  (float)GetScreenHeight() / 2 - radius / 2 };
}

void Bird::UpdateVelocity()
{
	velocity += gravity * GetFrameTime();
	IncrementYByVelocity();
}

void Bird::Flap()
{
	velocity = -300.0f;
}

bool Bird::OutOffBounds()
{
	return (position.y <= radius * -2 || position.y >= GetScreenHeight() - radius * -2);
}

bool Bird::HitPipe() const
{

	for (const auto& pipes : pipeManager.pipePair)
	{
		Rectangle topPipe = {
		pipes.bottom.x, 0.0f - 20.0f, pipes.width, pipes.bottom.y - pipes.gap
		};;

		Rectangle bottomPipe = {
				pipes.bottom.x, pipes.bottom.y + 20.0f , pipes.width, (float)GetScreenHeight() - pipes.bottom.y
		};

		return CheckCollisionCircleRec(position, radius, bottomPipe) || CheckCollisionCircleRec(position, radius, topPipe);
	}
	return false;
}

bool Bird::HasScoredPoint()
{
	for (auto& pipes : pipeManager.pipePair)
	{
		if (!pipes.scored && (pipes.bottom.x + pipes.width) < bird.position.x)
		{
			pipes.scored = true;
			return true;
		}
	}
	return false;
}

void Bird::IncrementYByVelocity()
{
	position.y += velocity * GetFrameTime();
}
