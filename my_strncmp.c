/* *****************************************************************************
** Reproduce the behavior of the function strncmp.
**
** The function shall be prototyped as follows:
** int	my_strcmp(char *s1, char *s2, int n);
**
** It shall return the same values as strncmp(3).
** ****************************************************************************/

int	my_strncmp(char *s1, char *s2, int n);

int	my_strncmp(char *s1, char *s2, int n)
{
  while (n --> 0 && *s1 && *s2 && *s1 == *s2)
  {
    ++s1;
    ++s2;
  }
  return (n >= 0 ? *s1 - *s2 : 0);
}

#ifdef MY_STRNCMP

#include <assert.h>
#include <stdio.h>
#include <string.h>

int	main()
{
  /* TODO: Write some tests. */
  return (0);
}

#endif /* !MY_STRNCMP */
