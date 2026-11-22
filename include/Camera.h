#include "raylib.h"

class GameCamera
{
public:
	Camera2D gameCamera = { 0 };
	void Update();
	GameCamera();

};