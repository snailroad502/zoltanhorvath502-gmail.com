#include <iostream>
#include <fstream>
#include <bits/stdc++.h>

#include "matrix.h"

using namespace std;

template<class T>
int Matrix<T>::read(ifstream& ifile)
{
  int columnsn = 0;
  int rowsn = 1;
  LineVector<T> oneRow;
  while(oneRow.read(ifile)) {
    rows.push_back(oneRow);
    rowsn++;
  }
  return rowsn;
}

template<class T>
int Matrix<T>::write(ofstream& ofile)
{
    for (auto c : rows)
    {  
        c.write(ofile); 
        ofile << endl;
    }
    return 0;
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
    }
    return 0;
}


