#include "Game.hpp"
#include <vector>
#include <unordered_map>

static constexpr int MAX_TEAMS = 20;

class League{
    private:
        vector<Team*> teams;
    public:
        League();
        League(vector<Team>& teams);
        vector<Team*> arrange(int round);
        vector<Team*> get_teams();
};