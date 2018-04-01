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
	string name;
	bool is_alive;
};

Player* player;

bool init_player() {
	player = new Player();
	player-> overall_score = 0;
	player-> intellegence = 8;
	player-> time = 8;
	player-> money = 8;
	player-> is_alive = true;
	cout << "Please input your character's name! ";
	cin >> player -> name;
}
int load_scores() {
	ifstream file("scores.dat");
	if (file.is_open()) {
		string scoreArray[10];
		for (int i = 0; i < 11; ++i) {
			file >> scoreArray[i];
		}
	}
}

//dummy code for now
int main() {
	init_player();
	return 0;
}

