#include "Team.hpp"

static double random(double lower, double upper){
    return ((double)rand() * (upper - lower)) / (double)RAND_MAX + lower;
}

Team::Team(string name): name(name), wins(0), losses(0), points_scored(0), points_absorbed(0),
                         max_win_streak(0), current_win_streak(0), max_loss_streak(0), current_loss_streak(0){
    talent_level = random(0, 1);
}

string& Team::get_name(){
    return name;
}

double Team::get_talent_level(){
    return talent_level;
}

void Team::inc_wins(){
    wins++;
    current_win_streak++;
    if (max_win_streak < current_win_streak){
        max_win_streak = current_win_streak;
    }
    current_loss_streak = 0;
}
void Team::inc_losses(){
    losses++;
    current_loss_streak++;
    if (max_loss_streak < current_loss_streak){
        max_loss_streak = current_loss_streak;
    }
    current_win_streak = 0;
}
void Team::inc_points_scored(int points){
    points_scored += points;
}
void Team::inc_points_absorbed(int points){
    points_absorbed += points;
}

int Team::get_wins(){
    return wins;
}

int Team::get_losses(){
    return losses;
}

int Team::get_points_scored(){
    return points_scored;
}

int Team::get_pointed_absorbed(){
    return points_absorbed;
}

int Team::get_max_win_streak(){
    return max_win_streak;
}

int Team::get_max_loss_streak(){
    return max_loss_streak;
}