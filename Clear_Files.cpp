#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "ru");
	
	int d = 0;
	do
	{
		int value;
		cout << "Введите 1 для выполнения чтения файла." << endl;
		cout << "Введите 2 для записи в файл." << endl;
		cout << "Введите любой другой символ для выхода из программы." << endl;
		cin >> value;
			
		if (value == 1)
		{
			ifstream fin;
			fin.open("3.1.txt");
				
			if (!fin.is_open())
			cout << "Ошибка открытия файла." << endl;
			else
			{	
				cout << "Содержимое файла:" << endl;
				char ch;
				while (fin.get(ch))
				cout << ch;
			}
			
			fin.close();
					
			cout << "\n";
		}
			
		if (value == 2)
		{
			ofstream fout;
			fout.open("3.1.txt", ofstream::app);
			
			if (!fout.is_open())
			cout << "Ошибка открытия файла." << endl;
			else
			{
				cout << "Введите название города:" << endl;
				string n;
				cin >> n;
				fout << "\n";
				fout << n;
				int l = n.length();
				if (l <= 7)
				fout << "\t";
				string a;
				for (int i = 2005; i < 2010; i++)
				{
					cout << "Данные на " << i<< " год:" << endl;
					cin >> a;
					fout << "\t";
					fout << a;
				}
			}
			fout.close();
				
			cout << "\n";
		}
		
		if (value != 1 && value != 2)
		{
		break;
		}
			
		cout << "Продолжаем работу с программой?\n1 - Да.\nЛюбая другая клавиша - Нет." << endl;
		cin >> d;
		if (d != 1)
		d = 0;
	}
	while(d);
	
	system("pause");
	return 0;
}