#include <iostream>
#include <vector>

static long findMissing(std::vector<int> list){
  int n = sizeof(list)/ sizeof(list[0]);
  int diff;
  int diff2;
  diff = list[1] - list[0];;
  diff2 = list[n] - list[n-1];
  if (diff == diff2){
    for(int i:list){
      if(i == 0){
            if(diff != list[1] - list[0]){
                 return list[0] + diff;
            }
             else std::cout<<"complete" ; 
        }
      else if(i!=0){
            if(diff != list[i] - list[i-1]){
                return list[0] + diff;
            }
        else std::cout<<"complete" ; 
      }
//       diff != list[i] -list[i-1]?return list[i] + diff: std::cout<<"complete";
    }
  }
return list[0];
}

int main(){
    std::vector<int> test = {1,3,5,9,11};
    findMissing(test);
}
    