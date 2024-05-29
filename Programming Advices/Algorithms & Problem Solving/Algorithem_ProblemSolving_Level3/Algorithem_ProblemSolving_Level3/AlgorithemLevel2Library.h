#include <iostream>
#include <string.h>
#include <random>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int RandomNumber(int From, int To)
{
	//Function to generate a random number
	int randNum = rand() % (To - From + 1) + From;
	return randNum;
}

void FillMatrixWithRandomNumbers(int arr[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			arr[i][j] = RandomNumber(1, 100);
		}
	}
}

void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			cout << setw(3) << arr[i][j] << " ";
		}
		cout << "\n";
	}
}

int RowSum(int arr[3][3], short RowNumber, short Cols)
{
	int Sum = 0;
	for (short j = 0; j <= Cols - 1; j++)
	{
		Sum += arr[RowNumber][j];
	}
	return Sum;
}

void SumRowsInArray(int arr[3][3], short Rows, short Cols, int ResultArray[3])
{
	for (short i = 0; i < Rows; i++)
	{
		ResultArray[i] = RowSum(arr, i, Cols);
	}
}

int SumColos(int arr[3][3], short ColsNumber, short Rows)
{
	int sum = 0;
	for (int i = 0; i < Rows; i++)
	{
		sum += arr[i][ColsNumber];
	}
	return sum;
}

void PrintEachRowSum(int Arr[3], int Rows)
{
	for (short j = 0; j < Rows; j++)
	{
		cout << "Sum Row[" << j + 1 << "]: " << Arr[j] << endl;
	}

}

void SumColsInArray(int arr[3][3], int ResultArray[3], int Rows, int Cols)
{
	for (int i = 0; i < Cols; i++)
	{
		ResultArray[i] = SumColos(arr, i, Rows);
	}
}

void PrintEachColsSum(int ResultArray[3], short Cols)
{
	for (int j = 0; j < Cols; j++)
	{
		cout << "Sum Of Cols[" << j + 1 << "]: " << ResultArray[j] << endl;
	}
}

void TransposMatrix(int arr[3][3], int Transpose[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			Transpose[i][j] = arr[j][i];
		}
	}
}

void FillMatrixWithFollowingNumbers(int arr[3][3], short Rows, short Cols)
{
	short Counter = 1;

	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			arr[i][j] = Counter;
			Counter++;
		}
	}
}

void MulTwoMatrix(int Matrix1[3][3], int Matrix2[3][3], int ResultMatrix[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			ResultMatrix[i][j] = Matrix1[i][j] * Matrix2[i][j];
		}
	}
}

void PrintMeddleRow(int arr[3][3], short Rows, short Cols)
{
	short MeddleRow = Rows / 2;
	for (int i = 0; i < Cols; i++)
	{
		printf("%0*d ", 2, arr[MeddleRow][i]);
	}
}

void PrintMeddleCols(int arr[3][3], short Rows, short Cols)
{
	short MeddleCols = Cols / 2;
	for (int i = 0; i < Cols; i++)
	{
		printf("%0*d ", 2, arr[i][MeddleCols]);
	}
}

int SumAllElementsOfMatrix(int arr[3][3], short Rows, short Cols)
{
	int sum = 0;
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			sum += arr[i][j];
		}
	}
	return sum;
}

bool IsMatrixEquls(int arr[3][3], int arr2[3][3])
{
	return (SumAllElementsOfMatrix(arr, 3, 3) == SumAllElementsOfMatrix(arr2, 3, 3));
}

bool ArrMatrixTypicl(int arr[3][3], int arr2[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			if (arr[i][j] != arr2[i][j])
				return false;
		}
	}
	return true;
}

void PrintEqualOrNot(bool AreMatrixTypicl)
{
	if (AreMatrixTypicl)
		cout << "\n Matrix is Typical \n";
	else
		cout << "\n Matrix in not Typical\n";
}

bool AreIdentityMatrix(int arr[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			if (i == j && (arr[i][j] != 1))
				return false;
			else if (i != j && (arr[i][j] != 0))
				return false;
		}
	}
	return true;
}

void FillMatrixWithIdentityNumbers(int arr[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (i == j)
				arr[i][j] = 1;
			else arr[i][j] = 0;
		}
	}
}

bool AreScalarMatrix(int arr[3][3], short Rows, short Cols)
{
	short ScalarNumber = arr[0][0];

	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			if (i == j && arr[i][j] != ScalarNumber)
				return false;
			else if (i != j && arr[i][j] != 0)
				return false;
		}
	}
	return true;
}

bool IsTheNumberOnMatrix(int arr[3][3], short Rows, short Cols, int Number)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			if (arr[i][j] == Number)
				return true;
		}
	}
	return false;
}

void PrintIsTheNumberOnMatrix(int arr[3][3], int arr2[3][3], short Rows, short Cols)
{
	int Test = 0;
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			Test = arr[i][j];
			if (IsTheNumberOnMatrix(arr2, 3, 3, Test))
				cout << Test << "\t";
		}
	}

}

int MinNumberOnMatrix(int arr[3][3], short Rows, short Cols)
{
	int MinNumber = arr[0][0];
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			if (arr[i][j] < MinNumber)
				MinNumber = arr[i][j];
		}
	}
	return MinNumber;
}

int MaxNumberOnMatrix(int arr[3][3], short Rows, short Cols)
{
	int MaxNumber = arr[0][0];
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			if (arr[i][j] > MaxNumber)
				MaxNumber = arr[i][j];
		}
	}
	return MaxNumber;
}

bool PalindromeMatrix(int arr[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols / 2; j++)
		{
			if (arr[i][j] != arr[i][Cols - (j + 1)])
				return false;
		}
	}
	return true;
}

void PrintFibonacciUsingRecurssion(short Number, int Prev1, int Prev2)
{
	int FebNumber = 0;
	if (Number > 0)
	{
		FebNumber = Prev2 + Prev1;
		Prev2 = Prev1;
		Prev1 = FebNumber;
		cout << FebNumber << " ";
		PrintFibonacciUsingRecurssion(Number - 1, Prev1, Prev2);
	}
}

int SumTwoNumbers(int Number1, int Number2)
{
	return (Number1 + Number2);
}

void ConvertFirstLetterFromEachWordCapital(string st)
{
	bool isFirstLetter = true;

	for (int i = 0; i <= st.length(); i++)
	{
		if (st[i] != ' ' && isFirstLetter)
		{
			st[i] = toupper(st[i]);
		}
		isFirstLetter = st[i] == ' ' ? true : false;
	}
	cout << st;
}

int ReadValidetNumber(int From, int To, string Messege)
{
	int Number = 0;
	do
	{
		cout << endl << Messege << endl;
		cin >> Number;
	} while (Number<From || Number>To);

	return Number;
}

string UpperAllString(string Sentence)
{
	for (int i = 0; i < Sentence.length(); i++)
	{
		if (islower(Sentence[i]))
			Sentence[i] = toupper(Sentence[i]);
	}
	return Sentence;
}

string LowerAllString(string Sentence)
{
	for (int i = 0; i < Sentence.length(); i++)
	{
		if (isupper(Sentence[i]))
			Sentence[i] = tolower(Sentence[i]);
	}
	return Sentence;
}

vector <int> veFibonacci(int  FiboNumber)
{
	int Counter = 1;
	vector <int> VeFibo;

	VeFibo.push_back(1);
	VeFibo.push_back(1);

	while (VeFibo.size() < FiboNumber)
	{
		VeFibo.push_back(SumTwoNumbers(VeFibo.at(Counter - 1), VeFibo.at(Counter)));
		Counter++;
	}
	return VeFibo;
}

char ReadChar(string Messege)
{
	cout << Messege;
	char ch;
	cin >> ch;
	return ch;
}

char InvertCharacterCase(char Letter)
{
	return isupper(Letter) ? tolower(Letter) : toupper(Letter);
}

string InvertSentenceCase(string St)
{
	for (int i = 0; i < St.length(); i++)
	{
		St[i] = InvertCharacterCase(St[i]);
	}
	return St;
}

int CountUpperLetters(string st)
{
	int Counter = 0;
	for (int i = 0; i < st.length(); i++)
	{
		if (isupper(st[i]))
			Counter++;
	}
	return Counter;
}

int CountLowerLetters(string st)
{
	int Counter = 0;
	for (int i = 0; i < st.length(); i++)
	{
		if (islower(st[i]))
			Counter++;
	}
	return Counter;
}

int CountCharacterAtString(string St, char CharTest, bool MatchCase = true)
{
	short Counter = 0;
	for (int i = 0; i < St.length(); i++)
	{
		if (MatchCase)
		{
			if (St[i] == CharTest)
				Counter++;
		}
		else
		{
			if (toupper(St[i]) == toupper(CharTest))
				Counter++;
		}

	}
	return Counter;
}

bool IsVoilLetter(char Letter)
{
	Letter = tolower(Letter);
	return (Letter == 'a') || (Letter == 'i') || (Letter == 'e') || (Letter == 'o') || (Letter == 'u');
}

short CountVowelLetterAtString(string st)
{
	short counter = 0;
	for (short i = 0; i < st.length(); i++)
	{
		if (IsVoilLetter(st[i]))
			counter++;
	}
	return counter;
}

void PrintVowelLetter(string st)
{
	cout << "\nVowel letters are: ";
	for (int i = 0; i < st.length(); i++)
	{
		if (IsVoilLetter(st[i]))
			cout << st[i] << "   ";
	}
}

void PrintEachWordInString(string S1)
{
	string delim = " "; // delimiter 
	cout << "\nYour string words are: \n\n";
	short pos = 0;
	string sWord; // define a string variable 
	// use find() function to get the position of the delimiters 
	while ((pos = S1.find(delim)) != std::string::npos)
	{
		sWord = S1.substr(0, pos); // store the word 
		if (sWord != "")
		{
			cout << sWord << endl;
		}
		S1.erase(0, pos + delim.length()); /* erase() until
	   positon and move to next word. */
	}
	if (S1 != "")
	{
		cout << S1 << endl; // it print last word of the string.
	}
}

vector<string> SplitString(string S1, string Delim)
{
	vector<string> vString;
	short pos = 0;
	string sWord; // define a string variable 
	// use find() function to get the position of the delimiters 
	while ((pos = S1.find(Delim)) != std::string::npos)
	{
		sWord = S1.substr(0, pos); // store the word 
		if (sWord != "")
		{
			vString.push_back(sWord);
		}
		S1.erase(0, pos + Delim.length()); /* erase() until
	   positon and move to next word. */
	}
	if (S1 != "")
	{
		vString.push_back(S1); // it adds last word of the string.
	}
	return vString;
}

int CountEachWordOnString(string St)
{
	string Dimi = " ", sWord;
	int counter = 0, pos = 0;

	while ((pos = St.find(Dimi)) != std::string::npos)
	{
		sWord = St.substr(0, pos);
		if (sWord != "")
		{
			counter++;
		}
		St.erase(0, pos + Dimi.length());
	}
	return ++counter;
}

string TrimLeft(string S1)
{
	for (short i = 0; i < S1.length(); i++)
	{
		if (S1[i] != ' ')
		{
			return S1.substr(i, S1.length() - 1);
		}
	}
	return "";
}

string TrimRight(string S1)
{
	for (short i = S1.length() - 1; i >= 0; i--)
	{
		if (S1[i] != ' ')
		{
			return S1.substr(0, i + 1);
		}
	}
	return "";
}

string Trim(string S1)
{
	return (TrimLeft(TrimRight(S1)));
}

string JoinString(vector <string> VectorWords, string Dimi)
{
	string NewString = "";
	for (string& Word : VectorWords)
	{
		NewString += Word + Dimi;
	}
	return NewString.substr(0, NewString.length() - Dimi.length());
}

string JoinString(string WordArray[10], int Length, string Dimi)
{
	string NewString = "";
	for (int i = 0; i < Length; i++)
	{
		NewString += WordArray[i] + Dimi;
	}
	return NewString.substr(0, NewString.length() - Dimi.length());
}

string ReplaceString(string Sentence, string WordforReplace, string NewWord)
{
	int Pos = 0;

	Pos = Sentence.find(WordforReplace);

	while (Pos != std::string::npos)
	{
		Sentence.replace(Pos, WordforReplace.length(), NewWord);
		Pos = Sentence.find(WordforReplace);
	}

	return	Sentence;
}

string ReplaceWordInStringUsingSplit(string S1, string StringToReplace, string sRepalceTo, bool MatchCase = true)
{
	vector<string> vString = SplitString(S1, " ");
	for (string& s : vString)
	{
		if (MatchCase)
		{
			if (s == StringToReplace)
			{
				s = sRepalceTo;
			}
		}
		else
		{
			if (LowerAllString(s) == LowerAllString(StringToReplace))
			{
				s = sRepalceTo;
			}
		}
	}
	return JoinString(vString, " ");
}

string RemovePunctuations(string Sentence)
{
	string NewString = "";
	int Pos = 0, Counter = 0;

	for (int i = 0; i < Sentence.length(); i++)
	{
		if (!ispunct(Sentence[i]))
		{
			NewString += Sentence[i];
		}
	}
	return NewString;
}

const string ClientsFileName = "Clients.txt";

struct sClient
{
	string AccountNumber = "";
	string PinCode = "";
	string Name = "";
	string Phone = "";
	double AccountBalance = 0.0;
	bool MarkForDelete = false;	
};

vector <string> SplitString(string S1, string Delim)
{
	vector<string> vString;
	short pos = 0;
	string sWord; // define a string variable 
	// use find() function to get the position of the delimiters 
	while ((pos = S1.find(Delim)) != std::string::npos)
	{
		sWord = S1.substr(0, pos); // store the word 
		if (sWord != "")
		{
			vString.push_back(sWord);
		}
		S1.erase(0, pos + Delim.length());
	}
	if (S1 != "")
	{
		vString.push_back(S1); // it adds last word of the string.
	}
	return vString;
}

string ConvertRecordToLine(sClient Record, string Seperator = "#//#")
{
	string Line = "";
	Line = Record.AccountNumber + Seperator + Record.PinCode + Seperator +
		Record.Name + Seperator + Record.Phone + Seperator +
		to_string(Record.AccountBalance);

	return Line;
}

sClient ConvertLinetoRecord(string Line, string Seperator = "#//#")
{
	sClient Client;
	vector<string> vClientData;
	vClientData = SplitString(Line, Seperator);
	Client.AccountNumber = vClientData[0];
	Client.PinCode = vClientData[1];
	Client.Name = vClientData[2];
	Client.Phone = vClientData[3];
	Client.AccountBalance = stod(vClientData[4]);//cast string to double

	return Client;
}

sClient ReadNewClient()
{
	sClient Client;
	cout << "Enter Account Number? ";
	getline(cin >> ws, Client.AccountNumber);
	cout << "Enter PinCode? ";
	getline(cin, Client.PinCode);
	cout << "Enter Name? ";
	getline(cin, Client.Name);
	cout << "Enter Phone? ";
	getline(cin, Client.Phone);
	cout << "Enter AccountBalance? ";
	cin >> Client.AccountBalance;
	return Client;
}

void PrintClientCard(sClient Client)
{
	cout << "Clinet Data: \n";
	cout << "Account Number: " << Client.AccountNumber << endl
		<< "Name:           " << Client.Name << endl
		<< "Pin Code:       " << Client.PinCode << endl
		<< "Phone Number:   " << Client.Phone << endl
		<< "Balance:        " << Client.AccountBalance << endl;

}

void LoadClientToFile(string FileName, string ClientLine)
{
	fstream MyFile;
	MyFile.open(FileName, ios::out | ios::app);

	if (MyFile.is_open())
	{
		MyFile << ClientLine << endl;
		MyFile.close();
	}
}

void AddNewClient()
{
	sClient Client;
	Client = ReadNewClient();
	LoadClientToFile(ClientsFileName, ConvertRecordToLine(Client));
}

void AddClients()
{
	char AddMore = 'y';

	do
	{
		system("cls");
		cout << "Add Client\n";
		AddNewClient();
		cout << "Client Add Secsesfully, Do you want to add more client (Y / N )\n";
		cin >> AddMore;

	} while (toupper(AddMore) == 'Y');
}

vector <sClient> LoadCleintsDataFromFile(string FileName)
{
	vector <sClient> vClients;
	fstream MyFile;
	MyFile.open(FileName, ios::in);//read Mode
	if (MyFile.is_open())
	{
		string Line;
		sClient Client;
		while (getline(MyFile, Line))
		{
			Client = ConvertLinetoRecord(Line);
			vClients.push_back(Client);
		}
		MyFile.close();
	}
	return vClients;
}

void PrintClientRecord(sClient Client)
{
	cout << "| " << setw(15) << left << Client.AccountNumber;
	cout << "| " << setw(10) << left << Client.PinCode;
	cout << "| " << setw(40) << left << Client.Name;
	cout << "| " << setw(12) << left << Client.Phone;
	cout << "| " << setw(12) << left << Client.AccountBalance;
}

void PrintAllClientsData(vector <sClient> vClients)
{
	cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
	cout <<
		"\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;
	cout << "| " << left << setw(15) << "Accout Number";
	cout << "| " << left << setw(10) << "Pin Code";
	cout << "| " << left << setw(40) << "Client Name";
	cout << "| " << left << setw(12) << "Phone";
	cout << "| " << left << setw(12) << "Balance";
	cout <<
		"\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;
	for (sClient Client : vClients)
	{
		PrintClientRecord(Client);
		cout << endl;
	}
	cout <<
		"\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;
}

void SearchNumberAccount(vector <sClient> Vclients, string AccountNumber)
{
	for (sClient Client : Vclients)
	{
		if (Client.AccountNumber == AccountNumber)
		{
			cout << "Yes it's there" << endl;
			PrintClientRecord(Client);
			cout << endl;
		}
	}
	cout << "No, it's not found";
}

bool FindClientByAccountNumber(string AccountNumber, vector <sClient> Vclients, sClient& Client)
{

	for (sClient C : Vclients)
	{
		if (C.AccountNumber == UpperAllString(AccountNumber))
		{
			Client = C;
			return true;
		}
	}
	return false;
}

bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector <sClient>& Vclients)
{
	for (sClient& C : Vclients)
	{
		if (C.AccountNumber == AccountNumber)
		{
			C.MarkForDelete = true;
			return true;
		}
	}
	return false;
}

vector <sClient> SaveClientsDataToFile(string filename, vector <sClient> Vclients)
{
	fstream MyFile;
	MyFile.open(filename, ios::out);

	if (MyFile.is_open())
	{
		string DataLine;
		for (sClient C : Vclients)
		{
			if (C.MarkForDelete == false)
			{
				DataLine = ConvertRecordToLine(C);
				MyFile << DataLine << endl;
			}
		}
		MyFile.close();
	}
	return Vclients;
}

bool DeleteClientByAccountNumber(string AccountNumber, vector <sClient>& Vclients)
{
	char YesOrNo = 'Y';
	sClient Client;
	if (FindClientByAccountNumber(AccountNumber, Vclients, Client))
	{
		PrintClientCard(Client);
		cout << "Do you want to delete " << AccountNumber << " Client (Y / N)\n";
		cin >> YesOrNo;

		if (toupper(YesOrNo) == 'Y')
		{
			MarkClientForDeleteByAccountNumber(AccountNumber, Vclients);
			SaveClientsDataToFile(ClientsFileName, Vclients);

			Vclients = LoadCleintsDataFromFile(ClientsFileName);
			cout << "\n\nClient Deleted Successfully.";
			return true;
		}
	}
	else
	{
		return false;
	}



}