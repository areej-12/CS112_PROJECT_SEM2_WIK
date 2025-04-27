#include <iostream>
#include <conio.h>
#include <windows.h>
#include<ctime>
#include<vector>
using namespace std;


class hint{			//			hint class
	private:
		int hintcount;			//members
		const int maxhint=3;
	public:
	hint(){				//constructor
		hintcount=0;
	}
	void randomclues(string arrayhint[],int size){			//function to randomly chosse hint
	 arrayhint[size];		
	 srand(time(0));			//		timeseed
	int random=rand()%size;				//		random->saves the randomly geneerated number based on mod
	cout <<"->[!] HINT :"<<arrayhint[random]<<endl;		//			hints revealed
}
	void revealhint(){			//			function to reveal hints
		string a[10]={
			"Check entry points for signs of struggle.[?]",
			"No signs of struggle? The killer may have been let in.",
			"Look for who had access to her room and the party.",			//hints->user can take maximum 3
			"Notice that her phone is missing — someone took it.",
			"Roommates share secrets. Look for personal items.",
			"Digital devices and Personal papers often hold hidden conflicts.",
			"Alibis need witnesses. Verify timelines",
			"Jealousy Kills!(Sometimes the people you love).",
			"Injuries can betray violent encounters!",
			"Motive + Opportunity + Means = Killer"
			};
			if(hintcount>=maxhint){
			cout <<"\n[!][!]You already have choose enough hints!\n[!][!]No hints left!";
		}else{
			randomclues(a,10);		//		interanl member call
			hintcount++;	
	}
}
	void remaininghint(){			// reamaining hint call
		int remain= maxhint-hintcount;
		cout <<"\n\t\t\t\t\tRemaining Hints :"<<remain<<endl;
}
};

int main(){
	int choice;
	hint h;
    cout << "\t\t HINTS[!]\t\t\t(TOTAL HINTS: 3)\n";
	h.revealhint();
	h.remaininghint();
	return 0;
}