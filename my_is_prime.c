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

int			my_is_prime2(int nb)
{
  static unsigned int	prime_divisors[] = { 2, 3, 5, 7 };
  unsigned int		i;

  if (nb <= 1)
    return (0);
  i = -1;
  while (++i < 4)
  {
    if (prime_divisors[i] == nb)
      return (1);
    if (nb % prime_divisors[i] == 0)
      return (0);
  }
  return (1);
}

#ifdef MY_IS_PRIME

#include <assert.h>
#include <stdio.h>

int		main()
{
  unsigned int	primes[] =
  {
    2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41,
    43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97
  };
  unsigned int	i = -1;

  assert(my_is_prime2(-1) == 0);
  assert(my_is_prime2(0) == 0);
  assert(my_is_prime2(1) == 0);
  while (++i < sizeof(primes) / sizeof(primes[0]))
    assert(my_is_prime2(primes[i]) == 1);
  puts("Everything is OK");
  return (0);
}

#endif /* !MY_IS_PRIME */
