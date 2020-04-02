#include <iostream>
#include <fstream>
#include <bits/stdc++.h>


using namespace std;

template <class T> class LineVector  {
    std::vector<T> values;
    T operator *(LineVector);
    LineVector operator *(T);
    LineVector operator +(LineVector);
public:
    int read(ifstream&);
    int write(ofstream&);
};


