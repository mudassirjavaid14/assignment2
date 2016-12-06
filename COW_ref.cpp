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
		ref_counter = 1; //initializing by 1
		
	}

	String(const char* string)
	{	
		_length = strlen(string); //saving the length of string into int length
		
		_strbuf = new char[_length]; //saving the length into string pointed to
		
		ref_counter = 1;
		strcpy(_strbuf, string);  //copying the string pointed to from string (source) to _strbuf (destiantion)
	}

	// Creating Contructor for creating Copy
	String(const String& string)
	{
		_length = string._length;
		_strbuf = new char[_length];
		ref_counter += 1;
		strcpy(_strbuf, string._strbuf);  //copying from sting._strbuf to _strbuf
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
		reserve(1);
		_strbuf[_length - 1] = add_Char;
		_strbuf[_length] = '\0';
	}


	void newChar(int chrLength)
	{
		char* temp = new char[_length];
	
		strcpy(temp, _strbuf);


		_strbuf = new char[_length + chrLength];
		
		strcpy(_strbuf, temp);
		_length += chrLength;
	}

	

	~String()  //destrucor 
		{
		ref_counter -= 1; // decrementing ref_counter by value -1
		// checking if ref_counter = 0 then delete the pointer
		if (ref_counter == 0)   
		{
			if (_strbuf != NULL)
			{
				cout << "Deleting!" << endl;
				delete[] _strbuf;
				_strbuf = NULL;
			}
		}
	}

private:

	char* _strbuf;    //buffer to store the original string
    int _length;  // int to store string length
	static int ref_counter;
};


int String:: ref_counter = 0;



void main()
{
	String str_obj("Running the COW with RC");
	String str2_obj(str_obj);
	cout << "It is Original String!" << endl;;
	str_obj.print(); //calling print method
	cout << "Printing the copy!" << endl;
	str2_obj.append('a'); //appending for checking purposes
	str2_obj.print(); //printing the copied string
	cout << "Character at 6th index is : " << str2_obj.charAt(6) << endl; //checking the charAt function
}