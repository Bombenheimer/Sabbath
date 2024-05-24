/*
*
*
*
*
*
*
*
*
*/

// STANDARD LIBRARIES
#include <stdio.h>
#include <string.h>
#include <iso646.h>
#include <errno.h>

// INSTALLED LIBRARIES

// OS SPECIFIC LIBRARIES
#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>

// CREATED LIBRARIES

// DEFINED PROGRAM MACROS
#define SABBATH_PASSWD "ACEPAN"

// ENUMERATION FOR DATA 
typedef enum
{
  TYPE_INT,
  TYPE_STRING
}
Datatype;

// FUNCTION PROTOTYPES FOR MEMORY ALLOCATION
int GetMem(void* dataptr, Datatype memtype, int memsize);
int FreeMem(void* dataptr);

// FUNCTION PROTOTYPES FOR MESSAGES
void firstmsg(void);
void prommsg(void);
void lovemsg(void);
void drunkmsg(void);

/*
 * FUNCTION NAME: main()
 * 
 * OPTIONAL INPUT PARAMETERS: void
 *
 * DESCRIPTION:
 * 	MAIN FUNCTION WHERE PROGRAM EXECUTION WILL OCCUR
 * 
 * PROGRAM EXECUTION STEPS:
 * 	1 - 
 *
 * 	2 - 
 *
 * 	3 - 
 *
 * RETURN VALUE:
 *  EXIT_SUCCESS - SUCCESSFUL PROGRAM EXECUTION
 *  EXIT_FAILURE - UNSUCCESSFUL PROGRAM EXECUTION
 */
int main(void)
{
  if (geteuid() != 0)
  {
    return EXIT_FAILURE;
  }
  else
  {
    unsigned short int MEM_EXIT; // RETURN VALUE OF GET MEMORY FUNCTION

    firstmsg();

    // LABEL memfail TO SIMPLIFY ERROR MESSAGES FOR MEMORY ALLOCATION CHECKS
    /*
    memfail:
      fprintf(stderr, "ERROR : memory allocation failed");
      fprintf(stderr, "sabbath : memfail");
      return EXIT_FAILURE;
    */
  }
  return EXIT_SUCCESS;
}

// FIRST MESSAGES 
void firstmsg(void)
{
  // Initialize ncurses
  initscr();

  // Write the first text
  printw("Hello, world!");
  refresh(); // Refresh to show changes
  sleep(1);  // Wait for 2 seconds

  // Clear the screen
  clear();
  refresh(); // Refresh to show changes
  sleep(1);  // Wait for 1 second

  // Write the second text
  printw("Goodbye, world!");
  refresh(); // Refresh to show changes
  sleep(1);  // Wait for 2 seconds

  // End ncurses mode
  endwin();
}

// GET MEMORY
int GetMem(void* dataptr, Datatype memtype, int memsize)
{
  // SWITCH STATEMENT TO FIND DATATPE
  switch (memtype)
  {
    case TYPE_INT:
      dataptr = (int*)malloc(memsize * sizeof(int));
      break;
    case TYPE_STRING:
      dataptr = (char*)malloc((memsize * sizeof(char*)) + 1);
      break;
  }
  // SEND A FAILURE NUMBER OF MEMORY ALLOCATION WAS NOT SUCCESFUL
  if (not(dataptr))
  {
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}

// FREE MEMORY
int FreeMem(void* dataptr)
{
  // FREEMEMORY BACK TO SYSTEM
  free(dataptr);
  return EXIT_SUCCESS;
}
