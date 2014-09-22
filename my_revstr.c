/* *****************************************************************************
** Write a function that reverse a string.
**
** The function shall be prorotyped as follows:
** char	*my_revstr(char *str);
**
** It shall return str.
** ****************************************************************************/

char	*my_revstr(char *str);

char	*my_revstr(char *str)
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

#ifdef MY_REVSTR

#include <assert.h>
#include <stdio.h>

int	main()
{
  return (0);
}

#endif /* !MY_REVSTR */
