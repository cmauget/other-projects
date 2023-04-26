#include <iostream>

int fact(int v){
    int a(1);
   
    for(int i=1;i<=v;i++){
        a=a*i;
    }
    return a;
    
}

void test(){
    std::cout<<fact(-3)<<"\n";
    std::cout<<fact(0)<<"\n";
    std::cout<<fact(5)<<"\n";
    std::cout<<fact(10)<<"\n";
}

int main(){
    test();
    return 0;
}