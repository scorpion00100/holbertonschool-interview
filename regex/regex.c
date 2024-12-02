#include "regex.h"

/**
 * regex_match - Checks whether a given pattern matches a given string
 *
 * @str: the string to scan
 * @pattern: the regular expression
 *
 * Return: 1 if the pattern matches the string, or 0 if it doesn't
 */
int regex_match(char const *str, char const *pattern)
{
	int first_match;

	if (*pattern == '\0')
		return (*str == '\0');

	first_match = (*str != '\0') && (*str == *pattern || *pattern == '.');

	if (*(pattern + 1) == '*')
		return (regex_match(str, pattern + 2)) ||
			(first_match && regex_match(str + 1, pattern));
	else
		return (first_match && regex_match(str + 1, pattern + 1));
}

