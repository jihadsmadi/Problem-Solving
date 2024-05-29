#pragma once
#include "clsDblLinkedList.h"
using namespace std;

template <class T>
class clsMyQueue
{
protected:

	clsDblLinkedList <T> _MyList;




public:


	void pop()
	{
		_MyList.DeleteFirstNode();
	}

	void Push(T Item)
	{

		_MyList.InsertAtEnd(Item);

	}

	void Print()
	{
		_MyList.PrintList();
	}

	int Size()
	{
		return _MyList.Size();
	}

	T front()
	{
		return _MyList.GetItem(0);
	}

	T back()
	{
		return _MyList.GetItem(_MyList.Size() - 1);
	}

	T GetItem(int index)
	{
		return _MyList.GetItem(index);
	}

	void Reverse()
	{
		_MyList.Reverse();
	}

	void UpdateItem(int index, T newValue)
	{
		_MyList.UpdateItem(index, newValue);
	}

	void InsertAfter(int index, T newValue)
	{
		_MyList.InsertAfter(index, newValue);
	}

	void InsertAtFront(T newValue)
	{
		_MyList.InsertAtBeginning(newValue);
	}

	void InsertAtBack(T newValue)
	{
		_MyList.InsertAtEnd(newValue);
	}

	void Clear()
	{
		_MyList.Clear();
	}






};

