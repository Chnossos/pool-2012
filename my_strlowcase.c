/* *****************************************************************************
** Write a function that sets in lowercase every letter of every word.
**
** The function shall be prototyped as follows:
** char	*my_strlowcase(char *str);
**
** It shall return str.
** ****************************************************************************/

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
