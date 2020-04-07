#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
 
#include "matrix.h"

template class Matrix<double>;
template class LineVector<double>;

using namespace std;

template<class T>
int Matrix<T>::read(ifstream& ifile)
{
  int columnsn = 0;
  int rowsn = 1;
  LineVector<T> oneRow;

  columnsn = oneRow.read(ifile);
  while(columnsn) {
    rows.push_back(oneRow);
    rowsn++;
    columnsn = oneRow.read(ifile);
    if (columnsn != ncols() && columnsn > 0) {
      throw SizeError();
    }
  }
  return rowsn;
}

template<class T>
int Matrix<T>::write(ofstream& ofile)
{
    int rowsn = 1;
    for (auto c : rows)
    {  
        c.write(ofile); 
        ofile << endl;
        rowsn++;
    }
    return rowsn;
}

template<class T>
Matrix<T> Matrix<T>::transponate()
{
  Matrix<T> retval;
  retval.rows.resize(ncols());
  for (auto c : rows)
  {
    int i = 0;  
    for (auto d : c.values)
    {
      retval.rows[i].values.push_back(d);
      i++;
    }
 }
  return retval;
}

template<class T>
Matrix<T> Matrix<T>::operator+(Matrix rhs)
{
    Matrix<T> retval;
    if (ncols()!= rhs.ncols() || nrows() !=rhs.nrows())
      throw SizeError();
    for (auto it1 = rows.begin(), it2 = rhs.rows.begin(); it1 != rows.end(); it1++,
    it2++)
    {  
      retval.rows.push_back(*it1 + *it2);
    }
    return retval;
}

template<class T>
Matrix<T> Matrix<T>::operator*(Matrix rhs)
{
    if (nrows()!= rhs.ncols())
      throw SizeError();
    Matrix<T> retval;
    retval.rows.resize(nrows());
    Matrix<T> tmp = rhs.transponate();
    int i = 0;
    for (LineVector<T> c : rows)
    {
      int j = 0;  
      for (LineVector<T> d : rhs.rows)
      {
        T val = c * d;
        retval.rows[i].values.push_back(val);
        j++;
      }
      i++;
    }
    return retval;
}



template<class T>
int LineVector<T>::read(ifstream& ifile)
{
    int cols = 0;
    string row;
    values.clear();
    if (getline(ifile, row)) {
      stringstream check1(row);
      string s;
      while(getline(check1, s, ';')) {
        T t;
        stringstream ss(s);
        ss >> t;
        values.push_back(t);
        cols++;
      }
    }
    return cols;
}

template<class T>
int LineVector<T>::write(ofstream& ofile)
{
    int count = 0;
    for (auto c : values)
    {  
        ofile << c <<" ";
        count++;
    }
    return count;
}

template<class T>
T LineVector<T>::operator*(LineVector rhs)
{
    T retval;
    if (values.size() != rhs.values.size())
      throw SizeError();
    for (auto it1 = values.begin(), it2 = rhs.values.begin(); it1 != values.end(); it1++,
    it2++)
    {  
      retval = retval+ (*it1 * *it2);
    }
    return retval;
}

template<class T>
LineVector<T> LineVector<T>::operator+(LineVector rhs)
{
    LineVector<T> retval;
    if (values.size() != rhs.values.size())
      throw SizeError();
    for (auto it1 = values.begin(), it2 = rhs.values.begin(); it1 != values.end(); it1++,
    it2++)
    {  
      retval.values.push_back(*it1 + *it2);
    }
    return retval;
}
  
