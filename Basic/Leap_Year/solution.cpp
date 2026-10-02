#include <iostream>
 #include <stdbool.h>
 int checkYear(int n) {
    
    if(n%400==0){
      return true;
    }
    else if(n%4==0&&n%100!=0){
        return true;
    }
    else{
        return false;
    }
}


int main() {
    int testYear = 2024;
    
    std::cout << "Testing year " << testYear << "...\n";
    if (checkYear(testYear)) {
        std::cout << testYear << " is a Leap Year!\n";
    } else {
        std::cout << testYear << " is NOT a Leap Year.\n";
    }
    
    return 0;
}
