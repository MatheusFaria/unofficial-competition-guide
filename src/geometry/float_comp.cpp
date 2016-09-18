#include <cmath>

#define DBL_DELTA 1e-9
#define DBL_EQ(a, b)  (fabs((a) - (b)) < DBL_DELTA)  // a == b
#define DBL_LT(a, b)  (((b) - (a)) > DBL_DELTA)      // a < b
#define DBL_GT(a, b)  (((a) - (b)) > DBL_DELTA)      // a > b
#define DBL_POS(a)    ((a) > -DBL_DELTA)             // a >= 0
#define DBL_NEG(a)    ((a) < DBL_DELTA)              // a <= 0

/*
    DBL_DELTA varies with the problem
*/

#include <cfloat>

// Important Macros

// FLT_MIN
// DBL_MIN
// LDBL_MIN

// FLT_MAX
// DBL_MAX
// LDBL_MAX

// FLT_EPSILON
// DBL_EPSILON
// LDBL_EPSILON
