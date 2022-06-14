#include "Game.hpp"

void Game::draw_points(){
    do {home_points = (int)round(d(gen));}
    while (home_points > MAX_POINTS || home_points < MIN_POINTS_HOME); //random number between 55 - 100

    do {away_points = (int)round(d(gen));}
    while (away_points > MAX_POINTS || away_points < MIN_POINTS_AWAY); //random number between 50 - 100

    home_points += (int)round((double)(home_team->get_talent_level())*BONUS_POINTS);
    away_points += (int)round((double)(away_team->get_talent_level())*BONUS_POINTS);

    home_team->inc_points_scored(home_points);
    home_team->inc_points_absorbed(away_points);
    away_team->inc_points_scored(away_points);
    away_team->inc_points_absorbed(home_points);
}

void Game::decide_winner(){
    int coin_flip = (int)(rand() % 2);
    if (home_points > away_points || 
       (home_points == away_points && home_team->get_talent_level() > away_team->get_talent_level()) ||
       (home_points == away_points && home_team->get_talent_level() == away_team->get_talent_level() && coin_flip == 0)){
        winner = home_team->get_name();
    }
    else if (home_points < away_points|| 
            (away_points == home_points && away_team->get_talent_level() > home_team->get_talent_level()) ||
            (away_points == home_points && away_team->get_talent_level() == home_team->get_talent_level() && coin_flip == 1)){
        winner = away_team->get_name();
    }

    if (winner == home_team->get_name()){
        home_team->inc_wins();
        away_team->inc_losses();
    }
    else{
        home_team->inc_losses();
        away_team->inc_wins();
    }
}

Game::Game(Team* home_team, Team* away_team): home_team(home_team), away_team(away_team), home_points(0), away_points(0){
    draw_points();
    decide_winner();
}

string Game::get_home_team(){
    return home_team->get_name();
}

string Game::get_away_team(){
    return away_team->get_name();
}

int Game::get_home_points() const{
    return home_points;
}

int Game::get_away_points() const{
    return away_points;
}

string Game::get_winner(){
    return winner;
}