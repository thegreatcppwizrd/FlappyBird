#pragma once
class Game
{
public:
	void Update();
	void Draw() const;
	Game();
	~Game();
	void DrawUI();
private:
	float timer;
	void HasPlayBeenClicked(Rectangle btn);
	Font font;
	enum States
	{
		Playing,
		Menu,
		GameOver
	};
	States currentState;
	unsigned int score;
};