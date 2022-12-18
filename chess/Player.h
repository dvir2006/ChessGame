#pragma once
#include <string>
class Player
{
public:
	//CTOR
	Player(const std::string name);
	//DTOR
	~Player();

	//setters
	void incStepsTaken();//increases the amount of steps a player already took
private:
	int _stepsTaken;
	std::string _name;
};

