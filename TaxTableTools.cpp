#pragma once
#include <iostream>
#include <vector>
#include <limits>
#include "TaxTableTools.h"
using namespace std;


TaxTableTools::TaxTableTools() {
    search.push_back(0);
    search.push_back(20000);
    search.push_back(50000);
    search.push_back(100000);
    search.push_back(numeric_limits<int>::max());
    value.push_back(0.0);
    value.push_back(0.10);
    value.push_back(0.20);
    value.push_back(0.30);
    value.push_back(0.40);
    nEntries = search.size();  
}


double TaxTableTools::GetValue(int searchArgument) {
    double result;
    bool keepLooking;
    int i;

    i = 0;
    keepLooking = true;

    while ((i < nEntries) && keepLooking) {
        if (searchArgument <= search.at(i)) {
            result = value[i];
            keepLooking = false;
        }
        else {
            ++i;
        }
    }

    return result;
}


void TaxTableTools::SetTables(vector<int> newSearch, vector<double> newValue) {
    int i;

    nEntries = newSearch.size();       
    search.resize(nEntries);            
    value.resize(nEntries);

    for (i = 0; i < nEntries; ++i) {     
        search.at(i) = newSearch.at(i);
        value.at(i) = newValue.at(i);
    }
}
