#include <iostream>
#include <string>

class person
{
private:
    std::string name;
    int age;
    std::string country;

public:
void setAGE(int age)
{
    this->age=age;
}
int getAGE()
{
    return age;
}
void setNAME(std::string name)
{
    this->name=name;
}
std::string getNAME()
{
    return name;
}
void setCOUNTRY(std::string country)
{
    this->country=country;
}
std::string getCOUNTRY()
{
    return country;
}

};

class data : public person
{
    public:
    data()
    {

    }

    void display()
    {
        std::cout<<"the name is: "<<getNAME()<<" the age is: "<<getAGE()<<" the country is: "<<getCOUNTRY()<<std::endl;


    }
};

int main()
{
    data per;
    per.setNAME("ahmed");
    per.setAGE(30);
    per.setCOUNTRY("egypt");
    per.display();
    return 0;
}