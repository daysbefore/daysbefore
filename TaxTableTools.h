#pragma once
#include <iostream>
#include <vector>
using namespace std;

class TaxTableTools {
public:
    TaxTableTools();
    double GetValue(int searchArgument);
    void SetTables(vector<int> newSearch, vector<double> newValue);
private:
    vector<int> search;
    vector<double> value;
    int nEntries;
};