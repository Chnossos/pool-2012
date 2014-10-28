/* *****************************************************************************
** Write a function that copies a stirng into another. The destination string
** will already have enough memory to copy the source string.
**
** The function shall be prototyped as follows:
** char	*my_strcpt(char *dest, char *src);
**
** It shall return dest.
** ****************************************************************************/

char	*my_strcpy(char *dest, char *src);

char	*my_strcpy(char *dest, char *src)
{
  char	*iter;

  if ((iter = dest))
  {
    while (*src)
      *iter++ = *src++;
    *iter = '\0';
  }
  return (dest);
}

#ifdef MY_STRCPY

#include <assert.h>
#include <stdio.h>

int	main()
{
  /* TODO: Write some tests */
  return (0);
}

#endif /* !MY_STRCPY */
