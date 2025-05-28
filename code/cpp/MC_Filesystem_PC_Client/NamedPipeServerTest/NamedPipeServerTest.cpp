#include "pch.h"
#include "CppUnitTest.h"
#include "PipeServerInternal.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace PipeServerInternal;

namespace NamedPipeServerTest
{
	TEST_CLASS(NamedPipeServerTest)
	{
	public:
		
		TEST_METHOD(PipeCannotInitWithExistingName)
		{
			NamedPipeServer server1;
			NamedPipeServer server2;

			try 
			{
				 server1 = NamedPipeServer("TestPipe1");	
				 server2 = NamedPipeServer("TestPipe1");

				Assert::Fail(); // fail if the initialization succeeds
			}
			catch (std::runtime_error const &rte)
			{
				// best thing to check here is that server1 variable did initialize correctly
			}
			catch (...)
			{
				Assert::Fail(); // no other exceptions should have happened
			}
		}
	};
}
