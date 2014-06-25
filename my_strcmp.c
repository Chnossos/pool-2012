/* *****************************************************************************
** Reproduce the behavior of the function strcmp.
**
** The function shall be prototyped as follows:
** int	my_strcmp(char *s1, char *s2);
**
** It shall return the same values as strcmp(3).
** ****************************************************************************/

int	my_strcmp(char *s1, char *s2)
{
  while (*s1 && *s2 && *s1 == *s2)
  {
    ++s1;
    ++s2;
  }
  return (*s1 - *s2);
}
