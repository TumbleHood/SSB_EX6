#include "Game.hpp"
#include <vector>
#include <unordered_map>

#define MAX_TEAMS 20

class League{
    private:
        Team* teams[MAX_TEAMS];
    public:
        League();
        League(vector<Team>& teams);
        vector<Team*> arrange(int round);
        vector<Team*> get_teams();
};