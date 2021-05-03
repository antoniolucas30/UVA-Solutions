#include <iostream>

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int input;
  unsigned long long result, lastNum, tmp;

  while(std::cin >> input && input != 0){

    result = 1;
    lastNum = 0;

    for(int i = 0; i < input; i++){

      tmp = result;
      result += lastNum;
      lastNum = tmp;

    }

    std::cout << result << '\n';

  }

  return 0;
}

