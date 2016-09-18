// A number squared
#define SQUARE(x) ((x) * (x))

// Tested on: UVA152

// ----------------------------------------------------------------------------

// Check if a number is power of 2
#define isPowerOf2(x) (((x) != 0) && (((x) & ((x) - 1)) == 0))

// ----------------------------------------------------------------------------

// Least Significant Bit
#define LSB(x) ((x) & (-(x)))

// Tested on: URI1500, URI1804, UVA12086

// ----------------------------------------------------------------------------

// Euclidian Greatest Common Divisior
inline int gcd(int a, int b)
{
    return (b == 0 ? a : gcd(b, a % b));
}

// Tested on: UVA11417, UVA10976, UVA12060

// ----------------------------------------------------------------------------

// Least Common Multiple
inline int lcm(int a, int b)
{
    return (a/gcd(a, b))*b;
}
