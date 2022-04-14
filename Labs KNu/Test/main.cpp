#include <iostream>
#include <string>
#include <fstream>
using namespace std;

bool show_history(fstream& history)
{
	string dane;
	while (!history.eof())
	{
		getline(history, dane);
		cout << dane << endl;
	}
	history.seekg(0, ios_base::beg);
	return true;
}
bool show_file(fstream& file)
{
	string dane;
	file.seekg(0, ios_base::beg);
	while (!file.eof())
	{
		getline(file, dane);
		int length = dane.length();

		for (int n=2;n<length;n++)
		{

			if (dane[n - 2] == '*' && dane[n - 1] == '*' && dane[n] == '*' )
			{
				for (int m = n+1;m < length;m++)
				{
					cout << dane[m];
				}
				cout << endl;
				continue;
			}
		}
	}

	return true;
}
bool add_file(fstream& file, fstream& in, fstream& history, string name)
{
	file.seekp(0, ios_base::end);
	history.seekp(0, ios_base::end);
	char bufor[1024];
	int a = 0;
	file <<endl<< "***" << name << endl;
	string dane;
	while (!in.eof())
	{
		for (int n = 0;n < 1024;n++)
		{
			bufor[n] = -1;
		}

		in.read(bufor, 1024);
		for (int n = 2;n < 1026;n++)
		{
			file << bufor[n - 2];
			if (bufor[n-1] == -1 && bufor[n] == -1)
			{
				break;
			}
		}
	}
	in.flush();
	history << "Dodanie pliku: " << name << endl;
	return true;
}
bool add_commit(fstream& history, string commit)
{
	history << commit << endl;
	return true;
}
int main()
{
	string s_in;
	fstream in;
	string commit;;
	cout << "Podaj plik projektu" << endl;
	fstream file;//otwarcie pliku projektu
	string n, m;
	cin >> n;
	file.open(n, ios::in | ios::out);
	if (!file)
	{
		cout << "Cannot open file: " << n << "\n";
		return EXIT_FAILURE;
	}
	cout << "Podaj plik histori" << endl;
	cin >> m;
	fstream history;
	history.open(m, ios::in | ios::out);
	if (!history)
	{
		cout << "Cannot open file: " <<m << endl;
		return EXIT_FAILURE;
	}
	int a = 0;
	while (a == 0)
	{
		cout << "Co chcesz zrobic?" << endl;
		cout << "0. Pokaz pliki" << endl;
		cout << "1. Dodaj pliki" << endl;
		cout << "2. Pokaz historie" << endl;
		cout << "3. Usun projekt" << endl;
		cout << "4. Dodaj komentarz do histori" << endl;
		cout << "5. Zamknij" << endl;
		int x;
		cin >> x;
		if (x == 0)
		{
			system("cls");
			show_file(file);
			cout << endl;
		}
		else if (x == 1)
		{
			cout << "podaj sciezke do pliku ktory chcesz dodac" << endl;
			string s_in;
			cin >> s_in;
			cout << "podaj nazwe pliku" << endl;
			string name;
			cin >> name;
			in.open(s_in, ios::in | ios::out);
			if (!in)
			{
				cout << "Cannot open file: " << s_in << "\n";
				return EXIT_FAILURE;
			}
			add_file(file, in, history, name);
			in.close();
		}
		else if (x == 2)
		{
			system("cls");
			show_history(history);
			cout << endl;
		}
		else if (x == 3)
		{
			system("cls");
			cout << "Skasowano Projekt" << endl;
			file.close();
			history.close();
			history.open(n, ios::out | ios::trunc);
			file.open(m, ios::out | ios::trunc);
			file.close();
			history.close();
			return true;
		}
		else if (x == 4)
		{
			system("cls");
			cout << "Dodaj komentarz, nie uzywaj spacji tylko '_'"<<endl;
			cin >> commit;
			add_commit(history, commit);
		}
		else if (x == 5)
		{
			file.close();
			history.close();
			in.close();
			return true;
		}

	}

}
