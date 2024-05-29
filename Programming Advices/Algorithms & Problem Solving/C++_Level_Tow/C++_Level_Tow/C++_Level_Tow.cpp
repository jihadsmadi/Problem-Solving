#pragma warning(disable : 4996)
#include <iostream>
#include <string.h>
#include "MyInputsLib.h"
#include <math.h>
#include <iomanip>
#include <vector>
#include <string>
#include <cctype>
#include <fstream>
#include <ctime>

using namespace std;


void SaveVectorToFile(string FilePath, vector <string> VMyFile)
{
	fstream MyFile;
	MyFile.open(FilePath, ios::out);

	if (MyFile.is_open())
	{
		for (string& line : VMyFile)
		{
			if (line != "")
			{
				MyFile << line << endl;
			}
		}

	}
	MyFile.close();
}

void LoadDataFromFileToVictor(string FilePath, vector <string>& VMyFile)
{
	fstream MyFile;
	MyFile.open(FilePath, ios::in);
	if (MyFile.is_open())
	{
		string line;
		while (getline(MyFile, line))
		{
			VMyFile.push_back(line);
		}
	}
	MyFile.close();
}

void PrintFileContent(string FileName) 
{
	fstream MyFile;
	MyFile.open(FileName, ios::in);

	if (MyFile.is_open()) 
	{
		string Line;
		while (getline(MyFile,Line))
		{
			cout << Line << endl;
		}
	}
	MyFile.close();
}

void DeleteRecord(string FilePath, string Record)
{
	vector <string> VMyFile;
	LoadDataFromFileToVictor(FilePath, VMyFile);

	for (string& Line : VMyFile)
	{
		if (Line == Record)
		{
			Line = "";
		}

	}
	SaveVectorToFile(FilePath, VMyFile);
}

int main()
{
	time_t t = time(0);
	char* dt = ctime(&t);
	cout << dt << endl;

	tm* gmtm = gmtime(&t);
	dt = asctime(gmtm);
	cout << dt << endl;
	
	return 0;
}


	




