#include <iostream>
#include <string>

void swap(int &first, int &second)
{
    int temp = first;
    first = second;
    second = temp;

}

int main()
{
    int x=5;
    int y=8;
    int &r=x;
    r=15;
    swap(x,y);
    std::cout<<"x: "<<x<<" y: "<<y<<std::endl;
    return 0;
    
}