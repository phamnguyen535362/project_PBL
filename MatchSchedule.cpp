#include "MatchSchedule.h"
#include <iomanip>
#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <chrono>

using namespace std;

// Constructor
MatchSchedule::MatchSchedule(int tID1, int tID2, int mID, const string& mTime, const string& sName, const string& ref)
    : teamID1(tID1), teamID2(tID2), matchID(mID), matchTime(mTime), stadiumName(sName), referee(ref)
	 {}

// Default constructor
MatchSchedule::MatchSchedule() 
: teamID1(0), teamID2(0), matchID(0), matchTime(""), stadiumName(""), referee("")
 {}

// Get
int MatchSchedule::getTeamID1() const { return teamID1; }
int MatchSchedule::getTeamID2() const { return teamID2; }
int MatchSchedule::getMatchID() const { return matchID; }
string MatchSchedule::getMatchTime() const { return matchTime; }
string MatchSchedule::getStadiumName() const { return stadiumName; }
string MatchSchedule::getReferee() const { return referee; }

// Load 
vector<MatchSchedule> MatchSchedule::loadMatchesFromFile(const string& filename) {
    ifstream file(filename);
    vector<MatchSchedule> matches;
    string line;
if (!file.is_open()) {
            cerr << "Loi: Khong the mo tep." << endl;
            return matches;
        }
        while (getline(file, line)) {
            istringstream iss(line);
            int mID, tID1, tID2;
            string stadium, referee, dateTimeStr;
            if (getline(iss, dateTimeStr, '|') && 
                (iss >> tID1) && 
                (iss.ignore()) && 
                (iss >> tID2) && 
                (iss.ignore()) && 
                (iss >> mID) && 
                (iss.ignore()) && 
                getline(iss, stadium, '|') && 
                getline(iss, referee)) {
                matches.emplace_back(tID1, tID2, mID, dateTimeStr, stadium, referee);
            } else {
                cerr << "Loi: Dinh dang du lieu khong hop le trong dong: " << line << endl;
            }
        }
        file.close();
        return matches;
    }

// Save
void MatchSchedule::saveMatchSchedule(const string& filename, const vector<MatchSchedule>& matches) 
{
    ofstream file(filename, ios::app);
    if (!file.is_open()) { 
        cerr << "Error: Unable to open file for writing." << endl;
        return;  
    }
    for (const auto& match : matches) {
        file << match.matchTime << "|"        
             << match.teamID1 << "|"
             << match.teamID2 << "|"
             << match.matchID << "|"
             << match.stadiumName << "|"     
             << match.referee << "\n";
    }
    file.close();
}


// Display 
void MatchSchedule::displayMatch() const {
    cout << "---------------------------------\n"
         << "Match Details:\n"
         << "Match ID     : " << matchID << "\n"
         << "Teams        : " << teamID1 << " vs " << teamID2 << "\n"
         << "Date & Time  : " << matchTime << "\n"
         << "Stadium      : " << stadiumName << "\n"
         << "Referee      : " << referee << "\n"
         << "---------------------------------\n";
}
void MatchSchedule::notifyTimeMatch() const {
    using namespace std::chrono;
    system_clock::time_point now = system_clock::now();

    // Parse matchTime (string) to tm structure
    int year, month, day, hour, minute;
    sscanf(matchTime.c_str(), "%d-%d-%d %d:%d", &year, &month, &day, &hour, &minute);

    tm match_tm = {};
    match_tm.tm_year = year - 1900;
    match_tm.tm_mon = month - 1;
    match_tm.tm_mday = day;
    match_tm.tm_hour = hour;
    match_tm.tm_min = minute;
    match_tm.tm_sec = 0;

    time_t match_time_t = mktime(&match_tm);
    if (match_time_t == -1) {
        cout << "Invalid match time format." << endl;
        return;
    }

    system_clock::time_point match_time_point = system_clock::from_time_t(match_time_t);

    // Calculate the time difference
    auto duration = duration_cast<seconds>(match_time_point - now);

    if (duration.count() < 0) {
        cout << "The match has already started or passed!" << endl;
        return;
    }

    // Calculate days, hours, and minutes remaining
    int daysLeft = duration.count() / (60 * 60 * 24);
    int hoursLeft = (duration.count() % (60 * 60 * 24)) / (60 * 60);
    int minutesLeft = (duration.count() % (60 * 60)) / 60;

    // Display time remaining
    cout << "Time remaining until match: "
         << daysLeft << " days, "
         << hoursLeft << " hours, "
         << minutesLeft << " minutes." << endl;
}
