#include "holberton.h"
#include <stdio.h>

/**
 * wildcmp - compares two strings.
 * @s1: first string
 * @s2: second string that can contain the special character *.
 * Return: 1 if the strings can be considered identicall, 0 othercase..
 */
int wildcmp(char *s1, char *s2)
{
	if (!*s1 && !*s2)
		return (1);

	if (!*s1 && *s2 == '*' && *(s2 + 1))
		return (0);

	if (*s1 == *s2)
		return (wildcmp(s1 + 1, s2 + 1));

	if (*s2 == '*')
		return (wildcmp(s1, s2 + 1) == 1 || wildcmp(s1 + 1, s2) == 1);

	return (0);
}
