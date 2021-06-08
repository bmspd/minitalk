SRCS_SERVER		= server.c utils.c
SRCS_CLIENT		= client.c utils.c

OBJS_SERVER		= $(SRCS_SERVER:.c=.o)
OBJS_CLIENT		= $(SRCS_CLIENT:.c=.o)


HEADER			= minitalk.h
CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Werror -Wextra -I $(HEADER)
NAME_S			= server
NAME_C			= client


all:			 $(NAME_S) $(NAME_C)


%.o:		%.c $(HEADER)
		$(CC) $(CFLAGS) -o $@ -c $<

$(NAME_S):		$(OBJS_SERVER)
				$(CC) $(CFLAGS) -o $(NAME_S) $(OBJS_SERVER)

$(NAME_C):		$(OBJS_CLIENT)
				$(CC) $(CFLAGS) -o $(NAME_C) $(OBJS_CLIENT)

clean:
				$(RM) $(OBJS_SERVER)
				$(RM) $(OBJS_CLIENT)

fclean:			clean
				$(RM) $(NAME_S)
				$(RM) $(NAME_C)
re:				fclean all

.PHONY:			all clean fclean re