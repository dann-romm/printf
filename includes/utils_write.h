#ifndef UTILS_WRITE_H
# define UTILS_WRITE_H

// utils_write.c
int	ft_putchar(char c);
int	ft_putnbr(long long n);
int	ft_putstr(char *s);
int	ft_puthex(unsigned long long n, int uppercase);
int	ft_puthexchar(int c, int uppercase);

// utils_str.c
int	ft_putsymbols(char c, int size);

#endif // UTILS_WRITE_H