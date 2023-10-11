#include <iostream>
#include <string>

struct data
{
    int id;
    std::string name;
    int age;
    int gpa;

};
int main()
{
    data *person1= new data[4];
    std::cout<<"please enter your data "<<std::endl;

for (int i = 0; i < 3; i++)
{
    std::cout << "please enter data["<<i<<"]\n";
    std::cin>>person1[i].age;
    std::cin>>person1[i].gpa;
    std::cin>>person1[i].name;
    std::cin>>person1[i].id;

}

for (int i = 0; i < 3; i++)
{
    std::cout<<" the name is: "<<person1[i].name<<std::endl;
    std::cout<<" the gpa is: "<<person1[i].gpa<<std::endl;
    std::cout<<" the id is: "<<person1[i].id<<std::endl;
    std::cout<<" the age is: "<<person1[i].age<<std::endl;

}
delete [] person1;

return 0;




   
    
}

