#include "MatchResult.h"
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std; 

 // Constructor
MatchResult::MatchResult(int tID1, int tID2, int g1, int g2, int c1, int c2)
    : teamID1(tID1), teamID2(tID2), goalsTeam1(g1), goalsTeam2(g2), cardsTeam1(c1), cardsTeam2(c2)
 {}

// Get
int MatchResult::getTeamID1() const { return teamID1; }
int MatchResult::getTeamID2() const { return teamID2; }
int MatchResult::getGoalsTeam1() const { return goalsTeam1; }
int MatchResult::getGoalsTeam2() const { return goalsTeam2; }
int MatchResult::getCardsTeam1() const { return cardsTeam1; }
int MatchResult::getCardsTeam2() const { return cardsTeam2; }




//read
 vector<MatchResult> MatchResult::loadResultsFromFile(const string& filename)
 {
    ifstream file(filename);
    vector<MatchResult> results; //tao vector
    string line;

    if (file.is_open()) {
        while (getline(file, line)) {
            istringstream iss(line);
            int tID1, tID2, g1, g2, c1, c2;
            iss >> tID1;
            iss.ignore(); 
            iss >> tID2;
            iss.ignore();
            iss >> g1;
            iss.ignore();
            iss >> g2;
            iss.ignore();
            iss >> c1;
            iss.ignore();
            iss >> c2;
            results.emplace_back(tID1, tID2, g1, g2, c1, c2);
        }
        file.close();
    } else {
        cerr << "Error: Unable to open file for reading." << endl;
    }
    return results;
}
 

// Save 



