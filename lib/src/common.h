/**********************************************************************
 * Author:      Leo Liberti                                            *
 * Name:        common.h                                               *
 * Source:      GNU C++                                                *
 * Purpose:     common stuff                                           *
 * History:     050909 0.0 work started                                *
 * License:    (C) Leo Liberti, all rights reserved. Code published under the
               Common Public License.
***********************************************************************/

#ifndef __EV3COMMONH__
#define __EV3COMMONH__

#define NOVARIABLE -1
#define LARGE 1E10
#define NOTVARNAME "_var_not_found_"

#pragma once

#ifdef EV3_DLL // DYNAMIC (must be set when we are building a dynamic library)
// If we are building DLL files we must declare dllexport/dllimport
#   ifdef ev3_EXPORTS
#       ifdef _WIN32
#           define EV3_API __declspec(dllexport)
#       else  // UNIX (GCC)
#           define EV3_API __attribute__((visibility("default")))
#       endif
#   else
#       ifdef _WIN32
#           define EV3_API __declspec(dllimport)
#       else
#           define EV3_API
#       endif
#   endif
#else  // STATIC
#   define EV3_API
#endif

namespace Ev3
{
typedef int Int;

// various operator types
enum OperatorType
{
  SUM, DIFFERENCE, PRODUCT, FRACTION, POWER,
  PLUS, MINUS, SIN, COS, TAN, ASIN, ACOS,
  ATAN, SINH, COSH, TANH, ASINH, ACOSH,
  ATANH, LOG2, LOG10, LOG, LN, LNGAMMA,
  GAMMA, EXP, ERF, ERFC, SQRT, CBRT,
  BESSELJ0, BESSELJ1, BESSELY0, BESSELY1,
  SIGN, RINT, ABS, COT, COTH,
  VAR, CONST,
  ERROR
};

// utility functions
extern double Ev3NearZero();
extern double Ev3Infinity();

} /* namespace Ev3 */

#ifdef _MSC_VER
template <typename T>
T log2(T arg)
{
  return log(arg) / log(2.0);
}
#endif

#endif /* __EV3COMMONH__ */
