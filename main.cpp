// run "make main"
// then run "./main"

#include "sources/Schedule.hpp"

int main(){

    Team t1 = Team("best", 1);
    Team t2 = Team("worst", 0);
    vector<Team> t = {t1, t2};

    Schedule s(t);

    cout << "Results:" << endl;
    s.result_table();
    cout << endl;

    pair<int, string> win_streak = s.longest_win_streak();
    cout << "Team '" << win_streak.second << "' had the longest win streak of " << win_streak.first << endl;
    cout << endl;

    pair<int, string> loss_streak = s.longest_loss_streak();
    cout << "Team '" << loss_streak.second << "' had the longest loss streak of " << loss_streak.first << endl;
    cout << endl;

    vector<string> top = s.top_teams(MAX_TEAMS);
    cout << "Top " << MAX_TEAMS << " teams:" << endl;
    for (unsigned int i = 0; i < top.size(); i++){
        cout << i+1 << ". " << top.at(i) << endl;
    }
    cout << endl;

    vector<string> scored = s.teams_that_scored_more_than_absorbed();
    cout << "Teams that scored more than absorbed:" << endl;
    for (unsigned int i = 0; i < scored.size(); i++){
        cout << scored.at(i) << endl;
    }
    cout << endl;

    cout << "Times the home team won: " << s.times_home_team_won() << endl;
    cout << endl;

    cout << "Average points per game: " << s.average_points_per_game() << endl;
    cout << endl;

    return 0;
}