/* *****************************************************************************
** The goal of this exercise is to swap each characters of the 'str' string two
** by two. Thus, we swap the first letter with the last one, the second with the
** penultimate, and so on.
**
** This function will return a pointer to the first character of the reversed
** string.
**
** char	*my_evil_str(char *str);
** ****************************************************************************/

char	*my_evil_str(char *str)
{
  char	letter;
  int	i;
  int	j;

  j = 0;
  while (str[j])
    ++j;
  i = -1;
  while (++i < --j)
  {
    letter = str[i];
    str[i] = str[j];
    str[j] = letter;
  }
  return (str);
}

#ifdef MY_EVIL_STR

#include <stdio.h>

int	main()
{
  char	test[] = "Hello, World !";

  puts(my_evil_str(test));
  return (0);
}

#endif /* !MY_EVIL_STR */
