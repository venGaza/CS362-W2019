#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
    int randNum = -1;

    // Hold all of the available character selections
    char characters[] = " abcdefghijklmnopqrstuvwxyz{}[]()";

    // Generate random number between 0 and 33 to select character (includes the NULL terminator)
    randNum = rand() % 33;

    // Return the selected character
    return characters[randNum];
}

char *inputString()
{
    int i = 0;
    int length = 6;
    char randomString[length];
    memset(randomString, '\0', length);
    
    // Choose 5 random characters for the random string
    for (i = 0; i < length - 1; i++) {
      randomString[i] = inputChar();
    }

    // Return the random string
    return strdup(randomString);
}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1)
  {
    tcCount++;
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' '&& state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      printf("error ");
      exit(200);
    }
  }
}

int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
