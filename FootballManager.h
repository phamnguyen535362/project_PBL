#ifndef FOOTBALLMANAGER_H
#define FOOTBALLMANAGER_H

#include <vector>
#include <string>
#include "Team.h"
#include "MatchSchedule.h"
#include "MatchResult.h"

using namespace std; 
class MatchInfo {
	
public:
    int matchID;
    vector<Team> teams;
    MatchInfo(int id) : matchID(id) {}
};
class FootballManager {
public:
    static void addTeam(vector<Team>& teams, const string& filePath);
    static void displayTeams(const vector<Team>& teams);
    static void findTeamById(const vector<Team>& teams);
    static void updateTeamInfo(vector<Team>& teams, int id, const string& filePath);

    static void addMatch(vector<MatchSchedule>& matches, const string& filePath, const vector<Team>& teams);
    static void displayMatches(const vector<MatchSchedule>& matches);
    static void findMatchByTeam(const vector<MatchSchedule>& matches, int teamId);
    static void updateMatchInfo(vector<MatchSchedule>& matches, int matchID, const string& filePath);
    
     static void updateMatchResult(vector<MatchResult>& results,vector<MatchSchedule>& matches,  const string& filePath, const vector<Team>& teams);
     static void displayResults(const vector<MatchResult>& results);
      bool  checkID1(const string& str);
      static bool checkString(const string& str); 
      bool  checkID2(const vector<Team>& teams, int id);
};

#endif
