#include<iostream>
using namespace std;

template<typename T>
class List
{
public:
	List();
	~List();

	void pop_font();
	void clear();
	void push_back(T data);
	void push_front(T data);
	void insert(T data, int index);
	void removeAt(int index);
	void pop_back();
	int GetSize() { return Size; }
	T& operator[](const int index);

private:

	template<typename T>
	class Node
	{
	public:
		Node* pNext;
		T data;
		
		Node(T data = T(), Node* pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};

	int Size;
	Node<T> *head;

};

template<typename T>
List<T>::List()
{
	Size = 0;
	head = nullptr;
}
template<typename T>
List<T>::~List()
{
	clear();
}

template<typename T>
void List<T>::pop_font()
{
	Node<T> *temp = head;

	head = head->pNext;

	delete temp;

	Size--;
}

template<typename T>
void List<T>::clear()
{
	while (Size)
	{
		pop_font();
	}
}

template<typename T>
void List<T>::push_back(T data)
{
	if (head == nullptr) {
		head = new Node<T>(data);
	}
	else
	{
		Node<T>* current = this->head;

		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);
	}

	Size++;
}

template<typename T>
void List<T>::push_front(T data)
{
	head = new Node<T>(data, head);
	Size++;
}

template<typename T>
void List<T>::insert(T data, int index)
{

	if (index == 0)
	{
		push_front(data);
	}
	else
	{
		Node<T>* previous = this->head;

		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}

		Node<T>* newNode = new Node<T>(data, previous->pNext);
		previous->pNext = newNode;

		Size++;
	}

}

template<typename T>
void List<T>::removeAt(int index)
{
	if (index == 0)
	{
		pop_font();
	}
	else
	{
		Node<T>* previous = this->head;

		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}

		Node<T>* toDelete = previous->pNext;
		previous->pNext = toDelete->pNext;

		delete toDelete;
		Size--;
	}
}

template<typename T>
void List<T>::pop_back()
{
	removeAt(Size - 1);
}

template<typename T>
T& List<T>::operator[](const int index)
{
	int counter = 0;
	Node<T> *current = this->head;
	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
}

int main()
{

	List<int> fst;
	fst.push_back(5);
	fst.push_back(10);
	fst.push_back(15);
	fst.push_back(20);
	fst.push_back(25);
	fst.push_back(35);

	cout << fst.GetSize() << endl;

	for (int i = 0; i < fst.GetSize(); i++)
	{
		cout << fst[i] << " ";
	}cout << endl;

	fst.pop_font();

	fst.push_front(1);

	fst.insert(99, 3);

	fst.removeAt(5);

	fst.pop_back();

	for (int i = 0; i < fst.GetSize(); i++)
	{
		cout << fst[i] << " ";
	}

}