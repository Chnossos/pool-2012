/* *****************************************************************************
** Write a function that displays on the screen, one by one, the characters of a
** string.
** The address of the first character of the string is contained in the pointer
** as a parameter to the function.
**
** It will be prototyped as follows:
** int	my_putstr(char *str);
**
** Additional rule:
** The function shall return the number of characters printed out.
** ****************************************************************************/

#include <unistd.h>

int	my_putstr(char *str);

int	my_putstr(char *str)
{
  char	*iter;

  if ((iter = str))
  {
    while (*iter)
      ++iter;
  }
  return (str ? (int)write(1, str, (size_t)(iter - str)) : 0);
}

#ifdef MY_PUTSTR

int	main(int ac, char *av[])
{
  int	i;

  if (ac > 1)
  {
    for (i = 0 ; i < ac ; ++i)
    {
      my_putstr(av[i]);
      write(1, "\n", 1);
    }
  }
  else
    my_putstr("Usage: Type some arguments please.\n");
  return (0);
}

#endif /* !MY_PUTSTR */
