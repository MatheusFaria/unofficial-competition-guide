Basic Geometry
==============

Useful Macros
-------------

.. code-block:: cpp

    #include <cfloat>

    FLT_MIN
    DBL_MIN
    LDBL_MIN

    FLT_MAX
    DBL_MAX
    LDBL_MAX

    FLT_EPSILON
    DBL_EPSILON
    LDBL_EPSILON


Floating Point Comparision
--------------------------

.. note::

    Tested with other computational geometry algorithms


.. code-block:: cpp

    #include <cmath>

    #define DBL_DELTA 1e-9
    #define DBL_EQ(a, b)  (fabs((a) - (b)) < DBL_DELTA)  // a == b
    #define DBL_LT(a, b)  (((b) - (a)) > DBL_DELTA)      // a < b
    #define DBL_GT(a, b)  (((a) - (b)) > DBL_DELTA)      // a > b
    #define DBL_POS(a)    ((a) > -DBL_DELTA)             // a >= 0
    #define DBL_NEG(a)    ((a) < DBL_DELTA)              // a <= 0


Euclidian Distance
------------------

.. note::

    Tested on: URI1552

.. code-block:: cpp

    inline int square_distance(int x0, int y0, int x1, int y1)
    {
        return (x1 - x0)*(x1 - x0) + (y1 - y0)*(y1 - y0);
    }


.. toctree::
   :maxdepth: 2
