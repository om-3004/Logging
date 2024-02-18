#ifndef _DATE_H
#define _DATE_H

#include "string.h"
#include <iostream>

namespace Util {
	class Date
	{
	private:
		int m_Day;
		int m_Month;
		int m_Year;
		bool isLeap(int );
		int daysInMonth(int , int );
		mutable String m_Cache;
		bool m_IsCacheValid;

	public:
		Date(int day, int month, int year);

		//getter setter for day
		int getDay() const {
			return m_Day;
		}
		void setDay(int& day);

		//getter setter for month
		int getMonth() const {
			return m_Month;
		}
		void setMonth(int& month);

		//getter setter for year
		int getYear() const {
			return m_Year;
		}
		void setYear(int& year);

		void setDate(const int& day, const int& month, const int& year);


		//add attr mem func
		Date& add_day(int );
		Date& add_month(int );
		Date& add_year(int );

		String getStrDate();
		void updateCache();

		void displayDate() const ;
	};
}

#endif