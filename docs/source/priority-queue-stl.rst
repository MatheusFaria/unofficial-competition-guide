Priority Queue (STL)
====================

.. note::

    Tested on: UVA11995, URI1244, URI1259, URI1851


With a custom class
-------------------

.. code-block:: cpp

    #include <iostream>   // cout, endl
    #include <queue>      // priority_queue
    #include <utility>    // pair, make_pair
    #include <vector>     // vector
    #include <functional> // function

    using namespace std;

    class Object{
    public:
        int a, b;

        Object(int _a, int _b)
        {
            a = _a;
            b = _b;
        }

        bool operator<(const Object& obj) const
        {
            if(b == obj.b) return a < obj.a;
            return b < obj.b;
        }
    };


Usage:

.. code-block:: cpp

    int main()
    {
        priority_queue<Object> pq;

        pq.push(Object(1, 2));
        pq.push(Object(3, 2));
        pq.push(Object(4, 2));
        pq.push(Object(1, 7));
        pq.push(Object(3, 8));
        pq.push(Object(2, 9));

        while(!pq.empty())
        {
            cout << pq.top().a << " " << pq.top().b << endl;
            pq.pop();
        }

        return 0;
    }


With C++ basic objects
----------------------

.. code-block:: cpp

    #include <iostream>   // cout, endl
    #include <queue>      // priority_queue
    #include <utility>    // pair, make_pair
    #include <vector>     // vector
    #include <functional> // function

    using namespace std;

    bool compare_function(const pair<int, int>& p1, const pair<int, int>& p2)
    {
        return p1.first < p2.first;
    }

    int main()
    {
        priority_queue< pair<int, int>,
                        vector< pair<int, int> >,
                        function< bool(pair<int, int>, pair<int, int>) >
                      > pq2(&compare_function);

        pq2.push(make_pair(1, 2));
        pq2.push(make_pair(4, 2));
        pq2.push(make_pair(3, 2));
        pq2.push(make_pair(2, 9));
        pq2.push(make_pair(1, 7));
        pq2.push(make_pair(3, 8));

        while(!pq2.empty())
        {
            cout << pq2.top().first << " " << pq2.top().second << endl;
            pq2.pop();
        }

        return 0;
    }


.. toctree::
   :maxdepth: 1
