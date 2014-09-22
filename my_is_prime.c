/* *****************************************************************************
** Write a function that returns 1 if the number is prime and 0 if the number is
** not prime.
**
** It will be prototyped as follows:
** int	my_is_prime(int nb);
**
** Additional rule:
** Your function must give its answer in less than 2 seconds.
** ****************************************************************************/

int	my_is_prime(int nb);

int	my_is_prime(int nb)
{
  int	divisor;

  if (nb <= 1)
    return (0);
  divisor = 2;
  while (divisor <= 7)
  {
    if (divisor != nb && nb % divisor == 0)
      return (0);
    ++divisor;
  }
  return (1);
}

#ifdef MY_IS_PRIME

#include <assert.h>
#include <stdio.h>

int	main()
{
  assert(my_is_prime(-1) == 0);
  assert(my_is_prime(0) == 0);
  assert(my_is_prime(1) == 0);
  assert(my_is_prime(2) == 0);
  puts("Everything is OK");
  return (0);
}

#endif /* !MY_IS_PRIME */
