#ifndef CLASS_CONTACTINFO 
#define CLASS_CONTACTINFO

#include <iostream>
#include <string>
using namespace std;

class ContactInfo
{
friend bool t_ContactList();
friend class ContactList;
private:
	string name;
	string phoneNum;
	string email;
public:
	ContactInfo()
	{
		name = "";
		phoneNum = "";
		email = "";
	}

	ContactInfo(string name, string phoneNum, string email)
	{
		this->name = name;
		this->phoneNum = phoneNum;
		this->email = email;
	}

	string Name()
	{
		return name;
	}

	string PhoneNum()
	{
		return phoneNum;
	}

	string Email()
	{
		return email;
	}

	int Key()
	{
		int sum = 0;
		for(unsigned i=0; i<name.length(); i++)
		{
			sum += name[i];
		}
		return sum;
	}

	bool empty()
	{
		if(name == "")
		{
			return true;
		}
		else
		{
			return false;
		}
	// TODO		不严谨，墓碑机制
	}

	friend bool operator==(ContactInfo &c1, ContactInfo &c2)
	{
		if(c1.name == c2.name &&
			c1.phoneNum == c2.phoneNum &&
			c1.email == c2.email)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	friend bool operator<(ContactInfo &c1, ContactInfo &c2)
	{	
		if(c1.name < c2.name)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	friend bool operator>(ContactInfo &c1, ContactInfo &c2)
	{
		if(c1.name > c2.name)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void operator=(ContactInfo &c1)
	{
		name = c1.Name();
		phoneNum = c1.PhoneNum();
		email = c1.Email();
	}

	void showInfo()
	{
		cout << name << '\t'
			<< phoneNum << '\t'
			<< email << endl;
	}
};

#endif
