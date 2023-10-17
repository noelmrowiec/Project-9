/* NoelMrowiecProj9.cpp
* This program is a hi-score tracker. It allows the user create a database of 
* high scores that are entered through the command prompt. The user must enter
* the name, the score (between 100 and 10,000 inclusive), and date of high score.
* The main menu allows the user to:
*    1) Add a Hi-Score
*    2) List Hi-Scores by score in descending order (highest to lowest)
*    3) Quit
* 
* Author: Noel Mrowiec
* Date: 25April2023
* CSCI 221 FHSU
*/

#include "HiScore.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono> // for date types


using namespace std;
using namespace hiscore;
using namespace chrono; // for date types

// a function to display the main menu and return the user's choice
int show_menu() {
    int choice;
    cout << "Main Menu\n";
    cout << "1) Add a Hi-Score\n";
    cout << "2) List Hi-Scores\n";
    cout << "3) Quit\n";
    cout << "Enter your choice: ";
    cin >> choice;
    return choice;
}

// a function to prompt user to enter the name of the high score
// returns a string
string get_hi_score_name() {
    string name;
    cout << "Enter the name of the player: ";
    cin >> name;
    return name;
}

// a function to prompts for score for the hi score and checks that 
// the score is valid (between 100 and 10,000 inclusive)
// returns value of score or -1 if score is invalid
int get_hi_score_value() {
    int score;
    cout << "Enter the score of the player: ";
    cin >> score;
    // check if the score is valid
    if (score < 100 || score > 10000) {
        cout << "Invalid score. The score must be between 100 and 10000.\n";
        return -1;
    }

    return score;
}

// a function to add a hi-score to a vector of hi-scores
// returns true if valid date entered, otherwise returns false
bool get_hi_score_date(year_month_day date) {
    int year;
    unsigned month, day; // for date input
    // ask the user to enter the date of the hi-score
    cout << "Enter the year of the hi-score: ";
    cin >> year;
    cout << "Enter the month of the hi-score (1-12): ";
    cin >> month;
    cout << "Enter the day of the hi-score (1-31): ";
    cin >> day;

    // combine year, month and day into year_month_day object
    date = chrono::year{ year }/ chrono::month{ month }/ chrono::day{ day };

    // check if the date is valid
    if (!date.ok()) {
        cout << "Invalid date. Please enter a valid date.\n";
        return false;
    }
    else
        return true;
}

// a function to add a hi-score to a vector of hi-scores
void add_hi_score(string name, int score, year_month_day date, vector<HiScore>& hi_scores) {

    // create a HiScore object and add it to the vector
    HiScore hi_score(name, score, date);
    hi_scores.push_back(hi_score);
}

// a function to sort a vector of hi-scores by score in descending order
void sort_hi_scores(vector<HiScore>& hi_scores) {
    // using the sort algorithm from STL to sort the vector
    sort(hi_scores.begin(), hi_scores.end(), greater<HiScore>());
}

// a function to display a vector of hi-scores
void list_hi_scores(const vector<HiScore>& hi_scores) {
    cout << "Hi-Scores (sorted in descending order):\n";
    for (const HiScore& hi_score : hi_scores) {
        cout << hi_score << "\n";
    }
}

// a function to clear any errors or extra input from the cin stream
void clearCin() {
    cin.clear();
    cin.ignore(1000, '\n');
}

int main() {
    vector<HiScore> hi_scores;

    // loop until the user chooses to quit
    bool quit = false;

    while (!quit) {
        int choice = show_menu();

        // perform different actions based on the user's choice
        switch (choice) {
            case 1:
            {
                // add a hi-score

                string name = get_hi_score_name();

                int score = -1;
                while (score == -1) {
                    //continue until valid score entered
                    score = get_hi_score_value();
                    clearCin();
                }

                year_month_day date = 2023y / 4 / 25d;       //default initialized

                bool validDate = false;
                while (!validDate){
                    //continue until valid date entered
                    validDate = get_hi_score_date(date);
                    clearCin();
                }

                add_hi_score(name, score, date, hi_scores);

                cout << "Successfully added: " << hi_scores.back() << endl;
                break;
            }
            case 2:
            {
                // sort and list hi-scores
                sort_hi_scores(hi_scores);
                list_hi_scores(hi_scores);
                break;
            }
            case 3:
            {
                // quit the program
                quit = true;
                break;
            }
            default:
            {
                // handle invalid choices
                cout << "Invalid choice. Please enter a number between 1 and 3.\n";
                break;
            }
        }//end switch

        // print an empty line for readability
        cout << "\n";

    }

}
