#include "Pipes.h"
#include "Camera.h"
#include <cstdlib>
#include <iostream>
#include "Colors.h"

extern GameCamera camera;

void PipeManager::SpawnPipe()
{
	pipePair.push_back({
		120.0f,
		80.0f,
		{ GetScreenToWorld2D({(float)GetScreenWidth() + 0.0f, 0.0f }, camera.gameCamera).x,
		(float)(250 + (rand() % 401))
		},
		false
		});
}

void PipeManager::DrawPipe() const
{

	for (const auto& pipes : pipePair)
	{


		
		Rectangle topPipe = {
		pipes.bottom.x, 0.0f - 20.0f, pipes.width, pipes.bottom.y - pipes.gap
		};;

		Rectangle bottomPipe = {
				pipes.bottom.x, pipes.bottom.y + 20.0f , pipes.width, (float)GetScreenHeight() - pipes.bottom.y
		};

		DrawRectangleRounded(
			bottomPipe,
			.25f,
			0,
			pipe
		);

		DrawRectangleRounded(
			topPipe,
			.25,
			0,
			pipe
		);

		
	}


}

void PipeManager::IsPipeOffBounds()
{
	for (const auto& pipes : pipePair)
	{
		Rectangle topPipe = {
		pipes.bottom.x, 0.0f - 20.0f, pipes.width, pipes.bottom.y - pipes.gap
		};;

		Rectangle bottomPipe = {
				pipes.bottom.x, pipes.bottom.y + 20.0f , pipes.width, (float)GetScreenHeight() - pipes.bottom.y
		};

		float screenLeftEdge = GetScreenToWorld2D({ 0.0f, 0.0f }, camera.gameCamera).x;

		if (!pipePair.empty() && (pipePair.front().bottom.x + pipePair.front().width) < screenLeftEdge)
		{
			pipePair.erase(pipePair.begin());
			std::cout << "erased Pipe" << std::endl;
		}
	}
}

