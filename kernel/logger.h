#ifndef _KERNEL_LOGGER_H_
# define _KERNEL_LOGGER_H_ 1

enum log_level
{
	INFO,
	SUCCESS,
	WARNING,
	ERROR,
	NONE = -1
};

# ifndef NDEBUG
#  define LOG(level, msg) __log(level, __FILE__, __LINE__, msg);
# else
#  define LOG(level, msg)
# endif							/* !NDEBUG */

void            __log(int, const char *, uint16_t, const char *);

#endif							/* !_KERNEL_LOGGER_H_ */
