#pragma once
#include <iostream>
#include "clsInputValidate.h"
using namespace std;
class clsHouse
{
private:
	string _Number;
	string _BuildingNumber;
	string _Tabek;
	string _Position;

public:

	clsHouse()
	{

	}
	clsHouse(string Number, string BuildingNumber, string Tabek, string Position)
	{
		_Number = Number;
		_BuildingNumber = BuildingNumber;
		_Tabek = Tabek;
		_Position = Position;
	}


	//Number
	void SetNumber(string Number)
	{
		_Number = Number;
	}

	string GetNumber()
	{
		return _Number;
	}
	__declspec(property(get = GetNumber, put = SetNumber)) string Number;

	//Building Number
	void SetBuildingNumber(string BuildingNumber)
	{
		_BuildingNumber = BuildingNumber;
	}

	string GetBuildingNumber()
	{
		return _BuildingNumber;
	}
	__declspec(property(get = GetBuildingNumber, put = SetBuildingNumber)) string BuildingNumber;

	//Tabek
	void SetTabek(string Tabek)
	{
		_Tabek = Tabek;
	}

	string GetTabek()
	{
		return _Tabek;
	}
	__declspec(property(get = GetTabek, put = SetTabek)) string Tabek;

	//position
	void SetPosition(string Position)
	{
		_Position = Position;
	}

	string GetPosition()
	{
		return _Position;
	}
	__declspec(property(get = GetPosition, put = SetPosition)) string Position;

	static clsHouse ReadHouseDeatils()
	{
		clsHouse House;
		cout << "Enter Your House Number: ";
		House.Number = clsInputValidate::ReadString();

		cout << "Enter Your Building Number: ";
		House.BuildingNumber = clsInputValidate::ReadString();

		cout << "Enter Your Tabek: ";
		House.Tabek = clsInputValidate::ReadString();

		cout << "Enter Your Position: ";
		House.Position = clsInputValidate::ReadString();

		return House;
	}

	void PrintInfo()
	{
		cout << "House Number:    " << _Number << "\n";
		cout << "Building Number: " << _BuildingNumber << "\n";
		cout << "Floor:           " << _Tabek << "\n";
		cout << "Position:        " << _Position << endl;
	}

};

