#include <iostream>
#include <vector>


int main(){

  std::vector<int> nums;


  for (int i = 0; i <= 3000; i++) {
    nums.push_back(i * 1000);
  }


  int offset, limit = 52;
  
  for (offset = 0; offset <= nums.size();) {

    std::cout << "offset " << offset << std::endl;
    
    if (offset + limit <= nums.size()) offset += limit;
    else offset += (offset + limit) - nums.size();
  } 

}
