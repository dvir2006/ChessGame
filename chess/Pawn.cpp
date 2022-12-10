#include "Pawn.h"

//CTOR
Pawn::Pawn(const int team, const int place) : IFigure("Pawn", team, place) { }

//DTOR
Pawn::~Pawn() { }

int Pawn::checkValidMove(const int index,  IFigure* (&board)[BOARD_LENGTH][BOARD_LENGTH], int currTeam)const
{
	int i = index / BOARD_LENGTH, j = index % BOARD_LENGTH, i1 = this->_place / BOARD_LENGTH, j1 = this->_place % BOARD_LENGTH;
	if (index < 0 || index >BOARD_LENGTH * BOARD_LENGTH - 1)
		return BAD_MOV_WRONG_INDEX;
	else if (currTeam != this->_team)
		return BAD_MOV_SRC_OP;
	else if (board[i][j] != nullptr && board[i][j]->getTeam() == currTeam)
		return BAD_MOV_DST_SP;
	else if (this->_place == index)
		return BAD_MOV_SAME_INDEX;
	else if ((this->_place + 8 != index || (this->_place + 16 != index && this->_stepsTaken != 0)) || (this->_place - 8 != index || (this->_place - 16 != index && this->_stepsTaken != 0)))
		return BAD_MOV_WRONG_MOV;
	return VALID_MOV;
}
