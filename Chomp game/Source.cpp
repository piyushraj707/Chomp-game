#include <iostream>
using namespace std;

int main() {
	int rows = 0, columns = 0;
	cout << "Enter number of rows: "; cin >> rows;
	cout << "Enter number of columns: "; cin >> columns;

	char player1[] = ""; char player2[] = "";
	cout << "Enter player 1's name: "; cin >> player1;
	cout << "Enter player 2's name: "; cin >> player2;
	char* players[2] = { player1,player2 };

	cout << rows << " " << columns << " " << players[0] << " " << players[1] << " " << endl;
	cout << "...................Let us start the game now..............." << endl;

	bool cond=true;
	bool player_number = true;
	int a = 10;
	int x_ord = rows, y_ord = columns;
	int ctr=0;
	int board[20][20];
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			board[i][j] = 1;
		}
	}
	while (true) {
		player_number = !player_number;
		cout << endl << endl; 
		cout << ".........................................." << endl;
		if (ctr == 2) {
			cout << players[player_number] << " has lost the game." << endl
				<< players[!player_number] << " wins!!!!!!!!!!!!";
			break;
		}
		cout<< players[player_number] << "'s chance" << endl;
		//printing the cookies, 1: cookie, 0: no cookie;
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				cout << board[i][j] << " ";
			}
			cout << endl;
		}

		while (true) {
			cout << "Select the cookie you want to eat, "<<players[player_number]<<": "; cin >> x_ord >> y_ord;
			
			x_ord -= 1; y_ord -= 1;

			if ((x_ord > rows-1) || (y_ord > columns-1)) {
				cout << "Don't be dumb! The board is not that big. Please try again." << endl;
				continue;
			}
			
			if ((x_ord < 0) || (y_ord < 0)) {
				cout << "Are you dumb? Counting starts from 1 not 0 or something. Try again" << endl;
				continue;
			}

			if (board[x_ord][y_ord] == 0) {
				cout << "That cookie has already been eaten :(. Please try again." << endl;
				continue;
			}
			
			break;
		}
		if ((x_ord == 0 && y_ord == 1) || (x_ord == 1 && y_ord == 0))
			ctr += 1;

		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				if ((i >= x_ord) && (j >= y_ord))
					board[i][j] = 0;
			}
		}
	}
	cout << endl << "...............Game Ends..........................." << endl;

	return 0;
}