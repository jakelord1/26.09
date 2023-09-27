#include <iostream>
using namespace std;


struct Element
{
	// ������
	char data;
	// ����� ���������� �������� ������
	Element* Next;
};

// ����������� ������
class List
{
	// ����� ��������� �������� ������
	Element* Head;
	// ����� ��������� �������� ������
	Element* Tail;
	// ���������� ��������� ������
	int Count;

public:
	// �����������
	List();
	// ����������
	~List();
	void DelPos(int i) {
		Element* temp = Head;
		while (i > 2) {
			temp = temp->Next;
			i--;
		}
		Element* del = temp->Next;
		temp = del->Next;
		delete del;
	}



	// ���������� �������� � ������
	void AddPos(char o, int i) {
		Element* temp = Head;
		while (i > 2) {
			temp = temp->Next;
			i--;
		}
		Element* add = temp->Next;
		temp->Next = add;
		add->data = o;
	}
	int Search(char j) {
		Element* temp = Head;
		int c = 0;
		while (temp->data != j) {
			temp = temp->Next;
			c++;
		}
		return c;
	}



	// (����� ������� ���������� ���������)
	void Add(char data);

	// �������� �������� ������
	// (��������� �������� �������)
	void Del();
	// �������� ����� ������
	void DelAll();

	// ���������� ����������� ������
	// (���������� ���������� � ��������� ��������)
	void Print();

	// ��������� ���������� ���������, ����������� � ������
	int GetCount();
};

List::List()
{
	// ���������� ������ ����
	Head = Tail = NULL;
	Count = 0;
}

List::~List()
{
	// ����� ������� ��������
	DelAll();
}

int List::GetCount()
{
	// ���������� ���������� ���������
	return Count;
}

void List::Add(char data)
{
	// �������� ������ ��������
	Element* temp = new Element;

	// ���������� �������
	temp->data = data;
	// ��������� ������� �����������
	temp->Next = NULL;
	// ����� ������� ���������� ��������� ��������� ������
	// ���� �� �� ������ �����������
	if (Head != NULL) {
		Tail->Next = temp;
		Tail = temp;
	}
	// ����� ������� ���������� ������������
	// ���� �� ������ �����������
	else {
		Head = Tail = temp;
	}
}

void List::Del()
{
	// ���������� ����� ��������� ��������
	Element* temp = Head;
	// ������������� ������ �� ��������� �������
	Head = Head->Next;
	// ������� ������ �������� �������
	delete temp;
}

void List::DelAll()
{
	// ���� ��� ���� ��������
	while (Head != 0)
		// ������� �������� �� ������
		Del();
}

void List::Print()
{
	// ���������� ����� ��������� ��������
	Element* temp = Head;
	// ���� ��� ���� ��������
	while (temp != 0)
	{
		// ������� ������
		cout << temp->data << " ";
		// ��������� �� ��������� �������
		temp = temp->Next;
	}

	cout << "\n\n";
}

// �������� ������
void main()
{
	// ������� ������ ������ List
	List lst;

	// �������� ������
	char s[] = "Hello, World !!!\n";
	// ������� ������
	cout << s << "\n\n";
	// ���������� ����� ������
	int len = strlen(s);
	// �������� ������ � ������
	for (int i = 0; i < len; i++)
		lst.Add(s[i]);
	// ������������� ���������� ������
	lst.Print();
	// ������� ��� �������� ������
	lst.Del();
	lst.Del();
	lst.Del();
	//������������� ���������� ������
	lst.Print();
}

