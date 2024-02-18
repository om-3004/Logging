#ifndef _STRING_h_
#define _STRING_h_

#include <cstring>
#include <iostream>

namespace Util {
	class String {
	private:
		std::unique_ptr<char[]> m_Buffer{};
		unsigned int m_Size{ 0 };
	public:
		//default constructor
		String(const char* string = "");

		//copy constructor
		String(const String& other);

		//copy assignment
		String& operator=(const String& other);

		//move constructor
		String(String&& other) noexcept;

		//move assignment
		String& operator=(String&& other) noexcept;

		/*~String() {
			delete[] m_Buffer;
		}*/

		int length() const {
			return m_Size;
		}

		// operators
		char& operator[](unsigned int ) const;
		bool operator==(const String& ) const ;
		friend String operator+(const String&, const String& );

		//methods
		String& append_string(const String&);
		String& to_lower();
		String& to_upper();
		static void reverseString(String&);
		static String to_string(int);

		friend std::ostream& operator<<(std::ostream& stream, const String& string);
	};
}

#endif
