#include<iostream>
#include<vector>
using namespace std;

class clue{
public:
vector<string>cluejournal;
void savescle(const string clue){
	string entry=clue;
	cluejournal.push_back(entry);
}
static int count;
static void countcondition(){
	}
}
void showclue(){
 cout << "\n|------------------------Your Clue Journal -----------------------------|\n";
    for (const string&clue:cluejournal) {
        cout << "|- " << clue << endl;
    }
    cout <<"------------------------------------------------------------------------|\n";
}
};
int clue::count=0;

int main(){
	clue c;
	c.savescle("Mandy's gaze fixates on someone in the room for a while but before.");
	c.savescle("for a while but before.");
	c.savescle("Mandy's gaze fixates on someone in the room for a while but before.");
	c.savescle("Mandy's gaze fixates on someone in the room for a while but before.");
	c.showclue();
	return 0;
}

