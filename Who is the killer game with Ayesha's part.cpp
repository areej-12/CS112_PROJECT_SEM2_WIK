#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <chrono>
#include<conio.h>
#include"myheader.h"
//#include"Character.h"
using namespace std;
//void investigationPhase;
void investigationPhase();
	string text;
void printWithDelay(const string &text, int delayMilliseconds) {
    for (char ch : text) {
        cout << ch << flush; // Print character and flush to ensure it's shown immediately
        this_thread::sleep_for(chrono::milliseconds(delayMilliseconds)); // Delay between characters
    }
}
// --- Ume's Part: Character and Interrogation Logic ---
class Character {
protected:
    string name;
    string role;
    int age;

public:
    Character(string n, string r, int a): name(n), role(r), age(a) {}
    //virtual void speak() {
        //cout << name << " says: 'I have nothing to hide.'\n";
    //}
    virtual void showDetails() {
        cout << "Name: " << name <<endl;
		cout<< "Relationship with victim: " << role <<endl;
		cout<< "Age: " << age << endl;
    }
    //virtual ~Character() {}
};

class Suspect : public Character {
private:
    string alibi;
    string motive;
    bool isKiller;

public:
    Suspect(string n, string r, int a, string al, string mo, bool killer)
        : Character(n, r, a), alibi(al), motive(mo), isKiller(killer) {}

    //void speak() override {
       // cout << name << " says: 'You have to believe me!'\n";
    //}

    void showDetails() override {
        Character::showDetails();
        cout << "Alibi: " << alibi <<endl;
    }

    bool getKillerStatus() { return isKiller; }
};

// --- Areej's Part: Clue & Hint System ---
class clue{
public:
vector<string> cluejournal;
void savescle(const string clue){
	string entry=clue;
	cluejournal.push_back(entry);
}
void showclue(){
 cout << "\n--- Your Clue Journal ---\n";
    for (const string& clue : cluejournal) {
        cout << "- " << clue << endl;
    }
    cout << "--------------------------\n";
}
void showsavedclue(){
	cout <<"\t[+] Clue Added to the Clue Journal !\n";
}
};


// --- Ayesha's Part: Player Class & Decision Tracker ---
class Player {
public:
    string name;
    int score;
    int attempts;
    int hintsUsed;

    Player(string n) : name(n), score(100), attempts(0), hintsUsed(0) {}

    void makeChoice() {
        attempts++;
    }

    void applyPenaltyForHint() {
        hintsUsed++;
        score -= 10;
    }

    void showResults(bool win) {
        cout << "\n--- Final Results ---\n";
        cout << "Detective: " << name << endl;
        cout << "Score: " << score << endl;
        cout << "Attempts: " << attempts << endl;
        cout << "Hints Used: " << hintsUsed << endl;

        if (win) {
            cout << "Outcome: WIN! Justice is served.\n";
        } else {
            cout << "Outcome: FAIL. The killer got away...\n";
        }
    }
};

// --- Abeer's Part: Game Class & Flow Controller ---
class Game {
private:
    bool foundEnoughClues;
    bool killerIdentified;
    int cluesFound;
    Player* player;
    //HintSystem hintSystem;
     clue c;
    Suspect mandy;
    Suspect chris;
    Suspect bob;

    void delay(int milliseconds) {
        this_thread::sleep_for(chrono::milliseconds(milliseconds));
    }

    void printDivider() {
        cout << "\n________________________________________________________________\n";
    }

public:
	string playerName;
    Game() : foundEnoughClues(false), killerIdentified(false), cluesFound(0),
        mandy("Mandy", "Roommate", 20, "At the cafe", "Jealousy", false),
        chris("Chris", "Boyfriend", 22, "Library", "Possessiveness", true),
        bob("Bob", "Friend", 21, "Stairwell", "Obsession", false) {}

    void startGame() {
        printDivider();
        cout << " \t WELCOME TO \n";
        scene2();
        printDivider();
        
        cout << "Enter your name, Detective: ";
        getline(cin, playerName);
        player = new Player(playerName);

        cout << "\nHello, Detective " << player->name << "! Your investigation begins...\n\n";
        delay(1000);
 		system("cls");
        sceneDiscovery();
    }

    void sceneDiscovery() {
        printDivider();
        cout << "SCENE: The Discovery \n";
        
    
    delay(1000);
    
    cout <<"After a long semester, you host a party in the common lounge of Hillview Girls' Hostel.\n"
		<<"The storm outside is fierce, rain hitting the windows and the lights flickering.\n"
		<<"As dawn breaks, the hostel falls into an eerie silence.\n"
		<<"You head to the bathroom, walking through the dim corridors.\n"
		<<"When you enter, you're shocked to find your friend Alice lying motionless on the floor,\n"
		<<"her eyes wide open and surrounded by blood.\n"
		<<"There's bruising around her neck.\n";
		 text="\t\t\tAlice is dead .\n";
		printWithDelay(text,100);


//        printDivider();
    delay(1000);
    cout <<" Press any key to move forward!\n";
    getch();
    system("cls");
    scene22();
//			scene 2 show up
        //investigationPhase();
    }
void scene22(){

//    string text = "Panicked, you attempt to call the police and the hostel warden, but the storm has knocked out all communication. "
//                  "Realizing the gravity of the situation and the absence of external help, you gather the remaining residents in the common lounge. "
//                  "It's clear: the murderer is among you.";
//
//    printWithDelay(text, 100);
cout <<"SCENE : REACTION\n";
cout << "After a quick look look around, you realise there is no sign of forced entry.\n"
    << "Realizing the gravity of the situation, you run back to the common lounge in a frenzy. \n";
    text="\n\t\t\tIt's clear: the murderer is among you.\n";
    printWithDelay(text,100);
	delay(100); // Adjust delay for slower or faster effect
	text = "\n\t\t\tYou must find the killer, if you wish to survive.\n";
	printWithDelay(text, 100);
	delay(100);
    

    
	 {
        int choice, choice2, choice3, choice4;
        do {
            printDivider();
            cout << "\nInvestigation Menu:\n";
            cout << "1. Call the Hostel Warden\n";
            cout << "2. Call the Police\n";
            cout << "3. Tell everyone what's going on\n";
            cout << "Enter your choice: ";
            cin >> choice;
            cin.ignore();

            switch (choice) {
                case 1:
                	
                	system("cls");
                    text = "\n\nCalling.......\n";
                    
                    printWithDelay(text, 200);
                    phone();
                    delay(200);
                    cout<<endl<<endl<<"NO SIGNAL"<<endl;
                    cout<<endl<<"Due to the raging storm outside, your call was not forwarded to the warden."<<endl;
                    
                    break;
                case 2:
                	
                    text = "\n\nCalling.......";
					phone();
                    printWithDelay(text, 200);
                    delay(200);
                    cout<<endl<<endl<<"NO SIGNAL"<<endl;
                    cout<<endl<<"Due to the raging storm outside, your call was not forwarded to the Police."<<endl;
                    
                    break;
                case 3:
                system("cls");
                cout<<"SCENE: THE REVEAL\n";
                cout<<endl<<"You reveal what you found to what's left of the group.\n"
				    <<"Understandably, everyone is horrified.\n";
				cout<<endl<<"CHARACTER PROFILES OF EVERONE WHO IS CURRENTLY IN THE ROOM WITH YOU: "<<endl;
				
				printDivider();
				mandy.showDetails();
				
				printDivider();
				chris.showDetails();
				
				printDivider();
				bob.showDetails();
				printDivider();
				
				do {
				
				cout<<"\nWho do you wish to interview?"<<endl;
				cout<<"1. Mandy"<<endl;
				cout<<"2. Chris"<<endl;
				cout<<"3. Bob"<<endl;
				cout<<"(Press 0 if you wish to move on to the next phase of your investigation)"<<endl;
				cout<<"Please enter your choice(0-3):";
				cin>>choice2;
				system("cls");
				switch(choice2){
					case 1:
						cout<<"SCENE: INTERVIEW WITH MANDY"<<endl;
						cout<<"MANDY:I'm not comfortable talking infront of...\n"
						    <<"\t*Mandy's gaze fixates on someone in the room for a while but before\n"
						    <<"\tcan figure out who it is, she looks back at you*\n"
						    <<"\teveryone. Do you mind coming to my room with me?\n\n";
						    c.savescle("Mandy's gaze fixates on someone in the room for a while but before.");
//						    c.showclue();
						    c.showsavedclue();
						//ASCII of Mandy's room
						cout<<"Press any key to continue...";
						getch();
						system("cls");
						
						cout<<"MANDY: Alice had been...distressed as of late.\n"
						    <<"\tSometimes, I'd get up during the night for a glass of water and I'd almost\n"	
						    <<"\talways find Alice sniffling, texting someone in disarray.\n"
						    <<"\tI have reason to believe it was her boyfriend, Chris.\n"
						    <<"\tI'm not sure what exactly went down between the two of them but you're welcome to look around\n"
						    <<"\ther side of the room if you wish."<<endl;
						    
						cout<<endl<<"As you look around Alice's side of the room, you find her phone and diary.\n"
						          <<"which do you wish to investigate?"<<endl;
						          cout<<"1. Her Phone"<<endl;
								  cout<<"2. Her Diary"<<endl;
								  cout<<"Please enter your choice (1-2):";
								  cin>>choice3;
								  system("cls");
								  
								  switch(choice3){
								  	case 1:
								  		alicephone();
								  		break;
								  		
								  	case 2:
								  		
								  		dairy();
								  		
								  		break;
							  		
								  		
								  		
								  }
								  
						break;
								  
						case 2:
							cout<<"SCENE: INTERVIEW WITH CHRIS"<<endl<<endl;
							cout<<"Chris: How are you so sure this was a murder?\n"
							    <<"\tThat b**** was clearly unstable. The way I see it, this case is pretty open and shut.\n"
							    <<"\tB**** probably took the easy way out\n"
								<<"\tWho are you to investigate us anyway?\n"
							    <<"\tHow are we so sure you didn't kill her?\t\n"
							    <<"\tJust do everyone a favour and end this little game of yours.\n"
							    <<"\n\t*Chris mumbles to himself\n\n"
							    <<"\tSelf-righteous a**"<<endl;
							    
							 
							
						break;
							
						case 3:
							cout<<"SCENE: INTERVIEW WITH BOB"<<endl<<endl;
							cout<<"Bob:\tC-Could we please t-talk in the hallway?\n"
							    <<"\tIf you dont mind...\n"
							    <<"\n\t*You follow Bob into the hallway*\n\n"
							    //Ascii for hallway if needed
							    <<"\tBob: *Sniffling*\n"
							    <<"\tI can't believe she's gone...\n"
							    <<"\tShe and I were close y'know. I didn't even get to tell her...\n"
							    <<"\tIf only that jerk Chris wasn't in the way...\n"
							    <<"\tI told her to break up with him...\n"
							    <<"\tThis wouldn't have happened if..\n"
							    <<"\n\t*Breaks down*\n\n"
							    <<"\tI'm s-sorry, I can't d-do this anymore. I hope you find whoever d-did this."<<endl;
							    
							    
						          
						
					    break;
						
				   }
				   
				   
						
				}
				while(choice2 != 0);
			break;
             
            default:
            cout << "\nInvalid choice. Please try again.\n";
            }
        } while (choice!=3);
        
    cout<<"So dear "<<playerName<<", are you ready to choose the Killer?"<<endl;
    cout<<"1. It was Chris"<<endl;
    cout<<"2. Bob did it"<<endl;
    cout<<"3. It was Mandy"<<endl;
    cout<<"Please enter your choice (1-3):";
    cin>>choice4;
    system("cls");
    
    switch(choice4){
    	case 1:
    		cout<<"Congratualions,"<<endl;
    		win();
    		
    	break;
    		
    	case 2:
    	    cout<<"Womp Womp,"<<endl;
    	    bust();
    	    
    	break;
			
		case 3:
    	    cout<<"Womp Womp,"<<endl;
    	    bust();

    	    
    	
    	    
    	
    	    
	
	}
    
        
        
    
    }
}

    /*void lookForClues() {
        printDivider();
        cout << "\U0001F50E Searching for clues...\n";
        delay(1000);
        Clue newClue("Alice's phone shows Chris's angry texts.", false);
        clues.push_back(newClue);
        cluesFound++;
        if (cluesFound >= 3) {
            foundEnoughClues = true;
            cout << "\n\U0001F389 You have gathered enough evidence! \U0001F389\n";
        } else {
            cout << "\n\U0001F4DD Clues found so far: " << cluesFound << "/3\n";
        }
    }

    void finalDeduction() {
        printDivider();
        if (!foundEnoughClues) {
            cout << "\U0001F6A7 WARNING: You haven't found enough evidence!" << endl;
            cout << "Proceed anyway? (yes/no): ";
            string confirm;
            getline(cin, confirm);
            if (confirm != "yes" && confirm != "Yes") {
                return;
            }
        }

        cout << "\n\U0001F52E Final Deduction Time!\n";
        cout << "Who do you accuse?\n";
        cout << "1. Mandy (Roommate)\n";
        cout << "2. Bob (Close Friend)\n";
        cout << "3. Chris (Boyfriend)\n";
        cout << "Enter your choice: ";

        int accuse;
        cin >> accuse;
        cin.ignore();

        if (accuse == 3) {
            printDivider();
            cout << "\U0001F52D Chris confesses after pressure.\n";
            player->makeChoice();
            player->showResults(true);
        } else {
            printDivider();
            cout << "\U0001F480 Wrong accusation. The killer escapes...\n";
            player->makeChoice();
            player->showResults(false);
        }

        killerIdentified = true;
        delete player;
    }*/
};

// --- Main function ---
int main() {
	 
	Game game;
	game.startGame();
    return 0;
}
 