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

char	*my_strncpy(char *dest, char *src, int n);

char	*my_strncpy(char *dest, char *src, int n)
{
  char	*iter;

  if ((iter = dest))
  {
    while (n --> 0 && *src)
      *iter++ = *src++;
    if (n)
      *iter = '\0';
  }
  return (dest);
}

#ifdef MY_STRNCPY

int main()
{
  /* TODO: Write some tests */
  return (0);
}

#endif /* !MY_STRNCPY */
