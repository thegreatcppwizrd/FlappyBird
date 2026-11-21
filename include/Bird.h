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
private:
	Vector2 direction;
};

extern Bird bird;