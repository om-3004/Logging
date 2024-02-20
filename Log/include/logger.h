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
	void Log::log(const String& msg, const Level& level, Args ...args) {
		if (level >= m_LogLevel) {
			std::cout << m_Date.getStrDate() << " [ " << m_NameLogger << " ] " << stringLevel(level) << " : " << msg << " ";
			print();
		}

		if (dumpInFile) {
			countLogs++;
			m_BufferLog.append_string(m_Date.getStrDate()).append_string(" ")
				.append_string("[ ").append_string(m_NameLogger)   // defaultLogger - delete
				.append_string(" ]").append_string(" ").append_string(stringLevelFile(level))
				.append_string(" : ").append_string(msg).append_string(" ");
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
	void Debug(const String& msg, Args ...args) {
		defaultLogger()->log(msg, Log::LevelDebug, args...);
	}
	template<typename ...Args>
	void Info(const String& msg, Args ...args) {
		defaultLogger()->log(msg, Log::LevelInfo, args...);
	}
	template<typename ...Args>
	void Warn(const String& msg, Args ...args) {
		defaultLogger()->log(msg, Log::LevelWarning, args...);
	}
	template<typename ...Args>
	void Error(const String& msg, Args ...args) {
		defaultLogger()->log(msg, Log::LevelError, args...);
	}
	template<typename ...Args>
	void Critical(const String& msg, Args ...args) {
		defaultLogger()->log(msg, Log::LevelCritical, args...);
	}
}

#endif
