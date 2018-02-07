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

double amount_loan, interest_rate, monthly_payments;
//the magic formula for formatting
cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	
	cout << "Loan Amount: ";
	cin >> amount_loan;
	cout << "Interest Rate (% per year): ";
	cin >> interest_rate;
	cout << "Monthly Payments: ";
	cin >> monthly_payments;


	cout << "*********************************************************************";
	cout << "\n\tAmortization Table";
	cout << "\n*********************************************************************";



}
