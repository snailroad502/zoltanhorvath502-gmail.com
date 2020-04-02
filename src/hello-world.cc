#include "matrix.h"


template<class T>
int LineVector<T>::read(ifstream& ifile)
{
    string row;
    if (getline(ifile, row)) {
      stringstream check1(row);
      string s;
      while(getline(check1, s, ';'))
        values.push_back(s);
      return 1;
    }
    return 0;
}

template<class T>
int LineVector<T>::write(ofstream& ofile)
{
    for (auto c : values)
    {  
        ofile << c;
    }
    return 0;
}



int main() {
  std::cerr << "Hello master!\n";
  LineVector<string> v;
  ifstream ifile;
  ifile.open("ifile.dat");
  v.read(ifile);
  ofstream ofile;
  ofile.open("ofile.dat");
  v.write(ofile);
  ofile.close();
  ifile.close();
}
