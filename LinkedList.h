
/*	@file		LinkedList.h
*	@author		Mustafa Yuþa Yenmez, yusayenmez@gmail.com
*	@date		October 6,2021	->	First Release
*/

#pragma once

template<typename T>
class LinkedList {
	
public:

	/*	Constructors and Destructor */
	LinkedList();			//Default Constructor 

	LinkedList(const T&);	//Parameterized Constructor

	~LinkedList();			//Destructor

	/*	Modifiers */
	LinkedList<T>& pushBack(const T&);	//Add a node to the end of list

	LinkedList<T>& pushFront(const T&);	//Add a node to the beginning of list

	LinkedList<T>& deleteBack(void);	//Delete the node at the end of the list

	LinkedList<T>& deleteFront(void);	//Delete the node at the beginning of the list

	LinkedList<T>& erase(const int&);	//Erase the nth element of the list

	LinkedList<T>& sort(void);			//Ascending sort with quick sort

	LinkedList<T>& unique(void);		//Remove duplicate node 

	LinkedList<T>& reverse(void);		//Reverse the list 

	LinkedList<T>& swap(const int&, const int&);	//Swap the two element in the list

	LinkedList<T>& insert(const T& Data, const int& index);	//Insert a node to the list

	void operator=(const LinkedList&);	//Assignmet operator overloading

	bool isEmpty(void)const;

	int size(void)const;	//Show the number of node in the list

protected:

	void quickSort(const int&, const int&);

	T partition(int, int);

	T at(const int&)const;

private:

	struct Node 
	{

		Node():Data(NULL),Next(NULL),Prev(NULL) {}
		
		T Data;
		Node* Next;
		Node* Prev;
	};

	Node* Head;
	Node* Tail;

	int Size;
};

/*
*	@brief	Default Constructor
*/
template <typename T>
LinkedList<T>::LinkedList() : Head(NULL), Tail(NULL), Size(0) {}

/*
*	@brief	Costructor with the first data
*	@param	Data	Initial element of the list 
*/
template <typename T>
LinkedList<T>::LinkedList(const T& Data) : Head(NULL), Tail(NULL), Size(0)
{
	Node* Iter = new Node;

	if (NULL != Iter)
	{
		Iter->Data = Data;
		Iter->Next = NULL;
		Iter->Prev = NULL;
		Head = Iter;
		Tail = Iter;
		Size++;
	}
}

/*
*	@brief	Destructor
*/
template <typename T>
LinkedList<T>::~LinkedList() 
{
	Node* Iter = Head;
	
	while (NULL != Iter) 
	{
		Head = Iter->Next;
		delete Iter;
		Iter = Head;
	}
	
	Size = 0;
	Head = NULL;
	Tail = NULL;
}

/*
*	@brief	Add the given data at the end of the list
*	@param	Data	Given data to add 
*	@return	lValue reference to the current list to support cascades
*/
template <typename T>
LinkedList<T>& LinkedList<T>::pushBack(const  T& Data)
{
	Node* Iter = Tail;
	if (NULL ==Iter )
	{
		Iter = new Node;
		
		if (NULL != Iter)
		{
			Iter->Data = Data;
			Iter->Next = NULL;
			Iter->Prev = NULL;
			Tail = Iter;
			Head = Iter;
			Size++;
		}
	}
	else
	{
		Iter->Next = new Node;
		
		if (NULL != Iter)
		{
			Iter = Iter->Next;
			Iter->Data = Data;
			Iter->Next = NULL;
			Iter->Prev = Tail;
			Tail = Iter;
			Size++;
		}
	}
	return *this;
}

/*
*	@brief	Add the given data at the beginning of the list
*	@param	Data	:Given data to add
*	@return	lValue reference to the current list to support cascades
*/
template <typename T>
LinkedList<T>& LinkedList<T>::pushFront(const T& Data)
{
	if (NULL == Head)
	{
		Node* Iter = new Node;

		if (NULL != Iter)
		{
			Iter->Data = Data;
			Iter->Next = NULL;
			Iter->Prev = NULL;
			Head = Iter;
			Tail = Iter;
			Size++;
		}
	}
	else
	{
		Node* Iter = new Node;

		if (NULL != Iter)
		{
			Iter->Data = Data;
			Iter->Next = Head;
			Iter->Prev = NULL;
			Head->Prev = Iter;
			Head = Iter;
			Size++;
		}
	}

	return *this;
}

/*
*	@brief	Delete the node at the end of the list
*	@return	lValue reference to the current list to support cascades
*/
template <typename T>
LinkedList<T>& LinkedList<T>::deleteBack(void)
{
	if (NULL == Head) {}
	else if (Head == Tail)
	{
		Node* Iter = Head;
		Head = NULL;
		Tail = NULL;
		delete Iter;
		Size--;
	}
	else
	{
		Node* Iter = Tail;
		Tail = Tail->Prev;
		Tail->Next = NULL;
		delete Iter;
		Size--;
	}

	return *this;
}

/*
*	@brief	Delete the node at the beginning of the list
*	@return	lValue reference to the current list to support cascades
*/
template<typename T>
LinkedList<T>& LinkedList<T>::deleteFront(void)
{
	if (NULL == Head) {}
	else if (Head == Tail)
	{
		Node* Iter = Head;
		Head = NULL;
		Tail = NULL;
		delete Iter;
		Size--;
	}
	else
	{
		Node* Iter = Head;
		Head = Head->Next;
		Head->Prev = NULL;
		delete Iter;
		Size--;
	}
	
	return *this;
}


/*
*	@brief	Gives the number of nodes in the list
*	@return	Size	Number of node in the list
*/

template <typename T>
int LinkedList<T>::size(void)const
{
	return Size;
}

/*
*	@brief	Erase the node at the given index
*	@param	idx		:Index of node
*	@return lValue reference to the current list to support cascades
*/
template <typename T>
LinkedList<T>& LinkedList<T>::erase(const int& idx)
{
	Node* Iter = Head;
	if (idx > (this->size() - 1)) {}
	else if (idx == 0 && this->size() == 1)
	{
		Node* Iter = Head;
		Head = NULL;
		Tail = NULL;
		delete Iter;
		Size--;
	}
	else if (idx == 0 && this->size() != 1)
	{
		Node* Iter = Head;
		Head = Head->Next;
		Head->Prev = NULL;
		Iter->Next = NULL;
		delete Iter;
		Size--;
	}
	else if (idx == (this->size() - 1))
	{
		Node* Iter = Tail;
		Tail = Tail->Prev;
		Tail->Next = NULL;
		delete Iter;
		Size--;
	}
	else
	{
		Node* Iter = Head;
		for (int index = 0; index < idx; index++) Iter = Iter->Next;
		Iter->Next->Prev = Iter->Prev;
		Iter->Prev->Next = Iter->Next;
		delete Iter;
		Size--;
	}

	return *this;
}

/*
*	@brief	Check if list empty or not
*	@return true	: if list is empty
*			false	: if list is not empty
*/
template <typename T>
bool LinkedList<T>::isEmpty(void) const
{
	if (this->Head == this->Tail) return true;

	return false;

}

/*
*	@brief	Get an element at given index 
*	@param	idx		:Index of element
*	@return	Value at the given index
*/
template <typename T>
T LinkedList<T>::at(const int& idx)const
{
	if (idx < this->size() && idx >= 0)
	{
		Node* Iter = Head;
		for (int index = 0; index < idx; index++) Iter = Iter->Next;
		return Iter->Data;
	}
	return NULL;
}

/*
*	@brief	Operator= overloading
*/
template <typename T>
void LinkedList<T>::operator=(const LinkedList& List)
{
	for (int idx = 0; idx < List.size(); ++idx)
	{
		this->pushBack(List.at(idx));
	}
}

/*
*	@brief	Swap two elements in the list
*	@param	idx1	:First index to be swap
*			idx2	:Second index to be swap
*	@return	lValue reference to the current list to support cascades	
*/
template <typename T>
LinkedList<T>& LinkedList<T>::swap(const int& idx1, const int& idx2)
{
	Node* Iter1 = Head;
	Node* Iter2 = Head;
	if (idx1 < this->size() && idx2 < this->size() && idx1 >= 0 && idx2 >= 0)
	{
		for (int index = 0; index < idx1; index++) Iter1 = Iter1->Next;
		for (int index = 0; index < idx2; index++) Iter2 = Iter2->Next;
		T temp = Iter1->Data;
		Iter1->Data = Iter2->Data;
		Iter2->Data = temp;
	}

	return *this;
}



/*
*	@brief	Apply Quick Sort to the list
*	@return lValue reference to the current list to support cascades
*/
template <typename T>
LinkedList<T>& LinkedList<T>::sort(void)
{
	this->quickSort(0, this->size() - 1);
	return *this;
}

/*
*	@brief	Remove nodes with data duplicating
*	@return lValue reference to the current list to support cascades
*/
template <typename T>
LinkedList<T>& LinkedList<T>::unique(void)
{
	Node* Iter = Head;

	for (int index1 = 0; index1 <= this->size() - 2; index1++)
	{
		for (int index2 = index1 + 1; index2 <= this->size() - 1; index2++)
		{
			if (this->at(index1) == this->at(index2))
			{
				erase(index2);
				index1--;
				index2--;
			}
		}
	}
	
	return *this;
}

/*
*	@brief	Reverse the list 
*	@node	Instead of reversing list, it swaps head and tail
*	@return lValue reference to the current list to support cascades
*/
template <typename T>
LinkedList<T>& LinkedList<T>::reverse(void)
{
	if (1 < this->size())
	{
		Node* Temp;
		Node* Iter = Head;
		for (int index = 0; index <= this->size() - 1; index++)
		{
			Temp = Iter->Prev;
			Iter->Prev = Iter->Next;
			Iter->Next = Temp;
			Iter = Iter->Prev;
		}
		Temp = Head;
		Head = Tail;
		Tail = Temp;
	}
	
	return *this;
}

/*
*	@brief	Insert a given element to the given index
*	@param	Data	:Element to be inserted
*			index	:Index 
*	@return	lValue reference to the current list to support cascades
*/
template <typename T>
LinkedList<T>& LinkedList<T>::insert(const T& Data, const int& index)
{
	Node* Temp = new Node;
	Node* Iter = Head;

	if (NULL != Temp)
	{
		if (this->size() < index || 0 > index){}
		else if (0 == index)
		{
			this->pushFront(Data);
			Size++;
		}
		else if (this->size() == index)
		{
			this->pushBack(Data);
			Size++;
		}
		else
		{
			for (int idx = 0; idx < index - 1; idx++) Iter = Iter->Next;
			Temp->Data = Data;
			Temp->Prev = Iter;
			Temp->Next = Iter->Next;
			Iter->Next = Temp;
			Iter = Iter->Next->Next;
			Iter->Prev = Temp;
			Size++;
		}
	}
	return *this;
}


template <typename T>
T LinkedList<T>::partition(int low, int high)
{
	int Pivot = this->at(high);
	int i = (low - 1);
	for (int j = low; j <= high - 1; j++)
	{
		if (this->at(j) < Pivot)
		{
			i++;
			this->swap(i, j);
		}
	}
	swap(i + 1, high);
	return (i + 1);

}


template <typename T>
void LinkedList<T>::quickSort(const int& low, const int& high)
{
	if (low < high)
	{
		T pi = partition(low, high);
		quickSort(low, pi - 1);
		quickSort(pi + 1, high);
	}
}
