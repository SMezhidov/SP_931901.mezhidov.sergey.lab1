#include <iostream>
#include <string>

using namespace std;

int	Add(int a, int b); 
int	Sub(int a, int b);
int	Mul(int a, int b);
int	Div(int a, int b);
int Com(int a, int b);
int Not(int a);
int And(int a, int b);
int Or(int a, int b);
int Xor(int a, int b);

int main()
{
	setlocale(LC_ALL, "Russian");
	while (true)
	{
		cout << "Выберите операцию:" << endl;
		cout << "\t1 - Сложение\n\t2 - Вычитание\n\t3 - Умножение\n\t4 - Деление\n\t5 - Сравнение\n\t6 - Логическая операция not\
\n\t7 - Логическая операция and\n\t8 - Логическая операция or\n\t9 - Логическая операция xor" << endl;

		int menu;
		int a;
		int b;
		int c;

		cin >> menu;
		switch (menu)
		{
		case 1:
			system("cls");
			cout << "Вы выбрали операцию сложения!\n\n";
			cout << "Введите a: ";
			cin >> a;
			cout << "Введите b: ";
			cin >> b;
			c = Add(a, b);
			cout << a << "+" << b << "=" << c << endl;
			break;
		case 2:
			system("cls");
			cout << "Вы выбрали операцию вычитания!\n\n";
			cout << "Введите a: ";
			cin >> a;
			cout << "Введите b: ";
			cin >> b;
			c = Sub(a, b);
			cout << a << "-" << b << "=" << c << endl;
			break;
		case 3:
			system("cls");
			cout << "Вы выбрали операцию умножения!\n\n";
			cout << "Введите a: ";
			cin >> a;
			cout << "Введите b: ";
			cin >> b;
			c = Mul(a, b);
			cout << a << "*" << b << "=" << c << endl;
			break;
		case 4:
			system("cls");
			cout << "Вы выбрали операцию деления!\n\n";
			cout << "Введите a: ";
			cin >> a;
			cout << "Введите b: ";
			cin >> b;
			c = Div(a, b);
			cout << a << "/" << b << "=" << c << endl;
			break;
		case 5:
			system("cls");
			cout << "Вы выбрали операцию сравнения!\n\n";
			cout << "Введите a: ";
			cin >> a;
			cout << "Введите b: ";
			cin >> b;
			c = Com(a, b);
			switch (Com(a,b))
			{
				case 0:
					cout << a << ">" << b << endl;
					break;
				case 1:
					cout << a << "<" << b << endl;
					break;
				case 2:
					cout << a << "=" << b << endl;
					break;
			}
			
			break;
		case 6:
			system("cls");
			cout << "Вы выбрали логическую операцию not!\n\n";
			cout << "Введите a: ";
			cin >> a;
			c = Not(a);
			cout << c << endl;
			break;
		case 7:
			system("cls");
			cout << "Вы выбрали логическую операцию and!\n\n";
			cout << "Введите a: ";
			cin >> a;
			cout << "Введите b: ";
			cin >> b;
			c = And(a, b);
			cout << c << endl;
			break;
		case 8:
			system("cls");
			cout << "Вы выбрали логическую операцию or!\n\n";
			cout << "Введите a: ";
			cin >> a;
			cout << "Введите b: ";
			cin >> b;
			c = Or(a, b);
			cout << c << endl;
			break;
		case 9:
			system("cls");
			cout << "Вы выбрали логическую операцию xor!\n\n";
			cout << "Введите a: ";
			cin >> a;
			cout << "Введите b: ";
			cin >> b;
			c = Xor(a, b);
			cout << c << endl;
			break;
		default:
			cout << "Вы не выбрали операцию!\n";
			break;

		}
	}
	

	system("pause");
	return 0;
}

int Add(int a, int b)
{	
	__asm
	{
		mov eax, a
		mov ebx, b
		add eax, ebx
		mov a, eax
	}
	return a;
}

int Sub(int a, int b)
{
	__asm
	{
		mov eax, a
		mov ebx, b
		sub eax, ebx
		mov a, eax
	}
	return a;
}

int Mul(int a, int b)
{
	__asm
	{
		mov eax, a
		mov ebx, b
		mul ebx
		mov a, eax
	}
	return a;
}

int Div(int a, int b)
{
	__asm
	{
		mov eax, a
		mov ecx, b
		sub edx, edx
		div ecx
		mov a, eax
	}
	return a;
}

int Com(int a, int b)
{
	int res, result;
	result = -1;

	res = Sub(a, b);
	if (res > 0)
	{
		result = 0;
	}
	else if (res < 0)
	{
		result = 1;
	}
	else
	{
		result = 2;
	}
	return result;
}

int Not(int a)
{
	__asm
	{
		mov eax, a;
		not eax;
		mov a, eax;
	}
	return a;
}

int And(int a, int b)
{
	__asm
	{
		mov eax, a;
		mov ebx, b;
		and ebx, eax;
		mov a, ebx;
	}
	return a;
}

int Or(int a, int b)
{
	__asm
	{
		mov ebx, a;
		mov eax, b;
		or ebx, eax;
		mov a, ebx;
	}
	return a;
}

int Xor(int a, int b)
{
	__asm
	{
		mov ebx, a;
		mov eax, b;
		xor ebx, eax;
		mov a, ebx;
	}
	return a;
}