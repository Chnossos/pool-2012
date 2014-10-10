/* *****************************************************************************
** Write a function that splits a string into words.
**
** Seperators are all non-alphanumeric characters.
**
** The function returns an array, where each cell contains the address of a
** string representing a word. The last element shall equal 0, thus marking the
** end of the array.
**
** The transmitted string will be modifiable and shall be modified in your
** function.
**
** It shall be prototyped as follows:
** char	**my_str_to_wordtab(char *str);
** ****************************************************************************/

#include <stdlib.h>
#include "my_ctype.c"

char	**my_str_to_wordtab(char *);

static int	count_words(char *str)
{
  int		count;

  if (!str)
    return (0);
  count = 0;
  while (*str)
  {
    while (!my_isalnum(*str))
      ++str;
    if (!*str)
      break;
    ++count;
    while (my_isalnum(*str))
      ++str;
  }
  return (count);
}

char	**my_str_to_wordtab(char *str)
{
  char	**tab;
  int	i;

  tab = malloc((size_t)(count_words(str) + 1) * sizeof(char *));
  i = 0;
  while (*str)
  {
    while (*str && !my_isalnum(*str))
      ++str;
    if (!*str)
      break;
    tab[i++] = str;
    while (my_isalnum(*str))
      ++str;
    if (*str)
      *str++ = '\0';
  }
  tab[i] = NULL;
  return (tab);
}

#ifdef MY_STR_TO_WORDTAB

#include <stdio.h>

int	main(int ac __attribute__((unused)), char *av[])
{
  char	**tab = my_str_to_wordtab(av[1]);
  int	i = 0;

  while (tab[i])
    printf("%s\n", tab[i++]);
  free(tab);
  return (0);
}

#endif /* !MY_STR_TO_WORDTAB */
