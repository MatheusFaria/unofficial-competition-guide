C Builtin Functions
===================

.. attention::
    The following functions can only be used if the judge uses the GCC compiler.
    But other compilers, as Clang, implements most of them as well.

Those functions can be used to improve your code performance or to help you in
your solution.

__builtin_expect
----------------

Helps the compiler with branch prediction. You basically will tell to the compiler
which value it should expect for that varaible.

.. code-block:: cpp

    if (__builtin_expect (x, 0)) // should expect x == 0
        foo ();


More builtin function at: `Other Built-in Functions Provided by GCC <https://gcc.gnu.org/onlinedocs/gcc/Other-Builtins.html>`_

.. toctree::
   :maxdepth: 2
