#include "Schedule.hpp"

static void ntimes(int n, const string& c){
    while (n > 0){
        cout << c;
        n--;
    }
}

Schedule::Schedule(){
    league = League();
    game();
}

Schedule::Schedule(vector<Team>& teams){
    league = League(teams);
    game();
}

void Schedule::game(){
    for (int round = 1; round <= ROUNDS; round++){
        vector<Team*> arrangement = league.arrange(round);
        for (unsigned int i = 0; i < MAX_TEAMS / 2; i++){ //first cycle
            Game* game = new Game(arrangement.at(i), arrangement.at(MAX_TEAMS-i-1));
            games.push_back(game);
        }
        for (unsigned int i = 0; i < MAX_TEAMS / 2; i++){ //second cycle (home team <=> away team)
            Game* game = new Game(arrangement.at(MAX_TEAMS-i-1), arrangement.at(i));
            games.push_back(game);
        }
    }

    vector<Team*> teams = vector<Team*>(league.get_teams());
    for (int i = 0; i < league.get_teams().size(); i++){
        unsigned int best_index = 0;
        int most_wins = -1;
        int most_points = -1;
        for (unsigned int j = 0; j < teams.size(); j++){ 
            if (teams.at(j)->get_wins() > most_wins){
                most_wins = teams.at(j)->get_wins();
                best_index = j;
            }
            else if (teams.at(j)->get_wins() == most_wins){
                if (teams.at(j)->get_points_scored() > teams.at(best_index)->get_points_scored()){
                    best_index = j;
                }
            }
        }
        rated.push_back(teams.at(best_index));
        teams.erase(teams.begin() + best_index);
    }
}

void Schedule::result_table(){
    size_t max_team_name_length = 0;
    size_t max_win_loss_ratio_length = 0;
    size_t max_score_difference_length = 0;

    vector<Team*> teams = league.get_teams();
    for (auto it = teams.begin(); it != teams.end(); ++it){
        int current_team_name_length = ((*it)->get_name()).length();
        if (max_team_name_length < current_team_name_length){
            max_team_name_length = (size_t)current_team_name_length;
        }
        int current_win_loss_ratio_length = (to_string((*it)->get_wins()) + ":" + to_string((*it)->get_losses())).length();
        if (max_win_loss_ratio_length < current_win_loss_ratio_length){
            max_win_loss_ratio_length = (size_t)current_win_loss_ratio_length;
        }
        int current_score_difference_length = (to_string((*it)->get_points_scored() - (*it)->get_pointed_absorbed())).length();
        if (max_score_difference_length < current_score_difference_length){
            max_score_difference_length = (size_t)current_score_difference_length;
        }
    }

    cout << "┌"; ntimes(max_team_name_length, "─"); cout << "╥";
    ntimes(max_win_loss_ratio_length, "─"); cout << "┬";
    ntimes(max_score_difference_length, "─"); cout << "┐" << endl;

    for (auto it = teams.begin(); it != teams.end(); ++it){
        
        if (it != teams.begin()){
            cout << "├"; ntimes(max_team_name_length, "─"); cout << "╫";
            ntimes(max_win_loss_ratio_length, "─"); cout << "┼";
            ntimes(max_score_difference_length, "─"); cout << "┤" << endl;
        }

        string team_name = (*it)->get_name();
        string win_loss_ratio = to_string((*it)->get_wins()) + ":" + to_string((*it)->get_losses());
        string score_difference = to_string((*it)->get_points_scored() - (*it)->get_pointed_absorbed());

        cout << "│" << team_name << string(max_team_name_length - team_name.length(), ' ') << "║"
             << win_loss_ratio << string(max_win_loss_ratio_length - win_loss_ratio.length(), ' ') << "│"
             << score_difference << string(max_score_difference_length - score_difference.length(), ' ') << "│" << endl;
    }

    cout << "└"; ntimes(max_team_name_length, "─"); cout << "╨";
    ntimes(max_win_loss_ratio_length, "─"); cout << "┴";
    ntimes(max_score_difference_length, "─"); cout << "┘" << endl;
}

vector<string> Schedule::top_teams(int number){
    vector<string> top;
    for (unsigned int i = 0; i < number; i++){
        top.push_back(rated.at(i)->get_name());
    }
    return top;
}

pair<int, string> Schedule::longest_win_streak(){
    int longest = -1;
    int index = -1;
    for (unsigned int i = 0; i < rated.size(); i++){
        if (rated.at(i)->get_max_win_streak() > longest){
            longest = rated.at(i)->get_max_win_streak();
            index = (int)i;
        }
    }
    pair<int, string> team;
    team.first = longest;
    team.second = rated.at((unsigned int)index)->get_name();
    return team;
}

pair<int, string> Schedule::longest_loss_streak(){
    int longest = -1;
    int index = -1;
    for (unsigned int i = 0; i < rated.size(); i++){
        if (rated.at(i)->get_max_loss_streak() > longest){
            longest = rated.at(i)->get_max_loss_streak();
            index = (int)i;
        }
    }
    pair<int, string> team;
    team.first = longest;
    team.second = rated.at((unsigned int)index)->get_name();
    return team;
}

vector<string> Schedule::teams_that_scored_more_than_absorbed(){
    vector<string> teams;
    for (unsigned int i = 0; i < rated.size(); i++){
        if (rated.at(i)->get_points_scored() > rated.at(i)->get_pointed_absorbed()){
            teams.push_back(rated.at(i)->get_name());
        }
    }
    return teams;
}

int Schedule::times_home_team_won(){
    int sum = 0;
    for (unsigned int i = 0; i < games.size(); i++){
        if (games.at(i)->get_winner() == games.at(i)->get_home_team()){
            sum++;
        }
    }
    return sum;
}

double Schedule::average_points_per_game(){
    unsigned int i = 0;
    int sum = 0;
    for (i = 0; i < games.size(); i++){
        sum += games.at(i)->get_home_points();
        sum += games.at(i)->get_away_points();
    }
    return (double)sum/(i*2);
}