/*Huy Duong
This program is modify from the project 9 and add more delete function the the program*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "request.h"
int main(void)
{
  char code;
	struct request *new_list = NULL;
  printf("Operation Code: a for appending to the list, u for updating a request"
	  ", p for printing the list, d for delete a request; q for quit.\n");
  for (;;) {
    printf("Enter operation code: ");
    scanf(" %c", &code);
    while (getchar() != '\n')   /* skips to end of line */
      ;
    switch (code) {
      case 'a': new_list = append_to_list(new_list);
                break;
      case 'u': update(new_list);
                break;
      case 'p': printList(new_list);
                break;
      case 'd': delete_from_list(new_list);
                break;
      case 'q': clearList(new_list);
		return 0;
      default:  printf("Illegal code\n");
    }
    printf("\n");
  }
}
