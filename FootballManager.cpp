#include "FootballManager.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <limits>
#include <cctype>
#include <chrono>
 // ---------------------------------sua vector thanh mang cap phat dong-----------------------------
using namespace std; 
 
 
 
bool  FootballManager::checkID1(const string& str) {
    for (char ch : str) {
        if (!isdigit(ch)) { 
            return false;
        }
    }
    return !str.empty(); 
}

bool FootballManager::checkID2(const vector<Team>& teams, int id) {
    for (const Team& team : teams) {
        if (team.getTeamID() == id) { 
            return false;
        }
    }
    return true;
}
bool FootballManager::checkString(const string& str){
	for(char ch : str){
        if (isdigit(ch)) {    //   isdigit(): kiem tra chuoi ki tu co xuat hien chu so hay khong
            return true;
        }
    }
    return false;
}

 
void FootballManager::addTeam(vector<Team>& teams, const string& filePath) 
{   string input;
    int id, membersCount;
    string name, captain, coach;
    FootballManager Teamid;
  while(true) {
        cout << "Enter team ID: ";
        cin >> input;
        if(Teamid.checkID1(input)){
        	id = stoi(input);    // stoi() ham chuyen chuoi string sang kieu so nguyen int

		if(!Teamid.checkID2(teams, id)) {
            cout << "ID bi trung lap, vui long nhap lai ID moi.\n";
        }else{     break;  }
		 }else {   
		            cout << "vui long nhap ID la so.\n" ;
		}
    }
 
      
  
    cin.ignore();
    while(true){
    	cout << "Enter team name: ";
        getline(cin, name);
       if(checkString(name)){ 
           cout << "Vui long nhap lai!!!\n";
	   }else if(name.empty()){
	   	   cout << "vui long nhap ten doi bong!!!\n";
	   } else {  break;
	   }
	}
	
	while(true){
    	cout << "Enter captain's name: ";
    getline(cin, captain);
       if(checkString(captain)){ 
           cout << "Vui long nhap lai!!!\n";
	   }else if(captain.empty()){
	   	   cout << "vui long nhap ten doi truong!!!\n";
	   } else {  break;
	   }
	}

    cout << "Enter coach's name: ";
    getline(cin, coach);
    cout << "Enter number of members: ";
    cin >> membersCount;

    Team newTeam(id, name, captain, coach, membersCount);
    teams.push_back(newTeam);                                               
    Team::saveToFile(filePath, teams);

    cout << "Team added successfully.\n";
}


void FootballManager::displayTeams(const vector<Team>& teams) {
    for (const auto& team : teams) {
        team.displayTeam();                     
    }
}


//void FootballManager::findTeamById(const vector<Team>& teams, int id) {
//    for (const auto& team : teams) {
//        if (team.getTeamID() == id) {
//            team.displayTeam();                
//            return;
//        }
//    }
//    cout << "Team not found with ID: " << id << endl;
//}
void FootballManager::findTeamById(const vector<Team>& teams) {
    int id;
    while (true) {
        cout << "Enter Team ID (0 to exit): ";
        cin >> id;

        if (id == 0) {
            cout << "Exiting search." << endl;
            return;
        }

        bool found = false;
        for (const auto& team : teams) {
            if (team.getTeamID() == id) {
                team.displayTeam();
                return; 
            }
        }

        cout << "Team not found with ID: " << id << ". Please try again." << endl;
    }
}


void FootballManager::updateTeamInfo(vector<Team>& teams, int id, const string& filePath) {
    for (auto& team : teams) {
        if (team.getTeamID() == id) {
            string name, captain, coach;
            int membersCount;

            cout << "Enter new team name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter new captain's name: ";
            getline(cin, captain);
            cout << "Enter new coach's name: ";
            getline(cin, coach);
            cout << "Enter new number of members: ";
            cin >> membersCount;

            team.setTeamName(name);
            team.setCaptain(captain);
            team.setCoach(coach);
            team.setNumMembers(membersCount);

            Team::saveToFile(filePath, teams);
            cout << "Team information updated successfully.\n";
            return;
        }
    }
    cout << "Team not found with ID: " << id << endl;
}


void FootballManager::addMatch(vector<MatchSchedule>& matches, const string& filePath, const vector<Team>& teams) {
    int teamID1, teamID2, matchID;
    int day, month, year, hour, minute;
    string timeStr, stadium, referee;
    
    cout << "Enter match ID: ";
    cin >> matchID;
    
    for(const auto& match : matches){
    	if(match.getMatchID() == matchID){
    		cout << "ID ban nhap bi trung, vui long nhap lai";
		}
	}
    
    bool validTeam1 = false;
    while (!validTeam1) {
        cout << "Enter team 1 ID: ";
        cin >> teamID1;

        
        for (const auto& team : teams) {
            if (team.getTeamID() == teamID1) {
                validTeam1 = true; 
                break;
            }
        }

        if (!validTeam1) {
            cout << "Team 1 with ID " << teamID1 << " does not exist. Please enter a valid team ID.\n";
        }
    }

    
    bool validTeam2 = false;
    while (!validTeam2) {
        cout << "Enter team 2 ID: ";
        cin >> teamID2;

        
        if (teamID2 == teamID1) {
            cout << "Team 2 cannot be the same as Team 1. Please enter a different team ID.\n";
        } else {
            bool teamFound = false;
            for (const auto& team : teams) {
                if (team.getTeamID() == teamID2) {
                    teamFound = true;
                    break;
                }
            }
            
            if (teamFound) {
                validTeam2 = true; 
            } else {
                cout << "Team 2 with ID " << teamID2 << " does not exist. Please enter a valid team ID.\n";
            }
        }
    }
     cin.ignore();
    cout << "Day: ";
     cin >> day;
    cout << "Month: ";
     cin >> month;
    cout << "Year: ";
     cin >> year;
    cout << "Hour: ";
     cin >> hour;
    cout << "Minute: ";
     cin >> minute;
    timeStr =  to_string(year) + "-" + (month < 10 ? "0" : "") + to_string(month) + "-" + 
            (day < 10 ? "0" : "") + to_string(day) + " " + 
            (hour < 10 ? "0" : "") + to_string(hour) + ":" + 
            (minute < 10 ? "0" : "") + to_string(minute);
//    cout << "Enter match time (YYYY-MM-DD HH:MM:SS): ";
       cin.ignore();      
//    getline(cin, timeStr);
    cout << "Enter stadium name: ";
    cin.ignore();
    getline(cin, stadium);
    cout << "Enter referee's name: ";
    getline(cin, referee);
    MatchSchedule newMatch(teamID1, teamID2, matchID, timeStr, stadium, referee);
    matches.push_back(newMatch);                                                  //sua-----------khong dung thu vien
    MatchSchedule::saveMatchSchedule(filePath, matches);

    cout << "Match schedule added successfully.\n";
    
}

  

void FootballManager::displayMatches(const vector<MatchSchedule>& matches) {
    for (const auto& match : matches) {
        match.displayMatch();
        match.notifyTimeMatch();
    }
}


void FootballManager::findMatchByTeam(const vector<MatchSchedule>& matches, int teamId) {
    for (const auto& match : matches) {
        if (match.getTeamID1() == teamId || match.getTeamID2() == teamId) {
            match.displayMatch();
        }
    }
}


void FootballManager::updateMatchInfo(vector<MatchSchedule>& matches, int matchID, const string& filePath) {
    for (auto& match : matches) {
        if (match.getMatchID() == matchID) {
            string stadium, referee, timeStr;
            cout << "Enter new stadium name: ";
            getline(cin, stadium);
            cout << "Enter new referee's name: ";
            getline(cin, referee);
            cout << "Enter match time (YYYY-MM-DD HH:MM:SS): ";
            getline(cin, timeStr);
            match = MatchSchedule(match.getTeamID1(), match.getTeamID2(), matchID, timeStr, stadium, referee);
            MatchSchedule::saveMatchSchedule(filePath, matches);
            cout << "Match schedule updated successfully.\n";
            return;
        }
    }
    cout << "Match schedule not found with ID: " << matchID << endl;
}


void FootballManager::updateMatchResult(vector<MatchResult>& results,vector<MatchSchedule>& matches,  const string& filePath,const vector<Team>& teams )
 {
    int  matchID, teamID1, teamID2, score1, score2, cards1, cards2;
    bool matchFound = false;
    ;
    
    cout << "Enter match ID: ";
    cin >> matchID;
    
    
    for (auto& match : matches) {
        if (match.getMatchID() == matchID) {
            matchFound = true;
         
         string team1Name, team2Name;
         for (const auto& team : teams) {
                if (team.getTeamID() == match.getTeamID1()) team1Name = team.getTeamName();
                if (team.getTeamID() == match.getTeamID2()) team2Name = team.getTeamName();
            
        }
        cout << "Match found between Team " << team1Name << " and Team " << team2Name << "\n";
            
            
           
            cout << "Team 1: " << team1Name << " (ID: " << match.getTeamID1() << ")\n";
            cout << "Team 2: " << team2Name << " (ID: " << match.getTeamID2() << ")\n";

            cout << "Enter number of goals for team " << team1Name << ": ";
            cin >> score1;
            cout << "Enter number of goals for team " << team2Name << ": ";
            cin >> score2;
            cout << "Enter number of cards for team " << team1Name << ": ";
            cin >> cards1;
            cout << "Enter number of cards for team " << team2Name << ": ";
            cin >> cards2;

         
            MatchResult newResult(match.getTeamID1(), match.getTeamID2(), score1, score2, cards1, cards2);
            results.push_back(newResult);

            
            MatchResult::saveResultsToFile(filePath, results);

            cout << "Match result updated successfully.\n";
            break;  
        }
    }

    
    if (!matchFound) {
        cout << "No match found with ID " << matchID << ". Please check the ID and try again.\n";
    }
}
//    cout << "Enter team 1 ID: ";
//    cin >> teamID1;
//    cout << "Enter team 2 ID: ";
//    cin >> teamID2;
//    cout << "Enter number of goals for team 1: ";
//    cin >> score1;
//    cout << "Enter number of goals for team 2: ";
//    cin >> score2;
//    cout << "Enter number of cards for team 1: ";
//    cin >> cards1;
//    cout << "Enter number of cards for team 2: ";
//    cin >> cards2;
//    MatchResult newResult( teamID1, teamID2, score1, score2, cards1, cards2);
//    results.push_back(newResult);                         //sua-----------khong dung thu vien
//    MatchResult::saveResultsToFile(filePath, results);
//
//    cout << "Match result updated successfully.\n";
//}

// Hàm hiển thị kết quả trận đấu
void FootballManager::displayResults(const vector<MatchResult>& results) {
    for (const auto& result : results) {
        result.displayResult();
    }
}
