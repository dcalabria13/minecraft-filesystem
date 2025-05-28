#pragma once

// Contains the internal functions for the named pipe server 
// Nothing defined in this header file should be visible outside of the compiled dll since the dll will (probably) interact functionally 

#include <string>
#include <stdexcept>

#ifndef PIPE_DEFAULT_NAME
#define PIPE_DEFAULT_NAME "ChangeMePlease" //the user changes this, not the developer on this actual line. The default name really doesn't matter and is just used to initialize _namedPipeName
#endif

namespace PipeServerInternal // lowkey bad name
{
	class NamedPipeServer
	{
	private:
		// default name for the pipe, requires the user to change or initialization will fail
		std::string _namedPipeName{ PIPE_DEFAULT_NAME }; 

		// function used to verify if a pipe exists before trying to create one.
		bool PipeExists(std::string pipeName)
		{
			return true;
		}

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

			// do not allow the user to initialize a pipe with a name that is already in use
			// caller is expected to try again with a different name, or abort the operation
			if (PipeExists(namedPipeName))
			{
				throw std::runtime_error("Cannot initialize named pipe with provided name. Use a different one.");
			}

			// if both conditions are good then we can proceed, otherwise throw an exception
			_namedPipeName = namedPipeName;

			// lastly actually initialize the pipe, save any handles, and put a "Ready" status as the first message

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