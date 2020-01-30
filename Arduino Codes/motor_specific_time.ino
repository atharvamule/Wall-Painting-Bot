boolean replay=true;
int t=millis();

int dir1= 12;
int pwm1=9;

int dir2=7;
int pwm2=5;

float aim= 4000;

void setup() {
  // put your setup code here, to run once:

pinMode(dir1,OUTPUT);
pinMode(pwm1,OUTPUT);


pinMode(dir2,OUTPUT);
pinMode(pwm2,OUTPUT);



}
void loop(){

while(millis()-t>=1000)
{
  digitalWrite(dir1,HIGH);
  digitalWrite(pwm1,HIGH);


  digitalWrite(dir2,LOW);
  digitalWrite(pwm2,HIGH);
} 

while(1){/*empty*/}
 
}


/*
     OR

while(replay==true)
{
while(millis()-t>=1000)
{
  digitalWrite(dir1,HIGH);
  digitalWrite(pwm1,HIGH);


  digitalWrite(dir2,LOW);
  digitalWrite(pwm2,HIGH);
} 

}
replay=false;
*/
