#include "Camera.h"
#include "Bird.h"
extern Bird bird;
GameCamera camera;

void GameCamera::Update()
{
	gameCamera.target = Vector2{ bird.position.x, 0.0f };
	gameCamera.zoom = 1.0f;
	gameCamera.offset = Vector2{ 100.0f, 0.0f };
}

GameCamera::GameCamera()
{
	gameCamera.zoom = 0.0f;
}

