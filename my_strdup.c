/* *****************************************************************************
** Write a function that allocates enough memory and makes a copy of the string
** given as argument.
**
** It shall be prototyped as follows:
** char	*my_strdup(char *str);
**
** It must return a pointer on the newly-allocated string.
** ****************************************************************************/

#include <stdlib.h>
#include "my_strcpy.c"
#include "my_strlen.c"

char	*my_strdup(char *str);

char	*my_strdup(char *str)
{
  char	*dup;

  if (str && (dup = malloc((size_t)my_strlen(str) + 1)))
    return (my_strcpy(dup, str));
  return (NULL);
}

#ifdef MY_STRDUP

#include <assert.h>
#include <stdio.h>
#include <string.h>

int	main(int ac __attribute__((unused)), char *av[])
{
  char	*dup;

  if ((dup = my_strdup(av[0])))
  {
    assert(strcmp(dup, av[0]) == 0);
    puts("Everything is OK");
    free(dup);
  }
  else
    perror("malloc");
  return (0);
}

#endif /* !MY_STRDUP */
