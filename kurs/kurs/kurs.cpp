#include "pch.h"
#include <string>
#include <fstream>
#include <iostream>
#include <Windows.h>

using namespace std;

class Dictionary
{
public:
	string KeyW, ValueW;

	friend ostream& operator<<(ostream& out, Dictionary& w)
	{
		out << w.KeyW << " " << w.ValueW;
		return out;
	}

	friend istream& operator>>(istream& in, Dictionary& w)
	{
		in >> w.KeyW >> w.ValueW;
		return in;
	}

};

template<class Key, class Value>
class MyMap
{
private:
	struct pair
	{
		Key key;
		Value value;
	};

	int size;
	int length;

	pair* pairs;

public:
	MyMap() : size(1), length(0)
	{
		pairs = new pair[size];
	}

	~MyMap()
	{
		delete[] pairs;
	}

	bool un(Key key)
	{
		for (int i = 0; i < length; i++)
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
		if (un(key))
		{
			if (length == size)
			{
				pair* old = pairs;
				pairs = new pair[size * 2];
				memcpy(pairs, old, sizeof(pair) * size);
				size *= 2;
				delete old;
			}
		}

		pair temp;
		temp.key = key;
		temp.value = value;
		pairs[length++] = temp;
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

	Value& operator[](Key key)
	{
		for (int i = 0; i < length; i++)
		{
			if (pairs[i].key == key)
			{
				return pairs[i].value;
			}
		}
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

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	MyMap<string, string> dictionary;

	dictionary.download();

	cout << "Выберите режим работы словаря:\n" << "1. Англо-Русский.\n" << "2. Русско-Английский.\n" << "3. Ввод слов.\n";
	int c;
	cin >> c;

	switch (c)
	{
	case 1:
		break;

	case 2:
		break;

	case 3: cin >> dictionary;
		break;

	default: cout << "error\n";
	}

	dictionary.save();

	system("pause");
	return 0;
}