#include<iostream>

using namespace std;

enum enChoice{stone = 1, paper = 2, scissors = 3};
enum enWinner{player = 1, computer = 2, draw = 3};
struct stRoundInfo
{
	short roundNumber;
	enChoice playerChoice;
	enChoice computerChoice;
	enWinner roundWinner;
	string roundWinnerName;
};

struct stGameInfo
{
	short gameRounds;
	short playerWonTimes;
	short computerWonTimes;
	short drawTimes;
	enWinner gameWinner;
	string gameWinnerName;
};

int howManyRounds()
{
	int num;
	do
	{
		cout << "How Many Rounds You Want To Play 1 To 10 ?";
		cin >> num;
	} while (num < 1 || num > 10);
	return num;
}

int readRandomNumber(int from, int to)
{
	int rnd = rand() % (to - from + 1) + from;
	return rnd;
}

enChoice playerChoice()
{
	short choice;
	do
	{
		cout << "\nYour Choice: [1]:Stone, [2]:Paper, [3]:Scissors ? ";
		cin >> choice;
	} while (choice < 1 || choice > 3);
	return (enChoice)choice;
}

enChoice computerChoice()
{
	return (enChoice)readRandomNumber(1, 3);
}

enWinner roundWinner(stRoundInfo roundInfo)
{
	if (roundInfo.playerChoice == roundInfo.computerChoice) return enWinner::draw; 
	switch (roundInfo.playerChoice)
	{
	case enChoice::paper:    if (roundInfo.computerChoice == enChoice::scissors) return enWinner::computer;
		break;
	case enChoice::scissors: if (roundInfo.computerChoice == enChoice::stone)    return enWinner::computer;
		break;
	case enChoice::stone:    if (roundInfo.computerChoice == enChoice::paper)    return enWinner::computer;
		break;
	}
	return enWinner::player;
}

string winnerName(enWinner roundWinner)
{
	string winner[3]{ "player","computer","draw" };
	return winner[roundWinner - 1];
}

void setScreenColor(enWinner winner)
{
	switch (winner)
	{
	case enWinner::player:   system("color 2F");
		break;
	case enWinner::computer: system("color 4F");
		cout << "\a";
		break;
	default:			    system("color 6F");
	}
}

string Choice(enChoice choices)
{
	string choice[3]{ "stone","paper","scissors" };
	return choice[choices - 1];
}

void printRoundResult(stRoundInfo roundInfo)
{
	cout << "\n____________Round [" << roundInfo.roundNumber << "] ____________\n\n";
	cout << "Player   Choice : " << Choice(roundInfo.playerChoice) << "\n";
	cout << "computer Choice : " << Choice(roundInfo.computerChoice) << "\n";
	cout << "Round Winner    : [" << roundInfo.roundWinnerName << "]\n";
	cout << "------------------------\n";
	setScreenColor(roundInfo.roundWinner);
}

enWinner gameWinner(short playerWins, short compWins)
{
	if     (playerWins == compWins)return enWinner::draw;
	else if(playerWins > compWins) return enWinner::player;
	else							return enWinner::computer;
}

stGameInfo fullGameInfo(short gameRounds, short playerWinTimes, short computerWinTimes, short drawTimes)
{
	stGameInfo gameInfo;
	gameInfo.gameRounds       = gameRounds;
	gameInfo.playerWonTimes   = playerWinTimes;
	gameInfo.computerWonTimes = computerWinTimes;
	gameInfo.drawTimes = drawTimes;
	gameInfo.gameWinner = gameWinner(playerWinTimes, computerWinTimes);
	gameInfo.gameWinnerName = winnerName(gameInfo.gameWinner);
	return gameInfo;
}

stGameInfo playGame(int totalRounds)
{
	stRoundInfo roundInfo;
	short playerWinTimes = 0, computerWinTimes = 0, drawTimes = 0;
	for (short round = 1; round <= totalRounds; round++)
	{
		 cout << "\nRound [" << round << "] begins:\n";
		 roundInfo.roundNumber     = round;
		 roundInfo.playerChoice    = playerChoice();
		 roundInfo.computerChoice  = computerChoice();
		 roundInfo.roundWinner	   = roundWinner(roundInfo);
		 roundInfo.roundWinnerName = winnerName(roundInfo.roundWinner);
		 if (roundInfo.roundWinner == enWinner::player)   playerWinTimes++;
		 else if (roundInfo.roundWinner == enWinner::computer) computerWinTimes++;
		 else  drawTimes++;
		 printRoundResult(roundInfo);
	}
	return fullGameInfo(totalRounds, playerWinTimes, computerWinTimes, drawTimes);
}

void resetScreen()
{
	system("cls");
	system("color 0F");
}

string tabs(short num) {
    return string(num, '\t');
}

void ShowGameOverScreen()
{
	cout << tabs(2) << "__________________________________________________________\n\n";
	cout << tabs(2) << "                 +++ G a m e  O v e r +++\n";
	cout << tabs(2) << "__________________________________________________________\n\n";
}

void printFinalGameResult(stGameInfo gameInfo)
{
	cout << tabs(2) << "_____________________ [Game Results ]_____________________\n\n";
	cout << tabs(2) << "Game Rounds        : " << gameInfo.gameRounds << endl;
	cout << tabs(2) << "Player Won Times   : " << gameInfo.playerWonTimes << endl;
	cout << tabs(2) << "Computer Won Times : " << gameInfo.computerWonTimes << endl;
	cout << tabs(2) << "Draw Times		   : " << gameInfo.drawTimes << endl;
	cout << tabs(2) << "Final Winner	   : " << gameInfo.gameWinnerName << endl;
	cout << tabs(2) << "__________________________________________________________\n\n";
	setScreenColor(gameInfo.gameWinner);
}

void startGame()
{
	char playAgain = 'Y';
	do
	{
		resetScreen();
		cout << tabs(3) << "S T O N E ** P A P E R ** S C I S S O R S\n";
		stGameInfo gameInfo = playGame(howManyRounds());
		ShowGameOverScreen();
		printFinalGameResult(gameInfo);
		cout << endl << tabs(3) << "Do you want to play again? Y/N? ";
		cin >> playAgain;
	} while (playAgain == 'y' || playAgain == 'Y');
}

int main()
{
	srand((unsigned)time(NULL));
	startGame();
	return 0;
}