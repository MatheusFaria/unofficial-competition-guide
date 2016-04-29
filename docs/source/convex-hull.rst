Convex Hull
===========

Used to find the smallest convex polygon that envolves a set of points in a 2D plane.

.. note::

    Tested on: URI1982

.. code-block:: cpp

    
	struct Point{
	    int x, y;
	    Point(){}
	    Point(int _x, int _y){
	        x = _x;
	        y = _y;
	    }
	    bool operator <(const Point &p)const {
	        return x < p.x || (x == p.x && y < p.y);
	    }
	};

	ll cross(const Point &O, const Point &A, const Point &B){
	    return (A.x - O.x)*(ll)(B.y - O.y) - (A.y - O.y)*(ll)(B.x - O.x);
	}

	vector<Point> convex_hull(vector<Point> P){
	    int n = P.size(), k=0;
	    vector<Point> H(2*n);
	    sort(P.begin(), P.end());
	    for(int i=0; i<n; ++i){
	        while(k >= 2 && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
	        H[k++] = P[i];
	    }
	    for(int i=n-2, t=k+1; i>=0; --i){
	        while(k >= t && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
	        H[k++] = P[i];
	    }
	    H.resize(k);
	    return H;
	}

.. toctree::
   :maxdepth: 2
