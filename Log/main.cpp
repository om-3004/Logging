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
	/*Log log = Log();
	log.SetLogLevel(Log::Level::LevelError);

	log.Info("Fine!");
	log.Warn("Carefull!");
	log.Error("Stop!");

	log.Info("Fine!");
	log.Warn("Carefull!");
	log.Error("Stop!");
	log.setDate(23, 4, 2024);

	log.Info("Fine!");
	log.Warn("Carefull!");
	log.Error("Stop!");*/

	/*String s{ "Om" };
	try {
		std::cout << s[45] << '\n';
	}
	catch (myException& e) {
		std::cout << e.getMessage() << '\n';
	}*/

	Date d1{ 31, 12, 2024 };
	String s{ "Om" };
	try {
		d1.setDate( 32, 12, 2024 );
		auto ch{ s[4] };
	}
	catch (InvalidDate& e) {
		std::cout << e.getMessage() << '\n';
	}
	catch (IndexOutOfBound& e) {
		std::cout << e.getMessage() << '\n';
	}

	



	String s1{ "OMTHAKKAR" };
	s1.to_lower();
	std::cout << "Lower: " << s1 << '\n';

	//String s2 = "Om";
	//String s3 = "Thakkar";
	//std::cout << "Om" + s3 << '\n';

		//String s1{ "Thakkar" };
		//s1 = std::move(s);
		////s1 = s;
		//std::cout << s1 << '\n';
		//std::cout << s << '\n';

		/*String s1{ "Thakkar" };
		String s2{ s1 };
		String s3 = std::move(s1);*/

		/*String s = "Om";
		String::reverseString(s);
		std::cout << s;*/

		//std::cin.get();
}