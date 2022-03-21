/* 
 * Joshua Forlenza jf4229
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  //uses negation and the & operator to find a number with the opposite bits of the result of using x^y
  //then negates the result to get x^y
  int a = ~x&y;
  int b = x&~y;
  return ~(~a&~b);
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  //shifts 1 31 places to the left to get a 1 in the most significant bit place
  //1000... is the bit representation of the minimum two's complement integer
  return 1<<31;
}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 2
 */
int isTmax(int x) {
  /* If x is Tmax then x+1 will equal Tmin.
      Tmin ^ Tmax produces -1 and flipping the bits with ~ gives 0.
      The sum of ~(Tmax+1) + !(x+1) will be zero.
      The ! operator returns 1 only on zero and 0 on nonzeros, so
      performing ! on the sum of (~(Tmax+1) + !(x+1)) should return 1
      if x is Tmax.
    */
  return !(~((x+1)^x)+!(x+1));
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
  /* 170's bit representation has all 1s in the odd bit places.
    Because we are constrained from using integer constants between 0 and 255
    the expression in A constructs a 32-bit integer with 1s in every odd place.
    This expression is compared to x using & and returns A if they are the same.
    (x&A)^A is used to return a 0 and the ! returns a 1 for when x has all odd-numbered bits
    set to 1;
  */
  int A = 170 | 170<<8 | 170<<16 | 170<<24 ;
  return  !((x&A)^A); 
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  //~ operator flips bits and then +1 is used to get the correct
  //two's complement representation of the negated int
  return ~x + 1;
}
//3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) { 
  int s = 1<<31;

  //if x is greater than 0x39, upper becomes negative; becomes 0 if not
  int upper = s & ((~(s | 0x39))+x) >> 31;
  //if x is less than 0x39, lower becomes negative; becomes 0 if not
  int lower = s & ((~0x30)+1+x) >> 31; 

  //returns 1 only if upper and lower are 0
  return !(upper | lower);
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  //x is turned into boolean form 0 or 1
  x = !!x;
  //negate x to two's complement form giving all 0s or all 1s
  x = ~x+1;
  //if x is all 0s then z is returned; y is returned if x is all 1s
  return (x & y) | (~x & z);
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  //if -x+y<0 then x is greater than y
  int xNegate = ~x+1;
  int sign = (xNegate+y) >> 31 & 1;

  /*
  this is used for edge cases.
  checks the sign bits of x and y to determine if x<=y
  */
  int tMin = 1 << 31;
  int xMSB = tMin & x;
  int yMSB = tMin & y;
  int XandY = ((xMSB ^ yMSB) >> 31) & 1;
 
  return (XandY & (xMSB>>31)) | (!sign & !XandY);
}
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
  //(x|(~x+1)) will produce -1 for when x is nonzero
  //adding 1 to it results in a return of 0
  return (((x | (~x+1)) >> 31) +1);
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
  //computes bits using log2 algorithm
  int bits = 0;
  int plus16,plus8,plus4,plus2,plus1,plus;
  x = x ^ (x >> 31);

  plus16 = ((!!(x >> (bits + 16))) << 4);
  bits += plus16;

  plus8 = ((!!(x >> (bits + 8))) << 3);
  bits += plus8;

  plus4 = ((!!(x >> (bits + 4))) << 2);
  bits += plus4;

  plus2 = ((!!(x >> (bits + 2))) << 1);
  bits += plus2;

  plus1 = ((!!(x >> (bits + 1))));
  bits += plus1;

  plus = (x >> bits);
  bits += plus;

  return bits + 1;
}
//float
/* 
 * float_twice - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_twice(unsigned uf) {
  //isolate sign, exp, and frac 
  unsigned s = uf & 0x80000000;
  unsigned exp = uf & 0x7f800000;
  unsigned frac = uf & 0x007fffff;

  //special case
  if (exp == 0x7f800000)
      return uf;

  //denormalzied
  if (exp == 0)
      return s | uf << 1;

  //normalized
  exp += 0x00800000;
  //check for infinity
  if (exp == 0x7f800000)
      frac = 0;

  return s + exp + frac;
}
/* 
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_i2f(int x) {
  int minInt, e, s, frac, exp;

  //if x is 0 then return 0
  if (!x)
    return 0;

  minInt = 0x80000000;
  //if x is the smallest int then return highest exp
  if (x == minInt)
    return minInt + (158<<23);
  
  s = x&minInt;
  if (s)
    //reverse two's complement
    x = ~x + 1;

  //31 is the highest possible for e
  e = 31;
  //to find e, the integer is divided by 2 until it equals 0
  while (!(x&minInt)) {
    x = x<<1;
    e -= 1;
  }
  //bias is added to compute exp
  exp = e+127;

  frac = (x&0x7FFFFFFF)>>8;
  //accounts for rounding
  if (x&0x80 && ((x&0x7F) > 0 || frac&1))
    frac++;
  
  return s + (exp<<23) + frac;
}
/* 
 * float_f2i - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int float_f2i(unsigned uf) {
  int s = uf >> 31;
  int exp = (uf >> 23) & 0xFF;
  int e = exp - 127;
  //isolate and normalize frac
  int frac = (uf & 0x7FFFFF) | 0x800000;

  //decimal numbers close to 0 are rounded to 0
  if(e < 0)
     return 0;
  //check for out of range numbers
  if(e > 30)
    return 0x80000000u;

  if(e < 23)
    //right shift when e is less than 23
    frac = frac >> (23 -e);
  if(e>23)
    //left shift when e is greater than 23
    frac = frac << (e-23);

  if(s) 
    //negative is returned
    return ~frac + 1;

  return frac;
}
