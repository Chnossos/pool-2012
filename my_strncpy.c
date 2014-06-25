/* *****************************************************************************
** Write a function that copies n characters from a string into another. The
** destination string will already have sufficient memory to contain n
** characters.
**
** Add '\0' if n > the length of the string.
** Don't add '\0' if n < length of the string (because dest is not supposed to
** contain more than n bytes).
**
** The function shall be prototyped as follows:
** char	*my_strncpy(char *dest, char *src, int n);
**
** It shall return dest.
** ****************************************************************************/

char	*my_strncpy(char *dest, char *src, int n)
{
  while (n --> 0 && *src)
    *dest++ = *src++;
  if (n)
    *dest = '\0';
  return (dest);
}
