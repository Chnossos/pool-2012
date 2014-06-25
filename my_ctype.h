#include <stdbool.h>

bool	my_isdigit(char c)
{
  return (c >= '0' && c <= '9');
}

bool	my_isupper(char c)
{
  return (c >= 'A' && c <= 'Z');
}

bool	my_islower(char c)
{
  return (c >= 'a' && c <= 'z');
}

bool	my_isalpha(char c)
{
  return (my_islower(c) || my_isupper(c));
}

bool	my_isalnum(char c)
{
  return (my_isdigit(c) || my_isalpha(c));
}
