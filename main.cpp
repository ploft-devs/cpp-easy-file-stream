#include<iostream>
#include"fs.hpp"
using namespace std;

int main(){
    FileStream a ("teste.txt");
    cout<<a.nextFloat() + a.nextInt()*a.nextInt();
    return 0;
}