/* *****************************************************************************
** Write a function that returns the prime number immediately hight or equal to
** the number given as a parameter.
**
** It will be prototyped as follows:
** int	my_find_prim_sup(int nb);
**
** Additional rule:
** Your function must give its answer in less than 2 seconds.
** ****************************************************************************/

int	my_find_prime_sup(int nb);

int	my_find_prime_sup(int nb)
{
  int	divisor;
  int	is_prime;

  is_prime = -1;
  while (is_prime != 1)
  {
    divisor = 2;
    is_prime = -1;
    ++nb;
    while (divisor <= 7)
    {
      if (nb != divisor && (nb % divisor) == 0)
	is_prime = 0;
      ++divisor;
    }
    if (is_prime == -1)
      is_prime = 1;
  }
  return (nb);
}

#ifdef MY_FIND_PRIME_SUP

int	main()
{
  return (0);
}

#endif /* !MY_FIND_PRIME_SUP */
