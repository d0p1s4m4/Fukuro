# vim: set tabstop=4:shiftwidth=4:noexpandtab

LIB_FUKURO_SRCS	= logger.c

LIB_FUKURO_OBJS	= $(addprefix lib/fukuro/, $(LIB_FUKURO_SRCS:.c=.o))

GARBADGE += LIB_FUKURO_OBJS
