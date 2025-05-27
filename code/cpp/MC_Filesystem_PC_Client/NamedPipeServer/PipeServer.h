#pragma once

// Contains the internal functions for the named pipe server 
// Nothing defined in this header file should be visible outside of the compiled dll since the dll will (probably) interact functionally 

namespace PipeServerInternal // lowkey bad name
{
	class NamedPipeServer
	{
	private:
		// string of the pipe name, provided by constructor
		// function to check if a pipe already exists
	public:
		// constructor -> does initialization, after checking if pipe already exists, takes a string name parameter and saves it to the class privately
		// destructor? if not feature, consider doing Start() and Stop() members. Either way need something to close the pipe when we are done
		// AddMessage(*byte[]) or equivalent type
		// ReadMessage(int) returns *byte[] or equaivalent type

	};


}