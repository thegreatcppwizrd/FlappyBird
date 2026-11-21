#pragma once
#include "raylib.h"
#include <vector>

struct PipePair
{
	float gap;
	float width;
	Vector2 bottom = { 0,0 };

	
};

class PipeManager
{
public:
	std::vector<PipePair> pipePair;
	void SpawnPipe();
	void DrawPipe();
};