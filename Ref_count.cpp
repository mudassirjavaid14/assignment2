#include <iostream>
#include <string>
#include <conio.h>
#include <cstring>
#include <stdlib.h>



using namespace std;



class String
{
public:

	String() //default constructor 

	{   _strbuf = NULL;
		_length = 0;
		
		
	}

	String(const char* string)
	{	
		_length = strlen(string); //saving the length of string into int length
		
		_strbuf = new char[_length]; //saving the length into string pointed to
		
		
		strcpy(_strbuf, string);  //copying the string pointed to from string (source) to _strbuf (destiantion)
	}

	



	// Creating Contructor for creating Copy
	String(const String& string)
	{
		
		_strbuf = new char[_length];
		
		
	}

	String(char* &ptr, int length)
{
	
	_strbuf = ptr;
	ptr = NULL;		// to avoid dangling pointer
	_length = length;

}


	

	char charAt(int index) const
	{
		return _strbuf[index];     //retrning the found index in string
	}

	void reserve(int res)
	{
		char* tmp = new char[_length];
		strcpy(tmp, _strbuf);

		_strbuf = new char[_length + res];
		strcpy(_strbuf, tmp);
		_length += res;
	}


	
	void print()
	{
		for (int i = 0; i < _length; i++)
		{
			cout << _strbuf[i];
			
		}
		cout<< endl;
		cout << "===" << endl;
	}


	void append(char add_Char)
	{
		char* tmp = _strbuf;
	_length++;
	_strbuf = new char[_length];

	for (int i = 0; i < _length - 1; i++)
	{
		_strbuf[i] = tmp[i];
	}
	_strbuf[_length - 1] = add_Char;
	delete[] tmp;
	}


	void newChar(int chrLength)
	{
		char* tmp = new char[_length];
	
		strcpy(tmp, _strbuf);


		_strbuf = new char[_length + chrLength];
		
		strcpy(_strbuf, tmp);
		_length += chrLength;
	}

	

	~String()  //destrucor 
		{

		delete[] _strbuf;  
	}


	 bool diff()  
     {
     	if(Previous == this && NexPtr == this)
     		return 1;
     	else
     		return 0;
     }



private:

	char* _strbuf;    //buffer to store the original string
    int _length;  // int to store string length

	String*   Previous;
    String*   NexPtr;
    
    void Fetch(const String& str)
    { 
        _strbuf = str._strbuf;
        _length = str._length;
        NexPtr = str.NexPtr;
        NexPtr->Previous = this;
     
        (const_cast<String*>(&str))->NexPtr = this;
    }


	  String& operator= (const String &str2 )
    { 

    	if (this != &str2) {
            diff();
            Fetch(str2);
        }
        return *this;
    }



    void erase()
    { 
        if (diff()) 
        	delete[] _strbuf;
        else
        {
            Previous->NexPtr = NexPtr;
            NexPtr->Previous = Previous;
            Previous = NexPtr = 0;
            
        }
       
    }


	
};






void main()
{
	String str_obj("COW with REF Counting");
	String str2_obj(str_obj);
}