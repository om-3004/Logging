#include <iostream>
#include "../include/date.h"
#include "../include/string.h"
#include "../include/exception.h"

using Util::Date;
using Util::String;
//using Exception::myException;

// constructor
Date::Date(int day, int month, int year) {
	if (month < 1 || month > 12)
		throw Exception::InvalidDate("Invalid month");
	else {
		m_Month = month;
		if (day > daysInMonth(month, year)) {
			throw Exception::InvalidDate("Invalid day");
		}
		else {
			m_Day = day;
		}
	}
	m_Year = year;
	updateCache();
	m_IsCacheValid = false;
}

bool Date::isLeap(int m_Year) {
	if ((m_Year % 100 != 0 && m_Year % 4 == 0) || m_Year % 400 == 0)
		return true;
	return false;
}

int Date::daysInMonth(int m_Month, int m_Year) {
	switch (m_Month) {
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		return 31;
		break;
	case 4: case 6: case 9: case 11:
		return 30;
		break;
	case 2:
		return(isLeap(m_Year) ? 29 : 28);
		break;
	}
}

void Date::setDay(int& day) {
	if (day > daysInMonth(m_Month, m_Year))
		throw Exception::InvalidDate("Invalid day");
	m_Day = day;
	m_IsCacheValid = false;
}

void Date::setMonth(int& month) {
	if (month < 1 || month>12)
		throw Exception::InvalidDate("Invalid month");
	m_Month = month;
	m_IsCacheValid = false;
}

void Date::setYear(int& year) {
	m_Year = year;
	m_IsCacheValid = false;
}

Date& Date::add_day(int day) {

	while (day != 0) {
		auto DIM{ Date::daysInMonth(m_Month, m_Year) };
		if ((m_Day + day) <= DIM) {
			m_Day += day;
			day = 0;
		}
		else {
			m_Month++;
			if (m_Month > 12) {
				m_Year++;
				m_Month = 1;
			}
			auto temp{ DIM - m_Day };
			day -= temp;
			m_Day = 0;
		}
	}
	m_IsCacheValid = false;
	return *this;
}

Date& Date::add_month(int month){
	if((m_Month + month) > 12){
		m_Year += (month)/12;
		m_Month += month%12;
		if(m_Month > 12){
			m_Year++;
			m_Month = (m_Month-12);
		}

		auto DIM{ Date::daysInMonth(m_Month, m_Year) };
		if(DIM < m_Day){
			auto temp{ m_Day - DIM };
			m_Month++;
			m_Day = temp;

			// As dec has 31(which is max) days, it will work even if we won't check this condition again, or else if it overflows the max days in a month and after correcting it and making m_Month++, and if the incremented m_Month overflows the year (12 months), then we again had to adjust it by making m_Year++...
			// if(m_Month > 12){
			// 	m_Year++;
			// 	m_Month = (m_Month-12);
			// }
		}
	} else {
		m_Month += month;
		auto DIM{ Date::daysInMonth(m_Month, m_Year) };
		if(DIM < m_Day){
			int temp = m_Day - DIM;
			m_Month++;
			m_Day = temp;

		// As dec has 31(which is max) days, it will work even if we won't check this condition again, or else if it overflows the max days in a month and after correcting it and making m_Month++, and if the incremented m_Month overflows the year (12 months), then we again had to adjust it by making m_Year++...
		// if(m_Month > 12){
		// 	m_Year++;
		// 	m_Month = (m_Month-12);
		// }
		}
	}
	m_IsCacheValid = false;
	return *this;
}

Date& Date::add_year(int year) {
	m_Year += year;
	m_IsCacheValid = false;
	return *this;
}

void Date::updateCache() {
	m_Cache = "";
	m_Cache.append_string(String::to_string(m_Day)).append_string("/");
	m_Cache.append_string(String::to_string(m_Month)).append_string("/");
	m_Cache.append_string(String::to_string(m_Year));
	m_IsCacheValid = true;
}

String Date::getStrDate() {
	if (!m_IsCacheValid) {
		std::cout << "Cache miss" << '\n';
		updateCache();
	}
	else {
		std::cout << "Cache hit" << '\n';
	}
	return m_Cache;
}

void Date::setDate(const int& day, const int& month, const int& year) {
	if (month < 1 || month > 12)
		throw Exception::InvalidDate("Invalid month");
	else {
		m_Month = month;
		if (day > daysInMonth(month, year)) {
			throw Exception::InvalidDate("Invalid day");
		}
		else {
			m_Day = day;
		}
	}
	m_Year = year;
	m_IsCacheValid = false;
}

void Date::displayDate() const {
	std::cout << m_Day << '/' << m_Month << '/' << m_Year << '\n';
}