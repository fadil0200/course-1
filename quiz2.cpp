#include <iostream>
#include <string>

class date
{
private:
int day;
int month;
int year;
   
public:
void setDay(int local_day)
{
    day=local_day;
}    
int getDay()
{
    return day;
}
void setMonth(int local_month)
{
    month=local_month;
}
int getMonth()
{
    return month;
}
void setYear(int local_year)
{
    year=local_year;
}
int getYear()
{
    return year;
}
void validate()
{
    if(year<2000)
    {
        std::cout<<"entry is wrong"<<std::endl;
    }
    if(month>12)
    {
        std::cout<<"entry month is wrong"<<std::endl;
    }
    if(day>31)
    {
        std::cout<<"entry day is wrong"<<std::endl;
    }
}
void leap()
{
    if(month==2&&day==29)
    {
    std::cout<<"leap year"<<std::endl;
    }
    else
    {
        std::cout<<"not a leap year"<<std::endl;
    }

}

};

class today : public date
{
    public:
    today()
    {

    }
    void display()
    {
        std::cout<<"the year is: "<<getYear()<<" the month is: "<<getMonth()<<" the day is: "<<getDay()<<std::endl;
    }


};

int main()
{
    today now;
    
    now.setMonth(3);
    now.setDay(32);
    now.setYear(2010);
    now.leap();
    now.validate();
    now.display();
    
    return 0;

}