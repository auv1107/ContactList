ContactList
===========

# ContactList.h
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
