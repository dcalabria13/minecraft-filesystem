#include "pch.h"
#include "CppUnitTest.h"
#include "PipeServerInternal.h"

#include "NamedPipeFunctionalServer.h"
#include "NamedPipeFunctionalServer.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace PipeServerInternal;
using namespace NamedPipeFunctionalServer;

namespace NamedPipeServerTest
{
	TEST_CLASS(NamedPipeServerTest)
	{
	public:
		
		TEST_METHOD(NewFunctionalInitTest)
		{
			int returnValue = Start();
			Assert::AreEqual(0, returnValue);

			// grab named pipes on system and check for our name


		}
	};
}
