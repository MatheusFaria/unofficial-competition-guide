Binary Heap
===========

.. warning::
    NOT TESTED


.. code-block:: cpp

    #include <iostream> // cout, endl
    #include <cstring>  // memset

    using namespace std;

    #define      parent(x) (x/2)
    #define  left_child(x) (2*x)
    #define right_child(x) (2*x + 1)

    class BinaryMinHeap {
    public:
        int * heap;
        int size;
        int max_size;

        BinaryMinHeap(int s)
        {
            /*
                Obs: 0 is sentinel
                Complexity: O(1)
            */

            max_size = s + 1;
            size = 0;

            heap = new int[max_size];
            memset(heap, 0, max_size*sizeof(int));
        }

        void build(int * values, int n)
        {
            /*
                build: builds a heap from an array of values.
                Complexity: O(n log n)
            */
            for(int i = 0; i < n; i++)
                insert(values[i]);
        }

        void heapify(int values[], int n)
        {
            /*
                heapify: turns an array into a heap.
                Complexity: O(n log n)

                !!ATENTION!!
                * Remember to put the sentinel at 0 in the values array
                * The array `values` will be changed in the process
            */

            size = n;
            heap = values;

            for(int i = size/2; i >= 1; --i)
                shift_down(i);
        }

        void insert(int element)
        {
            /*
                insert: adds an element into the heap
                Complexity: O(log n)
            */

            // If the heap is full, there is nothing to be done
            if(size + 1 == max_size) return;

            size++;

            // Add the element to the heap
            heap[size] = element;

            // Rearrenge the heap considering the new element
            int parent_index = parent(size);
            int index = size;

            // While the new element is less the its parent, new element its not
            // the root
            while(index > 1 && heap[parent_index] > element)
            {
                heap[index] = heap[parent_index];
                heap[parent_index] = element;

                index = parent_index;
                parent_index = parent(parent_index);
            }
        }

        int extract_min()
        {
            /*
                extract_min: removes the root element from the heap
                Complexity: O(log n)
            */

            // if the heap is empty, return -1
            if(size == 0) return -1;

            // Pick the root element to extract
            int element = heap[1];

            // Put the last leaf in the root
            heap[1] = heap[size];
            size--;

            // Rearrenge the heap after remotion
            shift_down(1);

            return element;
        }

    private:

        inline void shift_down(int index)
        {
            /*
                shift_down: moves the node down until it reachs a level where its
                            children have a lower priority than it has.
                Complexity: O(log n)
            */

            int lowest_child_index;
            int lowest_child;

            // While the node has children
            while(index <= size/2)
            {
                // If the node has lower priority than one of its children
                // swap the child with its parent

                lowest_child_index = get_lowest_child_index(index);
                lowest_child = heap[lowest_child_index];

                if(lowest_child > heap[index]) break;

                heap[lowest_child_index] = heap[index];
                heap[index] = lowest_child;

                index = lowest_child_index;
            }
        }

        inline int get_lowest_child_index(int index)
        {
            /*
                Complexity: O(1)
            */

            int lowest_child_index = left_child(index);

            if(right_child(index) <= size &&
              heap[left_child(index)] > heap[right_child(index)])
                lowest_child_index = right_child(index);

            return lowest_child_index;
        }

    };



Usage:

.. code-block:: cpp

        BinaryMinHeap heap(10);

        int values[] = {45, 2, 12, 8, 6, 23, 1, 6, 9, 10};

        heap.build(values, 10);

        heap.extract_min();

        int values2[] = {0, 45, 2, 12, 8, 6, 23, 1, 6, 9, 10};

        heap.heapify(values2, 10);

        heap.insert(80);


.. toctree::
   :maxdepth: 2
