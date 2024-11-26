/* #include <iostream>
#include "FootballManager.h"
using namespace std;

int main() {
    vector<Team> teams;
    vector<MatchSchedule> matches;
    vector<MatchResult> results;

    string teamFilePath = "Team.txt";
    string matchFilePath = "MatchSchedule.txt";
    string resultFilePath = "MatchResult.txt";

    // Load data from files
    teams = Team::loadTeamsFromFile(teamFilePath);
    matches = MatchSchedule::loadMatchesFromFile(matchFilePath);
    results = MatchResult::loadResultsFromFile(resultFilePath);

    bool isRunning = true;
    int option;

    
    while (isRunning) {
        cout << "\n\t\t\t\t\t\t\t==== QUAN LY LICH THI DAU BONG DA ====\n\n\n\n ";
        cout << "\t\t\t\t1. Them doi bong\n";
        cout << "\t\t\t\t2. Hien thong tin cac doi bong\n";
        cout << "\t\t\t\t3. Tim kiem doi bong\n";
        cout << "\t\t\t\t4. Sua thong tin doi bong\n";
        cout << "\t\t\t\t5. Them lich thi dau\n";
        cout << "\t\t\t\t6. Hien lich thi dau\n";
        cout << "\t\t\t\t7. Tim kiem lich thi dau theo doi\n";
        cout << "\t\t\t\t8. Sua lich thi dau\n";
        cout << "\t\t\t\t9. Cap nhat ket qua tran dau\n";
        cout << "\t\t\t\t10. Hien ket qua tran dau\n";
        cout << "\t\t\t\t0. Thoat\n";
        cout << "\t\tChon mot tuy chon: ";
        cin >> option;
       system("cls");
        switch (option) {
            case 1:
                FootballManager::addTeam(teams, teamFilePath);
                break;

            case 2:
                if (teams.empty()) {
                    cout << "Chua co doi bong. Vui long them doi bong truoc!!!!!!!!!!.\n";
                } else {
                    FootballManager::displayTeams(teams);
                }
                break;

            case 3:
//                if (teams.empty()) {
//                    cout << "Chua co doi bong. Vui long them doi bong truoc.\n";
//                } else {
//                    int teamID;
//                    cout << "Nhap ID doi can tim: ";
//                    cin >> teamID;
//                    FootballManager::findTeamById(teams, teamID);
//                }
//                break;
          if (teams.empty()) {
                    cout << "Chua co doi bong. Vui long them doi bong truoc.!!!!!!!!!!!!!!!!\n";
                } else {

                    FootballManager::findTeamById(teams);
                }
                break;           

            case 4:
                if (teams.empty()) {
                    cout << "Chua co doi bong. Vui long them doi bong truoc!!!!!!!!!!!!!!!!!!.\n";
                } else {
                    int teamID;
                    cout << "\t\tNhap ID doi can sua: ";
                    cin >> teamID;
                    FootballManager::updateTeamInfo(teams, teamID, teamFilePath);
                }
                break;

            case 5:
                if (teams.empty()) {
                    cout << "Chua co doi bong. Vui long them doi bong truoc khi them lich thi dau!!!!!!!!!!!!!.\n";
                } else {
                    FootballManager::addMatch(matches, matchFilePath);
                }
                break;

            case 6:
                if (matches.empty()) {
                    cout << "Chua co lich thi dau. Vui long them lich thi dau truoc!!!!!!!!!!!!!!!!!.\n";
                } else {
                    FootballManager::displayMatches(matches);
                }
                break;

            case 7:
                if (matches.empty()) {
                    cout << "Chua co lich thi dau. Vui long them lich thi dau truoc!!!!!!!!!!!!!!!!!!!.\n";
                } else {
                    int searchTeamID;
                    cout << "Nhap ID doi can tim trong lich thi dau: ";
                    cin >> searchTeamID;
                    FootballManager::findMatchByTeam(matches, searchTeamID);
                }
                break;

            case 8:
                if (matches.empty()) {
                    cout << "Chua co lich thi dau. Vui long them lich thi dau truoc khi sua!!!!!!!!!!!!!!!!.\n";
                } else {
                    int matchID;
                    cout << "Nhap ID tran dau can sua: ";
                    cin >> matchID;
                    FootballManager::updateMatchInfo(matches, matchID, matchFilePath);
                }
                break;

            case 9:
                if (results.empty()) {
                    cout << "Chua co ket qua tran dau. Vui long cap nhat ket qua tran dau!!!!!!!!!!!!!!!.\n";
                } else {
                    FootballManager::updateMatchResult(results, resultFilePath);
                }
                break;

            case 10:
                if (results.empty()) {
                    cout << "Chua co ket qua tran dau. Vui long cap nhat ket qua tran dau!!!!!!!!!!!!!!!!!.\n";
                } else {
                    FootballManager::displayResults(results);
                }
                break;

            case 0:
                isRunning = false;
                
                break;

            default:
                cout << "Tuy chon khong hop le. Vui long chon lai.\n";
        }
                if (isRunning) {
            cout << "\n\t\t\tNhấn phím bất kỳ để tiếp tục...";
            cin.ignore();
            cin.get();
        }
    }

    return 0;
}  */
#include <iostream>
#include "FootballManager.h"
#include <iomanip>  // Thư viện để căn chỉnh dễ dàng
using namespace std;

int main() {
    vector<Team> teams;
    vector<MatchSchedule> matches;
    vector<MatchResult> results;

    string teamFilePath = "Team.txt";
    string matchFilePath = "MatchSchedule.txt";
    string resultFilePath = "MatchResult.txt";

    // Load data from files
    teams = Team::loadTeamsFromFile(teamFilePath);
    matches = MatchSchedule::loadMatchesFromFile(matchFilePath);
    results = MatchResult::loadResultsFromFile(resultFilePath);

    bool isRunning = true;
    int option;

    while (isRunning) {
        system("cls");  

        cout << "\n\t\t\t\t\t\t\t==== QUAN LY LICH THI DAU BONG DA ====\n";
        cout << "\t\t\t\t-----------------------------------------------\n";
        cout << "\t\t\t\t 1. Them doi bong\n";
        cout << "\t\t\t\t 2. Hien thong tin cac doi bong\n";
        cout << "\t\t\t\t 3. Tim kiem doi bong\n";
        cout << "\t\t\t\t 4. Sua thong tin doi bong\n";
        cout << "\t\t\t\t 5. Them lich thi dau\n";
        cout << "\t\t\t\t 6. Hien lich thi dau\n";
        cout << "\t\t\t\t 7. Tim kiem lich thi dau theo doi\n";
        cout << "\t\t\t\t 8. Sua lich thi dau\n";
        cout << "\t\t\t\t 9. Cap nhat ket qua tran dau\n";
        cout << "\t\t\t\t 10. Hien ket qua tran dau\n";
        cout << "\t\t\t\t 0. Thoat\n";
        cout << "\t\t\t\t-----------------------------------------------\n";
        cout << "\n\t\t\tChon mot tuy chon (0-10): ";
        cin >> option;
        system("cls");
        
        if (option < 0 || option > 10) {
            cout << "\n\t\t\tTuy chon khong hop le! Vui long chon lai.\n";
            continue;
        }

     
        switch (option) {
            case 1:
                FootballManager::addTeam(teams, teamFilePath);
                break;

            case 2:
                if (teams.empty()) {
                    cout << "\n\t\t\tChua co doi bong. Vui long them doi bong truoc!\n";
                } else {
                    FootballManager::displayTeams(teams);
                }
                break;

            case 3:
                if (teams.empty()) {
                    cout << "\n\t\t\tChua co doi bong. Vui long them doi bong truoc!\n";
                } else {
                    FootballManager::findTeamById(teams);
                }
                break;

            case 4:
                if (teams.empty()) {
                    cout << "\n\t\t\tChua co doi bong. Vui long them doi bong truoc!\n";
                } else {
                    int teamID;
                    cout << "\n\t\t\tNhap ID doi can sua: ";
                    cin >> teamID;
                    FootballManager::updateTeamInfo(teams, teamID, teamFilePath);
                }
                break;

            case 5:
                if (teams.empty()) {
                    cout << "\n\t\t\tChua co doi bong. Vui long them doi bong truoc khi them lich thi dau!\n";
                } else {
                    FootballManager::addMatch(matches, matchFilePath, teams);
                }
                break;

            case 6:
                if (matches.empty()) {
                    cout << "\n\t\t\tChua co lich thi dau. Vui long them lich thi dau truoc!\n";
                } else {
                    FootballManager::displayMatches(matches);
                }
                break;

            case 7:
                if (matches.empty()) {
                    cout << "\n\t\t\tChua co lich thi dau. Vui long them lich thi dau truoc!\n";
                } else {
                    int searchTeamID;
                    cout << "\n\t\t\tNhap ID doi can tim trong lich thi dau: ";
                    cin >> searchTeamID;
                    FootballManager::findMatchByTeam(matches, searchTeamID);
                }
                break;

            case 8:
                if (matches.empty()) {
                    cout << "\n\t\t\tChua co lich thi dau. Vui long them lich thi dau truoc khi sua!\n";
                } else {
                    int matchID;
                    cout << "\n\t\t\tNhap ID tran dau can sua: ";
                    cin >> matchID;
                    FootballManager::updateMatchInfo(matches, matchID, matchFilePath);
                }
                break;

            case 9:
                if (results.empty()) {
                    cout << "\n\t\t\tChua co ket qua tran dau. Vui long cap nhat ket qua tran dau!\n";
                } else {
                    FootballManager::updateMatchResult(results,matches,resultFilePath, teams);
                }
                break;

            case 10:
                if (results.empty()) {
                    cout << "\n\t\t\tChua co ket qua tran dau. Vui long cap nhat ket qua tran dau!\n";
                } else {
                    FootballManager::displayResults(results);
                }
                break;

            case 0:
                isRunning = false;
                break;

            default:
                break;
        }

        // Pause and wait for user input before continuing
        if (isRunning) {
            cout << "\n\t\t\tNhan phim bat ky de tiep tuc...";
            cin.ignore();
            cin.get();
        }
    }

    return 0;
}
