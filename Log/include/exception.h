#ifndef _EXCEPTION_H
#define _EXCEPTION_H

#include "string.h"
using Util::String;

namespace Exception {

	class myException {
	protected:
		String m_Msg;
	public:
		myException(): m_Msg("Some Exception occurred") {}
		myException(const String& reason): m_Msg(reason) {}

		virtual String getMessage() {
			return m_Msg;
		}

		virtual ~myException() = default;
	};

	class InvalidDate: public myException {
		public:
		InvalidDate(const String& reason): myException(reason) {}

		String getMessage() override {
			return "Date class exception: " + m_Msg;
		}

	};

	class IndexOutOfBound : public myException {
	public:
		IndexOutOfBound(const String& reason) : myException(reason) {}

		String getMessage() override {
			return "String class Exception: " + m_Msg;
		}
	};
}

#endif