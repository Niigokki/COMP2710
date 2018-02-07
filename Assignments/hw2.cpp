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

double loan_amount, interest_rate, monthly_payments, loan_balance, monthly_rate, loan_principal;
int months_paid;
//the magic formula for formatting
cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	
	cout << "Loan Amount: ";
	cin >> loan_amount;
	cout << "Interest Rate (% per year): ";
	cin >> interest_rate;
	cout << "Monthly Payments: ";
	cin >> monthly_payments;


	cout << "*********************************************************************";
	cout << "\n\tAmortization Table";
	cout << "\n*********************************************************************";
	//before we do any further calcs, we want to initalize our loan_balance and monthly rates
	loan_balance = loan_amount;
	monthly_rate = (interest_rate/12);
	double payment = (monthly_rate * loan_amount);
	//and setup table headers
	cout << "\nMonth\tBalance\t\tPayment\tRate\tInterest\tPrincipal";
	cout << "\n" << months_paid << "\t" << loan_balance << "\t\t" << monthly_payments << "\t" << monthly_rate << "\t" << payment << "\t\t" << loan_amount;
	/*while (loan_balance > 0) {
		
		months_paid++;
		//interest = principal * rate * time
		loan_balance - loan_balance - 500;
	}*/


}
