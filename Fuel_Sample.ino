double MAX_VAL_V = 235;//0.584; //voltage of maximum gauge value
double MIN_VAL_V = 570;//1.423;

//int potValue = 0;
double CAL=0;
int potValue[10];
int j,k;
float result;
float result_ave;
double V;
const int potPin= A0;
void setup()
{
  Serial.begin(9600);
//MAX_VAL_V = MAX_VAL_V ;//* 0.129 ; //voltage div ratio (68k,10k ohms)
 // MIN_VAL_V = MIN_VAL_V ;//* 0.129 ;
  CAL = (MAX_VAL_V - MIN_VAL_V);
}
void loop()
{
  read_fuel();
  delay(1000);
}
String read_fuel()
{
  double FL;
  for (j = 0; j < 10; j++) {
    potValue[j] = analogRead(potPin);
    Serial.println(potValue[j]);
    delay(20);
  }
  j=0;
  result=0;
  for (j = 0; j < 10; j++) {
    result = result + potValue[j];
    Serial.print(j);
    Serial.print(". ");
    Serial.println(result); 
    delay(10);
  }
   result_ave = result / 10;
   
Serial.print("Result= ");
Serial.println(result_ave);

if(result>MIN_VAL_V)
{
  result=MIN_VAL_V;
}
FL= map(result_ave,MIN_VAL_V,MAX_VAL_V,0,100);
if(FL>100)
{
  FL=100;
}
  Serial.println(" Fuel Level = "+ String(FL) +"%");
  Serial.println(V);
  Serial.println(CAL);
  //delay(500); 

  return (String)FL;
 
}
