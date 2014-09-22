/* *****************************************************************************
** Write a function that sets in uppercase every letter of every word.
**
** The function shall be prototyped as follows:
** char	*my_strupcase(char *str);
**
** It shall return str.
** ****************************************************************************/

char	*my_strupcase(char *str);

char	*my_strupcase(char *str)
{
  char	*iter;

  if ((iter = str))
  {
    while (*iter)
    {
      if (*iter >= 'a' && *iter <= 'z')
	*iter -= ('a' - 'A');
      ++iter;
    }
  }
  return (str);
}

#ifdef MY_STRUPCASE

#include <assert.h>
#include <stdio.h>
#include <string.h>

int	main()
{
  char	str[] = "Hello, World !";
  assert(strcmp("HELLO, WORLD !", my_strupcase(str)) == 0);
  puts("Everything is OK");
  return (0);
}

#endif /* !MY_STRUPCASE */
