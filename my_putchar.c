#ifdef _WIN32
# include <io.h>
#else
# include <unistd.h>
#endif

int	my_putchar(int c);

int	my_putchar(int c)
{
  return ((int)write(1, &c, 1));
}

#ifdef MY_PUTCHAR

int	main()
{
  return (0);
}

#endif /* !MY_PUTCHAR */
