#ifndef TEAM_H
#define TEAM_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std; 

class Team {
private:
    int teamID;          
    string teamName;    
    string captain;   
    string coach;        
    int numMembers;      
public:
    Team(int teamID, const string& teamName, const string& captain, const string& coach, int numMembers);
    
    Team(); // Constructor

    // Get
    int getTeamID() const;
    string getTeamName() const;
    string getCaptain() const;
    string getCoach() const;
    int getNumMembers() const;
    int getId() const;
    // Set
    void setTeamID(int teamID);
    void setTeamName(const string& teamName);
    void setCaptain(const string& captain);
    void setCoach(const string& coach);
    void setNumMembers(int numMembers);

    static vector<Team> loadTeamsFromFile(const string& filePath);
    static void saveToFile(const string& filePath, const vector<Team>& teams);
    void displayTeam() const;
};

#endif
