/* *****************************************************************************
** Write a function that capitalizes each word.
**
** The function shall be prototyped as follows:
** char	*my_strcapitalize(char *str);
**
** It shall return str.
** ****************************************************************************/

#include "my_ctype.c"

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
