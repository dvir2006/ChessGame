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
			this->_board[i][0] = new Rook(1,0);
			this->_board[i][1] = new Knight(1,1);
			this->_board[i][2] = new Bishop(1,2);
			this->_board[i][3] = new Queen(1,3);
			this->_board[i][4] = new King(1,4);
			this->_board[i][5] = new Bishop(1,5);
			this->_board[i][6] = new Knight(1,6);
			this->_board[i][7] = new Rook(1,7);
		}
		else if (i == 7)
		{
			this->_board[i][0] = new Rook(0,i * BOARD_LENGTH+0);
			this->_board[i][1] = new Knight(0, i * BOARD_LENGTH + 1);
			this->_board[i][2] = new Bishop(0, i * BOARD_LENGTH + 2);
			this->_board[i][3] = new Queen(0, i * BOARD_LENGTH + 3);
			this->_board[i][4] = new King(0, i * BOARD_LENGTH + 4);
			this->_board[i][5] = new Bishop(0,i * BOARD_LENGTH+5);
			this->_board[i][6] = new Knight(0, i * BOARD_LENGTH + 6);
			this->_board[i][7] = new Rook(0, i * BOARD_LENGTH + 7);
		}
		else if (i == 1)
		{
			for (int j = 0; j < BOARD_LENGTH; j++)
			{
				this->_board[i][j] = new Pawn(1,i*BOARD_LENGTH+j);
			}
		}
		else if (i == 6)
		{
			for (int j = 0; j < BOARD_LENGTH; j++)
			{
				this->_board[i][j] = new Pawn(0,i*BOARD_LENGTH+j);
			}
		}
	}
}

Board::~Board()
{
	for (int i = 0; i < BOARD_LENGTH; i++)
		for (int j = 0; j < BOARD_LENGTH; j++)
			delete this->_board[i][j];
}

int Board::isCheck()
{
	int place = findKing();
	for (int i = 0; i < BOARD_LENGTH; i++)
		for (int j = 0; j < BOARD_LENGTH; j++)
			if(this->_board[i][j] != nullptr)
				if (!this->_board[i][j]->checkValidMove(place, this->_board, !this->_currTeam))
					return i * BOARD_LENGTH + j;
	return -1;
}

bool Board::isCheckmate(const int place)
{	
	for (int k = 0; k < BOARD_LENGTH * BOARD_LENGTH; k++)
	{
		for (int i = 0; i < BOARD_LENGTH; i++)
			for (int j = 0; j < BOARD_LENGTH; j++)
				if (this->_board[i][j] != nullptr)
					if (!this->_board[i][j]->checkValidMove(k, this->_board, this->_currTeam))
					{
						if (willCheck(i * BOARD_LENGTH + j, k))
							continue;						
						return false;
					}
	}
	return true;
}

bool Board::willCheck(const int src, const int dest)
{
	int i= src / BOARD_LENGTH, j=src% BOARD_LENGTH, i1= dest / BOARD_LENGTH, j1=dest% BOARD_LENGTH;
	bool ans = false;
	IFigure* tempSrc = this->_board[i][j],* tempDest = this->_board[i1][j1];
	this->_board[i][j]->move(src, dest, this->_msg, this->_board);
	//changeTeam();
	if (isCheck() != -1)
	{
		ans = true;
	}
	this->_board[i][j] = tempSrc;
	if (this->_board[i][j] != nullptr)
	{
		this->_board[i][j]->setPlace(src);
		this->_board[i][j]->decStepsTaken();
	}
	this->_board[i1][j1] = tempDest;
	if (this->_board[i1][j1] != nullptr)
		this->_board[i1][j1]->setPlace(dest);
	//changeTeam();
	return ans;
}

int Board::findKing()
{
	for (int i = 0; i < BOARD_LENGTH; i++)
		for (int j = 0; j < BOARD_LENGTH; j++)
			if(this->_board[i][j] != nullptr)
				if (!this->_board[i][j]->getType().compare("King") && this->_board[i][j]->getTeam() == this->_currTeam)
					return i * BOARD_LENGTH + j;
	return 0; 
}

void Board::parseMsg(const std::string msgToParse, int(&results)[2])
{
	results[0] = BOARD_LENGTH*BOARD_LENGTH - 1 - ((int(msgToParse[1]) - '0' - 1) * BOARD_LENGTH + int(msgToParse[0]) - 'a');
	results[1] = BOARD_LENGTH*BOARD_LENGTH - 1 - ((int(msgToParse[3]) - '0' - 1) * BOARD_LENGTH + int(msgToParse[2]) - 'a');
}

void Board::updateBoard(const int src, const int dest)
{
	int i = src / BOARD_LENGTH,j = src % BOARD_LENGTH,flag = 0,checkPlace = -1;
	if (this->_board[i][j] != nullptr)
	{
		flag = this->_board[i][j]->checkValidMove(dest, this->_board, this->_currTeam);
		if (willCheck(src, dest))
		{
			flag = BAD_MOV_MAKE_CHECK;
		}
		if (!flag)
		{
			this->_board[i][j]->move(src, dest, this->_msg, this->_board);
			changeTeam();
			checkPlace = isCheck();
			if (checkPlace != -1)
			{
				flag = VALID_MOV_CHECK;
				if (isCheckmate(checkPlace))
				{
					flag = VALID_MOV_CHECKMATE;
					this->_won = true;
				}
			}
		}
	}
	else
	{
		flag = BAD_MOV_SRC_OP;
	}

	this->_msg[0] = flag + '0';
	this->_msg[1] = 0;


}




std::string Board::getMsg() const
{
	return this->_msg;
}

void Board::changeTeam() 
{
	if (this->_currTeam)
	{
		this->_p2.incStepsTaken();
		this->_currTeam = 0;
	}
	else
	{
		this->_p1.incStepsTaken();
		this->_currTeam = 1;
	}
}







