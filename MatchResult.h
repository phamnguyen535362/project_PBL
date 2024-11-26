//#ifndef MATCHRESULT_H
//#define MATCHRESULT_H
//#include <algorithm>
//#include <iostream>
//#include <string>
//#include <vector>
//#include <fstream>
//#include <sstream>
//#include <iomanip>
//using namespace std;
//
//class MatchResult {
//private:
//	int matchID;
//    int teamID1;       // ID của đội 1
//    int teamID2;       // ID của đội 2
//    int goalsTeam1;    // Số bàn thắng của đội 1
//    int goalsTeam2;    // Số bàn thắng của đội 2
//    int cardsTeam1;    // Số thẻ của đội 1
//    int cardsTeam2;    // Số thẻ của đội 2
//
//public:
//    // Constructor
//      MatchResult( int team1, int team2, int score1, int score2, int cards1, int cards2);
//    
//    // Get
//
//    int getTeamID1() const;
//    int getTeamID2() const;
//    int getGoalsTeam1() const;
//    int getGoalsTeam2() const;
//    int getCardsTeam1() const;
//    int getCardsTeam2() const;
//
//   
//    static  vector<MatchResult> loadResultsFromFile(const string& filename);
//   
//    static inline void saveResultsToFile(const string& filename, const vector<MatchResult>& results) {
//        ofstream file(filename, ios::app);
//        
//        if (!file.is_open()) {
//            cerr << "Error: Unable to open file for writing." << endl;
//            return; 
//        }
//
//        for (const auto& result : results) {
//            file << result.teamID1 << "|"
//                 << result.teamID2 << "|"
//                 << result.goalsTeam1 << "|"
//                 << result.goalsTeam2 << "|"
//                 << result.cardsTeam1 << "|"
//                 << result.cardsTeam2 << "\n"; 
//        }
//
//        file.close();
//        if (file.fail()) { 
//            cerr << "Error: Failed to write to file." << endl;
//        }
//    }
//
//    
//    void displayResult() const;
//};
//
//#endif
#ifndef MATCHRESULT_H
#define MATCHRESULT_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

class MatchResult {
private:
    int teamID1;       
    int teamID2;      
    int goalsTeam1;  
    int goalsTeam2;    
    int cardsTeam1;    
    int cardsTeam2;  

public:
    // Constructor
    MatchResult(int tID1, int tID2, int g1, int g2, int c1, int c2); 
        

    // Getters
    int getTeamID1() const ;
    int getTeamID2() const ;
    int getGoalsTeam1() const ;
    int getGoalsTeam2() const ;
    int getCardsTeam1() const ;
    int getCardsTeam2() const ;

    
    static vector<MatchResult> loadResultsFromFile(const string& filename);

  
    static inline void saveResultsToFile(const string& filename, const vector<MatchResult>& results) {
        ofstream file(filename, ios::app);

        if (!file.is_open()) {
            cerr << "Error: Unable to open file for writing." << endl;
            return;
        }

        file << "==== KeT QUa CaC TRaN ĐaU ====\n";
        for (const auto& result : results) {
            file << "---------------------------------\n";
            file << "Đội 1 (ID: " << result.teamID1 << "): " << result.goalsTeam1 << " bàn, "
                 << result.cardsTeam1 << " thẻ\n";
            file << "Đội 2 (ID: " << result.teamID2 << "): " << result.goalsTeam2 << " bàn, "
                 << result.cardsTeam2 << " thẻ\n";
        }
        file << "=================================\n";

        file.close();
        if (file.fail()) {
            cerr << "Error: Failed to write to file." << endl;
        }
    }

    // Hiển thị kết quả trên console
    void displayResult() const {
        cout << "---------------------------------\n";
        cout << "Team  1 (ID: " << teamID1 << "): " << goalsTeam1 << " Goals, " << cardsTeam1 << " Cards\n";
        cout << "Team  2 (ID: " << teamID2 << "): " << goalsTeam2 << " Goals, " << cardsTeam2 << " Card\n";
        cout << "---------------------------------\n";
    }
};

#endif

