#include "Camera.h"
#include "Bird.h"
extern Bird bird;

void GameCamera::Update()
{
	camera.target = Vector2{ bird.position.x, 0.0f };
	camera.zoom = 1.0f;
	camera.offset = Vector2{ 100.0f, 0.0f };
}
