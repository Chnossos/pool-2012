/* *****************************************************************************
** Write a function that copies a stirng into another. The destination string
** will already have enough memory to copy the source string.
**
** The function shall be prototyped as follows:
** char	*my_strcpt(char *dest, char *src);
**
** It shall return dest.
** ****************************************************************************/

char	*my_strcpy(char *dest, char *src)
{
  while (*src)
    *dest++ = *src++;
  *dest = '\0';
  return (dest);
}
