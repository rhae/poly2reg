/*
 * Copyright (c) 2015, R. Haertel
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of 
 * this software and associated documentation files (the "Software"), to deal in 
 * the Software without restriction, including without limitation the rights to 
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of 
 * the Software, and to permit persons to whom the Software is furnished to do so, 
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all 
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS 
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR 
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER 
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN 
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

/* header of standard C - libraries */
#include <stdlib.h>

/* header of common types */

/* shared common header */

/* header of project specific types */

/* project headers */

/* local header */

/* constant definitions
---------------------------------------------------------------------------*/

/* local defined data types
---------------------------------------------------------------------------*/

/* list of external used functions, if not in headers
---------------------------------------------------------------------------*/

/* list of global defined functions
---------------------------------------------------------------------------*/

/* list of local defined functions
---------------------------------------------------------------------------*/

static float avg( float *, size_t );
static float avg2( float *, size_t );
static float avg3( float *, size_t );
static float avg4( float *, size_t );

static float avg11( float *, float *, size_t );
static float avg12( float *, float *, size_t );

/* external variables
---------------------------------------------------------------------------*/

/* global variables
---------------------------------------------------------------------------*/

/* local defined variables
---------------------------------------------------------------------------*/
#ifdef CONFIG_FILE_ID
static char _fileid[] = "$Id$";
#endif

void poly2reg( float *Coeff, float *BufX, float *BufY, size_t Cnt )
{
  float x, y;         // Average x,y
  float x2, x3, x4;   // Average x^2, x^3, x^4
  float y_x2;         // Avarage y*x^2
  float y_x;          // Average y*x
  
  float a, b, c;
  
  float num, denom;
  
  x    = avg( BufX, Cnt );
  y    = avg( BufY, Cnt );
  x2   = avg2( BufX, Cnt );
  x3   = avg3( BufX, Cnt );
  x4   = avg4( BufX, Cnt );
  y_x  = avg11( BufX, BufY, Cnt );
  y_x2 = avg12( BufX, BufY, Cnt );

#if 0
  printf(
  "Cnt  = %d\n"
  "x    = %.4f\n"   
  "y    = %.4f\n"   
  "x2   = %.4f\n"   
  "x3   = %.4f\n"   
  "x4   = %.4f\n"   
  "y_x  = %.4f\n"   
  "y_x2 = %.4f\n",
  Cnt,
  x,
  y,
  x2,
  x3,
  x4,
  y_x,
  y_x2
  );
#endif

  num   = ((y_x2 - y * x2) * (x2 - x * x) - (y_x - y * x) * (x3- x*x2));
  denom = (x4 - x2 * x2) * (x2 - x * x) - (x3 - x * x2) * (x3 - x * x2);
  a     = num / denom;
  
  num   = y_x - y  * x - a * (x3 - x * x2);
  denom = x2 - x * x;
  b     = num / denom;
  
  c     = y - a * x2 - b * x;
  
  Coeff[0] = a;
  Coeff[1] = b;
  Coeff[2] = c;
}

static float avg( float *Buf, size_t Cnt )
{
  float Avg = 0;
  size_t n;
  for( n = 0; n < Cnt; n++ )
  {
    Avg += Buf[n];
  }
  Avg /= Cnt;
  
  return Avg;
}

static float avg2( float *Buf, size_t Cnt )
{
  float Avg = 0;
  size_t n;
  for( n = 0; n < Cnt; n++ )
  {
    Avg += (Buf[n] * Buf[n]);
  }
  Avg /= Cnt;
  
  return Avg;
}

static float avg3( float *Buf, size_t Cnt )
{
  float Avg = 0;
  size_t n;
  for( n = 0; n < Cnt; n++ )
  {
    Avg += (Buf[n] * Buf[n] * Buf[n]);
  }
  Avg /= Cnt;
  
  return Avg;
}

static float avg4( float *Buf, size_t Cnt )
{
  float Avg = 0;
  size_t n;
  for( n = 0; n < Cnt; n++ )
  {
    Avg += (Buf[n] * Buf[n] * Buf[n] * Buf[n]);
  }
  Avg /= Cnt;
  
  return Avg;
}

static float avg11( float *BufX, float *BufY, size_t Cnt )
{
  float Avg = 0;
  size_t n;
  for( n = 0; n < Cnt; n++ )
  {
    Avg += (BufY[n] * BufX[n]);
  }
  Avg /= Cnt;
  
  return Avg;
}

static float avg12( float *BufX, float *BufY, size_t Cnt )
{
  float Avg = 0;
  size_t n;
  for( n = 0; n < Cnt; n++ )
  {
    Avg += (BufY[n] * BufX[n] * BufX[n]);
  }
  Avg /= Cnt;
  
  return Avg;
}


/*______________________________________________________________________EOF_*/

