unsigned char mang []={1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  encode(mang);
}

void loop() {
  // put your main code here, to run repeatedly:
}
void encode(unsigned char src[])
{
  unsigned char temp[1000];
  int i=0,j=0;
  int rlen=1;
  int len =sizeof(mang);
  Serial.print("Leng of array: "); Serial.println(len);
  int count=0;
  for(int i=0;i<len;i++){
    temp[j++] = src[i];
    rlen=1;
    while((i+1)< len && src[i]==src[i+1]){
      rlen++;
      i++;
    }
    temp[j++]= rlen;
  }
  for(int t=0;t<j;t++)
  {
    Serial.print(temp[t]);
  }
}
