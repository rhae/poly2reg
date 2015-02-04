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

/**
 * \file poly2reg.h
 * Polynomial Regression of order 2
 */

#ifndef _POLY2REG_H_
#define _POLY2REG_H_

#include <stdio.h>

/* constant definitions
---------------------------------------------------------------------------*/

/* global defined data types
---------------------------------------------------------------------------*/

/* list of global defined functions
---------------------------------------------------------------------------*/
/**
 * Calculates the 3 regression Coefficients a, b and for the polynom
 * $a x^2 + b x + c$.
 * 
 * The number of data samples needs to be at least 3.
 * BufX and BufY must have the same size.
 * 
 * \param [out] Coeff    Buffer for the coefficients
 * \param [in]  BufX     Buffer with the x values
 * \param [in]  BufY     Buffer with the y values
 * \param       Cnt      Number of x valus
 */
void poly2reg( float *Coeff, float *BufX, float *BufY, size_t Cnt );

#endif
