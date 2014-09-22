/* *****************************************************************************
** Reproduce the behavior of the function strstr.
**
** The function shall be prototyped as follows:
** char	*my_strstr(char *str, char *to_find);
** ****************************************************************************/

char	*my_strstr(char *str, char *to_find);

char	*my_strstr(char *str, char *to_find)
{
  int	i;

  while (*str)
  {
    while (*str && *str != *to_find)
      ++str;
    if (*str)
    {
      i = 1;
      while (to_find[i] && to_find[i] == str[i])
	++i;
      if (!to_find[i])
	return (str);
      str += i;
    }
  }
  return (0);
}

#ifdef MY_STRSTR

#include <assert.h>
#include <stdio.h>
#include <string.h>

int	main()
{
  char	*str = "Hello, World !";
  char	*test1 = str;

  assert(my_strstr(str, test1) == strstr(str, test1));
  puts("Everything is OK");
}

#endif /* !MY_STRSTR */
