/*
 * Jacob Smith
 * jks0039
 * hw2.cpp
 * Compiled using g++
 * consulted with classmate about test cases, since I wasn't sure if there was more to be done or not, it felt to simple lol
 * g++ -o hw3 hw3.cpp
 */

#include <iostream>
#include <cstdlib>
#include <cassert>
#include <ctime>

using namespace std;

//method stubs to be filled in

bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive) {
/* Input: A_alive indicates whether Aaron is alive */
/*        B_alive indicates whether Bob is alive */
/*        C_alive indicates whether Charlie is alive */
/* Return: true if at least two are alive */
/*         otherwise return false */

    if (A_alive && B_alive) {
        return true;
    }
    if (A_alive && C_alive) {
        return true;
    }
    if (B_alive && C_alive) {
        return true;
    } else {
        return false;
    }
}

void Aaron_shoots1(bool &B_alive, bool &C_alive) {

/* Strategy 1: Use call by reference
 * Input: B_alive indicates whether Bob alive or dead
 * 		 C_alive indicates whether Charlie is alive or dead
 * Return: Change B_alive into false if Bob is killed.
 * 		  Change C_alive into false if Charlie is killed.
 */
    int shooting_result = rand() % 10;
    assert(B_alive || C_alive);

    if (C_alive == true) {
        cout << "\t\tAaron is shooting at Charlie\n";
        if (shooting_result <= 33) {
            C_alive = false;
            cout << "\t\tCharlie is dead\n";
        } else {
            cout << "\t\tAaron misses\n";
        }
    } else if (B_alive == true) {
        cout << "\t\tAaron is shooting at Bob\n";
        if (shooting_result <= 33) {
            B_alive = false;
            cout << "\t\tBob is dead\n";
        } else {
            cout << "\t\tAaron misses\n";
        }
    }
}


void Bob_shoots(bool &A_alive, bool &C_alive) {
    /* Call by reference
 * Input: A_alive indicates if Aaron is alive or dead
 * 		 C_alive indicates if Charlie is alive or dead
 * Return: Change A_alive into false if Aaron is killed.
 * 		  Change C_alive into false if Charlie is killed.
 */
    int shooting_result = rand() % 10;
    assert(A_alive || C_alive);
    if (C_alive) {
        cout << "\t\tBob is shooting at Charlie\n";
        if (shooting_result <= 50) {
            cout << "\t\tCharlie is dead\n";
            C_alive = false;

        } else {
            cout << "\t\tBob misses\n";
        }
    } else if (A_alive) {
        cout << "\t\tBob is shooting at Aaron\n";
        if (shooting_result <= 50) {
            cout << "\t\tAaron is dead\n";
            A_alive = false;
        } else {
            cout << "\t\tBob misses\n";
        }
    }


}


void Charlie_shoots(bool &A_alive, bool &B_alive) {
    /* Call by reference
 * Input: A_alive indicates if Aaron is alive or dead
 *        B_alive indicates whether Bob is alive or dead
 * Return: Change A_alive into false if Aaron is killed.
 * 		  Change B_alive into false if Bob is killed.
 */
    assert(A_alive || B_alive);
    if (B_alive == true) {
        cout << "\t\tCharlie is shooting at Bob\n";
        B_alive = false;
        cout << "\t\tBob is dead\n";
    } else if (A_alive == true) {
        cout << "\t\tCharlie is shooting at Aaron\n";
        A_alive = false;
        cout << "\t\tAaron is dead\n";
    }
}


void Aaron_shoots2(bool &B_alive, bool &C_alive) {

/* Strategy 2: Use call by reference
 * Input: B_alive indicates whether Bob is alive or dead
 * 		 C_alive indicates whether Charlie is alive or dead
 * Return: Change B_alive into false if Bob is killed.
 * 		  Change C_alive into false if Charlie is killed.
 */
    int i = 0;
    int shooting_result = rand() % 10;
    assert(B_alive || C_alive);
    if (B_alive && C_alive && i < 1) {
        cout << "\t\tAaron intentionally misses his first shot\n";
        cout << "\t\tBoth Bob and Charlie are alive.\n";
        i++;
    } else if (B_alive) {
        cout << "\t\tAaron is shooting at Bob\n";
        if (shooting_result <= 33) {
            cout << "\t\tBob is dead\n";
            B_alive = false;
        } else {
            cout << "\t\tAaron misses\n";
        }
    } else if (C_alive) {
        cout << "\t\tAaron is shooting at Charlie\n";
        if (shooting_result <= 33) {
            cout << "\t\tCharlie is dead\n";
            C_alive = false;
        } else {
            cout << "\t\tAaron misses\n";
        }
    }

}

void test_at_least_two_alive(void) {

/* This is a test driver for at_least_two_alive() */
    cout << "Unit Testing 1: Function - at_least_two_alive()\n";
    cout << "\tCase 1: Aaron alive, Bob alive, Charlie alive\n";
    assert(at_least_two_alive(true, true, true));
    cout << "\tCase passed ...\n";
    cout << "\tCase 2: Aaron dead, Bob alive, Charlie alive\n";
    assert(at_least_two_alive(false, true, true));
    cout << "\tCase passed ...\n";
    cout << "\tCase 3: Aaron alive, Bob dead, Charlie alive\n";
    assert(at_least_two_alive(true, false, true));
    cout << "\tCase passed ...\n";
    cout << "\tCase 4: Aaron alive, Bob alive, Charlie dead\n";
    assert(at_least_two_alive(true, true, false));
    cout << "\tCase passed ...\n";
    cout << "\tCase 5: Aaron dead, Bob dead, Charlie dead\n";
    assert(!at_least_two_alive(false, false, true));
    cout << "\tCase passed ...\n";
    cout << "\tCase 6: Aaron dead, Bob alive, Charlie dead\n";
    assert(!at_least_two_alive(false, true, false));
    cout << "\tCase passed ...\n";
    cout << "\tCase 7: Aaron alive, Bob dead, Charlie dead\n";
    assert(!at_least_two_alive(true, false, false));
    cout << "\tCase passed ...\n";
    cout << "\tCase 8: Aaron dead, Bob dead, Charlie dead\n";
    assert(!at_least_two_alive(false, false, false));
    cout << "\tCase passed ...\n";
}

void test_Aaron_shoots1(void) {

/* This is a test driver for Aaron_shoots1() */
    cout << "Unit Testing 2: Function Aaron_shoots1(Bob_alive, Charlie_alive)\n";
    bool bb_alive, cc_alive = true;

    cout << "\tCase 1: Bob alive, Charlie alive\n";
    Aaron_shoots1(bb_alive, cc_alive);

    cout << "\tCase 2: Bob dead, Charlie alive\n";
    bb_alive = false;
    cc_alive = true;
    Aaron_shoots1(bb_alive, cc_alive);

    cout << "\tCase 3: Bob alive, Charlie dead\n";
    bb_alive = true;
    cc_alive = false;
    Aaron_shoots1(bb_alive, cc_alive);

}

void test_Bob_shoots(void) {
/* This is a test driver for Bob_shoots() */

    cout << "Unit Testing 3: Function Bob_shoots(Aaron_alive, Charlie_alive)\n";
    bool aa_alive, cc_alive = true;

    cout << "\tCase 1: Aaron alive, Charlie alive\n";
    Bob_shoots(aa_alive, cc_alive);

    cout << "\tCase 2: Aaron dead, Charlie alive\n";
    cc_alive = true;
    aa_alive = false;
    Bob_shoots(aa_alive, cc_alive);

    cout << "\tCase 3: Aaron alive, Charlie dead\n";
    aa_alive = true;
    cc_alive = false;
    Bob_shoots(aa_alive, cc_alive);

}


void test_Charlie_shoots(void) {
    cout << "Unit Testing 4: Function Charlie_shoots(Aaron_alive, Bob_alive)\n";
    bool aa_alive, bb_alive = true;

    cout << "\tCase 1: Aaron alive, Charlie alive\n";
    Charlie_shoots(aa_alive, bb_alive);

    cout << "\tCase 2: Aaron dead, Charlie alive\n";
    bb_alive = true;
    aa_alive = false;
    Charlie_shoots(aa_alive, bb_alive);

    cout << "\tCase 3: Aaron alive, Charlie dead\n";
    aa_alive = true;
    bb_alive = false;
    Charlie_shoots(aa_alive, bb_alive);
}

/* This is a test driver for Charlie_shoots() */

void test_Aaron_shoots2(void) {
    cout << "Unit Testing 5: Function Aaron_shoots2(Bob_alive, Charlie_alive)\n";
    bool bb_alive, cc_alive = true;

    cout << "\tCase 1: Bob alive, Charlie alive\n";
    Aaron_shoots2(bb_alive, cc_alive);

    cout << "\tCase 2: Bob dead, Charlie alive\n";
    bb_alive = false;
    cc_alive = true;
    Aaron_shoots2(bb_alive, cc_alive);

    cout << "\tCase 3: Bob alive, Charlie dead\n";
    bb_alive = true;
    cc_alive = false;
    Aaron_shoots2(bb_alive, cc_alive);
}

/* This is a test driver for Aaron_shoots2() */


int main() {
    srand(time(0));
    srand(time(0));
    const int run_count = 10000;
    const int aaron_rate = 33;
    const int bob_rate = 50;
    const int charlie_rate = 1;
    int aa_wins_s1, bb_wins_s1, cc_wins_s1, aa_wins_s2, bb_wins_s2, cc_wins_s2 = 0;

    cout << "***Welcome to Jacob's Duel Simulator***\n";

    test_at_least_two_alive();
    cout << "Press any key to continue...";
    cin.ignore().get();

    test_Aaron_shoots1();
    cout << "Press any key to continue...";
    cin.ignore().get();

    test_Bob_shoots();
    cout << "Press any key to continue...";
    cin.ignore().get();

    test_Charlie_shoots();
    cout << "Press any key to continue...";
    cin.ignore().get();

    test_Aaron_shoots2();
    cout << "Press any key to continue...";
    cin.ignore().get();

    //Strategy 1
    cout << "Ready to test strategy 1 (run 10000 times):\n";
    cout << "press any key to continue...";
    cin.ignore().get();
    //loop testing
    aa_wins_s1 = 0;
    bb_wins_s1 = 0;
    cc_wins_s1 = 0;
    for (int i = 0; i < run_count; i++) {
        bool aaron_live = true;
        bool bob_live = true;
        bool charlie_live = true;

        while (at_least_two_alive(aaron_live, bob_live, charlie_live)) {
            if (aaron_live) {
                Aaron_shoots1(bob_live, charlie_live);
            }
            if (bob_live) {
                Bob_shoots(aaron_live, charlie_live);
            }
            if (charlie_live) {
                Charlie_shoots(aaron_live, bob_live);
            }
            cout << endl;


            if (aaron_live) {
                aa_wins_s1++;
            } else if (bob_live) {
                bb_wins_s1++;
            } else if (charlie_live) {
                cc_wins_s1++;
            }
        }
    }
    //results are stored and printed to terminal
    double Aaron_wins1 = aa_wins_s1 * 1.0 / run_count;
    double Bob_wins1 = bb_wins_s1 * 1.0 / run_count;
    double Charlie_wins1 = cc_wins_s1 * 1.0 / run_count;

    cout << "Aaron won " << aa_wins_s1 << "/10000 duels or " << Aaron_wins1 * 100 << "%\n";
    cout << "Bob won " << bb_wins_s1 << "/10000 duels or " << Bob_wins1 * 100 << "%\n";
    cout << "Charlie won " << cc_wins_s1 << "/10000 duels or " << Charlie_wins1 * 100 << "%\n\n";

    //Strat 2
    cout << "Ready to test strategy 2 (run 10000 times):\n";
    cout << "Press any key to continue...";
    cin.ignore().get();
    aa_wins_s2 = 0;
    bb_wins_s2 = 0;
    cc_wins_s2 = 0;
    for (int x = 0; x < run_count; x++) {
        bool aa_lives = true;
        bool bb_lives = true;
        bool cc_lives = true;

        while (at_least_two_alive(aa_lives, bb_lives, cc_lives)) {
            if (aa_lives) {
                Aaron_shoots2(bb_lives, cc_lives);
            }
            if (bb_lives) {
                Bob_shoots(aa_lives, cc_lives);
            }
            if (cc_lives) {
                Charlie_shoots(aa_lives, bb_lives);
            }
            cout << endl;
        }

        if (aa_lives) {
            aa_wins_s2++;
        } else if (bb_lives) {
            bb_wins_s2++;
        } else if (cc_lives) {
            cc_wins_s2++;
        }
    }

    double aa_win_total_s2 = aa_wins_s2 * 1.0 / run_count;
    double bb_win_total_s2 = bb_wins_s2 * 1.0 / run_count;
    double cc_win_total_s2 = cc_wins_s2 * 1.0 / run_count;

    cout << "Aaron won " << aa_wins_s2 << "/10000 duels or " << aa_win_total_s2 * 100 << "%\n";
    cout << "Bob won " << bb_wins_s2 << "/10000 duels or " << bb_win_total_s2 * 100 << "%\n";
    cout << "Charlie won " << cc_wins_s2 << "/10000 duels or " << cc_win_total_s2 * 100 << "%\n\n";

    if (aa_win_total_s2 > Aaron_wins1) {
        cout << "Strategy 2 is better than strategy 1.\n";
    } else {
        cout << "Strategy 1 is better than strategy 2.\n";
    }

    return 0;
}


