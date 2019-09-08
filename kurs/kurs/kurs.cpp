#include "pch.h"
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class words
{
public:
	string KeyW, ValueW;

	friend ostream& operator<<(ostream& out, words& w)
	{
		out << w.KeyW << " " << w.ValueW;
		return out;
	}

	friend istream& operator>>(istream& in, words& w)
	{
		in >> w.KeyW << w.ValueW;
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
	MyMap() : size(1), length(0);
	{
		pairs = pair[size];
	}

	~MyMap()
	{
		delete[] pairs;
	}

	bool un(Key key)
	{
		for (int i = 0; i < len; i++)
		{
			if (pairs[i].key == key)
			{
				return true;
			}
		}

		return false;
	}

	void insert(Key key, Value value)
	{
		if (!un(key))
		{
			if (len == size)
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
		pairs[len++] = temp;
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
		for (int i = 0; i < len; i++) 
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

		for (int i = 0; i < len; i++)
		{
			if (i == len - 1)
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
			cout << "Не найдет файл словаря" << endl;
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
	setlocale(2, "Rus");

	MyMap<string, string> dictionary;

	cout << "Выберите режим работы словаря\n" >>
		>> "1" >>
		>> "2" >>
		>> "3" >>
}