#include "Team.h"
#include <cctype>
using namespace std;
// Constructor
Team::Team(int teamID, const string& teamName, const string& captain, const string& coach, int numMembers)

    : teamID(teamID), teamName(teamName), captain(captain), coach(coach), numMembers(numMembers)
 {}

Team::Team() 
: teamID(0), numMembers(0), teamName(""), captain(""), coach("")
 {}

// Get
int Team::getTeamID() const { return teamID; }
string Team::getTeamName() const { return teamName; }
string Team::getCaptain() const { return captain; }
string Team::getCoach() const { return coach; }
int Team::getNumMembers() const { return numMembers; }

// Set
void Team::setTeamID(int teamID) { this->teamID = teamID; }
void Team::setTeamName(const string& teamName) { this->teamName = teamName; }
void Team::setCaptain(const string& captain) { this->captain = captain; }
void Team::setCoach(const string& coach) { this->coach = coach; }
void Team::setNumMembers(int numMembers) { this->numMembers = numMembers; }

// Load
vector<Team> Team::loadTeamsFromFile(const string& filePath) 
{
  ifstream file(filePath);  
    vector<Team> teams;       
    string line;

    if (!file.is_open()) {    
        cerr << "Error: Unable to open file for reading." << endl;
        return teams;         
    }
    while (getline(file, line)) {
        istringstream iss(line);
        string teamID_str, teamName, captain, coach, numMembers_str;
        getline(iss, teamID_str, '|');
        getline(iss, teamName, '|');
        getline(iss, captain, '|');
        getline(iss, coach, '|');
        getline(iss, numMembers_str, '|');

        int teamID = 0, numMembers = 0;
        try {
            teamID = stoi(teamID_str);  
            numMembers = stoi(numMembers_str); 
        } catch (const invalid_argument& e) {
            cerr << "Error: Invalid data format in line: " << line << endl;
            continue;  
        }
        teams.emplace_back(teamID, teamName, captain, coach, numMembers);
    }

    file.close();  
    return teams;  
}


// Save
void Team::saveToFile(const string& filePath, const vector<Team>& teams) {
    ofstream file(filePath, ios::trunc);  
    if (file.is_open()) {
        for (const auto& team : teams) {
            file << team.getTeamName() << "|" 
                 << team.getCaptain() << "|" 
                 << team.getCoach() << "|" 
                 << team.getTeamID() << "|" 
                 << team.getNumMembers() << "\n";
        }
        file.close();
    } else {
        cerr << "Error: Unable to open file for writing." << endl;
    }
}

// Display t
void Team::displayTeam() const {
    cout << "Team ID: " << teamID << "\n"
              << "Team Name: " << teamName << "\n"
              << "Captain: " << captain << "\n"
              << "Coach: " << coach << "\n"
              << "Number of Members: " << numMembers << "\n"
              << "----------------------\n";
}
