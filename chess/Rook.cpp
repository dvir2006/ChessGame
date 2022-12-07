#include "Rook.h"

//CTOR
Rook::Rook(const int team, const int place) : IFigure("Rook", team, place) { }

//DTOR
Rook::~Rook() { }

int Rook::checkValidMove(const int index, IFigure* (&board)[BOARD_LENGTH][BOARD_LENGTH], int currTeam)const
{
	if (this->_team != currTeam)
		return BAD_MOV_SRC_OP;
	else if (this->_place == index)
		return BAD_MOV_SAME_INDEX;
}