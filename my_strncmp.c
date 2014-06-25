/* *****************************************************************************
** Reproduce the behavior of the function strncmp.
**
** The function shall be prototyped as follows:
** int	my_strcmp(char *s1, char *s2, int n);
**
** It shall return the same values as strncmp(3).
** ****************************************************************************/

int	my_strncmp(char *s1, char *s2, int n)
{
  while (n --> 0 && *s1 && *s2 && *s1 == *s2)
  {
    ++s1;
    ++s2;
  }
  return (n >= 0 ? *s1 - *s2 : 0);
}
