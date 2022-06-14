#include "League.hpp"

League::League(){
    srand((unsigned)time(0));

    for (unsigned int i = 0; i < MAX_TEAMS; i++){
        Team* team = new Team("team" + to_string(i+1));
        teams.push_back(team);
    }
}

League::League(vector<Team>& teams){
    srand((unsigned)time(0));

    unsigned int i = 0;
    for (i = 0; i < teams.size(); i++){
        this->teams.push_back(&teams.at(i));
    }
    for (unsigned int j = i; j < MAX_TEAMS; j++){
        Team* team = new Team("team" + to_string(j-teams.size()+1));
        this->teams.push_back(team);
    }
}

vector<Team*> League::arrange(int round){
    vector<Team*> arrangement(MAX_TEAMS);
    arrangement[0] = teams.at(0);
    for (int i = 0; i < MAX_TEAMS-1; i++){
        arrangement.at((round+i-1)%(MAX_TEAMS-1) + 1) = teams.at((unsigned int)i+1);
    }

    return arrangement;
}

vector<Team*> League::get_teams(){
    return teams;
}