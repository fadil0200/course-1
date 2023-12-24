#define enca 2
#define encb 3
#define pwm 6
#define ir1 4
#define ir2 5


float current_time, reference_point; 
float integral, previous, output=0;
float kp, ki, kd;
float setpoint;
int pos=0;

void setup()
{
  Serial.begin(9600);
  pinMode(enca,INPUT);
  attachInterrupt(digitalPinToInterrupt(ENCA),readEncoder,RISING);
pinMode(pwm,OUTPUT);X
  pinMode(ir1,input);
  pinMode(ir2,input);
    
}

float pid(float error)
{
  float proportional = error;
   integral += error*current_time;
  previous=error;
float output=(kp*proportional)+(ki*integral)+(kd*derivatice);
return output;
}

void encoder_stat()
{
  int x=digitalread(encb);
  if(x>0){
  pos++;
  }
else  
{
  pos--;
}  
}  
void loop()
{
  float now=millis();
  current_time=(now-reference_point)/1000;
  reference_point=now;
  float error=setpoint-actual;
  output=pid(error);
  



  
  
}
  
