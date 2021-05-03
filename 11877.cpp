#include <iostream>

void funcRecur(int n1, int* result);

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n1;
  int result;

  while(std::cin >> n1 && n1 != 0){

    result = 0;

    funcRecur(n1, &result);

    std::cout << result << '\n';

  }

  return 0;
}

void funcRecur(int n1, int* result){

  if(n1 >= 3){

    (*result) += (n1 / 3);
    funcRecur((n1 / 3) + (n1 % 3), result);

  }

  else if(n1 == 2)
    (*result)++;

}
