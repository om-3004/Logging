#include <iostream>
#include "../include/log.h"
#include "../include/date.h"

using Util::Date;
using LogSystem::Log;

//TODO: Template

void Log::setDate(int d, int m, int y) {
	m_Date.setDate(d, m, y);
}

void Log::Error(const String& msg) {
	if (m_LogLevel >= Log::Level::LevelError)
		std::cout << "Date: " << m_Date.getStrDate() << " [Error]: " << msg << "\n\n";

}

void Log::Warn(const String& msg) {
	if (m_LogLevel >= Log::Level::LevelWarning)
		std::cout << "Date: " << m_Date.getStrDate() << " [Warning]: " << msg << "\n";
}

void Log::Info(const String& msg) {
	if (m_LogLevel >= Log::Level::LevelInfo)
		std::cout << "Date: " << m_Date.getStrDate() << " [Info]: " << msg << "\n";
}
