/* *****************************************************************************
** Write a function that counts and returns the number of characters found in
** the string passed as a parameter to the function.
**
** It will be prototypes as follows:
** int	my_strlen(char *str);
** ****************************************************************************/

int	my_strlen(char *str);

int	my_strlen(char *str)
{
  char	*iter;

  iter = str;
  while (*iter)
    ++iter;
  return ((int)(iter - str));
}

#ifdef MY_STRLEN

#include <assert.h>
#include <stdio.h>
#include <string.h>

int	main()
{
  char	*test1 = "";
  char	*test2 = "Hello, World !";
  char	test3[] = { 42, 0 };
  assert(my_strlen(test1) == (int)strlen(test1));
  assert(my_strlen(test2) == (int)strlen(test2));
  assert(my_strlen(test3) == (int)strlen(test3));
  puts("Everything is OK");
}

#endif /* !MY_STRLEN */
