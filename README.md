ContactList
===========

### ContactList.h
	- ArrayList<ContactInfo>* contacts
	- HashTable<ContactInfo*> contactsTable
	- int blockInfo[26][2]

	+ ContactList(int size)
	+ bool addContact(string name, string phoneNum, string email)
	+ bool updateContact()
	+ bool delContact(string name)
	+ void showList()
	+ int blockQuery(string name)
	+ int binarySearch(string name, int start, int end)
	+ int hashQuery(string name)
	+ bool showInfo(string name)


### ContactInfo.h
	- friend class ContactList
	- string name
	- string phoneNum
	- string email

	+ ContactInfo()
	+ ContactInfo(string name, string phoneNum, string email)
	+ string Name()
	+ string PhoneNum()
	+ string Email()
	+ bool empty()
	+ void showInfo()

	+ friend bool operator==(ContactInfo &c1, ContactInfo &c2)
	+ friend bool operator<(ContactInfo &c1, ContactInfo &c2)
	+ friend bool operator<(ContactInfo &c1, ContactInfo &c2)
	+ void operator=(ContactInfo &c1)
	

### HashTable.h (template <class T>)
	- friend class ContactList;
	- T* Array;
	- int maxSize;
	- int size;

	+ HashTable(int maxsize=MaxSize)
	+ ~HashTable()
	+ int Size()
	+ int MaxSize()
	+ int expIndexToInsert(int key, string name)
	+ int searchName(int key, string name)
	+ bool addContact(T ci)


### ArrayList.h (template <class T>)
	- friend class ContactList
	- T* Array
	- int lenForEachBlock

	+ ArrayList(int lenForEachBlock=DEFAULT_LENGTH)
	+ ~ArrayList()
