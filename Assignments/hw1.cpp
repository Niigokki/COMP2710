//Jacob Smith
//jks0039
//just a simple program that takes input, and performs a few simple calculations
//hw1.cpp
//just use gcc/g++
//g++ -o hw1 hw1.cpp
#include <iostream>
using namespace std;

int main()
{
   const double percentageSweetner = .001;
   int mouseWeight, dieterWeight;
   double amountSweetner;
   cout << "What is the amount of artificial sweetner needed to kill a mouse?" << endl;
   cin >> amountSweetner;
   cout << "What is the weight of the mouse?" << endl;
   cin >> mouseWeight;
   cout << "What is the desired  weight of the dieter?" << endl;
   cin >> dieterWeight;
   double ratDeath = (amountSweetner / percentageSweetner) * mouseWeight;
   double dieterDeath = ratDeath * dieterWeight;
   cout << "You can drink " << dieterDeath << " sodas without dying as a result" << endl; 
   return 0;
      
}
