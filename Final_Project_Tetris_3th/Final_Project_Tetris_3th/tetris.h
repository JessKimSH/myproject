#include <iostream>
#include <fstream>
#include "curses.h"
#include "Block.h"

#define KEY_SPACE 32

class CGame
{
private:
	WINDOW *win1; 
	WINDOW *win2;
	WINDOW *win3; 
	
	Block *block[7];
	int x, y; 
	int board[18][10];
	int score,	
		type;			//block�� ����
public:
	CGame(char *user);

	void printGameBoard();				//���Ӻ��� ���
	void printResult();					//���� ����� ���� ���
	void printScore();					//�ǽð� ���� ���(Score window)
	bool checkCollision(int x, int y);	//�浹 �˻�
	int moveBlock(int dir);				//Ű �Է¹ޱ�
	void checkLine();

	~CGame();
};