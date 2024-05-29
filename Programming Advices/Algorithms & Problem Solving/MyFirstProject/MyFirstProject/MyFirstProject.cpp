#include <iostream>
#include <string.h>
#include <random>
#include <string>

using namespace std;

int RandomNumber(int From, int To)
{
    //Function to generate a random number
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

int ReadPsitiveNumber(string Messege)
{
    int Number = 0;

    do
    {
        cout << Messege;
        cin >> Number;

    } while (Number < 0);

    return Number;
}

enum PartsOfGame { Stone = 1, Paper = 2, Scissor = 3, Computer = 4, Usir = 5,Draw=6 };

struct Result
{
    PartsOfGame RoundWinner,PlayerChoice,ComputerChoise;
    PartsOfGame FinalWinner;
    int RoundsGame,PlayerWonTimes=0, ComputerWonTimes=0, DrawTimes=0;
};

PartsOfGame ComputerChoice()
{
    int Rand = RandomNumber(1,3);

    if (Rand == 1)
    {
        return PartsOfGame::Stone;
    }
    else if (Rand == 2)
    {
        return PartsOfGame::Paper;
    }
    else
    {
        return PartsOfGame::Scissor;
    }
}

PartsOfGame UsirCohice(int NumberOfChoice)
{
    if (NumberOfChoice == 1)
    {
        return PartsOfGame::Stone;
    }
    else if (NumberOfChoice == 2)
    {
        return PartsOfGame::Paper;
    }
    else
    {
        return PartsOfGame::Scissor;
    }
}

PartsOfGame WinnerPlayer(PartsOfGame ChoiceComputer, PartsOfGame ChoiceUsir)
{
    if (int(ChoiceComputer) == 1)
    {
        if (int(ChoiceUsir) == 3)
            return PartsOfGame::Computer;
        else if (int(ChoiceUsir) == 2)
            return PartsOfGame::Usir;
        else return PartsOfGame::Draw;
    }
    else if (int(ChoiceComputer == 2))
    {
        if (int(ChoiceUsir) == 1)
            return PartsOfGame::Computer;
        else if (int(ChoiceUsir) == 2)
            return PartsOfGame::Draw;
        else return PartsOfGame::Usir;
    }
    else
    {
        if (int(ChoiceUsir) == 2)
            return PartsOfGame::Computer;
        else if (int(ChoiceUsir) == 3)
            return PartsOfGame::Draw;
        else return PartsOfGame::Usir;
    }
}

int GetUsirChoice()
{
    return ReadPsitiveNumber("Your choice : [1] Stone, [2] Paper, [3] Scissors ? ");
}

void EffectsOfRound(PartsOfGame Winner)
{
    switch (Winner)
    {
    case(4):
        cout << '/a/';
        system("color 4");
        break;
    case(5):
        system("color 2");
        break;
    case(6):
        system("color 6");
        break;
    }
}

void PrintStartOfRound(int RoundNumber)
{
    cout << "\n\n\t\tRound [" << RoundNumber << "] Bigins\n";
}

string ReturnStringChoice(PartsOfGame Game)
{
    if (Game == PartsOfGame::Computer)
        return "Computer";
    else if (Game == PartsOfGame::Usir)
        return "Usir";
    else if (Game == PartsOfGame::Draw)
        return "Draw";
    else if (Game == PartsOfGame::Paper)
        return "Paper";
    else if (Game == PartsOfGame::Stone)
        return "Stone";
    else
        return "Scissors";
}

void PrintRoundResult(Result Round1Result)
{
    EffectsOfRound(Round1Result.RoundWinner);
    cout << "\nPlayer Choice: " << ReturnStringChoice(Round1Result.PlayerChoice) << "\n";
    cout << "\nComputer Choice: " << ReturnStringChoice(Round1Result.ComputerChoise) << "\n";
    cout << "\nRound Winner: " << ReturnStringChoice(Round1Result.RoundWinner) << "\n";
    cout << "****************************************************\n";
}

void PrintGameResult(Result Game)
{
    EffectsOfRound(Game.FinalWinner);
    cout << "\n\n";
    cout << "____________________________\n";
    cout << "        Game Over          \n";
    cout << "____________________________\n\n";
    cout << "_______[Game Result]________\n";
    cout << "Game Round:  " << Game.RoundsGame<<"\n";
    cout << "Player won times :  " << Game.PlayerWonTimes << "\n";
    cout << "Computer Won Times:  " << Game.ComputerWonTimes << "\n";
    cout << "Draw Times:  " << Game.DrawTimes << "\n";
    cout << "Final Winner:  " << ReturnStringChoice(Game.FinalWinner)<< "\n";
    cout << "____________________________\n\n";
}

bool PlayAgain()
{
    char YesOrNo;

    cout << "Do you want to play again? Y/N ";
    cin >> YesOrNo;

    if ((int)YesOrNo == 89 || (int)YesOrNo == 121)
        return true;
    else return false;
}

void FinalWinner(Result &TheGameResult)
{
    if (TheGameResult.ComputerWonTimes > TheGameResult.PlayerWonTimes)
        TheGameResult.FinalWinner = PartsOfGame::Computer;
    else if (TheGameResult.ComputerWonTimes < TheGameResult.PlayerWonTimes)
        TheGameResult.FinalWinner = PartsOfGame::Usir;
    else TheGameResult.FinalWinner = PartsOfGame::Draw;
}

void StartGame()
{
    bool RGame = true;
    do
    {
        Result TheGame;

        TheGame.RoundsGame = ReadPsitiveNumber("How many rounds 1 to 10 ? ");

        for (int i = 1; i <= TheGame.RoundsGame; i++)
        {
            PrintStartOfRound(i);

            TheGame.PlayerChoice = UsirCohice(GetUsirChoice());
            TheGame.ComputerChoise = ComputerChoice();
            TheGame.RoundWinner = WinnerPlayer(TheGame.ComputerChoise, TheGame.PlayerChoice);

            PrintRoundResult(TheGame);

            if (TheGame.RoundWinner == PartsOfGame::Computer)
            {
                TheGame.ComputerWonTimes++;
            }
            else if (TheGame.RoundWinner == PartsOfGame::Usir)
            {
                TheGame.PlayerWonTimes++;
            }
            else
            {
                TheGame.DrawTimes++;
            }

        }

        FinalWinner(TheGame);
        PrintGameResult(TheGame);

        RGame = PlayAgain();

    } while (RGame);
}

int main()
{
    //Seeds the random number generator in C++, called only onc
    srand((unsigned)time(NULL));

    StartGame();


}

