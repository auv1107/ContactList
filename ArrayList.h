#ifndef CLASS_ARRAYLIST
#define CLASS_ARRAYLIST

#include <cstring>
#define DEFAULT_LENGTH 10


template <class T>
class ArrayList
{
friend class ContactList;
private:
	T *Array;
	int lenForEachBlock;
public:
	ArrayList(int lenforeachblock=DEFAULT_LENGTH)
	{	
		lenForEachBlock = lenforeachblock;
		Array = new T[26*lenForEachBlock];
		
//		memset(Array, 0, 26*lenForEachBlock*sizeof(T));
	//	for(int i=0; i<26*lenForEachBlock; i++)
	}

	~ArrayList()
	{	
		delete []Array;
	}
};	

#endif
