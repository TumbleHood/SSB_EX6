#include "doctest.h"
#include "sources/Schedule.cpp"

TEST_CASE("tests"){
    vector<string> names = {"Angles", "Beavers", "Chitas", "Devils", "Emus",
                            "Foxes", "Giants", "Huligans", "Indigos", "Jaguars",
                            "Koalas", "Llamas", "Monkeys", "Nimphs", "Owels",
                            "Panthers", "Queens", "Rebels", "Sharks", "Tigers"};

    vector<double> talent_levels = {0.05, 0.1, 0.15, 0.2, 0.25, 0.3, 0.35, 0.4, 0.45, 0.5,
                                    0.55, 0.6, 0.65, 0.7, 0.75, 0.8, 0.85, 0.9, 0.95, 1};
    
    vector<Team> teams;
    for (unsigned int i = 0; i < 0; i++){
        Team team = Team(names.at(i), talent_levels.at(i));
        teams.push_back(team);
    }

    Schedule schedule = Schedule(teams);

    CHECK_NOTHROW(schedule.result_table());
    
}