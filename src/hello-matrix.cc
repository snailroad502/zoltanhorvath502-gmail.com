#include <iostream>
#include <fstream>
#include <bits/stdc++.h>

#include "matrix.h"




int main() {
  std::cerr << "Hello master!\n";
  Matrix<double> v;
  ifstream ifile;
  ifile.open("ifile.dat");
  v.read(ifile);
  ofstream ofile;
  ofile.open("ofile.dat");
  v.write(ofile);
  ofile.close();
  ifile.close();
}
