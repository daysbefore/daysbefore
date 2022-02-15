#include <iostream>
#include <limits>
#include <vector>
#include <string>
#include "TaxTableTools.h"

int GetInteger(const string userPrompt) {
    int inputValue;

    cout << userPrompt << ": " << endl;
    cin >> inputValue;

    return inputValue;
}



int main() {
    const string PROMPT_SALARY = "\nEnter annual salary (-1 to exit)";
    int annualSalary;
    double taxRate;
    int taxToPay;
    vector<int> salaryBase(5);
    vector<double> taxBase(5);

    TaxTableTools table;

    salaryBase.at(0) = 0;
    salaryBase.at(1) = 20000;
    salaryBase.at(2) = 50000;
    salaryBase.at(3) = 100000;
    salaryBase.at(4) = numeric_limits<int>::max();

    taxBase.at(0) = 0.0;
    taxBase.at(1) = 0.10;
    taxBase.at(2) = 0.25;
    taxBase.at(3) = 0.40;
    taxBase.at(4) = 0.50;

    table.SetTables(salaryBase, taxBase);

    
    annualSalary = GetInteger(PROMPT_SALARY);

    while (annualSalary >= 0) {
        taxRate = table.GetValue(annualSalary);
        taxToPay = static_cast<int>(annualSalary * taxRate);   
        cout << "Annual Salary: " << annualSalary <<
            "\tTax rate: " << taxRate <<
            "\tTax to pay: " << taxToPay << endl;

        
        annualSalary = GetInteger(PROMPT_SALARY);
    }

    return 0;
}