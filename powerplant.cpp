#include <iostream>
#include <string>

float pw(float v, float p1, float p2)
{
    float pw;
    pw=v*(p2-p1);
    return pw;
}
float wout(float mf, float qin, float qout)
{
    float wnet;
    wnet=mf*(qin-qout);
    return wnet;
}
float nth(float qin, float qout)
{ 
    float nther;
    nther=(1-(qout/qin))*100;
    return nther;
}
float qin(float h3, float h2)
{
    float qin=h3-h2;
    return qin;
}
float qout(float h4, float h1)
{
    float qout=h4-h1;
    return qout;
}
float h2(float pw,float h1)
{
    float h2=pw+h1;
    return h2;
}
float qin_Reheat(float h3, float h2, float h5, float h4)
{std::cout<<"  "<<std::endl;
    float qin_reheat=(h3-h2)+(h5-h4);
    return qin_reheat;
}
float qout_Reheat(float h6, float h1)
{
    float qout_reheat=h6-h1;
    return qout_reheat;

}
float ha(float nt,float h_inlet,float h_outlet_ideal)
{
    float h_actual=h_inlet-(nt*(h_inlet-h_outlet_ideal));
    return h_actual;

}
float wpa(float nt,float v1,float p2, float p1)
{
    float wp_actual=(v1*(p2-p1))/nt;
    return wp_actual;

}
float wta(float h3, float h4a)
{
   float w_turbine_actual=h3-h4a;
   return w_turbine_actual;

}
float wna(float wta,float wpa)
{
    float w_net_actual=wta-wpa;
    return w_net_actual;

}
float ntha(float wnet_actual,float qin_actual)
{
    float nth_actual=(wnet_actual/qin_actual)*100;
    return nth_actual;
}

int main()
{
/*task1*/
float p1_ideal=10 , p2_ideal=3000, p3_ideal=3000, p4_ideal=10,  v1_ideal=0.001010/*from table*/ , mf=20, h1_ideal=191.81,h2_ideal,h3_ideal=3100/*from chart*/
,h4_ideal=2140/*from chart*/,qin_ideal, qout_ideal;
float pw_ideal, wnet_ideal, nther_ideal;
pw_ideal=pw(v1_ideal,p1_ideal,p2_ideal);
float x=0.81; /*from chart*/
h2_ideal=h2(pw_ideal,h1_ideal);
qin_ideal=qin(h3_ideal,h2_ideal);
qout_ideal=qout(h4_ideal,h1_ideal);
wnet_ideal=wout(mf,qin_ideal,qout_ideal);
nther_ideal=nth(qin_ideal,qout_ideal);
std::cout<<"  "<<std::endl;
std::cout<<"qin ideal= "<<qin_ideal<<std::endl;
std::cout<<"qout ideal= "<<qout_ideal<<std::endl;
std::cout<<"ideal moisture content is: "<<x<<std::endl;
std::cout<<"ideal pump work= "<<pw_ideal<<std::endl;
std::cout<<"ideal work net= "<<wnet_ideal<<std::endl;
std::cout<<"ideal thermal eff= "<<nther_ideal<<std::endl;
/*task 2*/
float ptask2_1=3600/*1.2 boiler pressure*/, ptask2_2=4200/*1.4 boiler pressure*/, ptask2_3=4800/*1.6 boiler pressure*/,ptask2_4=5400/*1.8 boiler pressure*/;
float pwtask2_1=pw(v1_ideal,p1_ideal,ptask2_1);
float h2task2_1=h2(pwtask2_1,h1_ideal);
float h3task2_1=3100;/*from chart*/
float h4task2_1=2180;/*from chat*/
float qintask2_1=qin(h3task2_1,h2task2_1);
float qouttask2_1=qout(h4task2_1,h1_ideal);
float nther_task2_1=nth(qintask2_1,qouttask2_1);
std::cout<<"  "<<std::endl;
std::cout<<"qin for task 2 no.1= "<<qintask2_1<<std::endl;
std::cout<<"qout for task 2 no.1= "<<qouttask2_1<<std::endl;
std::cout<<"thermal efficiency for task 2 no.1= "<<nther_task2_1<<std::endl;
float pwtask2_2=pw(v1_ideal,p1_ideal,ptask2_2);
float h2task2_2=h2(pwtask2_2,h1_ideal);
float h3task2_2=3080;/*from chart*/
float h4task2_2=2160;/*from chart*/
float qintask2_2=qin(h3task2_2,h2task2_2);
float qouttask2_2=qout(h4task2_2,h1_ideal);
float nther_task2_2=nth(qintask2_2,qouttask2_2);
std::cout<<"  "<<std::endl;
std::cout<<"qin for task 2 no.2= "<<qintask2_2<<std::endl;
std::cout<<"qout for task 2 no.2= "<<qouttask2_2<<std::endl;
std::cout<<"thermal efficiency for task 2 no.2= "<<nther_task2_2<<std::endl;
float pwtask2_3=pw(v1_ideal,p1_ideal,ptask2_1);
float h2task2_3=h2(pwtask2_3,h1_ideal);
float h3task2_3=3060;/*from chart*/
float h4task2_3=2150;/*from chart*/
float qintask2_3=qin(h3task2_3,h2task2_3);
float qouttask2_3=qout(h4task2_3,h1_ideal);
float nther_task2_3=nth(qintask2_3,qouttask2_3);std::cout<<"  "<<std::endl;
std::cout<<"  "<<std::endl;
std::cout<<"qin for task 2 no.3= "<<qintask2_3<<std::endl;
std::cout<<"qout for task 2 no.3= "<<qouttask2_3<<std::endl;
std::cout<<"thermal efficiency for task 2 no.3= "<<nther_task2_3<<std::endl;
float pwtask2_4=pw(v1_ideal,p1_ideal,ptask2_4);
float h2task2_4=h2(pwtask2_4,h1_ideal);
float h3task2_4=3050;/*from chart*/
float h4task2_4=2120;/*from chart*/
float qintask2_4=qin(h3task2_4,h2task2_4);
float qouttask2_4=qout(h4task2_4,h1_ideal);
float nther_task2_4=nth(qintask2_4,qouttask2_4);
std::cout<<"  "<<std::endl;
std::cout<<"qin for task 2 no.4= "<<qintask2_4<<std::endl;
std::cout<<"qout for task 2 no.4= "<<qouttask2_4<<std::endl;
std::cout<<"thermal efficiency for task 2 no.4= "<<nther_task2_4<<std::endl;
/*task 3*/
float ptask3_1=9 /*condenser prstd::cout<<"  "<<std::endl;esser *0.9*/, ptask3_2=8 /*condenser presser *0.8*/, ptask3_3=7 /*condenser presser *0.7*/, ptask3_4=6 /*condenser presser *0.6*/;
float v1task3_1=0.0010092;
float pwtask3_1=pw(v1task3_1,ptask3_1,p3_ideal);
float h1task3_1=182.586; /*interpolation*/
float h2task3_1=h2(pwtask3_1,h1task3_1);
float h4task3_1=2130;
float qintask3_1=qin(h3_ideal,h2task3_1);
float qouttask3_1=qout(h4task3_1,h1task3_1);
float nther_task3_1=nth(qintask3_1,qouttask3_1);
std::cout<<"  "<<std::endl;
std::cout<<"qin for task 3 no.1= "<<qintask3_1<<std::endl;
std::cout<<"qout for task 3 no.1= "<<qouttask3_1<<std::endl;
std::cout<<"thermal efficiency for task 3 no.1= "<<nther_task3_1<<std::endl;
float v1task3_2=0.0010084;
float pwtask3_2=pw(v1task3_2,ptask3_2,p3_ideal);
float h1task3_2=173.362; /*interpolation*/
float h2task3_2=h2(pwtask3_2,h1task3_2);
float h4task3_2=2100;
float qintask3_2=qin(h3_ideal,h2task3_2);
float qouttask3_2=qout(h4task3_2,h1task3_2);
float nther_task3_2=nth(qintask3_2,qouttask3_2);
std::cout<<"  "<<std::endl;
std::cout<<"qin for task 3 no.2= "<<qintask3_2<<std::endl;
std::cout<<"qout for task 3 no.2= "<<qouttask3_2<<std::endl;
std::cout<<"thermal efficiency for task 3 no.2= "<<nther_task3_2<<std::endl;
float v1task3_3=0.0010074;
float pwtask3_3=pw(v1task3_3,ptask3_3,p3_ideal);
float h1task3_3=182.586; /*interpolation*/
float h2task3_3=h2(pwtask3_3,h1task3_3);
float h4task3_3=2090;
float qintask3_3=qin(h3_ideal,h2task3_3);
float qouttask3_3=qout(h4task3_3,h1task3_3);
float nther_task3_3=nth(qintask3_3,qouttask3_3);
std::cout<<"  "<<std::endl;
std::cout<<"qin for task 3 no.3= "<<qintask3_3<<std::endl;
std::cout<<"qout for task 3 no.3= "<<qouttask3_3<<std::endl;
std::cout<<"thermal efficiency for task 3 no.3= "<<nther_task3_3<<std::endl;
float v1task3_4=0.0010062;
float pwtask3_4=pw(v1task3_4,ptask3_4,p3_ideal);
float h1task3_4=150.15; /*interpolation*/
float h2task3_4=h2(pwtask3_4,h1task3_4);
float h4task3_4=2070;/*from chart*/
float qintask3_4=qin(h3_ideal,h2task3_4);
float qouttask3_4=qout(h4task3_4,h1task3_4);
float nther_task3_4=nth(qintask3_4,qouttask3_4);
std::cout<<"  "<<std::endl;
std::cout<<"qin for task 3 no.4= "<<qintask3_4<<std::endl;
std::cout<<"qout for task 3 no.4= "<<qouttask3_4<<std::endl;
std::cout<<"thermal efficiency for task 3 no.4= "<<nther_task3_4<<std::endl;
/*task4*/
float pw_reheat=pw(v1_ideal,p1_ideal,p2_ideal);
float h2_reheat=h2(pw_reheat,h1_ideal);
float h4_reheat=2930;/*from chart*/
float h5_reheat=3140;/*from chart*/
float h6_reheat=2250;/*from chart*/
float x_reheat=0.86;/*from chart*/
float qin_reheat=qin_Reheat(h3_ideal,h2_reheat,h5_reheat,h4_reheat);
float qout_reheat=qout_Reheat(h6_reheat,h1_ideal);
float wnet_reheat=wout(mf,qin_reheat,qout_reheat);
float nther_reheat=nth(qin_reheat,qout_reheat);
std::cout<<"  "<<std::endl;
std::cout<<"the reheat pumpwork  = "<<pw_reheat<<std::endl;
std::cout<<"the reheat moisture content = "<<x_reheat<<std::endl;
std::cout<<"the reheat qin  = "<<qin_reheat<<std::endl;
std::cout<<"the reheat qout  = "<<qout_reheat<<std::endl;
std::cout<<"the reheat work net = "<<wnet_reheat<<std::endl;
std::cout<<"the reheat efficiency = "<<nther_reheat<<std::endl;
/*task 5*/
float pw_actual=wpa(0.95,v1_ideal,p2_ideal,p1_ideal);
float h2_actual=h2(pw_actual,h1_ideal);
float h4_actual=ha(0.85,h3_ideal,h4_ideal);
float x_actual=0.89; /*from chart*/
float w_trubine_actual=wta(h3_ideal,h4_actual);
float qin_actual=qin(h3_ideal,h2_actual);
float qout_actual=qout(h4_actual,h1_ideal);
float wnet_actual=wna(w_trubine_actual,pw_actual);
float nth_actual=ntha(wnet_actual,qin_actual);
std::cout<<"  "<<std::endl;
std::cout<<"the actual pumpwork  = "<<pw_actual<<std::endl;
std::cout<<"the actual moisture content = "<<x_actual<<std::endl;
std::cout<<"the actual qin  = "<<qin_actual<<std::endl;
std::cout<<"the actual qout  = "<<qout_actual<<std::endl;
std::cout<<"the actual work net = "<<wnet_actual<<std::endl;
std::cout<<"the actual efficiency = "<<nth_actual<<std::endl;





}