#include "Pipes.h"
#include "Camera.h"
#include <cstdlib>

extern GameCamera camera;

void PipeManager::SpawnPipe()
{
	pipePair.push_back({
		160.0f,
		80.0f,
		{ GetScreenToWorld2D({(float)GetScreenWidth() + 0.0f, 0.0f }, camera.gameCamera).x,
		(float)(250 + (rand() % 401))
		}
		});
}

void PipeManager::DrawPipe()
{
	for (auto& pipes : pipePair)
	{


		


		Rectangle bottomPipe = {
				pipes.bottom.x, pipes.bottom.y, pipes.width, (float)GetScreenHeight() - pipes.bottom.y
		};

		DrawRectangle(bottomPipe.x, bottomPipe.y,
			bottomPipe.width, bottomPipe.height,
			GREEN
		);

		Rectangle topPipe = {
			pipes.bottom.x, 0.0f, pipes.width, pipes.bottom.y - pipes.gap
		};;

		DrawRectangle(topPipe.x, topPipe.y,
			topPipe.width, topPipe.height,
			GREEN
		);
	}
}
