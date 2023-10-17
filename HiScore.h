/* HiScore.h
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

#ifndef HISCORE_H
#define HISCORE_H

#include <chrono>
#include <compare>

namespace hiscore 
{
	typedef std::chrono::year_month_day ymd;

	class HiScore
	{
	public:
		
		HiScore(std::string name, int score,ymd date);
		// name, score, and date must be specified
		bool operator==(const HiScore& rhs) const;
		bool operator!=(const HiScore& rhs) const;
		bool operator<(const HiScore& rhs)  const;
		bool operator<=(const HiScore& rhs) const;
		bool operator>(const HiScore& rhs)  const;
		bool operator>=(const HiScore& rhs) const;
		//compare operators used for sorting hi-scores by score

		std::string getName() const;
		int getScore() const;
		ymd getDate() const;
		friend std::ostream& operator<<(std::ostream& out, const HiScore& hiscore);
		//Prints name, score, and date

	private:
		HiScore();
		// Construction a HiScore without infomation is not allowed
		int score;
		std::string name;
		std::chrono::year_month_day date;

	};
}


#endif // !HISCORE_h
