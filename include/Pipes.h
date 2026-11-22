#pragma once
#include "raylib.h"
#include <vector>

struct PipePair
{
	float gap;
	float width;
	Vector2 bottom = { 0,0 };
	bool scored;
	
};

class PipeManager
{
public:
	std::vector<PipePair> pipePair;
	void SpawnPipe();
	void DrawPipe() const;
	void IsPipeOffBounds();
};