// Empty
#include "../include/log.h"

using LogSystem::Log;

std::string Log::stringLevel(const Level& level) {
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

std::string Log::stringLevelFile(const Level& level) {
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

std::string Log::getStrDateTime() {
	auto now = std::chrono::system_clock::now();
	auto currTime = std::chrono::system_clock::to_time_t(now);

	std::tm localTime;
	localtime_s(&localTime, &currTime);

	std::string res = std::to_string(localTime.tm_mday);

	res.append("/").append(std::to_string(localTime.tm_mon + 1)).append("/").append(std::to_string(localTime.tm_year + 1900))
		.append(" ").append(std::to_string(localTime.tm_hour)).append(":").append(std::to_string(localTime.tm_min))
		.append(":").append(std::to_string(localTime.tm_sec));
	return res;
}