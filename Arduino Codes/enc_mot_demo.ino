boolean replay=true;
int x_dist=5;  //in cm
int circum=22;  //in cm



int dist_2_enc_value(float x_dist)  //x is dist to be travelled in cm
{ 
return x_dist*2400/22;
}

int actual_enc_val(int x)  //x= pixel value of image
{
  return x*3*2400/2200;    // pix_val * 3mm per pix * no. of counts per mm
  }

  int y_dist(float )

  
int dir1= 12;
int pwm1=9;

int dir2=7;
int pwm2=5;

int encoderPin1=2;
int encoderPin2=3;

volatile int lastEncoded = 0;
volatile long encoderValue = 0;
 
long lastencoderValue = 0;
 
int lastMSB = 0;
int lastLSB = 0;

double Kp=3;
double Kd=.01;

double correction;
double prevError=0;
double PID(int encoderValue,int dist_2_enc_value(dist))//,double Kp,double Kd,double prevError)
{
  double error= dist_2_enc_value(dist)- encoderValue;
  double diffError = error- prevError;
  prevError= error;
 correction=  (Kp*error + Kd*diffError);
 return correction/42;
}

void setup() {
  // put your setup code here, to run once:

pinMode(dir1,OUTPUT);
pinMode(pwm1,OUTPUT);

pinMode(dir2,OUTPUT);
pinMode(pwm2,OUTPUT);


 Serial.begin (9600);
 
  pinMode(encoderPin1, INPUT); 
  pinMode(encoderPin2, INPUT);
 
  digitalWrite(encoderPin1, HIGH); 
  digitalWrite(encoderPin2, HIGH); 
 
  //call updateEncoder() when any high/low changed seen
  //on interrupt 0 (pin 2), or interrupt 1 (pin 3) 
  attachInterrupt(0, updateEncoder, CHANGE); 
  attachInterrupt(1, updateEncoder, CHANGE);

  


}


void updateEncoder(){
  int MSB = digitalRead(encoderPin1); //MSB = most significant bit
  int LSB = digitalRead(encoderPin2); //LSB = least significant bit
 
  int encoded = (MSB << 1) |LSB; //converting the 2 pin value to single number
  int sum  = (lastEncoded << 2) | encoded; //adding it to the previous encoded value
 
  if(sum == 0b1101 || sum == 0b0100 || sum == 0b0010 || sum == 0b1011) encoderValue ++;
  if(sum == 0b1110 || sum == 0b0111 || sum == 0b0001 || sum == 0b1000) encoderValue --;
 
  lastEncoded = encoded; //store this value for next time
}


void loop() {
  // put your main code here, to run repeatedly:

//call pid
double PID(int encoderValue,int dist_2_enc_value(dist));

if(encoderValue < dist_2_enc_value(5))
{
  digitalWrite(dir1,LOW);
analogWrite(pwm1,correction);


digitalWrite(dir2,LOW);
analogWrite(pwm2,correction);

Serial.println(encoderValue);
  }

analogWrite(pwm1,0);
analogWrite(pwm2,0);

if(encoderValue > dist_2_enc_value(5))
{
 digitalWrite(dir1,HIGH);
analogWrite(pwm1,correction);



digitalWrite(dir2,HIGH);
analogWrite(pwm2,correction);

Serial.println(encoderValue);
  }

analogWrite(pwm1,0);
analogWrite(pwm2,0);



//Serial.println(encoderValue);
//  delay(1000); //just here to slow down the output, and show it will work  even during a delay


}
