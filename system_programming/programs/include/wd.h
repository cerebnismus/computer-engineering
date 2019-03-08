/* Routines for extracting words from strings */


/* bow (beginning of word) returns a pointer to the first 
   non-whitespace character in a string.
   Returns NULL if the string is all whitespace */

extern char *bow(char *);




/* eow (end of word) Returns a pointer to the first whitespace character 
                     (or '\0') in a string.  */

extern char *eow(char *);




/* wncopy copies the string starting at b, and ending with (but not including)
   ei to the memory pointed to by "to".  It will null-terminate this string.
   It will not copy more than n characters.  It returns the number
   of characters copied (not including the null character).   

   int wncopy(char *to, char *b, char *e, int n)
*/

extern int wncopy(char *, char *, char *, int);

