/* To debug my code, for every function that I implemented, I tested them each individually. 
First, starting with all the code in int main, I slowly took it apart using functions and global variables.
The major part of my debugging process was using call by reference and call by order functions as those were very unfamiliar to me.
I would often mix them up, but because I tested after each time I was able to realise my issues for each individual funciton.
I also had problems with the for loop and switch case since I was generating the wrong numbers from 0-29 and 0-5 instead of 1-30 and 
1-6. I was able to resolve my issues through taking it one at a time and testing every time I added a function or loop.
*/
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

// Setting up Global Variables to Track Scores 
int team_a_score = 0, team_b_score = 0;
int team_a_ycards = 0, team_b_ycards = 0;
int team_a_shots_on = 0, team_b_shots_on = 0;
int team_a_blocks = 0, team_b_blocks = 0;
int team_a_shots_off = 0, team_b_shots_off = 0;
int team_a_fouls = 0, team_b_fouls = 0;
int team_a_rcards = 0, team_b_rcards = 0;

// Setting up Variables for random events
int event_type; 
int number_of_events;

// Declaring functions for each type of event
string attempted_shot_team_a(int outcome);
string attempted_shot_team_b(int outcome);
string foul_team_b(int card);
string foul_team_a(int card);
string penalty_team_a(int kick);
string penalty_team_b(int kick);

// Declaring functions to generate an intial random number, run through events, and print out stats for halftime and end
void generate_random_number();
void run_events();
void stats();
void initiate_soccer_game();

int main(){
    generate_random_number();       // Generates a random number to decide the number of events that happen
    initiate_soccer_game();         // Starts soccer game simulation
}

// This function handles when Team A attempts a shot
string attempted_shot_team_a(int outcome){
    outcome = rand() % 4;           // Generates random number from 0-3
    
    if (outcome == 0){              // If number = 0, then it returns that team A makes a goal
        team_a_score++;             // Team A making a goal and shooting on target is recorded
        team_a_shots_on++;
        return "Team A attempts a shot and... \nTeam A has made a goal! Good shot! \n";
    }
    else if (outcome == 1){         // If number = 1, then it returns that team A's shot is blocked while on target
        team_a_shots_on++;          // Team A shooting on target and Team B blocking is recorded 
        team_b_blocks++;
        return "Team A attempts a shot and... \nThe shot was on target, but blocked by the goalie! Nice Block! \n";
    }
    else if (outcome == 2){         // If number = 2, then it returns that Team A's shot misses completely
        team_a_shots_off++;         // Team A shooting off target is recorded 
        return "Team A attempts a shot and... \nMisses the net and any defenders! Unfortunate miss!\n";
    }   
    else{                           // If number = 3, then it returns Team A's shot is blocked while off target
        team_a_shots_off++;         // Team A shooting off target and Team B's block is recorded 
        team_b_blocks++;
        return "Team A attempts a shot and... \nIt's blocked by the defenders! Amazing defence Team B!\n";
    }
}

// This functional handles when Team B attempts a shot
string attempted_shot_team_b(int outcome){
     outcome = rand() % 4;         // The same applies for this function as attempted_shot_team_a
    
    if (outcome == 0){              // It will check and then return the appropriate text for Team B
        team_b_score++;             // It will add the stats the same way, but this time for Team B
        team_b_shots_on++;
        return "Team B attempts a shot and... \nTeam B has made a goal! Nice shot! \n";     
    }
    else if (outcome == 1){
        team_b_shots_on++;      
        team_a_blocks++;
        return "Team B attempts a shot and... \nThe shot was on target, but blocked by the goalie! Nice Block! \n";
    }
    else if (outcome == 2){
        team_b_shots_off++;
        return "Team B attempts a shot and... \nMisses the net and any defenders! Unfortunate miss!\n";
    }
    else{
        team_b_shots_off++;
        team_a_blocks++;
        return "Team B attempts a shot and... \nIt's blocked by the defenders! Amazing defence Team A!\n";
    }
}

// This function handles when Team B makes a foul 
string foul_team_b(int card){
     card = rand() % 3;             // Generates a random number between 0-2
     team_b_fouls++;                // Team B's Foul is recorded 
    if (card == 0){
        return "A foul is called on Team B!\n";     // If the number = 0, then it returns that the foul is called 
    }
    else if (card == 1){                            // If the number = 1, then it returns that a yellow card is called
        team_b_ycards++;                            // Team B's yellow card is recorded 
        return "Foul!! Yellow card on Team B!\n";
    }
    else{                                           // If the number is 2, then it returns that a red card was called
        team_b_rcards++;                            // Team B's red card is recorded
        return "Foul!! Red card on Team B!\n";
    }
}

// This function handles when Team A makes a foul 
string foul_team_a(int card){
     card = rand() % 3;             // The same applies to this function as foul_team_b
     team_a_fouls++;                // The stats are recorded the same way except for Team A instead of Team B
    if (card == 0){
        return "A foul is called on Team A!\n";
    }
    else if (card == 1){            
        team_a_ycards++;
        return "Foul!! Yellow card on Team A!\n";
    }
    else{
        team_a_rcards++;
        return "Foul!! Red card on Team A!\n";
    }
}

// This function handles when Team A gets a penalty shot
string penalty_team_a(int kick){
     kick = rand() % 3;         // Randomly selects a number between 0-2
    if (kick == 0){             // If the number is 0 then Team A makes the penalty shot 
        team_a_score++;         // Team A's goal and shot on target is recorded
        team_a_shots_on++;
        return "Team A takes the penalty shot and scores! What a goal!\n";
    }
    else if (kick == 1){        // If the number is 1. then Team A's penalty was blocked by the goalie
        team_a_shots_on++;      // Team A's shot on target and Team B's block is recorded
        team_b_blocks++;
        return "Team A takes the penalty, but the goalie blocks! Amazing defence!\n";
    }
    else{                       // If the number is 2, then Team A missed the net completely 
        team_a_shots_off++;     // Team A's shot off target is recorded
        return "Team A takes the penalty, but misses! Unlucky!\n";
    }
}

// This function handles when Team B gets a penalty shot
string penalty_team_b(int kick){
    kick = rand() % 3;      // The same is applied to this function as in penalty_team_a
    if (kick == 0){
        team_b_score++;     // The stats are recorded the same except for Team B instead of Team A
        team_b_shots_on++;
        return "Team B takes the penalty shot and scores! What a goal!\n";
    }
    else if (kick == 1){
        team_b_shots_on++;
        team_a_blocks++;
        return "Team B takes the penalty, but the goalie blocks! Amazing defence! \n";
    }
    else{
        team_b_shots_off++;
        return "Team B takes the penalty, but misses! Unlucky!\n";
    }
}

// This function generates a random number, and then determines the amount of events that will happen
void generate_random_number(){
    srand(time(0));                         // Random number is generated 
    number_of_events = rand() % 30 + 1;     // The number is then place in a range from 1-30
}

// This function determines which kind of event will happen
void run_events() {
    event_type = rand() % 6 + 1;        // Generates a number between 1-6
    switch (event_type){            // If the number is 1, then Team A attempts a shot
        case 1:
             cout << attempted_shot_team_a(0);
            break;
        case 2:                     // If the number is 2, then Team B attempts a shot
             cout << attempted_shot_team_b(0);
            break;
        case 3:                     // If the number is 3, then a foul is called against Team B and Team A attempts a shot
             cout << foul_team_b (0) << "Team A is rewarded a free kick!\n" << attempted_shot_team_a (0);
            break;
        case 4:                     // If the number is 4, then a foul is called against Team A and Team B attempts a shot
             cout << foul_team_a(0) <<  "Team B is rewarded a free kick!\n" << attempted_shot_team_b(0);
            break;
        case 5:                     // If the number is 5, then a foul is called agiinst Team B and Team A gets a penalty
             cout << foul_team_b(0) << "Team A is rewarded a penalty since it was close to net!\n" << penalty_team_a(0);
            break;
        case 6:                     // If the number is 6, then a foul is called agiinst Team A and Team B gets a penalty
             cout << foul_team_a(0) << "Team B is rewarded a penalty since it was close to net!\n" << penalty_team_b(0);
            break;
        
      }
    cout << "---------------------------------------------------\n";
}


// This function outputs all the stats 
void stats(){
       cout << "          Team: A | B\n";                       // It uses all the global variables that have been recording the stats to output the current stats
       cout << "         Score: " << team_a_score << " | " << team_b_score << "\n";
       cout << " Shots on Goal: " << team_a_shots_on << " | " << team_b_shots_on << "\n";
       cout << "Shots off Goal: " << team_a_shots_off << " | " << team_b_shots_off << "\n";
       cout << "        Blocks: " << team_a_blocks << " | " << team_b_blocks << "\n";
       cout << "         Fouls: " << team_a_fouls << " | " << team_b_fouls<< "\n"; 
       cout << "  Yellow Cards: " << team_a_ycards << " | " << team_b_ycards << "\n";
       cout << "     Red Cards: " << team_a_rcards << " | " << team_b_shots_on << "\n";
       cout << "---------------------------------------------------\n";

}

void initiate_soccer_game(){
    for (int i = 0; i < number_of_events/2; i++){                 // Loops for the first half of the game
        run_events();                                             // Chooses events randomly and outputs them using function
    }
       cout << "Halftime! Here are the stats!\n";                 // Outputting halftime statistics using function
        stats();
    for (int i = number_of_events/2; i <= number_of_events; i++){ // Loops for the second half of the game using function 
        run_events();
    }
      cout << "Anddd Game! Here are the stats!\n";                // Outputting end of game stats using function
        stats(); 
}
