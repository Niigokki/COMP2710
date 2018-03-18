 /*
  * Jacob Smith
  * jks0039
  * hw5.cpp
  * as always, method stubs taken from PDF.
  * Compiled using g++
  * g++ -o hw5 hw5.cpp
  */

#include <iostream>
#include <string>

using namespace std;
#define UNIT_TESTING
//our data structure
struct TriviaNode{
	string question;
	string answer;
	int point_value;
	TriviaNode *next;
};

//list initalizer
class TriviaList{
	//using the public keyword here makes all of these vars public.
	public:
	int count = 0;
	TriviaNode *first, *current;
	TriviaList() {
		first = NULL;
		current = NULL;
	}
};

//init a list with our hardcoded questions
void initList(TriviaList &someList) {
	TriviaNode *q1 = new TriviaNode, *q2 = new TriviaNode, *q3 = new TriviaNode;
	q1 -> question =  "How long was the shortest war on record? (Hint: how many minutes)";
	q1 -> answer = "38";
	q1 -> point_value = 100;
	q1 -> next = q2;

	q2 -> question =  "What was Bank of America's original name? (Hint: Bank of Italy or Bank of Germany)";
	q2 -> answer = "Bank of Italy";
	q2 -> point_value = 50;
	q2 -> next = q3;
	q3 -> question =  "What is the best-selling video game of all time? (Hint: Minecraft or Tetris)";
	q3 -> answer = "Tetris";
	q3 -> point_value = 20;
	q3 -> next = NULL;

	someList.first = q1;
	someList.current = q3;
	someList.count += 3;
}
//create a question based on user input and add it to the prexisting list
//using getline to clear input
void addQuestion(TriviaList &someList) {
	TriviaNode *newNode = new TriviaNode;
	TriviaNode *endNode = someList.first;
while (endNode != NULL && endNode->next != NULL)
	{
		endNode = endNode->next;
}
	if (newNode == NULL) {
	exit(1);
	}
	cout << "Enter a question: ";
        getline(cin, newNode -> question);
	cout << "Enter an answer: ";
	getline(cin, newNode -> answer);
	cout << "Enter award points: ";
	cin >> newNode -> point_value;
	cin.get();
	if (endNode == NULL) {
		someList.first = newNode;
	}
	else {
		endNode -> next = newNode;
	}
	someList.count++;

}

int askQuestion(TriviaList trivia, int i) {
	TriviaNode *currentNode = trivia.first;

	if (i == 0) {
	 cout << "\nWarning - The number of trivia to be asked must equal to or be larger than 1.";
	 return 0;
	}
	if (i > trivia.count) {
		cout << "\n Warning - There are only " << trivia.count << " trivia questions in the list";
		i = trivia.count;
	}
	string player_answer;
	int points = 0;
	for (int z = 0; z < i; z++) {
		cout << "\nQuestion: " << currentNode -> question << "\nAnswer: ";
		getline(cin,player_answer);
		if (currentNode -> answer == player_answer) {
			cout << "Correct! You recieve " << currentNode -> point_value << " points.";
		       points += currentNode -> point_value;	
		}
		else {
		cout << "Sorry, but your answer is incorrect.  The correct answer is : " << currentNode -> answer;
		}
		cout << "\nYour Point Total Is: " << points << endl;
		currentNode = currentNode -> next;
	}
	return 0;

}
//production code only right now
int main() {

	cout << "*** Welcome to Jacob's trivia quiz game ***" << endl;
	TriviaList game;
	string input;
	initList(game);
	bool addQuestions = true;
	do {
	addQuestion(game);
	cout << "Continue? (Yes/No)";
	cin >> input;
	//we have to flush the input here or the new line gets taken to the add question, skipping
	//the part where we actually set our question
	cin.ignore();
	if (input == "No" || input == "no" || input == "N" || input == "n") {
	addQuestions = false;
	}

	}
	while (addQuestions);
	
	askQuestion(game, game.count);
	cout << "\n..." << endl;

	cout <<"\n*** Thank you for playing the trivia quiz game.  Goodbye! ***" << endl;
	

return 0;
}
