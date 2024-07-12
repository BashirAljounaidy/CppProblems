#include <iostream>
using namespace std;

const string RED = "\033[31m\033[1m";
const string GREEN = "\033[32m\033[1m";
const string RESET = "\033[0m";


enum enOperationType { Add = 1, Sub, Mul, Div, MixType };
enum enLevel { Easy = 1, Mid, Hard, MixLevel };

struct stQuestion {
    int firstNumber;
    int secondNumber;
    int CorrectResult;
    enOperationType OperationType;
};

struct stFinalResult {
    string StringResult;
    short NumberOfQuestions;
    enLevel Questionslevel;
    enOperationType OperationType;
    short CorrectQuestions;
    short WrongQuestions;
};

int ReadHowManyQuestions() {
    int Number = 1;
    do {
        cout << "How many rounds from 1 to 10? ";
        cin >> Number;
    } while (Number < 1 || Number > 10);
    return Number;
}


enLevel ReadLevel() {
    short Choice = 0;
    do {
        cout << "Choose Level     : [1] Easy [2] Mid [3] Hard [4] Mix ? ";
        cin >> Choice;
    } while (Choice > 4 || Choice < 1);
    return static_cast<enLevel>(Choice);
}

enOperationType ReadOperationType() {
    short Choice = 0;
    do {
        cout << "Choose Operation : [1] Add  [2] Sub [3] Mul  [4] Div [5] Mix ? ";
        cin >> Choice;
    } while (Choice > 5 || Choice < 1);
    return static_cast<enOperationType>(Choice);
}

int ReadAnswer() {
    int Number;
    cin >> Number;
    return Number;
}

// Decoders

string DecodeOperation(enOperationType Operation) {
    switch (Operation) {
        case Add: return "+";
        case Sub: return "-";
        case Mul: return "x";
        case Div: return "/";
        case MixType: return "Mix";
        default: return "Error Decoding Tool";
    }
}

string DecodeLevel(enLevel Level) {
    switch (Level) {
        case Easy: return "Easy";
        case Mid: return "Mid";
        case Hard: return "Hard";
        case MixLevel: return "Mix";
        default: return "Error Decoding Tool";
    }
}

//Printers

void PrintQuestionCount(int index, int lastIndex) {
    cout << "\n";
    cout << "Question [" << index << "/" << lastIndex << "]" << endl;
    cout << "\n";
}

void PrintQuestion(stQuestion Question) {
    cout << Question.firstNumber << endl;
    cout << Question.secondNumber << " " << DecodeOperation(Question.OperationType) << endl;
    cout << "_________"<<endl;
}

// void PrintEvaluate(int Answer, int CorrectAnswer) {
//     (Answer == CorrectAnswer) ? cout << "Right Answer :)\nCorrect Answer is "<<CorrectAnswer<< endl : cout <<"Wrong Answer :)\nCorrect Answer is "<<CorrectAnswer<< endl<< endl;
// }
void PrintEvaluate(int Answer, int CorrectAnswer) {
    if (Answer == CorrectAnswer) cout << GREEN << "Right Answer :)\nCorrect Answer is " << CorrectAnswer << RESET << endl;
    else cout << RED << "Wrong Answer :(\nCorrect Answer is " << CorrectAnswer << RESET << endl;
}

void PrintFinalResult(stFinalResult &FinalResult) {
    (FinalResult.CorrectQuestions > FinalResult.WrongQuestions)?cout<<GREEN:cout<<RED;
    cout<<"\n";
    cout << "_____________________________" << "\n\n";
    cout << "   Final Result is " << FinalResult.StringResult << "\n";
    cout << "_____________________________" << "\n";
    cout << "Number of Questions       : " << FinalResult.NumberOfQuestions << "\n";
    cout << "Questions Level           : " << DecodeLevel(FinalResult.Questionslevel) << "\n";
    cout << "OpType                    : " << DecodeOperation(FinalResult.OperationType) << "\n";
    cout << "Number of Right Questions : " << FinalResult.CorrectQuestions << "\n";
    cout << "Number of Wrong Questions : " << FinalResult.WrongQuestions << "\n";
    cout << "_____________________________" << "\n";
    cout<<RESET;
}

int random_number(int from, int to) {
    return rand() % (to - from + 1) + from;
}

int ComputeResultByOperation(enOperationType &Operation, int Number1, int Number2) {
    switch (Operation) {
        case Add: return Number1 + Number2;
        case Sub: return Number1 - Number2;
        case Mul: return Number1 * Number2;
        case Div: return Number1 / Number2;
        case MixType: {
            Operation = static_cast<enOperationType>(random_number(Add, Div));
            return ComputeResultByOperation(Operation, Number1, Number2);
        }
        default: return 0;
    }
}

int GenerateNumberByLevel(enLevel Level) {
    switch (Level) {
        case Easy: return random_number(1, 9);
        case Mid: return random_number(10, 50);
        case Hard: return random_number(50, 100);
        case MixLevel: return random_number(1, 100);
        default: return 0;
    }
}

void FillQuestion(enLevel Level, enOperationType Operation, stQuestion &Question) {
    Question.firstNumber = GenerateNumberByLevel(Level);
    Question.secondNumber = GenerateNumberByLevel(Level);
    Question.CorrectResult = ComputeResultByOperation(Operation, Question.firstNumber, Question.secondNumber);
    Question.OperationType = Operation;
}

string GetStringResult(int Correct, int Wrong) {
    if (Correct == Wrong) return "Tie";
    else if (Correct > Wrong) return "Pass";
    else return "Fail";
}

void StartGame() {
    short HowManyQuestions = ReadHowManyQuestions();
    enLevel Level = ReadLevel();
    enOperationType OperationType = ReadOperationType();
    stQuestion Question;
    stFinalResult FinalResult;
    FinalResult.NumberOfQuestions = HowManyQuestions;
    FinalResult.OperationType = OperationType;
    FinalResult.Questionslevel = Level;
    FinalResult.CorrectQuestions = 0;
    FinalResult.WrongQuestions = 0;

    for (short i = 0; i < HowManyQuestions; i++) {
        FillQuestion(Level, OperationType, Question);
        PrintQuestionCount(i + 1, HowManyQuestions);
        PrintQuestion(Question);
        short Answer = ReadAnswer();
        (Answer == Question.CorrectResult) ? FinalResult.CorrectQuestions++ : FinalResult.WrongQuestions++;
        PrintEvaluate(Answer, Question.CorrectResult);
        
    }

    FinalResult.StringResult = GetStringResult(FinalResult.CorrectQuestions, FinalResult.WrongQuestions);
    PrintFinalResult(FinalResult);
}

int main() {
    srand(static_cast<unsigned>(time(NULL)));
    bool PlayAgain=0;
    do
    {
        StartGame();
        cout<<"\nDo You Want to play again? [1] Yes [0] No ?  ";
        cin>>PlayAgain;
    } while (PlayAgain == 1);
    

    return 0;
}
