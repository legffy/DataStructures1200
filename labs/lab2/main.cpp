#include <iostream>
#include <cmath>
void compute_squares(unsigned int a [],unsigned int b [],unsigned int n){
    for(int i = 0; i<n;i++){
        *(b+i) = *(a+i)**(a+i);
        std::cout << b[i] << std::endl;
    }


}

int main(){
    unsigned int arr[5] = {1,2,3,4,5};
    unsigned int arr2 [5];
    compute_squares(arr,arr2,5);
}