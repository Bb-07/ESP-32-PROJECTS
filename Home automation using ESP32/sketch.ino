int relay1=16;
int relay2=17;
int relay3=18;
int relay4=18;


void setup() 
{
  pinMode(16, OUTPUT);
  pinMode(17, OUTPUT);
  pinMode(18, OUTPUT);
  pinMode(19, OUTPUT);
}

void loop() 
{
  digitalWrite(16, HIGH);
  digitalWrite(17, HIGH);
  digitalWrite(18, HIGH);
  digitalWrite(19, HIGH);
  delay(5000);

  digitalWrite(16,0);
  digitalWrite(17,0);
  digitalWrite(18,0);
  digitalWrite(19,0);
  delay(1000);

  
}
