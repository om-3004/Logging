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
		enum Level {
			LevelDebug,
			LevelInfo,
			LevelWarning,
			LevelError,
			LevelCritical
		};
		Log(const String& name) : m_NameLogger{ name }, m_Date{ 31, 12, 2022, dmy } {}
		Log(const String& name, const Level& level) : m_NameLogger{name}, m_LogLevel { level }, m_Date{ 31, 12, 2022, dmy } {}
		Log(const String& name, const Level& level, const String& file) : m_NameLogger{ name }, m_LogLevel{ level }, m_FileName{ file }, m_Date{ 31, 12, 2022, dmy }, dumpInFile{true} {}

		void SetLogLevel(const Level& level) {
			m_LogLevel = level;
		}

		void setDate(const unsigned int&, const unsigned int&, const unsigned int&);
		Level getLogLevel() const {
			return m_LogLevel;
		}

		template<typename ...Args>
		void log(const String& msg, const Level& level, Args ...args);
		
		template<typename ...Args>
		void Debug(const String& msg, Args ...args);
		template<typename ...Args>
		void Error(const String& msg, Args ...args);
		template<typename ...Args>
		void Warn(const String& msg, Args ...args);
		template<typename ...Args>
		void Info(const String& msg, Args ...args);
		template<typename ...Args>
		void Critical(const String& msg, Args ...args);

		void print() { std::cout << '\n'; }
		template<typename T, typename ...Args>
		void print(T arg, Args ...args) {
			std::cout << arg << " ";
			print(args...);
		}

		void appendBuffer() { m_BufferLog.append_string("\n"); }
		template<typename T, typename ...Args>
		void appendBuffer(T arg, Args ...args) {
			m_BufferLog.append_string(arg).append_string(" ");
			appendBuffer(args...);
		}

		bool dumpInFile{ false };

	private:
		short int countLogs{ 0 };

		Level m_LogLevel;
		Date m_Date;

		String m_NameLogger;
		String m_BufferLog{ "" };
		String m_FileName{ "default-log.txt" };

		String stringLevel(const Level& level) {
			switch (level) {
			case LevelDebug:
				return "\033[0;35m[ DEBUG ]\033[0m";
			case LevelInfo:
				return "\033[0;36m[ INFO ]\033[0m";
			case LevelWarning:
				return "\033[1;33m[ WARNING ]\033[0m";
			case LevelError:
				return "\033[1;31m[ ERROR ]\033[0m";
			case LevelCritical:
				return "\033[0;31m[ CRITICAL ]\033[0m";
			}
			return "";
		}

		String stringLevelFile(const Level& level) {
			switch (level) {
			case LevelDebug:
				return "[ DEBUG ]";
			case LevelInfo:
				return "[ INFO ]";
			case LevelWarning:
				return "[ WARNING ]";
			case LevelError:
				return "[ ERROR ]";
			case LevelCritical:
				return "[ CRITICAL ]";
			}
			return "";
		}
	};
	
	void Log::setDate(const unsigned int& d, const unsigned int& m, const unsigned int& y) {
		m_Date.setDate(d, m, y);
	}

	template<typename ...Args>
	void Log::Debug(const String& msg, Args ...args) {
		log(msg, LevelDebug, args...);
	}

	template<typename ...Args>
	void Log::Info(const String& msg, Args ...args) {
		log(msg, LevelInfo, args...);
	}

	template<typename ...Args>
	void Log::Warn(const String& msg, Args ...args) {
		log(msg, LevelWarning, args...);
	}

	template<typename ...Args>
	void Log::Error(const String& msg, Args ...args) {
		log(msg, LevelError, args...);
	}

	template<typename ...Args>
	void Log::Critical(const String& msg, Args ...args) {
		log(msg, LevelCritical, args...);
		/*if (m_LogLevel >= Log::Level::LevelCritical) {
			std::cout << "Date: " << m_Date.getStrDate() << " [Critical]: " << msg << " ";
			if (sizeof...(args) > 0)
				print(args...);
			else
				std::cout << "\n";
		}*/
	}
}

#endif