#include <iostream>
#include <array>
#include <vector>
#include <sstream>

using namespace std;

vector<vector<int>> reports;

bool is_valid(vector<int>& report) {
    if (report.size() < 2) {
        return true;
    }

    bool increasing = report[1] > report[0];
    int upper = (increasing)? 3: -1;
    int lower = (increasing)? 1: -3;

    for (int i = 1; i < report.size(); i++) {
        int diff = report[i] - report[i-1]; 
        if (diff > upper || diff < lower) {
            return false;
        }
    }
    return true;
}

bool is_valid_2(vector<int>& report) {
    if (report.size() < 3) {
        return true;
    }

    bool valid_unchanged = is_valid(report);
    if (valid_unchanged) {
        return true;
    }

    for (int skip = 0; skip < report.size(); skip++) {
        vector<int> new_report;
        for (int i = 0; i < report.size(); i++) {
            if (i != skip) {
                new_report.push_back(report[i]);
            }
        }
        if (is_valid(new_report)) {
            return true;
        }
    }
    
    return false;
}


int main() {
    string s;
    while (getline(cin, s)) {
        stringstream ss(s);
        vector<int> report;
        int x;
        while (ss >> x) {
            report.push_back(x);
        }
        reports.push_back(report);
    }

    int result1 = 0;
    for (vector<int>& report: reports) {
        if (is_valid(report)) {
            result1++;
        }
    }

    cout << "Part 1: " << result1 << endl;

    int result2 = 0;
    for (vector<int>& report: reports) {
        if (is_valid_2(report)) {
            result2++;
        }
    }

    cout << "Part 2: " << result2 << '\n';

    return 0;
}