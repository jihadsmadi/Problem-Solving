#pragma once
#include "clsPerson.h"
#include "clsDate.h"

class clsRealClient : public clsPerson
{
private:
	bool _MarkForDelete = false;
	string _ClientId;

public:

	clsRealClient()
	{

	}

	clsRealClient(string ClientId,string FirstName,string LastName
		,string Phone,string FatherName,string MotherName,string IdNumber,clsDate DateOfBearth )

		: clsPerson(FirstName, LastName, Phone, FatherName, MotherName, IdNumber, DateOfBearth)
	{
		_ClientId = ClientId;
	}

	void SetClientId(string ClientId)
	{
		_ClientId = ClientId;
	}

	string GetClientId()
	{
		return _ClientId;
	}
	__declspec(property(get = GetClientId, put = SetClientId)) string ClientId;

	void SetMarkForDelete(bool MarkForDelete)
	{
		_MarkForDelete = MarkForDelete;
	}

	bool GetMarkForDelete()
	{
		return _MarkForDelete;
	}
	__declspec(property(get = GetMarkForDelete, put = SetMarkForDelete)) bool MarkForDelete;

	
	




};

