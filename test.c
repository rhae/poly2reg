/**
 * \file test.c
 * Test the quadreg_calc function
 */


/* header of standard C - libraries */
#include <stdio.h>
#include <string.h>
#include <math.h>

/* header of common types */

/* shared common header */

/* header of project specific types */

/* project headers */

/* local header */
#include "poly2reg.h"

/* constant definitions
---------------------------------------------------------------------------*/
#ifndef countof
#define countof( x ) ( sizeof(x)/ sizeof(x[0]) )
#endif

/* local defined data types
---------------------------------------------------------------------------*/

/* list of external used functions, if not in headers
---------------------------------------------------------------------------*/

/* list of global defined functions
---------------------------------------------------------------------------*/

/* list of local defined functions
---------------------------------------------------------------------------*/
int test_1( void );
int test_rosetta( void );

/* external variables
---------------------------------------------------------------------------*/

/* global variables
---------------------------------------------------------------------------*/

/* local defined variables
---------------------------------------------------------------------------*/
#ifdef CONFIG_FILE_ID
static char _fileid[] = "$Id$";
#endif


/***************************************************************************/
/**
 *  Run the test code.
 */
int main(
      int argc, /**< */
      char **argv
      )
{
  int SuccessCnt = 0;
  int FailureCnt = 0;
  
  setvbuf(stdout, NULL, _IONBF, 0);
  if( test_1() )
  {
    SuccessCnt++;
  }
  else
  {
    FailureCnt++;
  }
  
  if( test_rosetta() )
  {
    SuccessCnt++;
  }
  else
  {
    FailureCnt++;
  }
  
  printf("Success/Failure: %d/%d\n\n", SuccessCnt, FailureCnt);
  
  return 0;
}


/**
 *  Test case 1
 */
int test_1( void )
{
  float BufX[] = {1,    2,    3,    4,    5,    6,    7 };
  float BufY[] = {0.38, 1.15, 2.71, 3.92, 5.93, 8.56, 11.24};

  float Coeff[3];
  int   _Coeff[3];
  poly2reg( Coeff, BufX, BufY, countof(BufX) );
  
  _Coeff[0] = Coeff[0] * 10000;
  _Coeff[1] = Coeff[1] * 10000;
  _Coeff[2] = Coeff[2] * 10000;

#if 0
  printf( "Test 1\n"
          "a  = %.5f/%d\n"
          "b  = %.5f/%d\n"
          "c  = %.5f/%d\n\n",
          Coeff[0], _Coeff[0],
          Coeff[1], _Coeff[1],
          Coeff[2], _Coeff[2]
        );
#endif
  
  if( (_Coeff[0] == 1964) && (_Coeff[1] == 2364)&& (_Coeff[2] ==-328) )
  {
    return 1;
  }
  return 0;
}

/**
 *  The rosetta code archive presents solutions for a task in many languages.
 *  It also has a task for polynomial regression.
 *  This test uses the values and checks if the result is the same.
 *  http://rosettacode.org/wiki/Polynomial_regression
 */
int test_rosetta( void )
{
  float BufX[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  float BufY[] = {1, 6, 17, 34, 57, 86, 121, 162, 209, 262, 321};

  float Coeff[3];
  int   _Coeff[3];
  poly2reg( Coeff, BufX, BufY, countof(BufX) );
  
  _Coeff[0] = Coeff[0] * 10000;
  _Coeff[1] = Coeff[1] * 10000;
  _Coeff[2] = Coeff[2] * 10000;

#if 0
  printf( "Test Rosetta\n"
          "a  = %.5f/%d\n"
          "b  = %.5f/%d\n"
          "c  = %.5f/%d\n\n",
          Coeff[0], _Coeff[0],
          Coeff[1], _Coeff[1],
          Coeff[2], _Coeff[2]
        );
#endif
  
  if( (_Coeff[0] == 30000) && (_Coeff[1] == 20000)&& (_Coeff[2] == 10000) )
  {
    return 1;
  }
  return 0;
}

/*______________________________________________________________________EOF_*/
