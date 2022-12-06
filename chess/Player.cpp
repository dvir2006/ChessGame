#include "Player.h"
//CTOR
Player::Player(const std::string name)
	:_name(name),_stepsTaken(0)
{
}

//DTOR
Player::~Player()
{
}
//increases the amount of steps a player already took
void Player::incStepsTaken()
{
	this->_stepsTaken++;
}
