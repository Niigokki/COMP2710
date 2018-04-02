/*
  * Jacob Smith
  * jks0039
  * Project1.cpp
  * as always, method stubs taken from PDF.
  * Compiled using g++
  * g++ -o Project1 Project1.cpp
  */

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

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

int choose_encounter(){
	int encounter_chance = rand() % 120 + 1;
	player-> time--;
	cout <<"\n Moving forward....";
	if (encounter_chance < 11) {
 		cout << "\nClass is canceled for the day! Enjoy your free time!";
		player-> time + 2;
		player -> steps_remaining--;
	}
	else if (encounter_chance <=50 && encounter_chance >= 11) {
		cout << "\nYou encounter a Puzzle!";
		//TODO add call to puzzle generation method
		player -> steps_remaining--;	
	}
	else if (encounter_chance <=75 && encounter_chance >= 50) {
		cout << "\nYou encounter your 2710 Professor, Dr. Kuu! You gain insight from his knowledge and research";
		player -> intellegence++;
		player -> steps_remaining--;
		cout << "\nYou now have " << player -> intellegence << " insight" << endl;
		cout << player -> steps_remaining << " steps remain" << endl;
	}
	else if (encounter_chance <=100 && encounter_chance >= 75) {
		cout << "\nIt's time to grade some papers for COMP 2210! Losing time has never been so monontous";
		player -> time--;
		player -> money++;
		player -> steps_remaining--;
	}
	else if (encounter_chance <=120 && encounter_chance >= 100) {
		cout << "\nAttacked by the dreaded busy work assignment, you're left with not only less time, but also less insight.";
		player -> intellegence--;
		player -> steps_remaining--;
	}

	return 0;
	
}
int read_paper() {
	player -> time--;
	cout << "You decided to read some technical papers that Dr. Kuu gave you... You already feel enlightened!"<< endl;
	player -> intellegence++;
	cout << "You now have "<< player -> intellegence << " insight" << endl;
}
int search_for_change(){
	player -> time--;
	cout << "You search for change..., but not much turns up." << endl;
	player -> money++;
	cout << "You now have " << player -> money << " dolarydoos." << endl;
}

int view_player() {
	cout << "Hello " << player-> name << endl;
	cout << "You have " << player-> intellegence << " insight" << endl;
	cout << "You also have " << player -> money << " dollarydoos" << endl;
       	cout << "Time is running short! You only have " << player->time << " nanohours left before the end of the day!" << endl;
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
	view_player();
	break;
	case ('2'):
	//TODO display scores
	load_scores();
	break;
	case ('3'):
	return 0;
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

