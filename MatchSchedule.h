#ifndef MATCHSCHEDULE_H
#define MATCHSCHEDULE_H

#include <iostream>
#include <fstream>
#include <sstream>  //work with string 
#include <vector>
#include <string>
#include <iomanip>
#include <ctime>

using namespace std; 
class MatchSchedule {
private:
    int teamID1; 
    int teamID2; 
    int matchID; 
    string matchTime; 
    string stadiumName; 
    string referee; 

public:
    MatchSchedule(int tID1, int tID2, int mID,const string& matchTime , const string& sName, const string& ref);
    MatchSchedule(); // Constructor 

    // Get
    int getTeamID1() const;
    int getTeamID2() const;
    int getMatchID() const;
    string getMatchTime() const;
    string getStadiumName() const;
    string getReferee() const;
    
    // Load 
    static vector<MatchSchedule> loadMatchesFromFile(const string& filename);
    static void saveMatchSchedule(const string& filename, const vector<MatchSchedule>& matches);
    void notifyTimeMatch() const;
    // Display 

    void displayMatch() const;
};

#endif 
