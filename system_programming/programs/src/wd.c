/* Routines for extracting words from strings */

#include "wd.h"
#include <stdio.h>

/* Returns a pointer to the first non-whitespace character in a string.
   Returns NULL if the string is all whitespace */

char *bow(char *s)
{
  int i;

  for (i = 0; isspace(s[i]); i++);
  if (s[i] == '\0') return NULL;
  return (s+i);
}
    
/* Returns a pointer to the first whitespace character (or '\0') 
   in a string.  */

char *eow(char *s)
{
  int i;

  for (i = 0; !isspace(s[i]) && s[i] != '\0'; i++);
  return (s+i);
}

/* Copies the string starting at b, and ending with (but not including)
   ei to the memory pointed to by "to".  It will null-terminate this string.
   It will not copy more than n characters.  It returns the number
   of characters copied (not including the null character).   */

int wncopy(char *to, char *b, char *e, int n)
{
  int i;

  i = 0;
  while(b != e && i < n) {
    *to = *b;
    to++;
    b++;
    i++; 
  }
  if (i < n) *to = '\0';
  return i;
}
