#include <iostream>
#include <vector>
#include <thread>
#include <string>

void typeIt(std::string stringToType, int timeInMilli = 0, int pauseTime = 0)
{
	for (int i = 0; i != stringToType.size(); i++)
	{
		std::cout << stringToType[i];
		std::this_thread::sleep_for(std::chrono::milliseconds(timeInMilli));
	}
	std::this_thread::sleep_for(std::chrono::milliseconds(pauseTime));
}

void printBoard(char board[3][3], int xSize, int ySize)
{
	for (int i = 0; i < xSize; i++)
	{
		for (int j = 0; j < ySize; j++)
		{
			std::cout << board[i][j];
		}
		std::cout << std::endl;
	}
}

int main()
{
	char retryYorN;
	short int x, y;

	bool p1turn = true;
	bool endGame = false;
	bool endRound = false;

	int turns = 0;
	int p1Score = 0;
	int p2Score = 0;
	char board[3][3] = { {'_', '_', '_' },
						 {'_', '_', '_' },
						 {'_', '_', '_' } };

	typeIt("Welcome to tic tac toe!", 25, 2000);
	typeIt("\n\nTo play, enter the x axis (location LEFT TO RIGHT), press enter, then the y axis (location UP TO DOWN, then press enter.", 25, 2000);

	while (!endGame)
	{
		printBoard(board, 3, 3);
		while (!endRound)
		{
			if (p1turn)
			{
				typeIt("Player 1, Go! You have " + std::to_string(p1Score) + " wins so far.\n\n", 10);
			}
			else
			{
				typeIt("Player 2, Go! You have " + std::to_string(p2Score) + " wins so far.\n\n", 10);
			}
			typeIt("Row: ", 10);
			std::cin >> x;
			typeIt("\nColumn: ", 10);
			std::cin >> y;
			if (x <= 3 && x >= 1 && y <= 3 && y >= 1)
			{
				x -= 1;
				y -= 1;
				if (board[x][y] == '_')
				{
					p1turn ? board[x][y] = 'O' : board[x][y] = 'X';
					p1turn = !p1turn;
				}
				else
				{
					typeIt("That place is taken!\n", 0, 1000);
					std::cin.ignore();
					continue;
				}
				turns++;
			}
			else
			{
				typeIt("Invalid.\n\n", 0, 500);
			}
			std::cin.ignore();

			printBoard(board, 3, 3);

			if (board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O' ||
				board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O' ||
				board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O' ||
				board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O' ||
				board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O' ||
				board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O' ||
				board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O' ||
				board[2][0] == 'O' && board[1][1] == 'O' && board[0][2] == 'O')
			{
				typeIt("Player 1 wins!", 150, 300);
				p1Score++;
				endRound = true;
			}

			else if (board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X' ||
				board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X' ||
				board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X' ||
				board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X' ||
				board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X' ||
				board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X' ||
				board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X' ||
				board[2][0] == 'X' && board[1][1] == 'X' && board[0][2] == 'X')
			{
				typeIt("Player 2 wins!", 150, 300);
				p2Score++;
				endRound = true;
			}
			if (turns >= 9)
			{
				typeIt("TIE!");
				endRound = true;
			}
		}
		typeIt("\n\nRetry? (Y/N)", 10);
		std::cin >> retryYorN;

		if (retryYorN == 'y' || retryYorN == 'Y')
		{
			turns = 0;
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++)
					board[i][j] = '_';
			endRound = false;
			p1turn = true;
			continue;
		}
		else if (retryYorN == 'n' || retryYorN == 'N')
		{
			typeIt("The score was:", 10, 500);
			typeIt("\n\nPlayer1: " + std::to_string(p1Score) + " points", 50, 500);
			typeIt("\n\nPlayer2: " + std::to_string(p2Score) + " points", 50, 500);
			typeIt("\n\n\nThanks for playing!", 50, 500);
			typeIt("\nByeee...", 250, 3000);
			endRound = true;
			endGame = true;
		}
	}

	return 0;
}