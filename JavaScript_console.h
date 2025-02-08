#ifndef _JAVASCRIPT_CONSOLE
#define _JAVASCRIPT_CONSOLE

#include<stdarg.h>
#include<stdio.h>
#include<string.h>

#include"JavaNew.h"
#include"rust_result.h"
#include"kotlinUnitAny.h"
#include"DropForFree.h"

#define init_console() \
	Console* _console = _init_console();\
	Console console = *_console;

#define destroy_console() \
	drop(_console);

typedef struct 
{
	Unit (*log)	(char*, ...);
	Unit (*warn)	(char*, ...);
	Unit (*debug)	(char*, ...);
	Unit (*error)	(char*, ...);
} Console;

Console* _init_console();

#ifdef _CONSOLE_IMPLEMENTATION

Unit Log(char* pattern, va_list args)
{
	vprintf(pattern, args);
}

#define create_new_pattern(X) \
	size_t pattern_len = strlen(pattern); \
	char* warn = X; \
	size_t warn_len = strlen(pattern); \
	char* new_pattern = malloc(sizeof(char) * (warn_len + pattern_len + 2)); \
	strcpy(new_pattern, warn); \
	strcat(new_pattern, pattern); \
	strcat(new_pattern, "\n")

#define call_log_with_pattern(X) \
	va_list rest; \
	va_start(rest, pattern); \
	Log(X, rest)

Unit log_impl(char* pattern, ...)
{
	create_new_pattern("");
	call_log_with_pattern(new_pattern);
}

Unit warn_impl(char* pattern, ...)
{
	create_new_pattern("[WARNING] - ");
	call_log_with_pattern(new_pattern);
}

Unit debug_impl(char* pattern, ...)
{
	create_new_pattern("[DEBUG]   - ");
	call_log_with_pattern(new_pattern);
}

Unit error_impl(char* pattern, ...)
{
	create_new_pattern("[ERROR]   - ");
	call_log_with_pattern(new_pattern);
}

Result(Console*, Any) _init_console()
{
	Console* console = new(Console);
	if(console == NULL) Err(NULL)

	console->log = log_impl;
	console->warn = warn_impl;
	console->debug = debug_impl;
	console->error = error_impl;
	
	Ok(console)
}

#endif
#endif

