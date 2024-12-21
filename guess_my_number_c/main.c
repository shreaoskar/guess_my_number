#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
static const unsigned int MAX = 100;
static bool matched = false;
int main(void) {
  printf("\n~~~ Guess My Number ~~~\n");
  srand(time(NULL));
  unsigned int number = rand() % (MAX + 1);
  // printf("%d\n", number);
  unsigned int number_guessed;
  while (!matched) {
    printf("\nWhat's your guess?\n");
    if (scanf("%u", &number_guessed) != 1) {
      printf(" [ ERROR ] Your input wasn't a valid integer.\n");
      return 101;
    }

    if (number_guessed < 0) {
      printf("hello\n");
    }

    if (number_guessed == number) {
      printf("\nCongrats! You guessed correctly!\n");
      matched = true;
    } else {
      printf("\nOops! You guessed wrong! Try again.\n");
      if (number > number_guessed) {
        printf("Your guess is smaller than my number.\n");
      } else {
        printf("Your guess is larger than my number.\n");
      }
    }
  }
  return 0;
}
/*
When you enter "-4" as input for scanf("%u", &num),
it doesn't produce an error and it seems to work without any issues.
This behavior is due to how scanf handles the conversion for unsigned integers.
Why does this happen?

When you provide a negative number (like -4) to scanf("%u", &num),
scanf does not directly reject the input.
Instead, it interprets the negative number as an unsigned value
by converting the signed integer value of -4 into its corresponding unsigned
integer representation.

This is due to how the conversion works at the binary level.
In C, when a signed integer (like -4) is assigned to an unsigned integer,
it undergoes an integer overflow or wraparound.
The negative value is treated as an extremely large positive value (a
wraparound).

Example of the conversion:

    The two's complement representation of -4 in a 32-bit system is:
        -4 as a signed integer is represented as 0xFFFFFFFC (in hexadecimal).
        When this is stored as an unsigned integer,
        it is interpreted as 0xFFFFFFFC,
        which is a large unsigned integer: 4294967292 in decimal.

Thus, scanf will interpret the input "-4" as the unsigned integer 4294967292,
which is a valid value for an unsigned int (assuming it's within the range of
the type).
*/
