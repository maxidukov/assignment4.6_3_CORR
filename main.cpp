#include <iostream>
#include <string>
#include <numeric>
#include <iomanip>

int sumhash(const std::string&);

int find_substring_light_rabin_karp(const std::string&, const std::string& );

int main() {
  //std::cout << "Hello World!\n";
  //std::string txt  =  "hello";
  //std::cout << sumhash(txt) << std::endl;
  std::string text;
  std::cout << "Введите строку, в которой будет осуществляться поиск: ";
  std::cin >> std::setw(255) >> text;
  std::string pattern;
  do{
    std::cout << "Введите подстроку, которую нужно найти: ";
    std::cin >> std::setw(255) >> pattern;
    int res = find_substring_light_rabin_karp(text,pattern);
    std::cout << "Подстрока " << pattern;
     if(res > -1){
        std::cout<<" найдена по индексу " << res << "\n";
      } else {
       std::cout<<" не найдена" << "\n";
     }
  }while(pattern != "exit");
}

int sumhash(const std::string& str){
  return std::accumulate(str.begin(), str.end(), 0, []( int a, char c){return a + c;});
}

int find_substring_light_rabin_karp(const std::string& text, const std::string& pattern){
  int pattern_hash = sumhash(pattern);
  //std::cout<<"Pattern hash is "<<pattern_hash<<"\n";
  int pattern_length = pattern.size();
  int hash = sumhash(text.substr(0, pattern_length));
  //int retval = -1;
  for(int i{}; i <= text.size() - pattern_length; i++){
    if(i>0){
      hash = hash - sumhash(text.substr(i-1,1)) + sumhash(text.substr(i+pattern_length-1,1));
    }
    //std::cout<<"Subtext hash at index "<<i<<" is "<<hash<<"\n";
    if(hash == pattern_hash){
      //std::cout<<"Got hash match\n";
      for(int j{}; j < pattern_length; j++){
        if(text[i+j] != pattern[j]){
          //std::cout<<text[i+j]<<" != "<<pattern[j]<<"\n";
          break;
        }
        return i;
      }
    }
  }
  return -1;
}
