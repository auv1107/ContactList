#ifndef CLASS_CONTACTLIST
#define CLASS_CONTACTLIST

#include <cstring>
#include "ArrayList.h"
#include "HashTable.h"
#include "ContactInfo.h"

using namespace std;

class ContactList
{
friend bool t_ContactList();
private:
	ArrayList<ContactInfo>* contacts;
	HashTable<ContactInfo*> contactsTable;
	int blockInfo[26][2];
public:
	ContactList(int size);
	bool addContact(string name, string phoneNum, string email);
	bool updateContact();
	bool delContact(string name);
	void showList();
	int blockQuery(string name);
	int binarySearch(string name, int start, int end);
	int hashQuery(string name);
	bool showInfo(string name);
};

ContactList::ContactList(int size=DEFAULT_LENGTH)
{
//  线性表初始化
	for(int i=0; i<26; i++)
	{
		blockInfo[i][0]= i*size;
		blockInfo[i][1]= i*size-1;
	}
	contacts = new ArrayList<ContactInfo>(size);
}

int ContactList::blockQuery(string name)
{
	int start = blockInfo[name[0]-65][0];
	int end = blockInfo[name[0]-65][1];

	return binarySearch(name, start, end);
}

int ContactList::binarySearch(string name, int start, int end)
{
	int mid;
	while(start <= end)
	{
		mid = (start + end)/2;
		if(contacts->Array[mid].name == name)
		{
			return mid;
		}
		if(name < contacts->Array[mid].name)
		{
			end = mid -1;
		}
		if(name > contacts->Array[mid].name)
		{
			start = mid + 1;
		}
	}
	return -1;
}

bool ContactList::addContact(string name, string phoneNum, string email)
{
//  添加线性表节点
	if(blockQuery(name) != -1)
	{
		return false;
	}

/*	int index = blockQuery(name);
	if(index != -1)
	{
		ContactInfo ci = contacts->Array[index];
		if(ci.name == name && ci.phoneNum == phoneNum && ci.email == email)
		{
			return false;
		}
	}
*/

	int start = blockInfo[name[0]-65][0];
	int end = blockInfo[name[0]-65][1];
	if(end-start >= DEFAULT_LENGTH - 1)
	{
		return false;
	}
	
	ContactInfo* &array = contacts->Array;
	while(start <= end)
	{
		if(name < array[start].name)
		{
			break;
		}
		start++;
	}
	
	//	插入节点
	int i = end;
	for(;i >= start; i--)
	{
		array[i+1] = array[i];
	}

	ContactInfo p(name, phoneNum, email);
	array[start] = p;
	blockInfo[name[0]-65][1]++;

	return true;
}

bool ContactList::delContact(string name)
{	
	int index=blockQuery(name);
	if(index == -1)
	{
		return false;
	}
	else
	{
		ContactInfo* &array = contacts->Array;

		int end = blockInfo[name[0]-65][1];
		for(int i=index; i<=end; i++)
		{
			array[i] = array[i+1];
		}
		blockInfo[name[0]-65][1]--;
	}
	

	return true;
}
	
void ContactList::showList()
{
cout << "showList" << endl;
	ContactInfo* &array = contacts->Array;
	cout << "首字母\t姓名\t电话\t\t邮箱" << endl;
	cout << "=======================================" << endl;
	for(int i=0; i<26; i++)
	{
		int start = blockInfo[i][0];
		int end = blockInfo[i][1];
		if(start <= end)
		{
			cout << char(i+65) << endl;
			for(int i=start; i<=end; i++)
			{
				cout << "\t"
					<< array[i].name << "\t"
					<< array[i].phoneNum << "\t"
					<< array[i].email << endl;
			}
		}
	}
}


bool ContactList::updateContact()
{
	ContactInfo* &array = contacts->Array;
	ContactInfo** &hashArray = contactsTable.Array;
	for(int i=0; i<contactsTable.MaxSize(); i++)
	{
		hashArray[i] = NULL;
	}

	for(int i=0; i<26; i++)
	{
		int start = blockInfo[i][0];
		int end = blockInfo[i][1];
		while(start <= end)
		{
			contactsTable.addContact(&array[start]);
			start++;
		}
	}

	return true;
}

int ContactList::hashQuery(string name)
{
	int key=0;
	for(unsigned i=0; i<name.length(); i++)
	{
		key += name[i];
	}

	int index = contactsTable.searchName(key, name);
	return index;
}

bool ContactList::showInfo(string name)
{
	int index = hashQuery(name);
	if(index != -1)
	{
		contactsTable.Array[index]->showInfo();
		return true;
	}
	else
	{
		return false;
	}
}

#endif
