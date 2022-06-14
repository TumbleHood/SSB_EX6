#include "League.hpp"
#include <iostream>

static constexpr int ROUNDS = MAX_TEAMS-1;

class Schedule{
    private:
        League league;
        vector<Game*> games;
        vector<Team*> rated;
        void game();
    public:
        Schedule();
        Schedule(vector<Team>& teams);
        Schedule(League& league): league(league){};
        void result_table();
        vector<string> top_teams(int number);
        pair<int, string> longest_win_streak();
        pair<int, string> longest_loss_streak();
        vector<string> teams_that_scored_more_than_absorbed();
        int times_home_team_won();
        double average_points_per_game();
};