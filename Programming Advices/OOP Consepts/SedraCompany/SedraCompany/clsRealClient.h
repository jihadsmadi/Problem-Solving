#pragma once
#include "clsPerson.h"


class clsRealClient : public clsPerson
{
private:

	string _ClientId;

public:

	clsRealClient(string ClientId ) : clsPerson(FirstName, LastName, Phone, FatherName, MotherName, IdNumber, DateOfBearth)
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

};

