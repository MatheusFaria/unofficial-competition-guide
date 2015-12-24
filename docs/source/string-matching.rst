String Matching
===============

Basic
-----

.. note::

    Tested on: UVA455


.. code-block:: cpp

    vector<int> basic_string_matching(string phrase, string word)
    {
        /*
            Finds all the word occurrences in the pharse, and return the indices of
            those occurrences

            Complexity: O(n*m)
        */
        vector<int> indices;

        // For each letter in the larger string a
        for(unsigned int i = 0; i < phrase.size(); i++)
        {
            bool found = true;
            // For each letter in the smaller string b
            for(unsigned int j = 0; j < word.size() && found; j++)
                if(i + j >= phrase.size() || word[j] != phrase[i + j]) found = false;

            if(found) indices.push_back(i);
        }

        return indices;
    }


KMP
---

.. note::

    Tested on: UVA455



.. code-block:: cpp

    #define MAX 1000010

    int back_table[MAX];

    void kmp_preprocess(string word)
    {
        /*
            Maps the repetitions inside the string you want to search.

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
    }


.. list-table:: Example of ``back_table`` after calling ``kmp_preprocess``
   :stub-columns: 1

   * - Word
     - S
     - E
     - V
     - E
     - N
     - T
     - Y
     - _
     - S
     - E
     - V
     - E
     - N
     -  
   * - Table
     - -1
     - 0
     - 0
     - 0
     - 0
     - 0
     - 0
     - 0
     - 0
     - 1
     - 2
     - 3
     - 4
     - 5

.. code-block:: cpp

    vector<int> kmp_string_matching(string phrase, string word)
    {
        /*
            Searchs for all occurrences of word in the phrase.

            Complexity: O(n + m)
        */
        vector<int> indices;

        // !!You can remove this depending on the context, and call it outside this
        //   function. Because it only need to be called once.
        kmp_preprocess(word);

        int i = 0, j = 0;
        int phrase_size = phrase.size();
        int   word_size =   word.size();

        while(i < phrase_size)
        {
            // If the chars at those positions mismatch, use the back table to
            // rewind until the necessary point
            while(j >= 0 && phrase[i] != word[j]) j = back_table[j];
            ++i; ++j;

            if(j == word_size)
            {
                // Found phrase's substring that matches with word
                indices.push_back(i - j);
                j = back_table[j];
            }
        }

        return indices;
    }


Example of a KMP already running with the back table calculated:

.. code-block:: cpp

    phrase: ABC ABCDAB ABCDABDDABDE
    word:       ABCDABD
    table:     -10000120

Mismatch at ``D != ' '``. Uses the ``back_table`` to restart at ``word`` index 2.


.. code-block:: cpp

    phrase: ABC ABCDAB ABCDABDDABDE
    word:           ABCDABD
    table:         -10000120


Mismatch at ``C != ' '``. Uses the ``back_table`` to restart at ``word`` index 0.


.. code-block:: cpp

    phrase: ABC ABCDAB ABCDABDDABDE
    word:              ABCDABD
    table:            -10000120

Now, the substring matches.

.. toctree::
   :maxdepth: 2
