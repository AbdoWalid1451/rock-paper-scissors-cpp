#include <iostream>

using namespace std;

enum enElmentsGame { papper = 1, scissor = 2, stone = 3 };

struct strResult
{
	int win = 0;
	int draw = 0;
	int loss = 0;

};

int RandomNumber(int from, int to)
{
	int R_number = rand() % (to - from + 1) + from;
	return R_number;
}

enElmentsGame ChoicePlayer()
{
	int c = 0;
	do {
		cout << "Your Choice: [1]:papper, [2]:scissors,[3]:stone ? ";
		cin >> c;
	} while (c > 3 || c < 1);
	return (enElmentsGame)c;
}

enElmentsGame ChoiceComputer()
{
	return (enElmentsGame)RandomNumber(1, 3);
}

string ChangeNumToString(enElmentsGame choice)
{
	if (choice == enElmentsGame::papper)
		return "papper";
	else if (choice == enElmentsGame::scissor)
		return "scissor";
	else if (choice == enElmentsGame::stone)
		return "stone";
}

void ShapeOfRound(int i, string ChoicePlayer1, string ChoiceComputer)
{
	cout << "-----------------Round [" << i << "]" << " --------\n";
	cout << "Player1 hoice: " << ChoicePlayer1 << endl;
	cout << "Computer Choice: " << ChoiceComputer << endl;

}

void RoundWinner(int ChoicePlayer1, int ChoiceOfComputer, strResult& player1, strResult& computer)
{
	if (ChoicePlayer1 == 3 && ChoiceOfComputer == 1)
	{
		computer.win++;
		player1.loss++;
		cout << "Round winner   :[Computer]\n";
		system("color 4f");
	}
	else if (ChoicePlayer1 == 1 && ChoiceOfComputer == 3)
	{
		player1.win++;
		computer.loss++;
		cout << "Round winner   :[Player1]\n";
		system("color 2f");
	}
	else if (ChoicePlayer1 > ChoiceOfComputer)
	{
		player1.win++;
		computer.loss++;
		cout << "Round winner   :[Player1]\n";
		system("color 2f");

	}
	else if (ChoicePlayer1 < ChoiceOfComputer)
	{
		computer.win++;
		player1.loss++;
		cout << "Round winner   :[Computer]\n";
		system("color 4f");
	}
	else
	{
		player1.draw++;
		computer.draw++;
		cout << "Round winner   :NoWinner\n";
		system("color 6f");
	}
}

string WhoWinner(strResult player1, strResult computer)
{
	if (player1.win > computer.win)
	{
		system("color 2f");
		return "player1";
	}
	else if (player1.win < computer.win)
	{
		system("color 4f");
		return "Computer";
	}
	else
	{
		system("color 6f");
		return "No Winner";

	}
}

void ShowFinal(int freq, strResult player1, strResult computer)
{
	cout << "\n\n";
	cout << "\t\t\t-----------------------------------------------\n ";
	cout << "\t\t\t            ***  G a m e  O v e r  *** \n";
	cout << "\t\t\t-----------------------------------------------\n ";
	cout << "\t\t\t-------------- [ Game Results ]----------------\n";
	cout << "\t\t\t Game Rounds        : " << freq << endl;
	cout << "\t\t\tPlayer1 won timeas  : " << player1.win << endl;
	cout << "\t\t\tComputer won times  : " << computer.win << endl;
	cout << "\t\t\tDraw times          : " << player1.draw << endl;
	cout << "\t\t\tFinal winner        : " << WhoWinner(player1, computer) << endl;
	cout << "\t\t\t-----------------------------------------------\n ";

}

int NumberOfRound()
{
	int freq = 0;

	cout << "How Many Rounds 1 To 10\n";
	cin >> freq;

	return freq;
}

void Game()
{
	char playagain = 'N';
	do {
		system("color 0F");
		strResult player1; strResult computer;
		int freq = NumberOfRound();
		for (int i = 1; i <= freq; i++)
		{
			cout << "Round [" << i << "] begins : \n";
			enElmentsGame ChoicePlayer1 = ChoicePlayer();
			enElmentsGame ChoiceOfComputer = ChoiceComputer();
			ShapeOfRound(i, ChangeNumToString(ChoicePlayer1), ChangeNumToString(ChoiceOfComputer));
			RoundWinner(ChoicePlayer1, ChoiceOfComputer, player1, computer);
			cout << "-------------------------------------------\n";
		}
		ShowFinal(freq, player1, computer);
		cout << "Do you want play again? Y/N? ";
		cin >> playagain;
	} while (playagain == 'Y' || playagain == 'y');
}


int main()
{
	srand((unsigned)time(NULL));

	Game();

}