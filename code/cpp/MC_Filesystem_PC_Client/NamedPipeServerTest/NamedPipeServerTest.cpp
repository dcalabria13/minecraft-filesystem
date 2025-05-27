#include "pch.h"
#include "CppUnitTest.h"
#include "MathLibrary.h"
#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace NamedPipeServerTest
{
	TEST_CLASS(NamedPipeServerTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			fibonacci_init(1, 1);

			// Write out the sequence values until overflow.
			do {
				std::cout << fibonacci_index() << ": "
					<< fibonacci_current() << std::endl;
			} while (fibonacci_next());
			// Report count of values written before overflow.
			std::cout << fibonacci_index() + 1 <<
				" Fibonacci sequence values fit in an " <<
				"unsigned 64-bit integer." << std::endl;

		}
	};
}
