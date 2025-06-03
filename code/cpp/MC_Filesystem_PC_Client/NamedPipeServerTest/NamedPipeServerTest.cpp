#include "pch.h"
#include "CppUnitTest.h"

#include "NamedPipeFunctionalServer.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace NamedPipeFunctionalServer;

namespace NamedPipeServerTest
{
	TEST_CLASS(NamedPipeServerTest)
	{
	public:
		
		TEST_METHOD(InitServerTest)
		{
			int returnValue = Start();
			Assert::AreEqual(0, returnValue);
		}

		//TEST_METHOD(TryInitTwoServersTest)
		//{
		//	int returnValue1 = Start();
		//	Assert::AreEqual(EXITCODE_SUCCESS, returnValue1);

		//	int returnValue2 = Start();
		//	Assert::AreEqual(EXITCODE_PIPEINITFAILED, returnValue2);
		//}


	};
}
