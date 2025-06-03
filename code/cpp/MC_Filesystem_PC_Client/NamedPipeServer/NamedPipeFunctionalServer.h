#pragma once

#define SERVER_NAME R"(\\.\pipe\MinecraftFilesystem)"
#define PIPE_BUFFER_SIZE 512

// Server stopped successfully
#define EXITCODE_SUCCESS 0

// Unknown and unhandled error occurred halting the server
#define EXITCODE_UNKNOWNERROR 1

// Server pipeline failed to initialize
#define EXITCODE_PIPEINITFAILED 2



namespace NamedPipeFunctionalServer
{
	extern "C" int Start(void);
}