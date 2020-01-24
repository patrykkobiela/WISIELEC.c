#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <termio.h>
#include <time.h>

void title(void)   
{
      printf("\t*******************************************************\n");
      printf("\t*\x1b[40m\x1b[32m#     #     #  #   # #   #  ####  #     ####      # \x1b[0m *\n");
      printf("\t*\x1b[40m\x1b[32m#    # #    #  #  #      #  #     #     #      #    \x1b[0m *\n");
      printf("\t*\x1b[40m\x1b[32m #   # #   #   #   # #   #  ####  #     ####  #     \x1b[0m *\n");
      printf("\t*\x1b[40m\x1b[32m #  #   #  #   #      #  #  #     #     #      #    \x1b[0m *\n");
      printf("\t*\x1b[40m\x1b[32m  #      #     #   # #   #  ####  ####  ####      # \x1b[0m *\n");
      printf("\t*******************************************************\n\n");
}
