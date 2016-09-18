Basic Math
==========

Square
------

.. note::

    Tested on: UVA152


.. code-block:: cpp

    #define SQUARE(x) ((x) * (x))


Power of 2
----------

Check if a number is power of 2

.. warning::

    NOT TESTED

.. code-block:: cpp

    #define isPowerOf2(x) (((x) != 0) && (((x) & ((x) - 1)) == 0))


Greatest Common Divisor (GCD)
-----------------------------

.. note::

    Tested on: UVA11417, UVA10976, UVA12060

.. code-block:: cpp

    inline int gcd(int a, int b)
    {
        return (b == 0 ? a : gcd(b, a % b));
    }

Least Common Multiple (LCM)
---------------------------

.. warning::

    NOT TESTED

LCM uses ``gcd`` function presented on this section.

.. code-block:: cpp

    inline int lcm(int a, int b)
    {
        // a * b / gcd
        return (a/gcd(a, b))*b;
    }

Least Significant Bit (LSB)
---------------------------

.. note::

    Tested on: URI1500, URI1804, UVA12086

.. code-block:: cpp

    #define LSB(x) ((x) & (-(x)))

.. toctree::
   :maxdepth: 2
