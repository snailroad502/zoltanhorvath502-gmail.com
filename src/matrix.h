using namespace std;
template <class T> class Matrix;
template <class T> class LineVector  {
friend class Matrix<T>;
    std::vector<T> values;
    T operator *(LineVector<T>);
    LineVector operator *(T);
    LineVector operator +(LineVector);
public:
    int read(ifstream&);
    int write(ofstream&);
};


template <class T> class Matrix  {
    std::vector< LineVector< T > > rows;
public:
    const int nrows() {return rows.size();};
    const int ncols() {return rows.size() ? rows.begin()->values.size() : 0;};
    Matrix transponate();
    Matrix operator *(Matrix);
    Matrix operator +(Matrix);
    int read(ifstream&);
    int write(ofstream&);
};

class MatrixError {};
class ZeroDivide : public MatrixError {};
class SizeError : public MatrixError {};


