/*
 * Jacob Smith
 * jks0039
 * hw2.cpp
 * Compiled using g++
 * g++ -o hw2 hw2.cpp
 */
#include <iostream>
using namespace std;

int main() {

double loanAmount, interestRate, numPayments;
//the magic formula for formatting
cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	
	cout << "Loan Amount: ";
	cin >> loanAmount;
	cout << "Interest Rate (% per year): ";
	cin >> interestRate;
	cout << "Monthly Payments: ";
	cin >> numPayments;



	cout << "*********************************************************************";
	cout << "\n\tAmortization Table";
		cout << "\n*********************************************************************";



}
