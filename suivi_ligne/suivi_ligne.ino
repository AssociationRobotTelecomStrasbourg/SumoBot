#include <PID_v1.h>

//#include <Boards.h>
//#include <FirmataDefines.h>
//#include <FirmataMarshaller.h>
//#include <Firmata.h>
//#include <FirmataParser.h>
//#include <FirmataConstants.h>

#include <ZumoShield.h>

int gauche;
int droite;
float gauche_pourcent;
float droite_pourcent;
double position,commande=0,consigne=0;
ZumoMotors motors;
Pushbutton button(ZUMO_BUTTON);

PID myPID(&position, &commande, &consigne,20,0,0.2, DIRECT);



void setup() {
  // put your setup code here, to run once:
  button.waitForButton();
  myPID.SetSampleTime(1);
  myPID.SetOutputLimits(-400,400);  
  myPID.SetMode(AUTOMATIC);
}

void loop() {
  // put your main code here, to run repeatedly:
  gauche=analogRead(0);
  droite=analogRead(3);
  position = (gauche+droite)/2-(1030+800)/2;
  myPID.Compute();
  if ( commande<0 )
  {
    motors.setLeftSpeed(400+commande);
    motors.setRightSpeed(400);
  }
  else {
    motors.setLeftSpeed(400);
    motors.setRightSpeed(400-commande);
    
  }
  
}
