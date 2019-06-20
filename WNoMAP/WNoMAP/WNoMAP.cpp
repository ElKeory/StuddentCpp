#include "pch.h"
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <windows.h>

#define elif else if

using namespace std;

void Input_Words(map<string, string>& dictionary);
void Oper_Mode(map<string, string>& dictionary);
void Angl_Dictionary();
void Rus_Dictionary();

template<class T1, class T2>
class MyMap
{
	T1* key;
	T2* value;
	size_t _size;
	size_t _length;

private:
	void resize(size_t new_size) 
	{
		_size = new_size;
		key = static_cast<T1*>(realloc(key, _size * sizeof(T1)));
		value = static_cast<T2*>(realloc(value, _size * sizeof(T2)));
	}
public:
	MyMap()
	{
		_size = 4;
		_leghth = 0;
		key = new T1[_size];
		value = new T2[_size];
	}

	~MyMap()
	{
		delete[] key;
		delete[] value;
	}

	void emplace(const T1 _key, const T2 _value)
	{
		if (_length + 1 > _size) 
			resize(_size * 2);

		if (key_comp)
			key[_length++] = _key;
		else
			cout << "Такое слово уже используется.\n"

		if(value_comp)
			value[_length++] = _value;
		else		
			cout << "Такое слово уже используется.\n"
	}

	template<class T1, class T2>
	bool key_comp(T1 _key) 
	{
		for (int i = 0; i < _size; i++)
		{
			if (key[i] == _key)
				return true;
			else
				return false;
		}
	}

	template<class T1, class T2>
	bool value_comp(T2 _value) 
	{
		for (int i = 0; i < _size; i++)
		{
			if (value[i] == _value)
				return true;
			else
				return false;
		}
	}

	T2 find(T1 _key) 
	{
		for (int i = 0; i < _size; i++)
			if (key[i] == _key)
				return value[i];

		return NULL;
	}

	template <class T1, class T2>
	friend ostream& operator<<(ostream& out, MyMap<T1, T2>& it)
	{
		out.clear();
		for (auto& value : it)
		{
			out << value;
			if (&value < it.end() - 1)
				out << ' ';
		}
		return out;
	}

	template <class T1, class T2>
	friend void operator>>(istream& in, MyMap<T1, T2>& it)
	{
		T2 _value;
		while (in >> _value)
		{
			it.emplace(_value);
			if (in.peek() == '\n')
				break;
		}
	}
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	map<string, string> dictionary; 

	Oper_Mode(dictionary);

	return NULL;
}

void Input_Words(map<string, string>& dictionary)
{
	cout << "Введите пару слов.\n";
	string key, value;
	cin >> key >> value;
	dictionary.emplace(key, value);

	ofstream file("file.txt", ios::app);
	file << key << endl << value << endl;


	ofstream fileA("fileA.txt", ios::app);					
	ofstream fileR("fileR.txt", ios::app);					
	for (int i = 0; i < key.length(); i++)					
	{
		if (key[i] >= 'a' && key[i] <= 'z')
		{
			fileA << key << endl << value << endl;
			fileR << value << endl << key << endl;
			break;
		}
		elif(key[i] >= 'а' && key[i] <= 'я')
		{
			fileA << value << endl << key << endl;
			fileR << key << endl << value << endl;
			break;
		}
	}

	key.clear();
	value.clear();

	bool c = false;
	while (c != true)
	{
		cout << "Перейти к выбору режима словаря или завершить работу?\nВведите 1 или 2.\n";
		int r = NULL; 
		cin >> r;
		switch (r)
		{
		case 1: Oper_Mode(dictionary); 
			break;

		case 2: c = true; exit(0);
			break;

		default: cout << "Выберите подходящий режим.\n";
		}
	}

	fileA.close();
	fileR.close();
	file.close();
}

void Oper_Mode(map<string, string>& dictionary)
{
	cout << "Выберите работу словаря: 1. Англо-Русский, 2. Русско-Английский, 3. Ввод слов в словарь.\n";
	bool c = false;
	while (c != true)
	{
		int r = NULL; 
		cin >> r;
		switch (r)
		{
		case 1: cout << "Режим Англо-Русского словаря.\n";
			Angl_Dictionary();
			break;

		case 2: cout << "Режим Русско-Английского словаря.\n";
			Rus_Dictionary();
			break;

		case 3: cout << "Режим ввода слов в словарь.\n";
			Input_Words(dictionary);
			break;

		default: cout << "Выберите подходящий режим.\n";
			c = true; 
		}
	}
}

void Angl_Dictionary()
{
	ifstream fileA("fileA.txt");
	map<string, string> D_Eng;
	if (!fileA.is_open())
	{
		cout << "Файл с Англо-Русским словарём не найден.\n";
		exit(0);
	}
	else
	{
		cout << "Введите слово на английском.\n";
		string w1;
		cin >> w1;

		auto it = D_Eng.find(w1);
		cout << w1 << " " << it->second << endl;
	}
}

void Rus_Dictionary()
{
	ifstream fileR("fileR.txt");
	map<string, string> D_Rus;
	if (!fileR.is_open())
	{
		cout << "Файл с Русско-Английским словарём не найден.\n";
		exit(0);
	}
	else
	{
		cout << "Введите слово на русском.\n";
		string w1;
		cin >> w1;

		auto it = D_Rus.find(w1);
		cout << w1 << " " << it->second << endl;
	}
}