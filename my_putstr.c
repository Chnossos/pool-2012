/* *****************************************************************************
** Write a function that displays on the screen, one by one, the characters of a
** string.
** The address of the first character of the string is contained in the pointer
** as a parameter to the function.
**
** It will be prototyped as follows:
** int	my_putstr(char *str);
**
** Additional rule:
** The function shall return the number of characters printed out.
** ****************************************************************************/

int	my_putstr(char *str)
{
  char	*iter;

  if ((iter = str))
  {
    while (*iter)
      ++iter;
  }
  return (str ? write(1, str, iter - str) : 0);
}
