#ifndef _LOGGER_H
#define _LOGGER_H

#include <iostream>
#include "log.h"
#include "fileDump.h"

namespace LogSystem {

	auto myLogger = std::make_shared<Log>("System");

	std::shared_ptr<Log> defaultLogger() {
		return myLogger;
	}

	void setLogger(std::shared_ptr<Log> logger) {
		myLogger = logger;
	}

	template<typename ...Args>
	void Log::log(const std::string& msg, const Level& level, Args ...args) {
		if (level >= m_LogLevel) {
			std::cout << getStrDateTime() << " [ " << m_NameLogger << " ] " << stringLevel(level) << " : " << msg << " ";
			print();
		}

		if (dumpInFile) {
			countLogs++;
			m_BufferLog.append(getStrDateTime()).append(" ")
				.append("[ ").append(m_NameLogger)   // defaultLogger - delete
				.append(" ]").append(" ").append(stringLevelFile(level))
				.append(" : ").append(msg).append(" ");
			appendBuffer(args...);

			if (countLogs >= 5) {
				fileDump f{ m_FileName };
				f.flushStream(m_BufferLog);
				m_BufferLog = "";
				countLogs = 0;
			}
		}
	}

	template<typename ...Args>
	void Debug(const std::string& msg, Args ...args) {
		defaultLogger()->log(msg, Log::LevelDebug, args...);
	}
	template<typename ...Args>
	void Info(const std::string& msg, Args ...args) {
		defaultLogger()->log(msg, Log::LevelInfo, args...);
	}
	template<typename ...Args>
	void Warn(const std::string& msg, Args ...args) {
		defaultLogger()->log(msg, Log::LevelWarning, args...);
	}
	template<typename ...Args>
	void Error(const std::string& msg, Args ...args) {
		defaultLogger()->log(msg, Log::LevelError, args...);
	}
	template<typename ...Args>
	void Critical(const std::string& msg, Args ...args) {
		defaultLogger()->log(msg, Log::LevelCritical, args...);
	}
}

#endif
