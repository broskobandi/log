/** \file include/log.h 
 * \brief Public header file for the log library. 
 * \details This file contains the public functions and function-like macros
 * for the log library. */

#ifndef LOG_H
#define LOG_H

#include <stdio.h>
#include <time.h>

/** Appends logging information at the end of the log file.
 * \param msg The log message.
 * \param file The current file.
 * \param func The current function.
 * \param line The current line. */
static inline void log_append(
	const char *msg,
	const char *file,
	const char *func,
	int line)
{
	FILE *log = fopen("log", "a");
	if (!log) return;
	fprintf(log,
		"[Clock: %li]\n\tMsg: %s\n\tFile: %s\n\tFunc: %s\n\tLine: %d\n",
		clock(), msg, file, func, line);
	fclose(log);
}

#ifndef NDEBUG
#define LOG(message)\
	log_append((message), __FILE__, __func__, __LINE__)
#else
#define LOG(message)
#endif

#endif
