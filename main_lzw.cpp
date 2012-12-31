/*
 * File : lzw.cpp
 *  Created on: Dec 26, 2012
 *      Author: prastyo
 *      OS : GNU/Linux Ubuntu 12.04.1 x64
 *      IDE : Eclipse-CDT
 *      Kelompok : Ade Abdul Gofur, Aziz Prastyo Wibowo, Regi Azwar Hadie
 */
#include <string>
#include <map>
#include <iostream>
#include <iterator>
#include <vector>

// Kompresi text
template <typename lzw>
lzw kompres(const std::string &nokompres, lzw result) {
// membuat kamus dengan ukuran 256
  int ukuran = 256;
  std::map<std::string,int> kamus;
  for (int i = 0; i < 256; i++)
	  kamus[std::string(1, i)] = i;

  std::string w;
  for (std::string::const_iterator a = nokompres.begin();
       a != nokompres.end(); ++a) {
    char k = *a;
    std::string wk = w + k;
    if (kamus.count(wk))
      w = wk;
    else {
      *result++ = kamus[w];
      kamus[wk] = ukuran++;
      w = std::string(1, k);
    }
  }

  // tampilkan kode
  if (!w.empty())
    *result++ = kamus[w];
  return result;
}

int main() {

}
