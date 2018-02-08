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

    double total_loan, interest_paid, interest, interest_rate, monthly_cost, loan_balance, monthly_rate, loan_principal;
    int months_paid = 0;
    //the magic formula for formatting
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    cout << "Loan Amount: ";
    cin >> total_loan;
    cout << "Interest Rate (% per year): ";
    cin >> interest_rate;
    cout << "Monthly Payments: ";
    cin >> monthly_cost;


    cout << "*********************************************************************" << "\n\tAmortization Table" << "\n*********************************************************************";
    //before we do any further calcs, we want to initalize our loan_balance and monthly rates
    loan_balance = total_loan;
    monthly_rate = (interest_rate / 12);
    //and setup table headers
    cout << "\nMonth\tBalance\t\tPayment\tRate\tInterest\tPrincipal";
    //formatting sucks this way : TODO find better way to handle this
    cout << "\n" << months_paid << "\t$" << loan_balance << "\tN/A\tN/A\tN/A\t\tN/A";

    if (monthly_cost <= ((interest_rate / 12) * total_loan) / 100) {
        cout << "\nRegular payments must be larger than monthly interest\n";
        return 0;
    }
    while (loan_balance > 0) {
        //calculate interest for the month,divided by 100 to get a decimal
        interest = ((loan_balance * monthly_rate) / 100);
        //calculate principal removed after interest
        loan_principal = monthly_cost - interest;
        //calculate balance after removing these things
        loan_balance = loan_balance - loan_principal;
        interest_paid += interest;
        ++months_paid;

        if (loan_balance <= 0) {
            loan_principal = loan_balance + loan_principal;
            monthly_cost = loan_principal + interest;
            loan_balance = 0;
        }

        cout << "\n" << months_paid << "\t$" << loan_balance << "\t\t$" << monthly_cost << "\t$" << interest_rate
             << "\t$" << interest << "\t\t$" << loan_principal;
    }

    cout << "\n*********************************************************************" << "\n\nIt takes " << months_paid
         << " months to pay off the loan." << "\nTotal interest paid is: $" << interest_paid << "\n";
    return 0;


}
