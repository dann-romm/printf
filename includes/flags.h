#ifndef FLAGS_H
# define FLAGS_H

# include <stdarg.h>

typedef struct s_flags
{
	char	flag;
	int		width;
	int		accuracy;
	char	conversion;
}			t_flags;

#endif // FLAGS_H
