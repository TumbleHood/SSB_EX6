#include "Game.hpp"

void Game::draw_points(){
    do {home_points = round(d(gen));}
    while (home_points > 100 || home_points < 55); //random number between 55 - 100

    do {away_points = round(d(gen));}
    while (away_points > 100 || away_points < 50); //random number between 50 - 100

    home_points += round(home_team->get_talent_level()*10.0);
    away_points += round(away_team->get_talent_level()*10.0);

    home_team->inc_points_scored(home_points);
    home_team->inc_points_absorbed(away_points);
    away_team->inc_points_scored(away_points);
    away_team->inc_points_absorbed(home_points);
}

void Game::decide_winner(){
    if (home_points > away_points){ //home team won by points
        winner = home_team->get_name();
    }
    else if (home_points < away_points){ //away team won by points
        winner = away_team->get_name();
    }
    //points tie
    else if (home_team->get_talent_level() > away_team->get_talent_level()){ //home team won by talent level
        winner = home_team->get_name();
    }
    else if (home_team->get_talent_level() < away_team->get_talent_level()){ //away team won by talent level
        winner = away_team->get_name();
    }
    //points tie and talent level tie
    else if (rand() % 2 == 0){ //flip a coin.
        winner = home_team->get_name();
    }
    else{
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

Game::Game(Team* home_team, Team* away_team): home_team(home_team), away_team(away_team){
    draw_points();
    decide_winner();
}

string Game::get_home_team(){
    return home_team->get_name();
}

string Game::get_away_team(){
    return away_team->get_name();
}

int Game::get_home_points(){
    return home_points;
}

int Game::get_away_points(){
    return away_points;
}

string Game::get_winner(){
    return winner;
}