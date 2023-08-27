#include <iostream>
#include <string>
using namespace std;

char board[3][3] = { { '1', '2', '3' }, { '4', '5', '6' }, { '7', '8', '9' } };
char turn = 'X';
string p1, p2;
int p1_winCount = 0, p2_winCount = 0;
bool draw = false;

bool isBoxEmpty(int, int);
int& playerInput(int&);
void displayBoard();
void playerTurn();
bool endGame();
char& y_n_input(char&);
void displayResults();
void clearBoard();


int main()
{
	char rematch = 'y';

	cout << "\n---------------------------*   TIC TAC TOE   *---------------------------\n";
	cout << "\n\t\tWelcome to the TIC TAC TOE game!\n";
	cout << "\n Enter your name to start playing\n";
	cout << "\n * Player 1: "; cin >> p1;
	cout << "\n * Player 2: "; cin >> p2;
	
	do
	{
		draw = false;

		while (!endGame())
		{
			displayBoard();
			playerTurn();
		}

		clearBoard();

		if (draw)
			cout << "\n\t\t * DRAW *\n";
		else
		{
			if (turn == 'O')
			{
				p1_winCount++;
				cout << "\n\t\t* " << p1 << " wins *\n";
			}
			else
			{
				p2_winCount++;
				cout << "\n\t\t* " << p2 << " wins *\n";
			}
		}

		cout << "\n\t Do you want a rematch?\n";
		cout << "\n\t Enter 'Y' for yes, 'N' for no\n";
		cout << "\n\t * Choice :  ";
		rematch = y_n_input(rematch);

	} while (rematch != 'n' && rematch != 'N');

	displayResults();

	return 0;
} 






bool isBoxEmpty(int r, int c)
{
	return (board[r][c] != 'X' && board[r][c] != 'O');
}


int& playerInput(int& n)
{
	cin >> n;
	while (cin.fail() || n > 9 || n < 1)
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore();
			cout << "\n Error! input must be numeric only \n";
		}
		else
			cout << "\n Error! Please choose a number from the given board (1-9)\n";

		cout << "\n\t- Choice : ";
		cin >> n;
	}
	return n;
}


void displayBoard()
{
	system("cls");
	cout << "\n---------------------------*   TIC TAC TOE   *---------------------------\n";
	cout << "\n\n\n\t\t       |       |       \n";
	cout << "\t\t   " << board[0][0] << "   |   " << board[0][1] << "   |   " << board[0][2] << "   \t\t Player Symbols:\n";
	cout << "\t\t       |       |       \n";
	cout << "\t\t-------|-------|--------\t\t"<<p1<<" :  X\n";
	cout << "\t\t       |       |       \n";
	cout << "\t\t   " << board[1][0] << "   |   " << board[1][1] << "   |   " << board[1][2] << "     \t\t" << p2 << " :  O\n"; 
	cout << "\t\t       |       |       \n";
	cout << "\t\t-------|-------|--------\n";
	cout << "\t\t       |       |       \n";
	cout << "\t\t   " << board[2][0] << "   |   " << board[2][1] << "   |   " << board[2][2] << "   \n";
	cout << "\t\t       |       |       \n\n\n";
	cout << "\n Instructions: To choose a box, you must choose the number written on it\n\n";
}


void playerTurn()
{
	int choice;
	int row = NULL, col = NULL;

	
	if (turn == 'X')
		cout << "\n\t * " << p1 << "'s turn  ( X ) *\n";
		

	else if (turn == 'O')
		cout << "\n\t * " << p2 << "'s turn  ( O ) *\n";

	cout << "\n\t- Choice : ";

	choice = playerInput(choice);

	switch (choice)
	{
	case 1:
	{
		row = 0;	col = 0;	break;
	}
	case 2:
	{
		row = 0;	col = 1;	break;
	}
	case 3:
	{
		row = 0;	col = 2;	break;
	}
	case 4:
	{
		row = 1;	col = 0;	break;
	}
	case 5:
	{
		row = 1;	col = 1;	break;
	}
	case 6:
	{
		row = 1;	col = 2;	break;
	}
	case 7:
	{
		row = 2;	col = 0;	break;
	}
	case 8:
	{
		row = 2;	col = 1;	break;
	}
	case 9:
	{
		row = 2;	col = 2;	break;
	}
	default:
	{
		cout << "\n Error! Please choose a number from the given board\n";
		break;
	}
	}


	if (isBoxEmpty(row, col))
	{
		if (turn == 'X')
		{
			board[row][col] = 'X';
			turn = 'O';
		}
		else
		{
			board[row][col] = 'O';
			turn = 'X';
		}
	}

	else
	{
		cout << "\n Box already filled, please choose a different box\n";
		playerTurn();
	}

	displayBoard();
}


bool endGame()
{
	for (int i = 0; i < 3; i++)
		if (board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i])
			return true;

	if (board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0])
		return true;

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (board[i][j] != 'X' && board[i][j] != 'O')
				return false;
	draw = true;

	return true;
}


char& y_n_input(char& ch)
{
	cin >> ch;
	while (ch != 'y' && ch != 'Y' && ch != 'n' && ch != 'N')
	{
		cout << "\n Error! Please choose from the given options \n";
		cout << "\n\t * Choice :  ";
		cin >> ch;
	}
	return ch;
}


void displayResults()
{
	system("cls");
	cout << "\n\n\tResult\n";
	for (int i = 0; i < 23; i++)cout << "-";
	cout << "\n Wins:\n";
	cout << "\n - " << p1 << ": " << p1_winCount << "\n";
	cout << "\n - " << p2 << ": " << p2_winCount << "\n";
}


void clearBoard()
{
	char temp = '1';

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) board[i][j] = temp++;
}
