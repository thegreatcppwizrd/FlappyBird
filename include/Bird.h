#include "raylib.h"

class Bird
{
public:
	Bird();
	Vector2 position;
	void Draw();
	void MoveRight();
	float radius;
	void Intit();
	void UpdateVelocity();
	void Flap();
	bool OutOffBounds();
	bool HitPipe() const;
	float velocity;
	bool HasScoredPoint();
private:
	float gravity;
	void IncrementYByVelocity();
};

extern Bird bird;