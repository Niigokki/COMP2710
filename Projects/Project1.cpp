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
#include <assert.h>
#include <cassert>

using namespace std;

int player_phase_menu();

void search_for_change();

void read_papers();

void view_player();

int player_switch();

int main_menu();

void puzzle();

int save_scores();

int load_scores();

struct Player {
    int overall_score;
    int intellegence;
    int time;
    int money;
    int steps_remaining;
    string name;
    bool is_alive;
};

Player *player;
int scoreArray[4];
string nameArray[4];


bool init_player() {
    player = new Player();
    player->overall_score = 0;
    player->intellegence = 8;
    player->time = 8;
    player->money = 8;
    player->steps_remaining = 20;
    player->is_alive = true;
    player->name = "Morgan_Tester";
    cout << "Please input your character's name! ";
    cin >> player->name;
}
bool test_player() {
    player = new Player();
    player->overall_score = 0;
    player->intellegence = 8;
    player->time = 8;
    player->money = 8;
    player->steps_remaining = 20;
    player->is_alive = true;
    player->name = "Morgan_Tester";
}
void init_scores() {
    string name1 = "\nMorgan";
    nameArray[0] = name1;
    int score1 = 100;
    scoreArray[0] = score1;
    string name2 = "\nMorgan";
    nameArray[1] = name2;
    int score2 = 60;
    scoreArray[1] = score2;
    string name3 = "\nMisato";
    nameArray[2] = name3;
    int score3 = 40;
    scoreArray[2] = score3;
    string name4 = "\nKaji";
    nameArray[3] = name4;
    int score4 = 20;
    scoreArray[3] = score4;
    string name5 = "\nRei";
    nameArray[4] = name5;
    int score5 = 0;
    scoreArray[4] = score5;

}

void add_highscores(int score) {

    ofstream outputFile("highscores.txt");
    outputFile.open("highscores.txt");
    outputFile << score << " " << endl;
    outputFile.close();

    ifstream InputFile("highscores.txt");
    if (InputFile.is_open()) {
        int score;
        InputFile >> score;
        cout << "Score: " << score;
        InputFile.close();
    }

}

void sort_scores(int score) {
    if (score > scoreArray[0]) {
        nameArray[0] = player->name;
        scoreArray[0] = score;
    }

    if (score > scoreArray[1]) {
        nameArray[1] = player->name;
        scoreArray[1] = score;
    }

    if (score > scoreArray[2]) {
        nameArray[2] = player->name;
        scoreArray[2] = score;
    }

    if (score > scoreArray[3]) {
        nameArray[3] = player->name;
        scoreArray[3] = score;
    }

    if (score > scoreArray[4]) {
        nameArray[4] = player->name;
        scoreArray[4] = score;
    }

}

void view_highscores() {
    ifstream inFile;

    inFile.open("highscores.txt");
    if (!inFile) {
        cout << "Unable to find scores! Generating preset scores..." << endl;
        init_scores();

    }
    //cout << inFile;
    inFile.close();
//    cout << nameArray[0] << "\t\t" << scoreArray[0] << "\n" << endl;
    cout << "\n---------------------------";
    cout << nameArray[1] << "\t\t" << scoreArray[1] << "\n" << endl;
    cout << "\n---------------------------";
    cout << nameArray[2] << "\t\t" << scoreArray[2] << "\n" << endl;
    cout << "\n---------------------------";
    cout << nameArray[3] << "\t\t" << scoreArray[3] << "\n" << endl;
    cout << "\n---------------------------";
    cout << nameArray[4] << "\t\t" << scoreArray[4] << "\n" << endl;
    main_menu();


}

int save_scores() {
    ofstream outStream;

    sort_scores(player->overall_score);

    outStream.open("highscores.txt");

    for (int i = 0; i < 4; i++) {
        outStream << nameArray[i] << "   " << scoreArray[i] << "\n";
    }

    outStream.close();
    return 0;
}
int load_scores() {
    ifstream inStream;
    int numScores = 0;
    string line;

    inStream.open("highscores.txt");

    if (inStream.fail()) {
        cout << "\nERROR: highscores.txt not found!  Please download highscores.txt!" << endl;
        init_scores();
        return 0;
    }

    while (getline(inStream, line)) {
        numScores++;
        cout << "\t" << numScores << ". " << line << "\n";
    }

    for (int i = 0; i < 4; i++) {
        inStream >> nameArray[i] >> scoreArray[i];
    }

    inStream.close();
    return 0;
}

void choose_encounter() {
    int encounter_chance = rand() % 120 + 1;
    player->time--;
    cout << "\nMoving forward and using some of your precious time, you find that...";
    if (encounter_chance < 11) {
        cout << "\nClass is canceled for the day! Enjoy your free time!" << endl;
        player->time + 3;
        player->steps_remaining--;
    } else if (encounter_chance <= 50 && encounter_chance >= 11) {
        cout << "\nYou encounter a Puzzle!" << endl;
        puzzle();
        player->steps_remaining--;
    } else if (encounter_chance <= 75 && encounter_chance >= 50) {
        cout
                << "\nYou encounter your 2710 Professor, Dr. Kuu! You gain insight from his knowledge, gained from years of research!";
        player->intellegence++;
        player->steps_remaining--;
        cout << "\nYou now have " << player->intellegence << " insight" << endl;
        cout << player->steps_remaining << " steps remain" << endl;
    } else if (encounter_chance <= 100 && encounter_chance >= 75) {
        cout << "\nIt's time to grade some papers for COMP 2210! Losing time has never been so monontous" << endl;
        player->time--;
        player->money++;
        player->steps_remaining--;
    } else if (encounter_chance <= 120 && encounter_chance >= 100) {
        cout
                << "\nAttacked by the dreaded busy work assignment, you're left with not only less time, but also less insight."
                << endl;
        player->intellegence--;
        player->steps_remaining--;
    }
    player_phase_menu();

}

void puzzle() {
    int encounter_chance = rand() % 50 + 1;
    string player_answer;
    player->time--;
    if (encounter_chance <= 11) {
        cout << "What is the better text editor: Emacs or Vim?";
        cin >> player_answer;
        if (player_answer == "Vim" || player_answer == "vim" || player_answer == "vi") {
            cout << "Correct!\nYou gain 5 insight and 5 time since you didn't waste any learning silly text editors!"
                 << endl;
            player->intellegence += 5;
            player->time += 5;
        } else {
            cout << "Incorrect, you lose more time and insight" << endl;
            player->intellegence - 1;
            player->time--;
        }
    }
    if (encounter_chance >= 11 && encounter_chance <= 21) {
        cout << "What is the better Programming language, C++ or Java?";
        cin >> player_answer;
        if (player_answer == "c++" || player_answer == "C++") {
            cout << "Correct!\n You gain 2 insight and two time" << endl;
            player->intellegence += 2;
            player->time += 2;
        } else {
            cout << "C++ is clearly the better language, so you lose 1 insight" << endl;
            player->intellegence--;
            player->time--;
        }
    }
    if (encounter_chance >= 21 && encounter_chance <= 31) {
        cout << "Who is the best character out of these three? Rei, Misato, or Asuka? ";
        cin >> player_answer;
        if (player_answer == "misato" || player_answer == "Misato") {
            cout << "Correct!\n You gain 5 insight and 5 time for being a person of culture as well!" << endl;
            player->intellegence += 5;
            player->time += 5;
        }
        if (player_answer == "Asuka" || player_answer == "asuka") {
            cout << "Correct!\n You gain 5 insight and 5 time for being a person of culture as well!" << endl;
            player->intellegence += 5;
            player->time += 5;
        } else {
            cout << "Incorrect!\n You lose 1 insight and 3 trying to explain yourself!";
            player->intellegence -= 1;
            player->time -= 3;
        }
    }
    if (encounter_chance >= 31 && encounter_chance <= 41) {
        cout << "Is this game fun or nah?";
        cin >> player_answer;
        if (player_answer == "Yes" || player_answer == "yes" || player_answer == "y") {
            cout << "I was hoping it would be after so much time spent on it\n Here, have 1 insight and 2 time. "
                 << endl;
            player->intellegence += 1;
            player->time += 2;
        } else {
            cout << "I was hoping it would be after so much time spent on it, but I guess not\nHere, have 1 insight and 2 time for being honest. "
                 << endl;
            player->intellegence += 1;
            player->time += 2;
        }
    }
    if (encounter_chance >= 41 && encounter_chance <= 51) {
        cout << "Is Astolfo best girl or what?";
        cin >> player_answer;
        if (player_answer == "Yes" || player_answer == "yes" || player_answer == "y" || player_answer == "Y") {
            cout << "Correct!\n You gain 10 insight and 10 time for properly identifying best girl" << endl;
            player->intellegence += 10;
            player->time += 10;
        } else {
            cout << "Depressingly incorrect answer, " << player->name;
            cout << "You lose 1  insight and time.";
            player->intellegence--;
            player->time--;
        }
    }
}

void read_paper() {
    player->time--;
    cout << "You decided to read some technical papers that Dr. Kuu gave you... You already feel enlightened!" << endl;
    player->intellegence++;
    cout << "You now have " << player->intellegence << " insight" << endl;
    player_phase_menu();
}

void search_for_change() {
    player->time--;
    cout << "You search for change..., but not much turns up." << endl;
    player->money++;
    cout << "You now have " << player->money << " dolarydoos." << endl;
    player_phase_menu();
}

void view_player() {
    cout << "You have " << player->intellegence << " insight" << endl;
    cout << "You also have " << player->money << " dollarydoos" << endl;
    cout << "Time is running short! You only have " << player->time << " nanohours left before the end of the day!"
         << endl;
    player_phase_menu();
}

int player_phase_menu() {
    char choice;
    if (player->is_alive = false) {
        cout << "How have you managed to die in a way that I didn't account for, " << player->name << "...";
        main_menu();
    }
    if (player->intellegence <= 0) {
        player->is_alive = false;
        cout << "You have run out of insight " << player->name << ", I guess grad school isn't for everyone." << endl;
        cout << "GAME OVER" << endl;
        if (player->name == "Morgan_Tester") {
            return 0;
        }
        if (player->name != "Morgan_Tester") {
            main_menu();
        }
    }
    if (player->money <= 0) {
        player->is_alive = false;
        cout << "You have run out of money " << player->name
             << ", I hope you don't mind moving back in with your parents" << endl;
        cout << "GAME OVER" << endl;
        main_menu();
    }
    if (player->time <= 0) {
        player->is_alive = false;
        cout << "Deadlines got you down, " << player->name << "?  Hope you don't mind being out of time!" << endl;
        cout << "GAME OVER" << endl;
        main_menu();
    }
    if (player->steps_remaining <= 0) {
        player->overall_score = player->intellegence * player->money* player->time;
        cout << "\nWow! You win! Are you sure you didn't cheat?\n";
        cout << "Score: " << player->overall_score << " \n";
        scoreArray[4] = player->overall_score;
        nameArray[4] = player->name;
        add_highscores(player->overall_score);
        sort_scores(player->overall_score);
        save_scores();
        main_menu();
    } else {
        cout << "\nHello " << player->name << endl;
        cout << "\nYou have " << player->steps_remaining << " steps between you and the end of the Shelby Center! "
             << endl;
        cout << "What will you do now? " << endl;
        cout << "\n1) Move toward the exit!";
        cout << "\n2) Search for spare change!";
        cout << "\n3) Read technical papers!";
        cout << "\n4) View your stats!";
        cout << "\n6) Testing command: exit game!";
        cout << "\n\nPlease enter one of these numbers to continue. ";
        player_switch();
    }
}

int player_switch() {
    char choice;
    cin >> choice;
    switch (choice) {
        case ('1'):
            choose_encounter();
            return 0;
            break;
        case ('2'):
            search_for_change();
            return 0;
            break;
        case ('3'):
            read_paper();
            return 0;
            break;
        case ('4'):
            view_player();
            return 0;
        case ('6'):
            return 0;
        default:
            cout << "\nPlease enter a valid option to continue";
            player_switch();
    }
}


void test_name_entry() {
    cout << "Testing name input...." << endl;
    init_player();
    assert(player->name!= "Morgan_Tester");
    cout << "Test Passed..." << endl;

}

void test_game() {
    cout << "Testing search for change menu... please select that option then exit the game..." << endl;
    test_player();
    player_phase_menu();
    assert(player->time != 8);
    assert(player->money != 8);
    cout << "Test Passed..." << endl;
    cout << "Testing read papers... please select that option then exit the game..." << endl;
    test_player();
    player_phase_menu();
    assert(player->intellegence != 8);
    assert(player->time != 8);
    cout << "Test Passed..." << endl;
    cout << "Testing encounters... if this exits to the ingame menu please exit it..." << endl;
    test_player();
    choose_encounter();
    assert(player->name!= "Morgan");
    assert(player->steps_remaining!= 20);
    cout << "Test Passed..." << endl;
    cout << "Testing puzzles..." << endl;
    test_player();
    puzzle();
    assert(player->name!= "Morgan");
    assert(player->time!= 8);
    assert(player->intellegence!= 8);
    cout << "Test Passed..." << endl;
    cout << "Testing death... this should display a message then kick you to the main menu, please exit it"  << endl;
    test_player();
    player->intellegence = 0;
    player_phase_menu();
    assert(player->is_alive == false);
    cout << "Test Passed..." << endl;
    cout << "All game tests passed.." << endl;

    cout << "Testing initscores" << endl;
    init_scores();
    assert(nameArray[1] == "Morgan");
    assert(scoreArray[1] == "100");
    cout << "Test passed...." << endl;
    main_menu();
}

int main_menu() {
    char choice;
    cout << "\nWelcome to Shelby Center and Dragons!";
    cout << "\n\n1) Start a new game of Shelby Center and Dragons!";
    cout << "\n2) View the High Score Table!";
    cout << "\n3) Exit to terminal";
    cout << "\n4) Run testing";
    cout << "\n\nPlease enter one of these numbers to continue. ";
    cin >> choice;
    switch (choice) {
        case ('1'):
            init_player();
            player_phase_menu();
            break;
        case ('2'):
            view_highscores();
            break;
        case ('3'):
            exit(1);
        case '4':
            test_name_entry();
            test_game();
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


