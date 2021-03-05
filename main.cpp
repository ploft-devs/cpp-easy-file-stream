#include<iostream>
#include"fs.hpp"
using namespace std;

int main(){
    FileStream a ("test.txt");
    cout<<a.nextFloat() + a.nextInt()*a.nextInt();
    return 0;
}