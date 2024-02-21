#include <iostream>
#include "./include/log.h"
//#include "./include/date.h"
//#include "./include/string.h"
//#include "./include/exception.h"
#include "./include/logger.h"

// TODO: COLOUR FORMATTING
int main()
{
	using LogSystem::Log;
	/*using Util::String;
	using Util::Date;
	using namespace Exception;*/

	auto myCustomLogger = std::make_shared<Log>( "Om Thakkar", Log::LevelDebug, "logs.txt");
	myCustomLogger->Debug("Debug");
	myCustomLogger->Info("Information");
	myCustomLogger->Warn("Warning");
	myCustomLogger->Error("Error");
	myCustomLogger->Critical("Critical");

	Log log{"Om", Log::LevelDebug, "logs.txt"};
	//log.dumpInFile = true;
	log.Debug("Debug");
	log.Info("Information");
	log.Warn("Warning");
	log.Error("Error");
	log.Critical("Critical");

	//LogSystem::Log::dumpInFile = true;
	// 
	// CANNOT DUMP IN FILE WHILE USING NAMESPACE
	//LogSystem::Debug("Debug");
	//LogSystem::Info("Information");
	//LogSystem::Warn("Warning");
	//LogSystem::Error("Error");
	//LogSystem::Critical("Critical");
}