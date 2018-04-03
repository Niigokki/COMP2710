/*
  * Jacob "Morgan" Smith
  * jks0039
  * Project1.cpp
  * Compiled using g++
  * g++ -o Project1 Project1.cpp
  */

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

void player_phase_menu();
void search_for_change();
void read_papers();
void view_player();
void player_switch();
int main_menu();

struct Player{
	int overall_score;
	int intellegence;
	int time;
	int money;
	int steps_remaining;
	string name;
	bool is_alive;
};

Player* player;
string scoreArray[10];
string nameArray[10];

bool init_player() {
	player = new Player();
	player-> overall_score = 0;
	player-> intellegence = 8;
	player-> time = 8;
	player-> money = 8;
	player-> steps_remaining = 20;
	player-> is_alive = true;
	player-> name = "Morgan";
	cout << "Please input your character's name! ";
	cin >> player -> name;
}

int load_scores() {
	ifstream file("scores.dat");
	cout << "loading high scores..." << endl;
	if (file.is_open()) {
		for (int i = 0; i < 11; ++i) {
			file >> scoreArray[i];
			cout << scoreArray[i];
		}
	}
	else {
	cout << "Error: You seem to be missing the high score table.";
	}
}

int save_scores() {
	ofstream outfile("scores.dat");
	if (outfile.is_open()) {
	for (int i = 0; i < 11; ++i) {
		outfile << scoreArray[i];
	}
	}
}

void choose_encounter(){
	int encounter_chance = rand() % 120 + 1;
	player-> time--;
	cout <<"\nMoving forward and using some of your precious time, you find that...";
	if (encounter_chance < 11) {
 		cout << "\nClass is canceled for the day! Enjoy your free time!" << endl;
		player-> time + 3;
		player -> steps_remaining--;
	}
	else if (encounter_chance <=50 && encounter_chance >= 11) {
		cout << "\nYou encounter a Puzzle!" << endl;
		//TODO add call to puzzle generation method
		player -> steps_remaining--;	
	}
	else if (encounter_chance <=75 && encounter_chance >= 50) {
		cout << "\nYou encounter your 2710 Professor, Dr. Kuu! You gain insight from his knowledge, gained from years of research!";
		player -> intellegence++;
		player -> steps_remaining--;
		cout << "\nYou now have " << player -> intellegence << " insight" << endl;
		cout << player -> steps_remaining << " steps remain" << endl;
	}
	else if (encounter_chance <=100 && encounter_chance >= 75) {
		cout << "\nIt's time to grade some papers for COMP 2210! Losing time has never been so monontous" << endl;
		player -> time--;
		player -> money++;
		player -> steps_remaining--;
	}
	else if (encounter_chance <=120 && encounter_chance >= 100) {
		cout << "\nAttacked by the dreaded busy work assignment, you're left with not only less time, but also less insight." << endl;
		player -> intellegence--;
		player -> steps_remaining--;
	}
	player_phase_menu();
	
}

void puzzle() {
	int encounter_chance = rand() % 10;
	string player_answer;
	player -> time--;
	if (encounter_chance <= 11) {
		cout <<"What is the better text editor: Emacs or Vim?";
		cin >> player_answer;
		if (player_answer == "Vim" || player_answer == "vim" || player_answer == "vi") {
			cout << "Correct!\n You gain 5 insight and 5 time since you didn't waste any learning silly text editors!" << endl;
			player-> intellegence += 5;
			player-> time += 5;
		}
	}if (encounter_chance >= 11 && encounter_chance <= 21) {
		cout <<"What is the better text editor: Emacs or Vim?";
		cin >> player_answer;
		if (player_answer == "Vim" || player_answer == "vim" || player_answer == "vi") {
			cout << "Correct!\n You gain 5 insight and 5 time since you didn't waste any learning silly text editors!" << endl;
			player-> intellegence += 5;
			player-> time += 5;
		}
	}if (encounter_chance >= 21 && encounter_chance <= 31) {
		cout <<"What is the better text editor: Emacs or Vim?";
		cin >> player_answer;
		if (player_answer == "Vim" || player_answer == "vim" || player_answer == "vi") {
			cout << "Correct!\n You gain 5 insight and 5 time since you didn't waste any learning silly text editors!" << endl;
			player-> intellegence += 5;
			player-> time += 5;
		}
		else {
		cout <<"Incorrect!\n You lose 1 insight and 3 time learning emacs!";
		player -> intellegence -= 1;
		player -> time -= 3;
		}
	}if (encounter_chance >= 31 && encounter_chance <= 41) {
		cout <<"What is the better text editor: Emacs or Vim?";
		cin >> player_answer;
		if (player_answer == "Vim" || player_answer == "vim" || player_answer == "vi") {
			cout << "Correct!\n You gain 5 insight and 5 time since you didn't waste any learning silly text editors!" << endl;
			player-> intellegence += 5;
			player-> time += 5;
		}
	}if (encounter_chance >= 41 && encounter_chance <= 51) {
		cout <<"What is the better text editor: Emacs or Vim?";
		cin >> player_answer;
		if (player_answer == "Vim" || player_answer == "vim" || player_answer == "vi") {
			cout << "Correct!\n You gain 5 insight and 5 time since you didn't waste any learning silly text editors!" << endl;
			player-> intellegence += 5;
			player-> time += 5;
		}
	}if (encounter_chance >= 61 && encounter_chance <= 71) {
		cout <<"What is the better text editor: Emacs or Vim?";
		cin >> player_answer;
		if (player_answer == "Vim" || player_answer == "vim" || player_answer == "vi") {
			cout << "Correct!\n You gain 5 insight and 5 time since you didn't waste any learning silly text editors!" << endl;
			player-> intellegence += 5;
			player-> time += 5;
		}
	}if (encounter_chance >= 71 && encounter_chance <= 81) {
		cout <<"What is the better text editor: Emacs or Vim?";
		cin >> player_answer;
		if (player_answer == "Vim" || player_answer == "vim" || player_answer == "vi") {
			cout << "Correct!\n You gain 5 insight and 5 time since you didn't waste any learning silly text editors!" << endl;
			player-> intellegence += 5;
			player-> time += 5;
		}
	}if (encounter_chance >= 81 && encounter_chance <= 91) {
		cout <<"What is the better text editor: Emacs or Vim?";
		cin >> player_answer;
		if (player_answer == "Vim" || player_answer == "vim" || player_answer == "vi") {
			cout << "Correct!\n You gain 5 insight and 5 time since you didn't waste any learning silly text editors!" << endl;
			player-> intellegence += 5;
			player-> time += 5;
		}
	}if (encounter_chance >= 91 && encounter_chance <= 101) {
		cout <<"What is the better text editor: Emacs or Vim?";
		cin >> player_answer;
		if (player_answer == "Vim" || player_answer == "vim" || player_answer == "vi") {
			cout << "Correct!\n You gain 5 insight and 5 time since you didn't waste any learning silly text editors!" << endl;
			player-> intellegence += 5;
			player-> time += 5;
		}
	}
	else {
		cout << "ERR" << endl;
	}



}

void read_paper() {
	player -> time--;
	cout << "You decided to read some technical papers that Dr. Kuu gave you... You already feel enlightened!"<< endl;
	player -> intellegence++;
	cout << "You now have "<< player -> intellegence << " insight" << endl;
	player_phase_menu();
}
void search_for_change(){
	player -> time--;
	cout << "You search for change..., but not much turns up." << endl;
	player -> money++;
	cout << "You now have " << player -> money << " dolarydoos." << endl;
	player_phase_menu();
}

void view_player() {
	cout << "You have " << player-> intellegence << " insight" << endl;
	cout << "You also have " << player -> money << " dollarydoos" << endl;
       	cout << "Time is running short! You only have " << player->time << " nanohours left before the end of the day!" << endl;
	player_phase_menu();
}

void player_phase_menu() {
	char choice;
	if (player -> intellegence <= 0) {
		player -> is_alive = false;
		cout << "You have run out of insight " << player->name <<", I guess grad school isn't for everyone." << endl;
		cout << "GAME OVER" << endl;
		main_menu();
	}
	if (player -> money <=0) {
		player -> is_alive = false;
		cout << "You have run out of money " << player->name << ", I hope you don't mind moving back in with your parents" << endl;
		cout << "GAME OVER" << endl;
		main_menu();
	}
	if (player -> time <=0) {
		player -> is_alive = false;
		cout << "Deadlines got you down, " << player->name<< "?  Hope you don't mind being out of time!" << endl;
		cout << "GAME OVER" << endl;
		main_menu();
	}
	else {
	cout << "\nHello " << player-> name << endl;
	cout << "\nYou have " << player->steps_remaining << " steps between you and the end of the Shelby Center! " << endl;
	cout<< "What will you do now? " << endl;
	cout <<"\n1) Move toward the exit!";
	cout <<"\n2) Search for spare change!";
	cout <<"\n3) Read technical papers!";
	cout <<"\n4) View your stats!";
	cout <<"\n6) Testing command: exit game!";
	cout <<"\n\nPlease enter one of these numbers to continue. ";
	player_switch();
	}
	}

void player_switch() {
	char choice;
	cin >> choice;
	switch (choice){
	case ('1'):
	//TODO move
	choose_encounter();
	break;
	case ('2'):
	search_for_change();
	break;
	case ('3'):
	read_paper();
	break;
	case ('4'):
	view_player();
	case ('6'):
	exit(1);
	default:
	cout << "\nPlease enter a valid option to continue";
	player_switch();

}
}

int main_menu() {
	char choice;
	cout <<"\nWelcome to Shelby Center and Dragons!";
	cout <<"\n\n1) Start a new game of Shelby Center and Dragons!";
	cout <<"\n2) View the High Score Table!";
	cout <<"\n3) Exit to terminal";
	cout <<"\n\nPlease enter one of these numbers to continue. ";
	cin >> choice;
	switch (choice){
	case ('1'):
	//TODO init game
	init_player();
	player_phase_menu();
	break;
	case ('2'):
	//TODO display scores
	load_scores();
	break;
	case ('3'):
	exit(1);
	break;
	default:
	cout << "\nPlease enter a valid option to continue";
	main_menu();
	}
	}

//dummy code for now
int main() {
	main_menu();
	return 0;
}

