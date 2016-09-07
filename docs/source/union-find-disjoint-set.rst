Union-Find Disjoint Set
=======================

.. note::

    Tested on: UVA599, UVA10583, UVA11503, URI1764


.. code-block:: cpp

	#include <iostream>
	#include <vector>

	using namespace std;
	using vi = vector<int>;

	class UFDS {
		int m_count;
		vi m_parents, m_rank;

		public:
		UFDS(int V) : m_count(V), m_parents(V + 1, 0), m_rank(V + 1, 0){
			for(int i=1; i<=V; i++)
			m_parents[i] = i;
		}

		int find_set(int u){
			return m_parents[u] == u ? u : (m_parents[u] = find_set(m_parents[u]));
		}

		inline bool same_set(int u, int v){
			return find_set(u) == find_set(v);
		}

		void union_set(int u, int v){
			if(same_set(u, v))
				return;

			int p = find_set(u);
			int q = find_set(v);

			if(m_rank[p] >= m_rank[q])
				m_parents[q] = p;
			else
				m_parents[p] = q;

			if(m_rank[p] == m_rank[q]) ++m_rank[p];
			--m_count;
		}

		int count() const {  return m_count; }
	};


Usage:

.. code-block:: cpp

    int main()
    {
        UFDS ufds(8);

        ufds.union_set(1, 2);
        ufds.union_set(5, 3);
        ufds.union_set(6, 8);
        ufds.union_set(5, 8);

        return 0;
    }

Usage graphical representation:

After class instantiation:

.. image:: _static/ufds-initial-state.png
   :width: 600 px
   :align: center

After unions:

.. image:: _static/ufds-final-state.png
   :width: 600 px
   :align: center

.. toctree::
   :maxdepth: 2
