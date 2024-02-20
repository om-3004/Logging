#include <iostream>
#include "./include/log.h"
#include "./include/date.h"
#include "./include/string.h"
#include "./include/exception.h"
#include "./include/logger.h"

// TODO: COLOUR FORMATTING
int main()
{
	using LogSystem::Log;
	using Util::String;
	using Util::Date;
	using namespace Exception;

	//Log log{"Om", Log::LevelInfo, "logs.txt"};
	////log.dumpInFile = true;
	//log.Debug("Debug");
	//log.Info("Information");
	//log.Warn("Warning");
	//log.Error("Error");
	//log.Critical("Critical");

	//LogSystem::Log::dumpInFile = true;
	// Cannot dump in file while using namespace
	LogSystem::Debug("Debug");
	LogSystem::Info("Information");
	LogSystem::Warn("Warning");
	LogSystem::Error("Error");
	LogSystem::Critical("Critical");

	/*log1.Info("Info");
	log1.Warn("Warning");
	log1.Error("Error");
	log1.Critical("Critical");*/

	// CHECKED - DATE FORMAT
	/*try {
		Date d{ 30, 4, 2003, dmy };
		d.displayDate();
		Date d1{ 30, 2003, 4, dym };
		d1.displayDate();
		Date d2{ 4, 30, 2003, mdy };
		d2.displayDate();
		Date d3{ 4, 2003, 30, myd };
		d3.displayDate();
		Date d4{ 2003, 30, 4, ydm };
		d4.displayDate();
		Date d5{ 2003, 4, 30, ymd };
		d5.displayDate();

	}
	catch (myException& e) {
		std::cout << e.getMessage() << '\n';
	}*/
	
	/*Log log = Log();
	log.SetLogLevel(Log::Level::LevelWarning);

	log.Info("Fine!");
	log.Warn("Carefull!");
	log.Error("Stop!");
	log.Error("Chup thai jaa");*/


	/*log.Info("Fine!", 2168);
	log.Warn("Carefull!", 47685, 'a', "abd");
	log.Error("Stop!", 574);
	log.Error("Chup thai jaa", 3.5);
	log.Error("Chup thai jaa");*/

	//log.Info("Fine!");
	//log.Warn("Carefull!");
	//log.Error("Stop!");
	//log.setDate(23, 4, 2024);

	//log.Info("Fine!");
	//log.Warn("Carefull!");
	//log.Error("Stop!");

	/*String s{ "Om" };
	try {
		std::cout << s[45] << '\n';
	}
	catch (myException& e) {
		std::cout << e.getMessage() << '\n';
	}*/

	//Date d1{ 31, 12, 2024 };
	//String s{ "Om" };
	//try {
	//	d1.setDate( 32, 12, 2024 );
	//	auto ch{ s[4] };
	//}
	//catch (InvalidDate& e) {
	//	std::cout << e.getMessage() << '\n';
	//}
	//catch (IndexOutOfBound& e) {
	//	std::cout << e.getMessage() << '\n';
	//}
}