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


template <class T> class Matrix  {
    std::vector< LineVector< T > > rows;
    LineVector<T> operator *(LineVector<T>);
    Matrix operator *(Matrix);
    Matrix operator +(Matrix);
public:
    int read(ifstream&);
    int write(ofstream&);
};

