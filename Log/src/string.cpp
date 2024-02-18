#include <cstring>
#include <iostream>
#include "../include/string.h"
#include "../include/exception.h"

using Util::String;

//default constructor
	String::String(const char* string)  {
		//std::cout << "Default constructor" << '\n';
		m_Size = static_cast<unsigned int>(strlen(string));
		m_Buffer = nullptr;
		m_Buffer = std::make_unique<char[]>(static_cast<size_t>(m_Size) + 1);
		//m_Buffer = new char[m_Size + 1];
		memcpy(m_Buffer.get(), string, m_Size);
		m_Buffer[m_Size] = '\0';
	}

//copy constructor
String::String(const String& other)  : m_Size(other.m_Size) {
	//std::cout << "Copy constructor" << '\n';
	m_Buffer = nullptr;

	m_Buffer = std::make_unique<char[]>(static_cast<size_t>(m_Size) + 1);
	memcpy(m_Buffer.get(), other.m_Buffer.get(), static_cast<size_t>(m_Size) + 1);
}

//copy assignment
String& String::operator=(const String& other)  {
	if (this != &other) { //CHECK for self assignemnt
		m_Buffer = nullptr;

		m_Size = other.m_Size;
		m_Buffer = std::make_unique<char[]>(static_cast<size_t>(m_Size) + 1);
		memcpy(m_Buffer.get(), other.m_Buffer.get(), static_cast<size_t>(m_Size) + 1);
	}

	return *this;
}

//move constructor
String::String(String&& other) noexcept: m_Buffer(std::move(other.m_Buffer)), m_Size(other.m_Size) {
	//std::cout << "Move constructor" << '\n';
	
	// IMP
	other.m_Size = 0;
	other.m_Buffer = nullptr;
}

//move assignment
String& String::operator=(String&& other) noexcept {
	if (this != &other) { // CHECK
		m_Buffer = nullptr;

		m_Size = other.m_Size;
		m_Buffer = std::move(other.m_Buffer);
		// IMP
		other.m_Size = 0;
		other.m_Buffer = nullptr;
	}

	return *this;
}

char& String::operator[](unsigned int index) const {
	if (index <= m_Size)
		return m_Buffer[index];
	else
		throw Exception::IndexOutOfBound("Excessing out of bound index");
}

bool String::operator==(const String& other) const {
	if (m_Size != other.m_Size) {
		return false;
	}
	else {
		for (auto i = 0U; i < m_Size; i++) {
			if (m_Buffer[i] != other.m_Buffer[i])
				return false;
		}
		return true;
	}
}

String Util::operator+(const String& str, const String& other) {
	auto new_size{ str.m_Size + other.m_Size };
	auto newBuffer = std::make_unique<char[]>(static_cast<size_t>(new_size) + 1);
	memcpy(newBuffer.get(), str.m_Buffer.get(), str.m_Size);
	memcpy(newBuffer.get() + str.m_Size, other.m_Buffer.get(), other.m_Size);
	newBuffer[new_size] = '\0';
	String AppendString(newBuffer.get());
	
	newBuffer = nullptr;

	return AppendString;
}

String& String::append_string(const String& other) {
	auto new_size{ m_Size + other.m_Size };
	auto newBuffer = std::make_unique<char[]>(static_cast<size_t>(new_size) + 1);
	memcpy(newBuffer.get(), m_Buffer.get(), m_Size);
	memcpy(newBuffer.get() + m_Size, other.m_Buffer.get(), other.m_Size);
	newBuffer[new_size] = '\0';

	m_Buffer = nullptr;

	m_Buffer = std::move(newBuffer);
	m_Size = new_size;

	return *this;
}

String& String::to_lower() {
	// 65 - 90
	for (auto i = 0U; i < m_Size; i++) {
		if ((m_Buffer[i] >= 65) && (m_Buffer[i] <= 90))
			m_Buffer[i] += 32;
	}
	return *this;
}

String& String::to_upper() {
	// 97 - 122
	for (auto i = 0U; i < m_Size; i++) {
		if ((m_Buffer[i] >= 97) && (m_Buffer[i] <= 122)) m_Buffer[i] -= 32;
	}
	return *this;
}

static void swap(char& a, char& b) {
	auto temp = a;
	a = b;
	b = temp;
}

void String::reverseString(String& s) {
	auto begin{ 0 };
	auto end{ s.length() - 1 };

	while (begin < end) {
		swap(s[begin], s[end]);
		begin++; end--;
	}

	return;
}

String String::to_string(int n) { // to_string(12)

	if (n == 0) {
		auto str{ new char[2] };
		str[0] = '0';
		str[1] = '\0';
		return String{ str };
	}

	auto len{ 0 };
	auto temp{ n };

	while (temp) {
		temp /= 10;
		len++;
	}

	auto str{ new char[len + 1] };
	auto i{ 0 };
	while (n) {
		str[i++] = n % 10 + '0';
		n /= 10;
	}
	str[len] = '\0';

	String s1{ str };
	reverseString(s1);

	return String{ s1 };
}


std::ostream& Util::operator<<(std::ostream& stream, const String& string) {
	stream << string.m_Buffer;
	return stream;
}