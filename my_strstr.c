/* *****************************************************************************
** Reproduce the behavior of the function strstr.
**
** The function shall be prototyped as follows:
** char	*my_strstr(char *str, char *to_find);
** ****************************************************************************/

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
