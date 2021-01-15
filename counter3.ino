//counting numbers 0 to 9999
#include <String.h>

int A[6]={2,3,4,5,6,8};
int B[7]={2,3,4,5,6,7,8};
int C[4]={3,4,6,7};
int D[6]={2,3,4,6,7,8};
int E[5]={3,4,5,6,7};

int nums[10][7]={
  {2,3,4,6,7,8,0},{2,8,0,0,0,0,0},{2,3,5,6,7,0,0},
  {2,3,5,8,7,0,0},{2,4,5,8,0,0,0},{3,4,5,8,7,0,0},
  {3,4,5,6,7,8,0},{2,3,8,0,0,0,0}, {2,3,4,5,6,7,8},{2,3,4,5,7,8,0} 
};

int ports = 12;
int start = 2;

int waits = 2000;
int timee;

void setup()
{
  for(int i=0;i<ports;i++)
  {
    pinMode(start+i,OUTPUT);
    digitalWrite(start+i,HIGH);
  }
  timee=0;
}

void setshigh(int value)
{
  delay(value);
  for(int i=0;i<ports;i++)
  {
    digitalWrite(start+i,HIGH);
  }
}

void setslow(int value)
{
  delay(value);
  for(int i=0;i<ports;i++)
  {
    digitalWrite(start+i,LOW);
  }
}

void displays(int timee)
{
  int n = timee;
  int p = 0;

  int ss=timee;
  
  while(1)
  {
    int d = n%10;
    for(int i=0;i<7;i++)
    {
      digitalWrite(nums[d][i],LOW);
      digitalWrite(10+p,LOW);
    }
    setshigh(1);
    n/=10;
    p++;

    if(n==0) break;
  }
}

void loop()
{  
  digitalWrite(10,HIGH);
  digitalWrite(11,HIGH);
  digitalWrite(12,HIGH);
  digitalWrite(13,HIGH);

  //delay(100);
  //displays(timee++);

  if(timee>9999)
  {
    for(int i=0;i<5;i++)
    {
      digitalWrite(E[i],LOW);
      digitalWrite(10,LOW);
      digitalWrite(11,LOW);
      digitalWrite(12,LOW);
      digitalWrite(13,LOW);
    }
    setshigh(1000);
  }
  else displays(timee++);
}
