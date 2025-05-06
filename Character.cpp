#include<iostream>
#include<string>
#include"Character.h"
using namespace std;

//character class details
Character::Character(): name(""), role(""), age(0){}
Character::Character(string n, string r, int a):  name(n), role(r), age(a){}	//constructor

string Character::getname(){
	return name;
}
string Character::getrole(){
	return role;
}
int Character::getage(){
	return age;
}
void Character::displaydetails() const{
	cout<<"Name: "<<name<<"\nAge: "<<age<<"\nRole: "<<role<<endl;
	}

//suspect class details
Suspect::Suspect(): Character(), alibi(""), motive(""), iskiller(false){}
Suspect::Suspect(string n, int a, string al, string m, bool killer): Character(n, "Suspect", a), alibi(al), motive(m), iskiller(killer){}	
bool Suspect::ifkiller(){
	return iskiller;
}
string Suspect::showalibi(){
	return alibi;
}
string Suspect::showmotive(){
	return motive;
}
void Suspect::displaydetails() const{
	Character::displaydetails();
	cout<<"Alibi: "<<alibi<<"\nMotive: "<<motive<<endl;
	}
	
void interrogation(){		//member function
	Suspect suspects[3]={
		Suspect("Mandy", 20, "Stayed with the group", "Exposed Alice for cheating", false),
		Suspect("Bob", 19, "Went to get drinks", "Scared, under pressure", false),
		Suspect("Chris", 22, "In the kitchen alone", "Angry ex-boyfriend", true)
	};
}

int main(){
	return 0;
}
