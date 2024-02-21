#ifndef _LOG_H
#define _LOG_H

#include <iostream>
#include <chrono>
#include <string>
#include "string.h"


namespace LogSystem {

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
		Log(const std::string& name) : m_NameLogger{ name }, m_Date{ getStrDateTime() } {}
		Log(const std::string& name, const Level& level) : m_NameLogger{name}, m_LogLevel { level }, m_Date{ getStrDateTime() } {}
		Log(const std::string& name, const Level& level, const std::string& file) : m_NameLogger{ name }, m_LogLevel{ level }, m_FileName{ file }, m_Date{ getStrDateTime() }, dumpInFile{true} {}

		void SetLogLevel(const Level& level) {
			m_LogLevel = level;
		}

		//void setDate(const unsigned int&, const unsigned int&, const unsigned int&);
		Level getLogLevel() const {
			return m_LogLevel;
		}

		template<typename ...Args>
		void log(const std::string& msg, const Level& level, Args ...args);
		
		template<typename ...Args>
		void Debug(const std::string& msg, Args ...args);
		template<typename ...Args>
		void Error(const std::string& msg, Args ...args);
		template<typename ...Args>
		void Warn(const std::string& msg, Args ...args);
		template<typename ...Args>
		void Info(const std::string& msg, Args ...args);
		template<typename ...Args>
		void Critical(const std::string& msg, Args ...args);

		void print() { std::cout << '\n'; }
		template<typename T, typename ...Args>
		void print(T arg, Args ...args) {
			std::cout << arg << " ";
			print(args...);
		}

		void appendBuffer() { m_BufferLog.append("\n"); }
		template<typename T, typename ...Args>
		void appendBuffer(T arg, Args ...args) {
			m_BufferLog.append(arg).append(" ");
			appendBuffer(args...);
		}

		bool dumpInFile{ false };

	private:
		short int countLogs{ 0 };

		Level m_LogLevel;
		std::string m_Date;

		std::string m_NameLogger;
		std::string m_BufferLog{ "" };
		std::string m_FileName{ "default-log.txt" };

		// MOVE INTO CPP FILE
		std::string stringLevel(const Level& level);

		std::string stringLevelFile(const Level& level);

		std::string getStrDateTime();

	};
	
	/*void Log::setDate(const unsigned int& d, const unsigned int& m, const unsigned int& y) {
		m_Date.setDate(d, m, y);
	}*/

	template<typename ...Args>
	void Log::Debug(const std::string& msg, Args ...args) {
		log(msg, LevelDebug, args...);
	}

	template<typename ...Args>
	void Log::Info(const std::string& msg, Args ...args) {
		log(msg, LevelInfo, args...);
	}

	template<typename ...Args>
	void Log::Warn(const std::string& msg, Args ...args) {
		log(msg, LevelWarning, args...);
	}

	template<typename ...Args>
	void Log::Error(const std::string& msg, Args ...args) {
		log(msg, LevelError, args...);
	}

	template<typename ...Args>
	void Log::Critical(const std::string& msg, Args ...args) {
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