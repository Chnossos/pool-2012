/* *****************************************************************************
** Write a function that sets in lowercase every letter of every word.
**
** The function shall be prototyped as follows:
** char	*my_strlowcase(char *str);
**
** It shall return str.
** ****************************************************************************/

char	*my_strlowcase(char *str);

char	*my_strlowcase(char *str)
{
  char	*iter;

  if ((iter = str))
  {
    while (*iter)
    {
      if (*iter >= 'A' && *iter <= 'Z')
	*iter += ('a' - 'A');
      ++iter;
    }
  }
  return (str);
}

#ifdef MY_STRLOWCASE

#include <assert.h>
#include <stdio.h>
#include <string.h>

int	main()
{
  char	str[] = "Hello, World !";

  assert(strcmp(str, "hello, world !") == 0);
  puts("Everything is OK");
  return (0);
}

#endif /* !MY_STRLOWCASE */
