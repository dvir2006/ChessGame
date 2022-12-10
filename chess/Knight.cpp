#include "Knight.h"

//CTOR
Knight::Knight(const int team, const int place) : IFigure("Knight", team, place) { }

//DTOR
Knight::~Knight() { }

int Knight::checkValidMove(const int index, IFigure* (&board)[BOARD_LENGTH][BOARD_LENGTH], int currTeam)const
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
	else if ((i1+2 == i && j+1 == j) || (i1 + 2 == i && j - 1 == j) || (i1 - 2 == i && j + 1 == j) || (i1 - 2 == i && j - 1 == j) || (i1 + 1 == i && j + 2 == j)|| (i1 - 1 == i && j + 2 == j) || (i1 + 1 == i && j - 2 == j) || (i1 - 1 == i && j - 2 == j))
		return VALID_MOV;
	return  BAD_MOV_WRONG_MOV;
}
