/* *****************************************************************************
** Write a function that sets in uppercase every letter of every word.
**
** The function shall be prototyped as follows:
** char	*my_strupcase(char *str);
**
** It shall return str.
** ****************************************************************************/

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
