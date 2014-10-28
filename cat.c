/*
** Write a program called cat which realizes the same work as the command cat of
** your system.
**
** You don't have to handle the options.
**
** The number of files given as parameters is unlimited.
**
** cat without parameters must be supported.
**
** You can the errno variable (see man errno).
**
** The perror() function is forbidden.
**
** The malloc() function is also forbidden.
**
** You can only do this exercise by declaring a fixed size array. This array
** will have a limited size of about 30 ko.
*/

#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

static void	cat(int fd)
{
  ssize_t	size;
  char		buffer[30720];

  while ((size = read(fd, buffer, 30720)) > 0)
    write(1, buffer, size);
  if (size < 0)
  {
    if (errno == EACCES)
      write(2, "Permission denied\n", 18);
    else if (errno == EISDIR)
      write(2, "Is a directory\n", 15);
    else if (errno == ENOENT)
      write(2, "No such file or directory\n", 26);
  }
  close(fd);
}

int	main(int ac, char const * const av[])
{
  int	i;

  if (ac == 1)
    cat(0);
  else
  {
    i = 0;
    while (++i < ac)
      cat(open(av[i], O_RDONLY));
  }
  return (0);
}
