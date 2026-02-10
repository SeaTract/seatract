/*
  seatract provides design-by-contract-like mechanisms to
  write preconditions and postconditions in C.

  preconditions and postconditions can be implemented using assert(3) but
  while still relying on assert, seatract offers more idiomatically named wrappers Require() and Ensure().
*/

 


#ifndef __SEATRACT_H
#define __SEATRACT_H

#include <stdio.h>
#include <stdlib.h>

/*
#define Require(cond) assert(cond)

#define Ensure(cond) assert(cond)
*/


/* 
A simple internal handler to add context
*/
#define CONTRACT_ASSERT(cond, type) \
    do { \
        if (!(cond)) { \
            fprintf(stderr, "SEATRACT VIOLATION [%s]: '%s' failed in %s (%s:%d)\n", \
                    type, #cond, __func__, __FILE__, __LINE__); \
            abort(); \
        } \
    } while (0)

#define Require(cond) CONTRACT_ASSERT(cond, "Precondition")
#define Ensure(cond)  CONTRACT_ASSERT(cond, "Postcondition")


#include <assert.h>



#endif /* __SEATRACT_H */
