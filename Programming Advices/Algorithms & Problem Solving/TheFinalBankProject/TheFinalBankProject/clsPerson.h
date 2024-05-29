#pragma once

#include "clsDate.h"
#include <iostream>


using namespace std;

class clsPerson
{
private:
	string _FirstName;
	string _LastName;
	string _FatherName;
	string _MotherName;
	string _Email;
	string _Phone;
	string _IdNumber;

	clsDate _DateOfBearth;



public:

	clsPerson(string FirstName, string LastName, string Email,
		string Phone,string ,string FatherName, string MotherName, string IdNumber, clsDate DateOfBearth)
	{
		_FirstName = FirstName;
		_LastName = LastName;
		_Email = Email;
		_Phone = Phone;
		_FatherName = FatherName;
		_MotherName = MotherName;
		_IdNumber = IdNumber;
		_DateOfBearth = DateOfBearth;
	}

	// First Name
	void SetFirstName(string FirstName)
	{
		_FirstName = FirstName;
	}

	string GetFirstName()
	{
		return _FirstName;
	}
	__declspec(property(get = GetFirstName, put = SetFirstName)) string FirstName;
	// Last Name
	void SetLastName(string LastName)
	{
		_LastName = LastName;
	}

	string GetLastName()
	{
		return _LastName;
	}
	__declspec(property(get = GetLastName, put = SetLastName)) string LastName;

	string FullName()
	{
		return (_FirstName + " " + _FatherName + " " + _LastName);
	}
	// Email
	void SetEmail(string Email)
	{
		_Email = Email;
	}

	string GetEmail()
	{
		return _Email;
	}
	__declspec(property(get = GetEmail, put = SetEmail)) string Email;

	// Phone
	void SetPhone(string Phone)
	{
		_Phone = Phone;
	}

	string GetPhone()
	{
		return _Phone;
	}
	__declspec(property(get = GetPhone, put = SetPhone)) string Phone;

	//Father
	void SetFatherName(string FatherName)
	{
		_FatherName = FatherName;
	}

	string GetFatherName()
	{
		return _FatherName;
	}
	__declspec(property(get = GetFatherName, put = SetFatherName)) string FatherName;

	//Mother
	void SetMotherName(string MotherName)
	{
		_MotherName = MotherName;
	}

	string GetMotherName()
	{
		return _MotherName;
	}
	__declspec(property(get = GetMotherName, put = SetMotherName)) string MotherName;

	//Id
	void SetIdNumber(string IdNumber)
	{
		_IdNumber = IdNumber;
	}

	string GetIdNumber()
	{
		return _IdNumber;
	}
	__declspec(property(get = GetIdNumber, put = SetIdNumber)) string IdNumber;

	//Date of bearth
	void SetDateOfBearth(string DateOfBearth)
	{
		_DateOfBearth = DateOfBearth;
	}

	clsDate GetDateOfBearth()
	{
		return _DateOfBearth;
	}
	__declspec(property(get = GetDateOfBearth, put = SetDateOfBearth)) string DateOfBearth;
	
};

