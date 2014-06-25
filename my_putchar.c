#include <unistd.h>

int	my_putchar(int c)
{
  return (write(1, &c, 1));
}
