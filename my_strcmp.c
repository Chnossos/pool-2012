/* *****************************************************************************
** Reproduce the behavior of the function strcmp.
**
** The function shall be prototyped as follows:
** int	my_strcmp(char *s1, char *s2);
**
** It shall return the same values as strcmp(3).
** ****************************************************************************/

int	my_strcmp(char *s1, char *s2);

int	my_strcmp(char *s1, char *s2)
{
  while (*s1 && *s2 && *s1 == *s2)
  {
    ++s1;
    ++s2;
  }
  return (*s1 - *s2);
}

#ifdef MY_STRCMP

#include <assert.h>
#include <stdio.h>
#include <string.h>

int	main()
{
  assert(my_strcmp("", "") == strcmp("", ""));
  assert(my_strcmp("42", "") == strcmp("42", ""));
  assert(my_strcmp("", "42") == strcmp("", "42"));
  assert(my_strcmp("42", "42") == strcmp("42", "42"));
  assert(my_strcmp("4242", "42") == strcmp("4242", "42"));
  assert(my_strcmp("42", "4242") == strcmp("42", "4242"));
  puts("Everything is OK");
}

#endif /* !MY_STRCMP */
