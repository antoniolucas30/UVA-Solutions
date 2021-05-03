#include <iostream>

bool areFriends(int* arrFriend, int friendU, int friendV);
bool areEnemies(int* arrEnemy, int enemyU, int enemyV);
void Union(int* arrUnify, int* arrFriends, int* arrEnemies, int* qntUnify, int friendU, int friendV, int operation);

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int totalPeople;
  int* Friends;
  int* qntFriends;
  int* Enemies;
  int* qntEnemies;
  int operation;
  int friendU;
  int friendV;

  std::cin >> totalPeople;

  Friends = new int[totalPeople];
  Enemies = new int[totalPeople];
  qntFriends = new int[totalPeople]{0};
  qntEnemies = new int[totalPeople]{0};

  for(int i = 0; i < totalPeople; i++){

    Friends[i] = i;
    Enemies[i] = i;

  }

  while(std::cin >> operation >> friendU >> friendV && operation != 0){

    if(operation == 1)
      Union(Friends, Friends, Enemies, qntFriends, friendU, friendV, operation);

    else if(operation == 2)
      Union(Enemies, Friends, Enemies, qntEnemies, friendU, friendV, operation);

    else if(operation == 3)
      std::cout << areFriends(Friends, friendU, friendV) << '\n';

    else
      std::cout << areEnemies(Enemies, friendU, friendV) << '\n';

  }

  delete[] Friends;
  delete[] Enemies;
  delete[] qntFriends;
  delete[] qntEnemies;

  return 0;
}

int Find(int* arr, int current){
  
  return (arr[current] == current) ? current : arr[current] = Find(arr, arr[current]);

}

bool areFriends(int* arrFriend, int friendU, int friendV){

  return Find(arrFriend, friendU) == Find(arrFriend, friendV);

}

bool areEnemies(int* arrEnemy, int enemyU, int enemyV){

  return Find(arrEnemy, enemyU) == Find(arrEnemy, enemyV);

}

void Union(int* arrUnify, int* arrFriends, int* arrEnemies, int* qntUnify, int friendU, int friendV, int operation){

  int fatherU;
  int fatherV;

  if(operation == 1 && areEnemies(arrEnemies, friendU, friendV)){

    std::cout << -1 << '\n';
    return;

  }

  else if(operation == 2 && areFriends(arrFriends, friendU, friendV)){

    std::cout << -1 << '\n';
    return;

  }

  fatherU = Find(arrUnify, friendU);
  fatherV = Find(arrUnify, friendV);

  if(qntUnify[fatherU] > qntUnify[fatherV])
    arrUnify[fatherV] = fatherU;

  else if(qntUnify[fatherU] < qntUnify[fatherV])
    arrUnify[fatherU] = fatherV;

  
  else{

    arrUnify[fatherU] = fatherV;
    qntUnify[fatherV]++;

  }

}


