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
//our data structure
struct TriviaNode{
	string question;
	string answer;
	int point_value;
	TriviaNode *next;
};
//list initalizer
class TriviaList{
	int count = 0;
	TriviaNode *current, *original;
	TriviaList() {
		current = NULL;
		original = NULL;
	}
};
//init a list with our hardcoded questions
void initList(TriviaList &someList) {
	TriviaNode *q1 = new TriviaNode;
}



int main() {
return 0;
}
