#include <iostream>
using namespace std;

enum enTools { stone = 1, paper = 2, scissors = 3 };
enum enWinner { Tie = 0, Player = 1, Computer = 2 };

struct stRoundInfo {
    short roundNumber = 0;
    enTools PlayerTool;
    enTools ComputerTool;
    enWinner Winner;
};

struct stGameInfo {
    short gameRounds = 0;
    short playerWonTimes = 0;
    short computerWonTimes = 0;
    short drawTimes = 0;
    enWinner gameWinner;
};

int ReadHowManyRounds() {
    int Number = 0;
    do {
        cout << "How many rounds from 1 to 10 ? ";
        cin >> Number;
    } while (Number < 1 || Number > 10);
    return Number;
}

enTools ReadPlayerTool() {
    short Choice = 0;
    do {
        cout << "Your Choice : (1) Stone (2) Paper (3) Scissors ? ";
        cin >> Choice;
    } while (Choice > 3 || Choice < 1);
    return static_cast<enTools>(Choice);
}

enTools GenerateComputerTool() {
    int random = rand() % 3 + 1;
    return static_cast<enTools>(random);
}

enWinner WinGame(enTools PlayerTool, enTools ComputerTool) {
    if (PlayerTool == ComputerTool) {
        return Tie;
    } else if ((PlayerTool == stone && ComputerTool == scissors) ||
               (PlayerTool == paper && ComputerTool == stone) ||
               (PlayerTool == scissors && ComputerTool == paper)) {
        return Player;
    } else {
        return Computer;
    }
}

// Decoders 
string DecodeTool(int Tool) {
    switch (Tool) {
        case 1: return "Stone";
        case 2: return "Paper";
        case 3: return "Scissors";
        default: return "Error Decoding Tool";
    }
}

string DecodeWinner(int Winner) {
    switch (Winner) {
        case 0: return "Tie";
        case 1: return "Player";
        case 2: return "Computer";
        default: return "Error Decoding Winner Name";
    }
}

enWinner DecideWinnerFromResult(short PlayerResult, short ComputerResult) {
    if (PlayerResult > ComputerResult) {
        return Player;
    } else if (PlayerResult < ComputerResult) {
        return Computer;
    } else {
        return Tie;
    }
}

void PrintRoundResults(stRoundInfo RoundInfo) {
    cout << "\n____________Round [" << RoundInfo.roundNumber << "] ____________\n\n";
    cout << "Player  Choice: " << DecodeTool(RoundInfo.PlayerTool) << endl;
    cout << "Computer Choice: " << DecodeTool(RoundInfo.ComputerTool) << endl;
    cout << "Round Winner   : [" << DecodeWinner(RoundInfo.Winner) << "] \n";
    cout << "__________________________________\n" << endl;
}

string tabs(short num) {
    return string(num, '\t');
}

void ShowGameOverScreen() {
    cout << tabs(2) << "__________________________________________________________\n\n";
    cout << tabs(2) << "                 +++ G a m e  O v e r +++\n";
    cout << tabs(2) << "__________________________________________________________\n\n";
}

void printFinalGameResult(stGameInfo gameInfo) {
    cout << tabs(2) << "_____________________ [Game Results ]_____________________\n\n";
    cout << tabs(2) << "Game Rounds        : " << gameInfo.gameRounds << endl;
    cout << tabs(2) << "Player Won Times   : " << gameInfo.playerWonTimes << endl;
    cout << tabs(2) << "Computer Won Times : " << gameInfo.computerWonTimes << endl;
    cout << tabs(2) << "Draw Times         : " << gameInfo.drawTimes << endl;
    cout << tabs(2) << "Final Winner       : " << DecodeWinner(gameInfo.gameWinner) << endl;
    cout << tabs(2) << "__________________________________________________________\n\n";
}

void PlayGame(int NumberOfRounds) {
    stRoundInfo RoundInfo;
    stGameInfo GameInfo;

    for (int round = 0; round < NumberOfRounds; round++) {
        RoundInfo.roundNumber = round + 1;
        RoundInfo.PlayerTool = ReadPlayerTool();
        RoundInfo.ComputerTool = GenerateComputerTool();
        RoundInfo.Winner = WinGame(RoundInfo.PlayerTool, RoundInfo.ComputerTool);
        PrintRoundResults(RoundInfo);

        switch (RoundInfo.Winner) {
            case Tie: GameInfo.drawTimes++; break;
            case Player: GameInfo.playerWonTimes++; break;
            case Computer: GameInfo.computerWonTimes++; break;
            default: break;
        }
    }

    GameInfo.gameWinner = DecideWinnerFromResult(GameInfo.playerWonTimes, GameInfo.computerWonTimes);
    GameInfo.gameRounds = NumberOfRounds;
    ShowGameOverScreen();
    printFinalGameResult(GameInfo);
}

int main() {
    srand((unsigned)time(NULL)); 
    int NumberOfRounds = ReadHowManyRounds();
    PlayGame(NumberOfRounds);
    return 0;
}
