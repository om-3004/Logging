#include <iostream>
#include "./include/log.h"
#include "./include/date.h"
#include "./include/string.h"
#include "./include/exception.h"

int main()
{
	using LogSystem::Log;
	using Util::String;
	using Util::Date;
	using namespace Exception;

	//Log log = Log(Log::Level::LevelError);
	Log log = Log();
	log.SetLogLevel(Log::Level::LevelWarning);

	log.Info("Fine!", 2168);
	log.Warn("Carefull!", 47685, 'a', "abd");
	log.Error("Stop!", 574);
	log.Error("Chup thai jaa", 3.5);
	log.Error("Chup thai jaa");

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