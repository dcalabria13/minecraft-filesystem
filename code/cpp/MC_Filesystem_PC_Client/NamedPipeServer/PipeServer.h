#pragma once

// Contains the internal functions for the named pipe server 
// Nothing defined in this header file should be visible outside of the compiled dll

// imports to the external winapi functions required

// function for initializeing a local named pipe server, given a name

// function for adding a byte array to a local named pipe server
//	-- no need to do any message / struct types. Those will get defined elsewhere and will get converted to bytes,
//     this funcitonality is for the pipe funcitonality only, not suporting structures

// funciton for closing the named pipe server
