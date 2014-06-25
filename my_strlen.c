/* *****************************************************************************
** Write a function that counts and returns the number of characters found in
** the string passed as a parameter to the function.
**
** It will be prototypes as follows:
** int	my_strlen(char *str);
** ****************************************************************************/

int	my_strlen(char *str)
{
  char	*iter;

  iter = str;
  while (*iter)
    ++iter;
  return (iter - str);
}
