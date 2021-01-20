#include <stdio.h>
#include <stdlib.h>

void print_board (char board[3][3]);
void print_board_2 (char board[3][3]);
int check_won (char board[3][3]);

int main (void)
{

	int game_won, count, player, status = 0;
	char input = '\0';
	char symbol = 'X';
	char reserved_nums[10] = {'\0'};

	//configure the initial board 

	char board[3][3] = { 

					{'1','2','3'},
					{'4','5','6'},
					{'7','8','9'}
	};

	print_board(board);

	while (game_won == 0)
	{
		status = 0;

		if(count % 2 == 0)
		{
			player = 1;
			symbol = 'X';
		}
		else
		{ 
			player = 2;
			symbol = 'O';
		}
		printf("player %d, enter a number\n", player);
		scanf("%s", &input);

		for (int i = 0; i < 10; i++)
			if (input == reserved_nums[i])
			{
				printf("unallowed input, try again\n");
				status = 1;
			}

			if (status > 0)
				continue;

		reserved_nums[count] = input;

		for (int i = 0; i < 3; ++i) //assign the symbol to the chosen corresponding input in array 
			for (int j =0; j < 3; ++j)
				if (input == board[i][j])
					board[i][j] = symbol;

		print_board(board); // print the modified board

		if ((check_won(board)) > 0)
		{
			printf("we have a winner! congrats player %d!\n\n", player);
			game_won = 1;
			break;
		}
		else if ((check_won(board)) < 0)
		{
			printf("The game is a draw!\n\n");
			game_won = 1;
			break;
		}

		++count;
	}

	return 0;
}

void print_board(char board[3][3]) //prints the current board when invoked 
{
	system("clear"); //clear the screen 
	printf("\nplayer 1: X\nPlayer 2: O\n\n");	
	printf("\n");
	printf("   %c   |   %c   |   %c   |\n",board[0][0],board[0][1],board[0][2]);
	printf("------------------------\n");
	printf("   %c   |   %c   |   %c   |\n",board[1][0],board[1][1],board[1][2]);
	printf("------------------------\n");
	printf("   %c   |   %c   |   %c   |\n",board[2][0],board[2][1],board[2][2]);
	printf("\n");

	return;
} 

int check_won(char board[3][3]) //checks the current board for wins when invoked, returns win status, 8 possible win scenarios
{
	int status = 0;

	if (board[0][0] == board[0][1] && board[0][0] == board[0][2]) //Checks for horizontal three in a row
		status = 1;
	else if (board[1][0] == board[1][1] && board[1][0] == board[1][2])
		status = 1;
	else if (board[0][0] == board[1][0] && board[0][0] == board[2][0])
		status = 1;
	
	else if (board[0][0] == board[1][0] && board[0][0] == board[2][0]) //checks for vertical three in a row 
		status = 1;
	else if (board[0][1] == board[1][1] && board[0][1] == board[2][1])
		status = 1;
	else if (board[0][2] == board[1][2] && board[0][2] == board[2][2])
		status = 1;

	else if (board[0][0] == board[1][1] && board[0][0] == board[2][2]) //checks for diagonal three in a row
		status = 1;
	else if (board[0][2] == board[1][1] && board[0][2] == board[2][0])
		status = 1;

	else if (board[0][0] != '1' && board[0][1] != '2' && board[0][2] != '3' && board[1][0] != '4' && board[1][1] != '5' && board[1][2] != '6' &&
			board[2][0] != '7' && board[2][1] != '8' && board[2][2] != '9')
			status = -1;
	
	return status;
}















