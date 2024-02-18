#ifndef _LOG_H
#define _LOG_H

#include <iostream>
#include "date.h"
#include "string.h"


namespace LogSystem {
	using Util::Date;
	using Util::String;
	class Log
	{
	public:
		enum class Level {
			LevelError, LevelWarning, LevelInfo
		};
	private:
		Level m_LogLevel;
		Date m_Date;
	public:
		// default constructor
		/*explicit inline Log() : m_LogLevel{ Level::LevelWarning } {
	
		}*/

		// parameterized constructor
		inline Log(const Level& level = Level::LevelWarning) : m_LogLevel{ level }, m_Date{31, 12, 2022} {
			
		}

		void SetLogLevel(const Level& level) {
			m_LogLevel = level;
		}

		void setDate(int , int , int );
	
		void Info(const String&) ;
		void Warn(const String&);
		void Error(const String&);
	};
}

#endif