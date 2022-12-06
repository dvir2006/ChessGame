#pragma once
#include <string>
class Player
{
public:
	Player(const std::string name);
	~Player();
	void incStepsTaken();
private:
	int _stepsTaken;
	std::string _name;
};

