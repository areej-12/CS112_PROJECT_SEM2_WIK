#ifndef CHARACTER_H
#define CHARACTER_H

#include<iostream>
#include<string>
using namespace std;

class Character{
	//to be accesible to the derived class and virtual functions
	protected:
		string name;
		string rs;
		int age;
		
	public:
		//constructor
		Character();
		Character(string n, string r, int a);
		
		//regular functions
		string getname();
		string getrs();
		int getage();
		
		//virtual function to display details
		virtual void displaydetails() const;
};


//friend class suspect
class Suspect: public Character{
	string alibi;
	string motive;
	bool iskiller;
	
	public:
		Suspect();
		Suspect(string n, string rs, int a, string al, string m, bool killer);
		void displaydetails() const override;
	
		bool ifkiller();
		string showalibi();
		string showmotive();
};
#endif
