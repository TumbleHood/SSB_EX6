#include "Team.hpp"
#include <random>
#include <cmath>

class Game{
    private:
        Team* home_team;
        Team* away_team;
        int home_points;
        int away_points;
        string winner;
        void draw_points();
        void decide_winner();
        random_device rand{};
        mt19937 gen{rand()};
        normal_distribution<> d{75, 25};
    public:
        Game(Team* home_team, Team* away_team);
        string get_home_team();
        string get_away_team();
        int get_home_points();
        int get_away_points();
        string get_winner();
};