#include "Team.hpp"
#include <random>
#include <cmath>

static constexpr int MIN_POINTS_HOME = 55;
static constexpr int MIN_POINTS_AWAY = 50;
static constexpr int MAX_POINTS = 100;
static constexpr int BONUS_POINTS = 10;

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
        normal_distribution<> d{(int)((MAX_POINTS + MIN_POINTS_AWAY)/2), MAX_POINTS - (int)((MAX_POINTS + MIN_POINTS_AWAY)/2)};
    public:
        Game(Team* home_team, Team* away_team);
        string get_home_team();
        string get_away_team();
        int get_home_points() const;
        int get_away_points() const;
        string get_winner();
};