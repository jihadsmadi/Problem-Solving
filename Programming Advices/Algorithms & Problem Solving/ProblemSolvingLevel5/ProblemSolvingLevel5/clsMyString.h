#pragma once
#include <iostream>

using namespace std;
#include "clsMyStack.h"

class clsMyString : protected clsMyStack<string>
{
private:
	string _value="";

	clsMyStack <string> _HistoryStack;
	
	clsMyStack <string> _HistoryStack2;
	
	


public:

	void SetValue(string value)
	{
		_value = value;

		_HistoryStack.push(value);
	}

	string GetValue()
	{
		return _HistoryStack.Top();
	}
	__declspec(property(get = GetValue, put = SetValue)) string value;

	void Undo()
	{
		

		_HistoryStack2.push(value);

		_HistoryStack.pop();
	}

	void Redo()
	{
		_HistoryStack.push(_HistoryStack2.Top());

		_HistoryStack2.pop();
	}


};

