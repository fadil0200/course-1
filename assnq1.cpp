#include <iostream>
#include <string>

class circle
{

private:
int radius=8;
float pi=3.14;

public:
circle()
{

}

circle(int par_r, int par_pi)
{
    radius=par_r;
    pi=par_pi;

}
int area()
{
    return radius*radius*pi;

}
int circ()
{
    return 2*radius*pi;
}


void display()
{
    std::cout<<"the area is: "<<area()<<" the circumference is: "<<circ()<<std::endl;
}
};

int main()
{
    circle cir;
    cir.area();
    cir.circ();
    cir.display();
    return 0;
}






    


