#pragma once

// Contains the internal functions for the named pipe server 
// Nothing defined in this header file should be visible outside of the compiled dll since the dll will (probably) interact functionally 

#include <string>
#include <stdexcept>
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <tchar.h>

#define PIPE_DEFAULT_NAME "ChangeMePlease" //the user changes this, not the developer on this actual line. The default name really doesn't matter and is just used to initialize _namedPipeName
#define BUFFER_SIZE = (1024 * 16) // 16KB buffer size, look at making it more accurate. Should fit ~10 message units maybe?


namespace PipeServerInternal // lowkey bad name
{
	class NamedPipeServer
	{
	private:
		// default name for the pipe, requires the user to change or initialization will fail
		std::string _namedPipeName{ PIPE_DEFAULT_NAME }; 
		HANDLE _serverPipeHandle;

	public:
		/// <summary>
		/// Default constructor will not initialize a named pipe and is just to make the compiler happy
		/// </summary>
		NamedPipeServer()
		{
			_namedPipeName = PIPE_DEFAULT_NAME;
		}

		/// <summary>
		/// Constructor that accepts a string, checks to make sure that pipe name is free, then creates it
		/// </summary>
		NamedPipeServer(std::string namedPipeName) 
		{
			// first make sure the string is not empty and is valid containing only alphanumeric characters and underscores

			_namedPipeName = "\\.\pipe\\" + namedPipeName;

			// initialize the pipe, save any handles, and put a "Ready" status as the first message
			_serverPipeHandle = CreateNamedPipeA(
				_namedPipeName.c_str(),
				PIPE_ACCESS_DUPLEX | FILE_FLAG_FIRST_PIPE_INSTANCE, // allows both reading and writing, restricts to only one pipe of this name being created
				PIPE_TYPE_MESSAGE | PIPE_READMODE_MESSAGE | PIPE_WAIT | PIPE_REJECT_REMOTE_CLIENTS, // use message units instead of bytes, read in message units, and wait for non-remote client connection
				2, // only two instances permitted. This one, and a single client
				1024 * 16, // output buffer size
				1024 * 16, // input buffer size
				0, // default timeout
				NULL // TODO implement security attributes to prevent remote connections
			);
			


		}

		/// <summary>
		/// Destructor that will close the pipe and free any resources allocated by the server
		/// </summary>
		~NamedPipeServer() 
		{
			// Add "Stopping" status message to the pipe to give clients a chance to disconnect (this is not guaranteed)

			// wait short time to allow clients to react. This should not cause any threading issues since calling the
			// destructor means the program is exiting or something bad happened that put the server out of scope
			
			// close the pipe server 
			
			// free any allocated memory if needed	
		}
			

		// Methods

		// AddMessage(*byte[]) or equivalent type
		



		// ReadMessage(int) returns *byte[] or equaivalent type


	};


}