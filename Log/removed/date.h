#ifndef _DATE_H
#define _DATE_H

#include "string.h"
#include <iostream>

enum d_Format {
	dmy, dym, mdy, myd, ydm, ymd
};

namespace Util {
	class Date
	{
	public:
		Date(unsigned int a, unsigned int b, unsigned int c, d_Format format = dmy);

		//getter setter for day
		unsigned int getDay() const {
			return m_Day;
		}
		void setDay(unsigned int& day);

		//getter setter for month
		unsigned int getMonth() const {
			return m_Month;
		}
		void setMonth(unsigned int& month);

		//getter setter for year
		unsigned int getYear() const {
			return m_Year;
		}
		void setYear(unsigned int& year);

		void setDate(const unsigned int& day, const unsigned int& month, const unsigned int& year);


		//add attr mem func
		Date& add_day(unsigned int );
		Date& add_month(const unsigned int& );
		Date& add_year(const unsigned int& );

		String getStrDate();
		void updateCache();

		void displayDate() const;

	private:
		unsigned int m_Day;
		unsigned int m_Month;
		unsigned int m_Year;

		bool isLeap(unsigned int );
		unsigned int daysInMonth(unsigned int , unsigned int );

		mutable String m_Cache;
		bool m_IsCacheValid;

		d_Format m_Format;
		void dateFormatter(unsigned int day, unsigned month, unsigned year);
	};
}

#endif