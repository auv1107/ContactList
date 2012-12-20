#ifndef CLASS_HASHTABLE
#define CLASS_HASHTABLE

#include "ContactInfo.h"
#define MAXSIZE 260

template <class T>
class HashTable
{
friend bool t_ContactList();
friend class ContactList;
private:
	T *Array;
	int maxSize;
	int size;
public:
	HashTable(int maxsize=MAXSIZE)
	{
		maxSize = maxsize;
		Array = new T[maxSize];
	}

	~HashTable()
	{
		delete []Array;
	}

	int Size()
	{
		return size;
	}

	int MaxSize()
	{
		return maxSize;
	}

	int expIndexToInsert(int key,string name)
	{
		if(size == maxSize)
		{
			return -1;
		}

		int index = key;
		while(index < maxSize)
		{
			if(Array[index] == NULL)
			{
				return index;
			}
			if(Array[index]->Name() == name)
			{
				return -1;
			}

			index++;
		}

		index = 0;
		while(index < key)
		{
			if(Array[index] == NULL)
			{
				return index;
			}
			if(Array[index]->Name() == name)
			{
				return -1;
			}
			index++;
		}

		return -1;
	}

	int searchName(int key, string name)
	{
		key = key % maxSize;
		if(size == 0)
		{
			return false;
		}
		
		int index = key;
		while(index < maxSize)
		{
			if(Array[index] == NULL)
			{
				return -1;
			}
			if(Array[index]->Name() == name)
			{
				return index;
			}
			index++;
		}

		index = 0;
		while(index < key)
		{
			if(Array[index] == NULL)
			{
				return -1;
			}
			if(Array[index]->Name() == name)
			{
				return index;
			}
			index++;
		}

		return -1;
	}

	bool addContact(T ci)
	{
		int key = ci->Key() % maxSize;
		key = expIndexToInsert(key, ci->Name());
		if(key == -1)
		{
			return false;
		}
		else
		{
			Array[key] = ci;
			size++;
			return true;
		}
	}

};




#endif
