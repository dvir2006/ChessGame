#include "Board.h"

Board::Board()
	:_msg(START_MSG), _p1("White"), _p2("Black"), _currTeam(0),_won(false)
{
	for (int i = 0; i < BOARD_LENGTH; i++)
	{
		if (i > 1 && i < 6)
		{
			for (int j = 0; j < BOARD_LENGTH; j++)
			{
				this->_board[i][j] = NULL;
			}
		}
		else if (i == 0)
		{
			this->_board[i][0] = new Rook();
			this->_board[i][1] = new Knight();
			this->_board[i][2] = new Bishop();
			this->_board[i][3] = new King();
			this->_board[i][4] = new Queen();
			this->_board[i][5] = new Bishop();
			this->_board[i][6] = new Knight();
			this->_board[i][7] = new Rook();
		}
		else if (i == 7)
		{
			this->_board[i][0] = new Rook();
			this->_board[i][1] = new Knight();
			this->_board[i][2] = new Bishop();
			this->_board[i][3] = new King();
			this->_board[i][4] = new Queen();
			this->_board[i][5] = new Bishop();
			this->_board[i][6] = new Knight();
			this->_board[i][7] = new Rook();
		}
		else if (i == 1)
		{
			for (int j = 0; j < BOARD_LENGTH; j++)
			{
				this->_board[i][j] = new Pawn();
			}
		}
		else if (i == 6)
		{
			for (int j = 0; j < BOARD_LENGTH; j++)
			{
				this->_board[i][j] = new Pawn();
			}
		}
	}
}

Board::~Board()
{
	delete[]this->_board;
}

void Board::parseMsg(const std::string msgToParse, int(&results)[2])
{
	results[0] = int(msgToParse[1]) - '0' + int(msgToParse[0]) - 'a';
	results[1] = int(msgToParse[2]) - '0' + int(msgToParse[3]) - 'a';
}

void Board::updateBoard(const int src, const int dest)
{
	int i = src / BOARD_LENGTH,j = src % BOARD_LENGTH,flag= this->_board[i][j]->checkValidMove(dest, this->_board);
	switch (flag)
	{
	case 0:
		this->_board[i][j]->move(src, dest, this->_msg, this->_board);
		break;
	case 1:
		this->_board[i][j]->move(src, dest, this->_msg, this->_board);
		break;
	case BOARD_LENGTH:
		this->_board[i][j]->move(src, dest, this->_msg, this->_board);
		this->_won = true;
		break;
	}
	this->_msg[65] = flag + '0';
	this->changeTeam();
	this->_msg[64] = this->_currTeam;



}




std::string Board::getMsg() const
{
	return this->_msg;
}

void Board::changeTeam() 
{
	this->_currTeam = this->_currTeam ? 0 : 1;
}







