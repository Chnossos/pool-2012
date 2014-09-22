/* *****************************************************************************
** Write a function that capitalizes each word.
**
** The function shall be prototyped as follows:
** char	*my_strcapitalize(char *str);
**
** It shall return str.
** ****************************************************************************/

#include "my_ctype.c"

char	*my_strcapitalize(char *str);

char	*my_strcapitalize(char *str)
{
  int	i;

  if (str)
  {
    i = -1;
    while (str[++i])
    {
      if (my_islower(str[i]) && (i == 0 || !my_isalnum(str[i - 1])))
	str[i] -= ('a' - 'A');
    }
  }
  return (str);
}

#ifdef MY_STRCAPITALIZE

#include <assert.h>
#include <stdio.h>
#include <string.h>

int	main()
{
  char	str[] = "hey, how are you ? 42words forty-two; fifty+one";
  assert(strcmp(my_strcapitalize(str),
		"Hey, How Are You ? 42words Forty-Two; Fifty+One") == 0);
  puts("Everything is OK");
  return (0);
}

#endif /* !MY_STRCAPITALIZE */
