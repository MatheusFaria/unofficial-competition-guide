C I/O
=====

.. role:: c(code)
   :language: c

All methods belongs to the :c:`#include<stdio.h>`.

Basic Input
-----------

.. code-block:: c

        int a; long int b; long long int c;
        float d; double e;
        char f;
        scanf ("%d %ld %lld %f %lf %c", &a, &b, &c, &d, &e, &f);


Basic Output
------------

.. code-block:: c

    printf ("%d %ld %lld %f %lf %c\n", a, b, c, d, e, f);


Using patterns on printf and scanf
----------------------------------

Get a line with spaces.

.. code-block:: c

    char name[100];
    scanf ("%[^\n]%*c", name);


Faster I/O
----------

Input:

.. code-block:: c

    char g;
    g = getchar();


Output:

.. code-block:: c

    putchar(g);


Fastest I/O (Unlocked I/O)
--------------------------

Input:

.. code-block:: c

    int read_int(){
         int x = 0, f = 1;

         char ch = getchar();
         while(ch < '0' || ch > '9'){
            if(ch=='-') f=-1;
            ch=getchar_unlocked();
         }
         while(ch>='0' && ch<='9'){
            x = (x<<1) + (x<<3) + ch - '0';
            ch = getchar_unlocked();
         }
         return x*f;
    }


.. toctree::
   :maxdepth: 2
