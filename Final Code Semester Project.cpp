#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <chrono>
#include <conio.h>
#include "myheader.h"
#include "Character.h"
using namespace std;

string text;

void printWithDelay(const string &text, int delayMilliseconds) {
    for (char ch : text) {
        cout << ch << flush; // Print character and flush to ensure it's shown immediately
        this_thread::sleep_for(chrono::milliseconds(delayMilliseconds)); // Delay between characters
    }
}

// --- Clue Journal System ---
class ClueJournal {
public:
    vector<string> clueEntries;
    
    void addClue(const string& clue) {
        // Check if the clue already exists in the journal
        for (const string& entry : clueEntries) {
            if (entry == clue) {
                return; // Skip duplicates
            }
        }
        clueEntries.push_back(clue);
    }
    
    void showClues() {
        cout << "\n|------------------------Your Clue Journal -----------------------------|\n";
        if (clueEntries.empty()) {
            cout << "|- No clues collected yet.\n";
        } else {
            for (const string& entry : clueEntries) {
                cout << "|- " << entry << endl;
            }
        }
        cout << "|------------------------------------------------------------------------|\n";
    }
};

// --- Character Logic ---
Character::Character(): name(""), rs(""), age(0){}
Character::Character(string n, string r, int a):  name(n), rs(r), age(a){}
string Character::getname(){
	return name;
}
string Character::getrs(){
	return rs;
}
int Character::getage(){
	return age;
}
void Character::displaydetails() const{
	cout<<"Name: "<<name<<"\nAge: "<<age<<"\nRelationship with victim: "<<rs<<endl;
	}

//suspect class details
Suspect::Suspect(): Character(), alibi(""), motive(""), iskiller(false){}
Suspect::Suspect(string n,string rs, int a, string al, string m, bool killer): Character(n, rs , a), alibi(al), motive(m), iskiller(killer){}	
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
	cout<<"Alibi: "<<alibi<<endl;
	}
	
//void interrogation(){
//	Suspect suspects[1]={
//		Suspect("Mandy", "Roommate" ,20, "Exposed Alice for cheating","motive", false),
//		Suspect("Bob", 19, "Went to get drinks", "Scared, under pressure", false),
//		Suspect("Chris", 22, "In the kitchen alone", "Angry ex-boyfriend", true)
//	};
//}


// --- Player Class ---
class Player {
public:
    string name;
    ClueJournal journal;

    Player(string n) : name(n) {}

    void showResults(bool win) {
        cout << "\n--- Final Results ---\n";
        cout << "Detective: " << name << endl;

        if (win) {
            cout << "Outcome: WIN! Justice is served.\n";
        } else {
            cout << "Outcome: FAIL. The killer got away...\n";
        }
    }
};

// --- Game Class & Flow Controller ---
class Game {
private:
    bool killerIdentified;
    Player* player;
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
    
    Game() : killerIdentified(false),
    //Suspect(string n,string rs, int a, string al, string m, bool killer)
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
        
        cout << "After a long semester, you host a party in the common lounge of Hillview Girls' Hostel.\n"
            << "The storm outside is fierce, rain hitting the windows and the lights flickering.\n"
            << "As dawn breaks, the hostel falls into an eerie silence.\n"
            << "You head to the bathroom, walking through the dim corridors.\n"
            << "When you enter, you're shocked to find your friend Alice lying motionless on the floor,\n"
            << "her eyes wide open and surrounded by blood.\n"
            << "There's bruising around her neck.\n";
        text = "\t\t\tAlice is dead .\n";
        printWithDelay(text, 100);

        delay(1000);
        cout << " Press any key to move forward!\n";
        getch();
        system("cls");
        scene22();
        investigationPhase();
    }

    void scene22() {
        cout << "SCENE : REACTION\n";
        cout << "After a quick look around, you realise there is no sign of forced entry.\n"
            << "Realizing the gravity of the situation, you run back to the common lounge in a frenzy. \n";
        text = "\n\t\t\tIt's clear: the murderer is among you.\n";
        printWithDelay(text, 100);
        delay(100);
        text = "\n\t\t\tYou must find the killer, if you wish to survive.\n";
        printWithDelay(text, 100);
        delay(100);
    }

    void investigationPhase() {
        int choice, choice2, choice3, choice4;
        bool investigation_complete = false;
        
        do {
            printDivider();
            cout << "\nInvestigation Menu:\n";
            cout << "1. Call the Hostel Warden\n";
            cout << "2. Call the Police\n";
            cout << "3. Tell everyone what's going on\n";
            cout << "4. Review your clue diary\n";
            cout << "Enter your choice: ";
            cin >> choice;
            cin.ignore();

            switch (choice) {
                case 1:
                    system("cls");
                    text = "\n\nCalling.......";
                    printWithDelay(text, 200);
                    delay(200);
                    cout << endl << endl << "NO SIGNAL" << endl;
                    cout << endl << "Due to the raging storm outside, your call was not forwarded to the warden." << endl;
                    player->journal.addClue("The storm has knocked out all communications. Nobody can leave or call for help.");
                    break;
                    
                case 2:
                    text = "\n\nCalling.......";
                    printWithDelay(text, 200);
                    delay(200);
                    cout << endl << endl << "NO SIGNAL" << endl;
                    cout << endl << "Due to the raging storm outside, your call was not forwarded to the Police." << endl;
                    player->journal.addClue("The storm has knocked out all communications. Nobody can leave or call for help.");
                    break;
                    
                case 3:
                    system("cls");
                    cout << "SCENE: THE REVEAL\n";
                    cout << endl << "You reveal what you found to what's left of the group.\n"
                        << "Understandably, everyone is horrified.\n";
                    cout << endl << "CHARACTER PROFILES OF EVERYONE WHO IS CURRENTLY IN THE ROOM WITH YOU: " << endl;
                    
                    printDivider();
                    mandy.displaydetails();
                    
                    printDivider();
                    chris.displaydetails();
                    
                    printDivider();
                    bob.displaydetails();
                    printDivider();
                    
                    investigation_complete = true;
                    
                    interviewPhase();
                    break;
                    
                case 4:
                    system("cls");
                    player->journal.showClues();
                    cout << "\nPress any key to continue...";
                    getch();
                    system("cls");
                    break;
                    
                default:
                    cout << "\nInvalid choice. Please try again.\n";
            }
        } while (!investigation_complete);
    }

    void interviewPhase() {
        int choice2, choice3;
        bool ready_to_accuse = false;
        
        do {
            cout << "\nWho do you wish to interview?" << endl;
            cout << "1. Mandy" << endl;
            cout << "2. Chris" << endl;
            cout << "3. Bob" << endl;
            cout << "4. Review your clue diary" << endl;
            cout << "5. Make your accusation" << endl;
            cout << "Please enter your choice (1-5): ";
            cin >> choice2;
            system("cls");
            
            switch (choice2) {
                case 1:
                    cout << "SCENE: INTERVIEW WITH MANDY" << endl;
                    cout << "MANDY: I'm not comfortable talking in front of...\n"
                        << "\t*Mandy's gaze fixates on someone in the room for a while but before\n"
                        << "\tyou can figure out who it is, she looks back at you*\n"
                        << "\teveryone. Do you mind coming to my room with me?\n\n";
                    
                    player->journal.addClue("Mandy's gaze fixated on someone in the room when discussing Alice's death.");
                    
                    cout << "Press any key to continue...";
                    getch();
                    system("cls");
                    
                    cout << "MANDY: Alice had been...distressed as of late.\n"
                        << "\tSometimes, I'd get up during the night for a glass of water and I'd almost\n"    
                        << "\talways find Alice sniffling, texting someone in disarray.\n"
                        << "\tI have reason to believe it was her boyfriend, Chris.\n"
                        << "\tI'm not sure what exactly went down between the two of them but you're welcome to look around\n"
                        << "\ther side of the room if you wish." << endl;
                    
                    player->journal.addClue("According to Mandy, Alice was frequently upset at night, texting someone - possibly Chris.");
                    
                    cout << endl << "As you look around Alice's side of the room, you find her phone and diary.\n"
                        << "Which do you wish to investigate?" << endl;
                    cout << "1. Her Phone" << endl;
                    cout << "2. Her Diary" << endl;
                    cout << "Please enter your choice (1-2): ";
                    cin >> choice3;
                    system("cls");
                    
                    switch (choice3) {
                        case 1:
                            alicephone();
                            player->journal.addClue("Alice's phone contains threatening messages from Chris: 'You're mine' and 'If you leave, no one will care.'");
                            player->journal.addClue("Chris' last messages were: 'You'll regret it' and 'You can't leave.'");
                            break;
                            
                        case 2:
                            dairy();
                            player->journal.addClue("Alice's diary mentions Chris has a scary temper and she didn't feel safe.");
                            player->journal.addClue("Alice's diary entry: 'Chris was being rude again. His temper scares me sometimes.'");
                            break;
                    }
                    
                    cout << "\nPress any key to continue...";
                    getch();
                    system("cls");
                    break;
                    
                case 2:
                    cout << "SCENE: INTERVIEW WITH CHRIS" << endl << endl;
                    cout << "Chris: How are you so sure this was a murder?\n"
                        << "\tThat b**** was clearly unstable. The way I see it, this case is pretty open and shut.\n"
                        << "\tB**** probably took the easy way out\n"
                        << "\tWho are you to investigate us anyway?\n"
                        << "\tHow are we so sure you didn't kill her?\t\n"
                        << "\tJust do everyone a favour and end this little game of yours.\n"
                        << "\n\t*Chris mumbles to himself\n\n"
                        << "\tSelf-righteous a**" << endl;
                    
                    player->journal.addClue("Chris is hostile and defensive. He tried to suggest Alice's death was suicide.");
                    player->journal.addClue("Chris tried to deflect suspicion by questioning your authority to investigate.");
                    
                    cout << "\nPress any key to continue...";
                    getch();
                    system("cls");
                    break;
                    
                case 3:
                    cout << "SCENE: INTERVIEW WITH BOB" << endl << endl;
                    cout << "Bob:\tC-Could we please t-talk in the hallway?\n"
                        << "\tIf you dont mind...\n"
                        << "\n\t*You follow Bob into the hallway*\n\n"
                        << "\tBob: *Sniffling*\n"
                        << "\tI can't believe she's gone...\n"
                        << "\tShe and I were close y'know. I didn't even get to tell her...\n"
                        << "\tIf only that jerk Chris wasn't in the way...\n"
                        << "\tI told her to break up with him...\n"
                        << "\tThis wouldn't have happened if..\n"
                        << "\n\t*Breaks down*\n\n"
                        << "\tI'm s-sorry, I can't d-do this anymore. I hope you find whoever d-did this." << endl;
                    
                    player->journal.addClue("Bob was close to Alice and seems genuinely upset by her death.");
                    player->journal.addClue("Bob told Alice to break up with Chris, calling him a 'jerk'.");
                    
                    cout << "\nPress any key to continue...";
                    getch();
                    system("cls");
                    break;
                    
                case 4:
                    player->journal.showClues();
                    cout << "\nPress any key to continue...";
                    getch();
                    system("cls");
                    break;
                    
                case 5:
                    ready_to_accuse = true;
                    break;
                    
                default:
                    cout << "\nInvalid choice. Please try again.\n";
                    break;
            }
        } while (!ready_to_accuse);
        
        makeAccusation();
    }
    
    void makeAccusation() {
        int choice4;
        system("cls");
        cout << "So dear " << playerName << ", are you ready to choose the Killer?" << endl;
        cout << "Before making your accusation, you review the evidence one last time:" << endl;
        player->journal.showClues();
        
        cout << "\n1. It was Chris" << endl;
        cout << "2. Bob did it" << endl;
        cout << "3. It was Mandy" << endl;
        cout << "Please enter your choice (1-3): ";
        cin >> choice4;
        system("cls");
        
        switch (choice4) {
            case 1:
                cout << "Congratulations, Detective " << playerName << "!" << endl;
                cout << "\nYou carefully present your evidence:" << endl;
                cout << "- The threatening messages on Alice's phone" << endl;
                cout << "- Alice's diary mentioning Chris's scary temper" << endl;
                cout << "- Chris's hostile and defensive behavior during questioning" << endl;
                cout << "\nChris breaks down and confesses to the murder." << endl;
                cout << "He couldn't handle Alice trying to leave him, so he followed her" << endl;
                cout << "and in a fit of rage, strangled her in the bathroom." << endl;
                win();
                player->showResults(true);
                break;
                
            case 2:
                cout << "Oh no, Detective " << playerName << "!" << endl;
                cout << "\nYou accuse Bob, but he's genuinely shocked and hurt by the accusation." << endl;
                cout << "While Bob was obsessed with Alice, the evidence doesn't support your theory." << endl;
                cout << "Meanwhile, Chris slips away during the confusion..." << endl;
                bust();
                player->showResults(false);
                break;
                
            case 3:
                cout << "Oh no, Detective " << playerName << "!" << endl;
                cout << "\nYou accuse Mandy, but she's absolutely bewildered by your accusation." << endl;
                cout << "The evidence clearly points elsewhere, and in your confusion," << endl;
                cout << "you've allowed the real killer to escape..." << endl;
                bust();
                player->showResults(false);
                break;
        }
    }
};

// --- Main function ---
int main() {
    Game game;
    game.startGame();
    return 0;
}