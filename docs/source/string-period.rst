String Period
=============

KMP Faliure Function
--------------------

.. note::

    Tested on: UVA10298

This algorithm uses the same algorithm presented at :doc:`string-matching` section,
the KMP. But to get the string period size, you need to do slightly modifications.


.. code-block:: cpp

    #define MAX 1000010

    int back_table[MAX];

    int kmp_period_size(string word)
    {
        /*
            If the word can be written on the form:
                word = a + a + ... + a
            Where "a" is a substring of word.
            This function will return the size of "a". Otherwise, the word size.

            Complexity: O(n)
        */

        int i = 0, j = -1; back_table[0] = -1;
        int word_size = word.size();

        while(i < word_size)
        {
            while(j >= 0 && word[i] != word[j]) j = back_table[j];
            ++i; ++j;
            back_table[i] = j;
        }

        if(back_table[i] == 0) return word_size;

        if(word[back_table[i]] == word[0]) return word_size - back_table[i];

        return word_size;
    }

.. toctree::
   :maxdepth: 2
