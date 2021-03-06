// Hash.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <time.h>
using namespace std;
int collision = 0;
size_t n = 0;
long *a = NULL;

void Read() //функция генерации массива случайных чисел
{
	size_t i;
	cout<<"Array size: ";
	cin >> n;

	a = (long*)calloc(n, sizeof(long));

	srand(time(NULL));

	int A = 1;
	int B = 1000;

	for (int i = 0; i < n; i++) {
		a[i] = A + rand() % ((B + 1) - A);
	}
}



class Hash_Table{
private:
	static const int tableSize=701;
	struct item {
		unsigned int key;
		item* next;
	};
	item* HashTable[tableSize];

public:
	Hash_Table()
	{
		for (int i = 0; i < tableSize; i++)
		{
			HashTable[i] = new item;
			HashTable[i]->key = NULL;
			HashTable[i]->next = NULL;
		}

	}
	
	void AddItem(unsigned int key)
	{
		int i = hash(key);
		if (HashTable[i]->key == NULL)
		{
			HashTable[i]->key = key;
		}
		else
		{
			collision++;
			item* Ptr = HashTable[i];
			item* n = new item;
			n->key = key;
			n->next = NULL;
			while (Ptr->next != NULL)
			{
				Ptr = Ptr->next;
			}
			Ptr->next = n;

		}
	}
	int NumberofItemsinInd(int i)
	{
		int count = 0;
		if (HashTable[i]->key == NULL)
		{
			return count;
		}
		else
		{
			count++;
			item* Ptr = HashTable[i];
			while (Ptr->next != NULL)
			{
				count++;
				Ptr = Ptr->next;
			}
		}
		return count;
	}
	void PrintTable()
	{
		int number = 0;
		for (int i = 0; i < tableSize; i++)
		{
			
			cout << "-------------\n"<<endl;
			number = NumberofItemsinInd(i);
			cout << "hash=" << i << endl;
			cout <<"This hash has " <<number <<" items"<<endl;
			PrintItemsWithHash(i);
			cout << "-------------\n" << endl;
			cout << "-------------\n" << endl;
		}
	}
	void PrintItemsWithHash(int i)
	{
		item* Ptr = HashTable[i];
		if (Ptr->key == NULL)
		{
			cout << "That hash empty\n";
		}
		while (Ptr != NULL)
		{
			cout << "-------------\n" << endl;
			//cout << "hash=" << i << endl;
			cout <<"Item: "<< Ptr->key << endl;
			Ptr = Ptr->next;
		 }
	}
	void FindKey(int key)
	{
		int i = hash(key);
		bool foundKey = false;
		item* Ptr = HashTable[i];
		while (Ptr != NULL)
		{
			if (Ptr->key == key)
			{
				foundKey = true;
				cout << "Found with hash " << i << endl;
				break;
			}
			Ptr = Ptr->next;
		}
		if(foundKey==false)
		{
			cout << "NOT FOUND" << endl;
		}
	}
	int hash(unsigned int key)
	{
		return key % 13;
	}
	
};

class Hash_Table2 {
private:
	static const int tableSize = 701;
	struct item {
		unsigned int key;
	};
	item* HashTable[tableSize];

public:
	Hash_Table2()
	{
		for (int i = 0; i < tableSize; i++)
		{
			HashTable[i] = new item;
			HashTable[i]->key = NULL;
		}

	}

	void AddItem(unsigned int key)
	{
		int i = 0;
		while (i != tableSize) 
		{
			int h = hash(key, i);
			if (HashTable[h]->key == NULL) 
			{
				HashTable[h]->key= key;
				break;
			}
			i++;
			collision++;
		}
	}

	void FindKey(int key)
	{
		int i = 0;
		bool foundKey = false;
		while (i != tableSize)
		{
			int h = hash(key, i);
			if (HashTable[h]->key == key)
			{
				cout << "Found with hash " << h << endl;
				foundKey = true;
				break;
			}
			i++;
		}
		if (foundKey == false)
		{
			cout << "NOT FOUND" << endl;
		}
	}
	void PrintTable()
	{
		int number = 0;
		for (int i = 0; i < tableSize; i++)
		{

			cout << "-------------\n" << endl;
			cout << "hash=" << i << endl;
			PrintItemsWithHash(i);
			cout << "-------------\n" << endl;
			
		}
	}
	void PrintItemsWithHash(int i)
	{
		item* Ptr = HashTable[i];
		if (Ptr->key == NULL)
		{
			cout << "That hash empty\n";
		}
		else
		{
			cout << "-------------\n" << endl;
			cout << "Item: " << Ptr->key << endl;
		}
	}
	
	int h1(unsigned int key)
	{
		return key % 701;
	}
	int hash(unsigned int key,int i)
	{
		return (h1(key) + i) % 701;
	}


};

class Hash_Table3 {
private:
	static const int tableSize = 701;
	struct item {
		unsigned int key;
	};
	item* HashTable[tableSize];

public:
	Hash_Table3()
	{
		for (int i = 0; i < tableSize; i++)
		{
			HashTable[i] = new item;
			HashTable[i]->key = NULL;
		}

	}

	void AddItem(unsigned int key)
	{
		int i = 0;
		while (i != tableSize)
		{
			int h = hash(key, i);
			if (HashTable[h]->key == NULL)
			{
				HashTable[h]->key = key;
				break;
			}
			i++;
			collision++;
		}
	}

	void FindKey(int key)
	{
		int i = 0;
		bool foundKey = false;
		while (i != tableSize)
		{
			int h = hash(key, i);
			if (HashTable[h]->key == key)
			{
				cout << "Found with hash " << h << endl;
				foundKey = true;
				break;
			}
			i++;
		}
		if (foundKey == false)
		{
			cout << "NOT FOUND" << endl;
		}
	}
	void PrintTable()
	{
		int number = 0;
		for (int i = 0; i < tableSize; i++)
		{

			cout << "-------------\n" << endl;
			cout << "hash=" << i << endl;
			PrintItemsWithHash(i);
			cout << "-------------\n" << endl;

		}
	}
	void PrintItemsWithHash(int i)
	{
		item* Ptr = HashTable[i];
		if (Ptr->key == NULL)
		{
			cout << "That hash empty\n";
		}
		else
		{
			cout << "-------------\n" << endl;
			cout << "Item: " << Ptr->key << endl;
		}
	}

	int h1(unsigned int key)
	{
		return key % 701;
	}
	int hash(unsigned int key, int i)
	{
		return (h1(key) + 2 * i + 2 * i*i) % 701;
	}
};

class Hash_Table4 {
private:
	static const int tableSize = 701;
	struct item {
		unsigned int key;
	};
	item* HashTable[tableSize];

public:
	Hash_Table4()
	{
		for (int i = 0; i < tableSize; i++)
		{
			HashTable[i] = new item;
			HashTable[i]->key = NULL;
		}

	}

	void AddItem(unsigned int key)
	{
		int i = 0;
		while (i != tableSize)
		{
			int h = hash(key, i);
			if (HashTable[h]->key == NULL)
			{
				HashTable[h]->key = key;
				break;
			}
			i++;
			collision++;
		}
	}

	void FindKey(int key)
	{
		int i = 0;
		bool foundKey = false;
		while (i != tableSize)
		{
			int h = hash(key, i);
			if (HashTable[h]->key == key)
			{
				cout << "Found with hash "<< h << endl;
				foundKey = true;
				break;
			}
			i++;
		}
		if (foundKey == false)
		{
			cout << "NOT FOUND" << endl;
		}
	}
	void PrintTable()
	{
		int number = 0;
		for (int i = 0; i < tableSize; i++)
		{

			cout << "-------------\n" << endl;
			cout << "hash=" << i << endl;
			PrintItemsWithHash(i);
			cout << "-------------\n" << endl;

		}
	}
	void PrintItemsWithHash(int i)
	{
		item* Ptr = HashTable[i];
		if (Ptr->key == NULL)
		{
			cout << "That hash empty\n";
		}
		else
		{
			cout << "-------------\n" << endl;
			cout << "Item: " << Ptr->key << endl;
		}
	}

	int h1(unsigned int key)
	{
		return key % 701;
	}
	int h2(unsigned int key)
	{
		return 1 + key % 700;
	}
	int hash(unsigned int key, int i)
	{
		return (h1(key) + i*h2(key)) % 701;
	}
};



int main()
{
	Hash_Table4 HT;
	Read();
	for (int i = 0; i < n; i++) {
		HT.AddItem(a[i]);
	}
	HT.AddItem(885);
	cout << "The number of collisions: "<<collision <<"\n"<< endl;
	HT.FindKey(885);
}

