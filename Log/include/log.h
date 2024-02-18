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
		inline Log(const Level& level = Level::LevelWarning) : m_LogLevel{ level }, m_Date{ 31, 12, 2022 } {

		}

		void SetLogLevel(const Level& level) {
			m_LogLevel = level;
		}

		void setDate(int, int, int);
	
		template<typename ...Args>
		void Error(const String& msg, Args ...args);
		template<typename ...Args>
		void Warn(const String& msg, Args ...args);
		template<typename ...Args>
		void Info(const String& msg, Args ...args);

		void print() {
			std::cout << '\n';
		}

		template<typename T, typename ...Args>
		void print(T arg, Args ...args) {
			std::cout << arg << " ";
			print(args...);
		}
	};
	
	void Log::setDate(int d, int m, int y) {
		m_Date.setDate(d, m, y);
	}

	template<typename ...Args>
	void Log::Error(const String& msg, Args ...args) {
		if (m_LogLevel >= Log::Level::LevelError) {
				std::cout << "Date: " << m_Date.getStrDate() << " [Error]: " << msg << " ";
			if (sizeof...(args) > 0)
				print(args...);
			else
				std::cout << "\n";
		}
	}

	template<typename ...Args>
	void Log::Warn(const String& msg, Args ...args) {
		if (m_LogLevel >= Log::Level::LevelWarning) {
				std::cout << "Date: " << m_Date.getStrDate() << " [Warning]: " << msg << " ";
			if (sizeof...(args) > 0)
				print(args...);
			else
				std::cout << "\n";
		}
	}
	
	template<typename ...Args>
	void Log::Info(const String& msg, Args ...args) {
		if (m_LogLevel >= Log::Level::LevelInfo) {
			std::cout << "Date: " << m_Date.getStrDate() << " [Info]: " << msg << " ";
			if (sizeof...(args) > 0)
				print(args...);
			else
				std::cout << "\n";
		}
	}
	
}

#endif