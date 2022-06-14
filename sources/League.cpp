#include "League.hpp"

League::League(){
    srand((unsigned)time(0));

    for (unsigned int i = 0; i < MAX_TEAMS; i++){
        Team* team = new Team("team" + to_string(i+1));
        teams[i] = team;
    }
}

League::League(vector<Team>& teams){
    srand((unsigned)time(0));

    unsigned int i = 0;
    for (i = 0; i < teams.size(); i++){
        this->teams[i] = (&teams.at(i));
    }
    for (unsigned int j = i; j < MAX_TEAMS; j++){
        Team* team = new Team("team" + to_string(j-teams.size()+1));
        this->teams[j] = team;
    }
}

vector<Team*> League::arrange(int round){
    Team* arrangement[MAX_TEAMS];
    arrangement[0] = teams[0];
    for (int i = 0; i < MAX_TEAMS-1; i++){
        arrangement[(round+i-1)%(MAX_TEAMS-1) + 1] = teams[i+1];
    }

    vector<Team*> returning;
    returning.insert(returning.begin(), begin(arrangement), end(arrangement));
    return returning;
}

vector<Team*> League::get_teams(){
    vector<Team*> returning;
    returning.insert(returning.begin(), begin(teams), end(teams));
    return returning;
}