// See example server code: https://learn.microsoft.com/en-us/windows/win32/ipc/multithreaded-pipe-server

#include "pch.h"
#include "NamedPipeFunctionalServer.h"

using namespace NamedPipeFunctionalServer;

HANDLE InitPipeServer(LPCSTR pipeName);
int RunServerLoop(HANDLE serverHandle);

/// <summary>
/// Start the named pipe server with the default configuration. 
/// Not currently allowing configuration changes since this is built for a specific purpose
/// </summary>
/// <returns>
/// Exit code indicating server execution status. Codes definitions listed in the header file.
/// </returns>
int NamedPipeFunctionalServer::Start(void)
{
	int exitCode = EXITCODE_UNKNOWNERROR; // default exit code indicating an unexpected error

	// Initialize the server pipe
	HANDLE serverHandle = InitPipeServer(SERVER_NAME);

	if (serverHandle != NULL) 
	{
		// Loop until a STOP message is recieved
		exitCode = RunServerLoop(serverHandle);
	}
	else 
	{
		// Caller may safely attempt to restart the server
		exitCode = EXITCODE_PIPEINITFAILED;
	}

	// Bounce 
	return exitCode;
}

HANDLE InitPipeServer(LPCSTR pipeName)
{
	// initialize named pipe
	HANDLE serverPipeHandle = NULL;

	serverPipeHandle = CreateNamedPipeA(
		pipeName,
		PIPE_ACCESS_DUPLEX | FILE_FLAG_FIRST_PIPE_INSTANCE, // allows both reading and writing, restricts to only one pipe of this name being created
		PIPE_TYPE_MESSAGE | PIPE_READMODE_MESSAGE | PIPE_WAIT | PIPE_REJECT_REMOTE_CLIENTS, // use message units instead of bytes, read in message units, and wait for non-remote client connection
		2, // only two instances permitted. This one, and a single client
		PIPE_BUFFER_SIZE,
		PIPE_BUFFER_SIZE,
		0, // default timeout
		NULL // TODO implement security attributes to prevent remote connections
	);

	return serverPipeHandle;
}

int RunServerLoop(HANDLE serverHandle)
{
	int exitCode = EXITCODE_UNKNOWNERROR; // default exit code indicating an unexpected error
	bool shouldBeRunning = true;

	while (shouldBeRunning)
	{
		// wait for message

		// if message is STOP -> shouldBeRunning = false and set exit code to 0;
		// otherwise, process message

	}

	return exitCode;
}