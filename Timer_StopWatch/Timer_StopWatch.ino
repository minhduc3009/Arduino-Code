/*
 * MySW.start();
 * MySW.isRunning();
 * MySW.value();
 * MySW.reset();
 * MySW.stop();
 */
#include <StopWatch.h>

StopWatch MySW; //default
StopWatch Timer_secs(StopWatch::SECONDS);

void setup()
{
  Serial.begin(115200);
  Serial.println("Stopwatch demo");
  Serial.print("Version: ");
  Serial.println(STOPWATCH_LIB_VERSION);
  Timer_secs.start();
}
 int a_pr=1;
void loop()
{
  int a_cr = Timer_secs.value();
  if(a_cr%2==0 && a_cr!=a_pr ) 
  {
    a_pr=a_cr;
    Serial.println(a_pr);
  }
  
//  if(Timer_secs.value()==20)
//  {
//    Timer_secs.stop();
//    Serial.print("Finish!");
//    Timer_secs.reset();
//  }
//  switch(Timer_secs.state())
//  {
//    case StopWatch::RESET: 
//      Serial.println("reset");  // e.g. disable stop/reset
//      break;
//    case StopWatch::RUNNING: 
//      Serial.println("running"); // display laptime
//      break;
//    case StopWatch::STOPPED: 
//      Serial.println("stopped"); // display finaltime
//      break;
//    default: 
//      Serial.println("unknown");
//      break;
//  }
}
