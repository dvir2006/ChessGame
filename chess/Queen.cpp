#include "Queen.h"

//CTOR
Queen::Queen(const int team, const int place) : IFigure("Queen", team, place) { }

//DTOR
Queen::~Queen() { }

int Queen::checkValidMove(const int index,  IFigure* (&board)[BOARD_LENGTH][BOARD_LENGTH], int currTeam)const
{
	int i = index / BOARD_LENGTH, j = index % BOARD_LENGTH, i1 = this->_place / BOARD_LENGTH, j1 = this->_place % BOARD_LENGTH, ci, cj;
	ci = i > i1 ? 1 : -1;
	cj = j > j1 ? 1 : -1;
	if (index < 0 || index >BOARD_LENGTH * BOARD_LENGTH - 1)
		return BAD_MOV_WRONG_INDEX;
	else if (currTeam != this->_team)
		return BAD_MOV_SRC_OP;
	else if (board[i][j] != nullptr && board[i][j]->getTeam() == currTeam)
		return BAD_MOV_DST_SP;
	else if (this->_place == index)
		return BAD_MOV_SAME_INDEX;
	else if (abs(i - i1) != abs(j - j1) || i != i1 || j != j1)
		return BAD_MOV_WRONG_MOV;
	if (i1 == i)
		for (int j2 = j1; j2 != j; j2 += cj)
			if (board[i1][j2] != nullptr)
				return BAD_MOV_WRONG_MOV;
	if (j1 == j)
		for (int i2 = i1; i2 != i; i2 += ci)
			if (board[i2][j1] != NULL)
				return BAD_MOV_WRONG_MOV;
	for (i1; i < i1; i += ci)
	{
		for (j1; j < j1; j += cj)
		{
			if (board[i1][j1] != nullptr)
				return BAD_MOV_WRONG_MOV;
		}
	}
	return VALID_MOV;
}
