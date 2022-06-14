#include "doctest.h"
#include "sources/Schedule.hpp"

TEST_CASE("tests"){
    vector<string> names = {"Angles", "Beavers", "Chitas", "Devils", "Emus",
                            "Foxes", "Giants", "Hornets", "Iguanas", "Jaguars",
                            "Koalas", "Llamas", "Monkeys", "Nimphs", "Owels",
                            "Panthers", "Queens", "Rebels", "Sharks", "Tigers"};

    vector<double> talent_levels = {0.05, 0.1, 0.15, 0.2, 0.25, 0.3, 0.35, 0.4, 0.45, 0.5,
                                    0.55, 0.6, 0.65, 0.7, 0.75, 0.8, 0.85, 0.9, 0.95, 1};
    
    vector<Team> teams;
    for (unsigned int i = 0; i < MAX_TEAMS; i++){
        Team team(names.at(i), talent_levels.at(i));
        teams.push_back(team);
    }

    Schedule schedule(teams);

    CHECK_NOTHROW(schedule.result_table());

    int longest = -1;
    int index = -1;
    for (unsigned int i = 0; i < teams.size(); i++){
        if (teams.at(i).get_max_win_streak() > longest){
            longest = teams.at(i).get_max_win_streak();
            index = (int)i;
        }
    }

    CHECK_EQ(longest, schedule.longest_win_streak().first);
    CHECK_EQ(teams.at((unsigned int)index).get_name(), schedule.longest_win_streak().second);

    longest = -1;
    index = -1;
    for (unsigned int i = 0; i < teams.size(); i++){
        if (teams.at(i).get_max_loss_streak() > longest){
            longest = teams.at(i).get_max_loss_streak();
            index = (int)i;
        }
    }

    CHECK_EQ(longest, schedule.longest_loss_streak().first);
    CHECK_EQ(teams.at((unsigned int)index).get_name(), schedule.longest_loss_streak().second);   
}