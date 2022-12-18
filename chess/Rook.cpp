#include "Rook.h"

//CTOR
Rook::Rook(const int team, const int place) : IFigure("Rook", team, place) { }

//DTOR
Rook::~Rook() { }

//function recives destination index,the chess board and the current team and returns a code according to the move(valid or not)
int Rook::checkValidMove(const int index, IFigure* (&board)[BOARD_LENGTH][BOARD_LENGTH], int currTeam)const
{
	int dstI = index / BOARD_LENGTH, dstJ = index % BOARD_LENGTH;
	int srcI = this->_place / BOARD_LENGTH, srcJ = this->_place % BOARD_LENGTH;
	int ci, cj, i, j;
	ci = dstI > srcI ? 1 : -1;
	cj = dstJ > srcJ ? 1 : -1;

	if (this->_team != currTeam)
		return BAD_MOV_SRC_OP;
	else if (board[dstI][dstJ] != NULL && board[dstI][dstJ]->getTeam() == currTeam)
		return BAD_MOV_DST_SP;
	else if (dstI > 7 || dstI < 0 || dstJ > 7 || dstJ < 0)
		return BAD_MOV_WRONG_INDEX;
	else if (this->_place == index)
		return BAD_MOV_SAME_INDEX;
	else if (srcI != dstI && srcJ != dstJ)
		return BAD_MOV_WRONG_MOV;

	if (srcI == dstI)
		for (j = srcJ + cj; j != dstJ; j += cj)
			if (board[srcI][j] != NULL)
				return BAD_MOV_WRONG_MOV;
	if (srcJ == dstJ)
		for (i = srcI + ci; i != dstI; i += ci)
			if (board[i][srcJ] != NULL)
				return BAD_MOV_WRONG_MOV;
	return VALID_MOV;

}