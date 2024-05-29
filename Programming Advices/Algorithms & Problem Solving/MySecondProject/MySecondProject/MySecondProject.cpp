#include <string.h>
#include <string>
#include <iostream>

using namespace std;


enum OpType      {Add=1,Sub=2,Mul=3,Div=4,MixOp=5};
enum NumbersLevel{Easy=1,Meduem=2,Hard=3,MixNu=4};

struct GameParts
{
    int NumberOfQustion = 0, NumberOfWrongAnswer = 0, NumberOfRightAnswer = 0;
    int Number1 = 0, Number2 = 0, SolveExam = 0, UsirSolve = 0;
    OpType ExamTypeGame = (OpType)1;
    OpType TypeGame = (OpType)1;
    NumbersLevel LevelGame = (NumbersLevel)1;
    string GamePassOrFail;
};

int RandomNumber(int From, int To)
{
    //Function to generate a random number
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

char ReturnOpType(OpType Type)
{
    char  Types[4] = { '+','-','*','/' };
    switch (Type)
    {
    case(1):
        return Types[0];
    case(2):
        return Types[1];
    case(3):
        return Types[2];
    case(4):
        return Types[3];
    default:
        return Types[1];
    }
}

int ReadPositiveNumber(string Messege)
{
    int Number = 0;
    do
    {
        cout << Messege;
        cin >> Number;

    } while (Number < 0);
    return Number;
}

int GetNumber(NumbersLevel Level)
{
    if (Level == NumbersLevel::Easy)
        return RandomNumber(1, 15);
    else if (Level == NumbersLevel::Meduem)
        return RandomNumber(16, 50);
    else if (Level == NumbersLevel::Hard)
        return RandomNumber(50, 200);
    else return RandomNumber(1, 200);
}

OpType GetOpType(int Number)
{
    switch (Number)
    {
    case(1):
        return OpType::Add;
    case(2):
        return OpType::Sub;
    case(3):
        return OpType::Mul;
    case(4):
        return OpType::Div;
    default:
        return OpType::MixOp;
    }

}

NumbersLevel GetLevel(int Number)
{
    switch (Number)
    {
    case(1):
        return NumbersLevel::Easy;
    case(2):
        return NumbersLevel::Meduem;
    case(3):
        return NumbersLevel::Hard;
    default:
        return NumbersLevel::MixNu;
    }

}

int MathQuezSlove(int Number1, int Number2, OpType Type)
{
    if (Type == OpType::Add)
        return (Number1 + Number2);
    else if (Type == OpType::Sub)
        return (Number1 - Number2);
    else if (Type == OpType::Mul)
        return (Number1 * Number2);
    else 
        return (Number1 / Number2);
}

string PassOrFail(int Number1,int Number2)
{
    if (Number1 >= Number2)
        return "Pass";
    else return "Faild";
}

string PrintLevel(NumbersLevel Level)
{
    string Levels[4] = { "Easy","Meduem","Hard","Mix" };
    return Levels[(int)Level - 1];
}

string PrintOpType(OpType Type)
{
    string Levels[5] = { "Add","Sub","Mul","Div","Mix" };
    return Levels[((int)Type) - 1];
}

void PritnQuestion(int Number1, int Number2,int NumberOfQuestion, int NumberOfQuestions, OpType Type)
{
    cout << "\nQuestion[" << NumberOfQuestion << "/" << NumberOfQuestions << "]\n";
    cout << Number1 << "\n";
    cout << Number2 << " " << ReturnOpType(Type) << "\n";
    cout << "______________\n\n";
}

void PrintWinnerResult(GameParts Game)
{
    cout << "\n\n\n________________________________________________________\n";
    cout << "                        Final Result is " << PassOrFail(Game.NumberOfRightAnswer,Game.NumberOfWrongAnswer)<<"__________\n";
    cout << "  _________________________________________________________\n";
    cout << "Number Of Qustion :        " << Game.NumberOfQustion << "\n";
    cout << "Questions Level   :        " << PrintLevel(Game.LevelGame)<<"\n";
    cout << "OpType:                    " << PrintOpType(Game.ExamTypeGame)<<"\n";
    cout << "Number Of Right Answer is: " << Game.NumberOfRightAnswer<<"\n";
    cout << "Number Of Wrong Answer is: " << Game.NumberOfWrongAnswer<<"\n";
}

bool IsUsirTrue(int Number1, int Number2)
{
    if (Number1 == Number2)
        return true;
    else
        return false;
}

bool WantToPlayAgain()
{
    char test;

    cout << "Do you want to play again ? Y/N ";
    cin >> test;

    if (test == 'Y' || test == 'y')
        return true;
    else
        return false;
}

void PlayGame() 
{
    GameParts TheGame;

    TheGame.NumberOfQustion = ReadPositiveNumber("How Many Questions YOu Want To Answer? \n");
    TheGame.LevelGame = GetLevel(ReadPositiveNumber("Enter Questions Level: [1]Easy,[2]Med,[3]Hard,[4]Mix ?  \n"));
    TheGame.ExamTypeGame = GetOpType(ReadPositiveNumber("Enter Operation Type [1]Add,[2]Sub,[3]Mul,[4]Div,[5]Mix ? \n"));
    


    for (int i = 1; i <= TheGame.NumberOfQustion; i++)
    {
        TheGame.Number1 = GetNumber(TheGame.LevelGame);
        TheGame.Number2 = GetNumber(TheGame.LevelGame);

        if (TheGame.ExamTypeGame == OpType::MixOp)
        {
            TheGame.TypeGame = GetOpType(RandomNumber(1, 4));
        }
        else
        {
            TheGame.TypeGame = TheGame.ExamTypeGame;
        }

        TheGame.SolveExam = MathQuezSlove(TheGame.Number1, TheGame.Number2, TheGame.TypeGame);
        PritnQuestion(TheGame.Number1, TheGame.Number2, i, TheGame.NumberOfQustion, TheGame.TypeGame);
        TheGame.UsirSolve = ReadPositiveNumber("");

        if (IsUsirTrue(TheGame.SolveExam, TheGame.UsirSolve))
        {
            cout << "Right Answer :-)\n";
            TheGame.NumberOfRightAnswer++;
        }
        else
        {
            cout << "Wrong Answe :-(\n";
            cout << "The Right Answer is: " << TheGame.SolveExam << "\n";
            TheGame.NumberOfWrongAnswer++;
        }
    }

    PrintWinnerResult(TheGame);

}

void StartGame()
{
    char YesOrNo = true;
    do
    {
        PlayGame();

        YesOrNo = WantToPlayAgain();

    } while (YesOrNo);
}

int main()
{
    srand((unsigned)time(NULL));
   
    StartGame();
   
}


