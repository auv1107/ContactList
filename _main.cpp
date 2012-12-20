#include <iostream>
#include "ContactInfo.h"
#include "ArrayList.h"
#include "ContactList.h"

using namespace std;

bool t_ContactList()
{
#ifdef CLASS_CONTACTLIST
	cout << "Test For Class ContactList" << endl;
	cout << "==========================" << endl;
	
	ContactList cl;
	
	cout << "Part 1:	ContactList(int size=DEFAULT_LENGTH)" << endl;
	cout << "-----------------------------------------------" << endl;
	for(int i=0; i<26; i++)
	{
		cout << cl.blockInfo[i][0] << " " << cl.blockInfo[i][1] << endl;
	}
	cout << endl;

	
	cout << "Part 2:	addContact" << endl;
	cout << "---------------------";
	cl.addContact("Lee", "00123456789", "Lee@hp.com");
	cl.addContact("Wang", "1234577899", "Wang@gmail.com");
	cl.addContact("Anti", "230239232", "Anti@hp.com");
	cl.addContact("L3i", "432534655", "Li@map.com");
	cl.addContact("Lxlee", "00123456789", "Lee@hp.com");
	cl.addContact("Lily", "00123456789", "Lee@hp.com");
	cl.addContact("Lany", "00123456789", "Lee@hp.com");
	cl.addContact("Wii", "1234577899", "Wang@gmail.com");
	cl.addContact("Anna", "230239232", "Anti@hp.com");
	cl.addContact("Lucy", "432534655", "Li@map.com");
	cl.addContact("Scott", "1234577899", "Wang@gmail.com");
	cl.addContact("Nauti", "230239232", "Anti@hp.com");
	cl.addContact("Sam", "432534655", "Li@map.com");
	cl.addContact("Tol", "1234577899", "Wang@gmail.com");
	cl.addContact("ORZ", "230239232", "Anti@hp.com");
	cl.addContact("Sun", "432534655", "Li@map.com");

	cl.addContact("Lam", "432534655", "Li@map.com");
	cl.addContact("Lol", "1234577899", "Wang@gmail.com");
	cl.addContact("LRZ", "230239232", "Anti@hp.com");
	cl.addContact("Lun", "432534655", "Li@map.com");

	cl.addContact("Lnti", "230239232", "Anti@hp.com");
	cl.addContact("Li", "432534655", "Li@map.com");
	cl.addContact("Lxee", "00123456789", "Lee@hp.com");
	cl.addContact("Lil", "00123456789", "Lee@hp.com");

	cout << "Part 3: 	showList" << endl;
	cout << "-------------------" << endl;
	cl.showList();

	cout << "Part 4:	delContact" << endl;
	cout << "---------------------" << endl;
	cl.delContact("Lee");
	cl.delContact("Li");
	cl.delContact("QQ");
	cl.showList();

	cout << "Prat 5:	updateContact" << endl;
	cout << "-------------------------" << endl;
	cl.updateContact();
	
	for(int i=0; i<cl.contactsTable.MaxSize(); i++)
	{
		if(cl.contactsTable.Array[i] != NULL)
		{
			cout << cl.contactsTable.Array[i]->Name() << endl;
		}
	}
	int index = cl.hashQuery("Wang");
	if(index != -1)
	{
		cl.showInfo("Wang");
	}
	
	return true;
#endif
}

bool t_ArrayList()
{
#ifdef CLASS_ARRAYLIST
	cout << "Test For Class ArrayList" << endl;
	cout << "========================" << endl;

	ArrayList<int> al;
	cout << sizeof(al) << endl;
	ArrayList<char> all(200);
	cout << sizeof(ArrayList<int>) << endl;

	cout << endl;
	return true;

#endif
}

bool t_ContactInfo()
{
#ifdef CLASS_CONTACTINFO 
	cout << "Test For Class ContactInfo" << endl;
	cout << "==========================" << endl;


	ContactInfo ci("Lef", "12345678900", "Lee@hp.com");
	cout << ci.Name() << endl;
	cout << ci.PhoneNum() << endl;
	cout << ci.Email() << endl;
	cout << ci.Key() << endl;
	
	ContactInfo cj("Wang", "00123456789", "Wang@hp.com");
	if(ci == cj)
	{
		cout << "ci == cj" << endl;
	}
	if(ci < cj)
	{
		cout << "ci < cj" << endl;
	}
	if(ci > cj)
	{
		cout << "ci > cj" << endl;
	}

	ci = cj;
	cout << ci.Name() << endl;
	cout << ci.PhoneNum() << endl;
	cout << ci.Email() << endl;
	cout << ci.Key() << endl;



	cout << endl;
	return true;

#endif
}

int main()
{
	t_ContactInfo();
	t_ArrayList();
	t_ContactList();


	return 0;
}
