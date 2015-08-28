/*************************************
*                                    *
*	�й�: 20123341                   *
*   �̸�: �����                     *
*                                    *
**************************************/

#include "tetris.h"

int main(int argc, char* argv[])
{
	std::ifstream inStream;
	std::cout << "��Ʈ���� ������ �����մϴ�." << std::endl;
	std::cout << "����� �̸� :" << std::endl;
	if(argc != 1)
		inStream.open(argv[1]);
	char user[8];

	if(argc != 1)
	{
		inStream >> user;
		int seed;
		inStream >> seed;
		srand(seed);
	}
	else
	{
		std::cin >> user;

		srand((unsigned)time(NULL));
	}
	
	CGame game(user);
	int key, state = 0;

	if (argc < 2)
	{
		while (state == 0)
		{
			key = getch();

			if (key == 'q') break;
			state = game.moveBlock(key);
		}

	}
	else
	{
		inStream.open(argv[1]);
		if (!inStream.fail())
		{
			while (1)
			{
				char ch;

				inStream >> ch;
				if (inStream.eof()) break;
				if (ch == 'q') break;

				switch (ch)
				{
				case 'l':
					game.moveBlock(KEY_LEFT);
					break;
				case 'r':
					game.moveBlock(KEY_RIGHT);
					break;
				case 'g':
					game.moveBlock(KEY_DOWN);
					break;
				case 'd':
					game.moveBlock(KEY_SPACE);
					break;
				}

			}

		}
	}
	game.printResult();
	getch();
}