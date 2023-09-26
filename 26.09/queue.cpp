#include <iostream>
#include <string.h>
#include <time.h>
using namespace std;

class Queue
{
	// �������
	int* Wait;
	// ������������ ������ �������
	int MaxQueueLength;
	// ������� ������ �������
	int QueueLength;

public:
	// �����������
	Queue(int m);

	//����������
	~Queue();

	// ���������� ��������
	void Add(int c);

	// ���������� ��������
	int Extract();

	// ������� �������
	void Clear();

	// �������� ������������� ��������� � �������
	bool IsEmpty();

	// �������� �� ������������ �������
	bool IsFull();

	// ���������� ��������� � �������
	int GetCount();

	//������������ �������
	void Show();
};

void Queue::Show() {
	cout << "\n-------------------------------------\n";
	//������������ �������
	for (int i = 0; i < QueueLength; i++) {
		cout << Wait[i] << " ";
	}
	cout << "\n-------------------------------------\n";
}

Queue::~Queue()
{
	//�������� �������
	delete[]Wait;
}

Queue::Queue(int m)
{
	//�������� ������
	MaxQueueLength = m;
	//������� �������
	Wait = new int[MaxQueueLength];
	// ���������� ������� �����
	QueueLength = 0;
}

void Queue::Clear()
{
	// ����������� "�������" ������� 
	QueueLength = 0;
}

bool Queue::IsEmpty()
{
	// ����?
	return QueueLength == 0;
}

bool Queue::IsFull()
{
	// �����?
	return QueueLength == MaxQueueLength;
}

int Queue::GetCount()
{
	// ���������� �������������� � ����� ���������
	return QueueLength;
}

void Queue::Add(int c)
{
	// ���� � ������� ���� ��������� �����, �� ����������� ����������
	// �������� � ��������� ����� �������
	if (!IsFull())
		Wait[QueueLength++] = c;
}

int Queue::Extract()
{
	// ���� � ������� ���� ��������, �� ���������� ���, 
	// ������� ����� ������ � �������� �������	
	if (!IsEmpty()) {
		//��������� ������
		int temp = Wait[0];

		//�������� ��� ��������
		for (int i = 1; i < QueueLength; i++)
			Wait[i - 1] = Wait[i];

		//��������� ����������
		//QueueLength--;
		Wait[QueueLength - 1] = temp;

		//������� ������(�������)
		return temp;
		//return 1;
	}

	else // ���� � ����� ��������� ���
		return -1;
}

void main()
{
	srand(time(0));

	//�������� �������
	Queue obj1(25);
	Queue obj2(25);
	Queue obj3(25);

	//���������� ����� ���������
	for (int i = 0; i < 15; i++) {
		obj1.Add(1+rand() % 3);
	}
	for (int i = 0; i < 15; i++) {
		obj2.Add(1+rand() % 3);
	}
	for (int i = 0; i < 15; i++) {
		obj3.Add(1+rand() % 3);
	}
	//����� �������
	char d = ' ';
	int a = 0, b = 0, c = 0;
	do {
		for (size_t i = 0; i < 10; i++)
		{
			obj1.Extract();
		}
		for (size_t i = 0; i < 15; i++)
		{
			obj2.Extract();
		}
		for (size_t i = 0; i < 17; i++)
		{
			obj3.Extract();
		}
		obj1.Show();
		obj2.Show();
		obj3.Show();
		cout << '^';
		a = obj1.Extract();
		b = obj2.Extract();
		c = obj3.Extract();
		cout << endl << a << ' ' << b << ' ' << c << endl;
		if (a == b == c) {
		cout << "You won!\n";
		}
		cout << "Roll?\n(0 to exit)\n";
		cin >> d;
		system("cls");
	} while (d != '0');
	
		
	

	
	
	
}


