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
//dekompresi
template <typename lzw>
std::string decompress(lzw begin, lzw end) {
	// membuat kamus dengan ukuran 256
  int ukuran = 256;
  std::map<int,std::string> kamus;
  for (int i = 0; i < 256; i++)
    kamus[i] = std::string(1, i);

  std::string w(1, *begin++);
  std::string result = w;
  std::string entry;
  for ( ; begin != end; begin++) {
    int k = *begin;
    if (kamus.count(k))
      entry = kamus[k];
    else if (k == ukuran)
      entry = w + w[0];
    else
      throw "Dekompresi gagal";

    result += entry;

    kamus[ukuran++] = w + entry[0];

    w = entry;
  }
  return result;
}
//coba kompresi file
  //compress(input_file,lzw_file);
  //fclose(input_file);
  //fclose(lzw_file);
  //free(code_value);
//membuka file
  //lzw_file=fopen("test_awal.lzw","rb");
  //output_file=fopen("test_awal.out","wb");
  //if (lzw_file==NULL || output_file==NULL)
  //{
    //cout<<"Fatal error opening files";
    //exit(-2);
  //};
//tampilkan file
  //expand(lzw_file,output_file);
  //fclose(lzw_file);
  //fclose(output_file);
  //free(prefix_code);
  //free(append_character);
//}
int main() {
	
    //std::ifstream myfile("example.txt");
    //std::string data;
    
   //while(! myfile.eof()) {
            //getline(myfile, data);
            //td::cout << data << "\n\n";
    //}
    
    //std::cin.get();
    
  std::vector<int> kompresi;
  kompres("Kompresi Text dengan Algoritma Lempel-Ziv-Welch", std::back_inserter(kompresi));
  copy(kompresi.begin(), kompresi.end(), std::ostream_iterator<int>(std::cout, ", "));
  std::cout << std::endl;
  std::string dekompresi = decompress(kompresi.begin(), kompresi.end());
  std::cout << dekompresi << std::endl;

return 0;
}
