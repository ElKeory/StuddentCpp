#include "pch.h"
#include <string>
#include <fstream>
#include <iostream>
#include <Windows.h>

using namespace std;

template<class Key, class Value>
class MyMap
{
private:
	struct pair
	{
		Key key;
		Value value;

		pair() {}
		pair(const Key& key, const Value& value) :
			key(key), value(value) {}
	};

	int size;
	int length;

	pair* pairs;

public:
	MyMap() : size(4), length(0)
	{
		pairs = new pair[size];
	}

	~MyMap()
	{
		delete[] pairs;
	}

	bool un(Key key)
	{
		for (int i = 0; i < size; i++)
		{
			if (pairs[i].key == key)
			{
				return false;
			}
		}

		return true;
	}

	void insert(Key key, Value value)
	{
		if (!un(key))
			return;
		
		if (length + 1 > size)
		{
			size *= 2;
			pairs = static_cast<pair*>(realloc(pairs, size * sizeof(pair)));				
		}
		
		pairs[length++] = pair(key, value);
	}

	friend ostream& operator<<(ostream& out, MyMap& a)
	{
		for (int i = 0; i < a.length; i++)
		{
			out << a.pairs[i].key << " : " << a.pairs[i].value << endl;
		}

		return out;
	}

	friend istream& operator>>(istream& in, MyMap& a)
	{
		Key key;
		Value value;

		in >> key;
		in >> value;

		a.insert(key, value);

		return in;
	}

	Value operator[](Key key)
	{
		for (int i = 0; i < length; i++)
		{
			if (pairs[i].key == key)
			{
				return pairs[i].value;
			}
		}

		return Value();
	}

	void save()
	{
		ofstream out;
		out.open("Dictionary.txt");

		for (int i = 0; i < length; i++)
		{
			if (i == length - 1)
			{
				out << pairs[i].key << endl << pairs[i].value;
			}
			else
			{
				out << pairs[i].key << endl << pairs[i].value << endl;
			}
		}

		out.close();
	}
	void download()
	{
		bool test = true;

		ifstream in;
		in.open("Dictionary.txt");

		if (!in)
		{
			cout << "Не найден файл словаря" << endl;
		}
		else
		{
			Key key;
			Value value;

			while (!in.eof())
			{
				in >> key;
				in >> value;

				insert(key, value);
			}
		}

		in.close();
	}
};

void choise()
{
	MyMap<string, string> dictionary;

	dictionary.download();

	cout << dictionary;

	string key;

	cout << "Выберите режим работы словаря:\n" << "1. Англо-Русский.\n" << "2. Русско-Английский.\n" << "3. Ввод слов.\n";
	int c;
	cin >> c;

	system("cls");

	switch (c)
	{
	case 1: 
		cout << "Введите слово на английском.\n";
		cin >> key;
		for (int i = 0; i < key.length(); i++)
		{
			if (key[i] > 'a' && key[i] < 'z')
			{
				cout << key << " : " << dictionary[key] << endl;
				break;
			}
			else
			{
				cout << "Слово в словаре не найдено.\n";
				break;
			}
		}

		key.clear();

		system("pause");
		system("cls");

		choise();
		break;

	case 2:
		cout << "Введите слово на русском.\n";
		cin >> key;
		for (int i = 0; i < key.length(); i++)
		{
			if (key[i] > 'а' && key[i] < 'я')
			{
				cout << key << " : " << dictionary[key] << endl;
				break;
			}
			else
			{
				cout << "Слово в словаре не найдено.\n";
				break;
			}
		}

		key.clear();

		system("pause");
		system("cls");

		choise();
		break;
		
	case 3: 
		cout << "Введите пару слов.\n";

		cin >> dictionary;

		dictionary.save();

		system("cls");

		choise();
		break;

	default: 
		cout << "error\n";
	}	
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	choise();

	return 0;
}