#include <string>

using namespace std;

class Team{
    private:
        string name;
        double talent_level;
        int wins;
        int losses;
        int points_scored;
        int points_absorbed;
        int max_win_streak;
        int current_win_streak;
        int max_loss_streak;
        int current_loss_streak;
    public:
        Team(string name, double talent_level): name(move(name)), talent_level(talent_level),
            wins(0), losses(0), points_scored(0), points_absorbed(0), max_win_streak(0), 
            current_win_streak(0), max_loss_streak(0), current_loss_streak(0){};
        Team(string name);
        string& get_name();
        double get_talent_level() const;
        void inc_wins();
        void inc_losses();
        void inc_points_scored(int points);
        void inc_points_absorbed(int points);
        int get_wins() const;
        int get_losses() const;
        int get_points_scored() const;
        int get_pointed_absorbed() const;
        int get_max_win_streak() const;
        int get_max_loss_streak() const;
};