/* HiScore.cpp
*
* Class to hold hi-score values. A hi-score must have a name,
* score, and date (using std::chrono::year_month_day class) 
*
* C++20 required
*
* Author: Noel Mrowiec
* Date: 25April2023
* CSCI 221 FHSU
*/

#include "HiScore.h"

namespace hiscore {

    // Constructor. name, score, and date must be specified
    HiScore::HiScore(std::string name, int score, ymd date) :
        name{ name }, score{score}, date{date}
    {
    }

    //Overloaded compare operator
    bool HiScore::operator==(const HiScore& rhs) const
    {
        return (this->score == rhs.score);
    }

    //Overloaded compare operator
    bool HiScore::operator!=(const HiScore& rhs) const
    {
        return (this->score != rhs.score);
    }

    //Overloaded compare operator
    bool HiScore::operator<(const HiScore& rhs) const
    {
        return score < rhs.score;
    }

    //Overloaded compare operator
    bool HiScore::operator<=(const HiScore& rhs) const
    {
        return !(rhs.score < this->score);
    }

    //Overloaded compare operator
    bool HiScore::operator>(const HiScore& rhs) const
    {
        return rhs.score < this->score;
    }

    //Overloaded compare operator
    bool HiScore::operator>=(const HiScore& rhs) const
    {
        return !(this->score < rhs.score);
    }

    //Get name
    std::string HiScore::getName() const
    {
        return name;
    }

    //Get score
    int HiScore::getScore() const
    {
        return score;
    }

    //Get date
    ymd HiScore::getDate() const
    {
        return date;
    }

    //Prints name, score, and date
    std::ostream& operator<< (std::ostream& out, const HiScore& hiscore) {
        out << hiscore.getName() << ':';
        out << " Score = " << hiscore.getScore();
        out << " Date: " << hiscore.getDate() << std::endl;
        return out;
    }
}

