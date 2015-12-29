Basic Math
==========

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
