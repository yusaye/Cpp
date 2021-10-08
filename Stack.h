/*
 *  @brief  Simple stack application.
 *  @author Mustafa Yusa Yenmez, yusayenmez@gmail.com
 *  @data   October 8, 2021 ->First Release
*/

#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <initializer_list>

template <typename T>
class Stack{
public:

    /* Constructors and Destructor */

    Stack();                        //Default constructor

    Stack(const T&);                //Parameterized Constructor

    Stack(const Stack<T>&);         //Copy constructor

    Stack(std::initializer_list<T>);//Initializer List Constructor

    ~Stack();

    /* Member Functions */

    T top(void)const;               //Returns the data at the top of stack

    Stack<T>& pop(void);            //Remove the node at the top of stack

    Stack<T>& push(const T&);       //Add a node at to the top of stack

    bool isEmpty(void)const;        //Check stack is empty or not

    int size(void)const;            //Number of node in stack

    void print(void);

protected:

    T getNodeData(int );

private:

    struct Node
    {
        Node():next(nullptr) {};

        Node* next;
        T data;
    };

    Node* root;

    Node* temp;

    int stackSize;
};

/*
 *  @brief  Default Constructor
*/
template <typename T>
Stack<T>::Stack(): root(nullptr),temp(nullptr),stackSize(0) {};

/*
 *  @brief  Parameterized Constructor
 *  @param  data    : initial value of first node of stack
*/
template <typename T>
Stack<T>::Stack(const T& data):root(nullptr),temp(nullptr),stackSize(0)
{
    this->push(data);
}

/*
 *  @brief  Copy Constructor
 *  @param  stack   : Another locally created stack to initialize the stack
*/
template<typename T>
Stack<T>::Stack(const Stack& stack):root(nullptr),temp(nullptr),stackSize(0)
{
    for(int idx = 0 ; idx<stack.size();++idx)
    {
        this->push(stack.getNodeData(idx));
    }
}

/*
 *  @brief  Initilializer List Constructor
 *  @param  list    :list of elements of type T
*/
template<typename T>
Stack<T>::Stack(std::initializer_list<T> list) : root(nullptr),temp(nullptr),stackSize(0)
{
    for(const T& elements : list)
    {
        this->push(elements);
    }
    return;
}

/*
 *  @brief  Destructor
*/
template<typename T>
Stack<T>::~Stack()
{
    this->temp = this->root;

    while(nullptr !=this->temp)
    {
        this->root = this->root->next;
        delete this->temp;
        this->temp = this->root;
    }
}

/*
 *  @brief  Get the elements at the top of the stack
*/
template<typename T>
T Stack<T>::top(void)const
{
    return this->root->data;
}

/*
 *  @brief  Adds an node with given data
 *  @param  data    :data for node
 *  @return lValue reference to the current list to support cascades
*/
template<typename T>
Stack<T>& Stack<T>::push(const T& data)
{
    this->temp = new Node();

    if( nullptr != this->temp)
    {
        this->temp->data = data;
        this->temp->next = this->root;
        this->root = this->temp;
        this->stackSize++;
    }

    return *this;
}

/*
 *  @brief  Remove the node at the top of the stack
 *  @return lValue reference to the current list to support cascades
*/
template<typename T>
Stack<T>& Stack<T>::pop(void)
{
    this->temp = this->root;

    if(!this->isEmpty())
    {
        this->root = this->root->next;
        delete this->temp;
        this->stackSize--;
    }
    else
        throw "Stack is empty.";
    return *this;
}

/*
 *  @brief  Check the stack if it is empty or not
 *  @return true    :if stack is empty
 *          false   :if stack is not empty
*/
template<typename T>
bool Stack<T>::isEmpty(void)const
{
    if( nullptr == this->root ) return 1;
    else return false;
}

/*
 *  @brief  Get the size of stack
 *  @return size of stack
*/
template<typename T>
int Stack<T>::size(void)const
{
    return this->stackSize;
}

/*
 *  @brief  Get value of the elements in stack
 *  @param  nodeIndex   :Index of node
 *  @return Value of the elements in the index of nodeIndex
*/
template<typename T>
T Stack<T>::getNodeData(int nodeIndex)
{
    this->temp = this->root;
    for (int idx = 0 ; idx<nodeIndex ; ++idx )
    {
        this->temp = this->temp->next;
    }
    return this->temp->data;
}

template<typename T>
void Stack<T>::print(void)
{
    for(int idx = 0; idx<this->size();++idx)
    {
        std::cout<<this->getNodeData(idx)<<std::endl;
    }
}

#endif // STACK_H
