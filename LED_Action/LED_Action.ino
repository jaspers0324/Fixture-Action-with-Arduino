int plate_led = 6;
int door_led = 7;
int probe_led = 8;
int dut_led = 9;
int box_check = 13;

void setup() 
{
 pinMode (13,OUTPUT);
 pinMode (plate_led,OUTPUT);
 pinMode (door_led,OUTPUT);
 pinMode (probe_led,OUTPUT);
 pinMode (dut_led,OUTPUT);
 
 Serial.begin(9600);
}

void loop() 
{
  
  int val;
  
  if(Serial.available()){
    
    delay(100);
    
    while(Serial.available() >0)
    {
      
      val=Serial.read();

        // Auto Open
        if(val=='0')
        {
          digitalWrite(dut_led,HIGH);
          delay (500);
          digitalWrite(probe_led,HIGH);
          delay (500);
          digitalWrite(door_led,HIGH);
          delay (500);
          digitalWrite(plate_led,HIGH);
          Serial.println ("Fixture Stop Action!");
         }
           
           // Plate Back
           if (val=='2') 
           {
              digitalWrite(plate_led,HIGH);
              Serial.println ("Plate Back");
           }

           // Door Open
           if (val=='4') 
           {
              digitalWrite(door_led,HIGH);
              Serial.println ("Door Open");
           }

           
           // Probe Up
           if (val=='6') 
           {
              digitalWrite(probe_led,HIGH);
              Serial.println ("Probe Up"); 
           }

           
           // DUT Dis-Link
           if (val=='8') 
           {
              digitalWrite(dut_led,HIGH);
              Serial.println ("DUT Dis-Link");
           }
          

        // Auto Close
        if (val=='1') 
        {
           digitalWrite(plate_led,LOW);
           delay (500);
           digitalWrite(door_led,LOW);
           delay (500);
           digitalWrite(probe_led,LOW);
           delay (500);
           digitalWrite(dut_led,LOW);
           Serial.println ("Fixture Already!");
         }
            
           // Plate Insert
           if (val=='3') 
           {
              digitalWrite(plate_led,LOW);
              Serial.println ("Plate Insert");
           }

           // Door Close
           if (val=='5') 
           {
              digitalWrite(door_led,LOW);
              Serial.println ("Door Close");
           }

           // Probe Contact 
           if (val=='7') 
           {
              digitalWrite(probe_led,LOW);
              Serial.println ("Probe Contact");
           }

           // Ping DUT
           if (val=='9') 
           {
              digitalWrite(dut_led,LOW);
              Serial.println ("Ping DUT");
           }
    }
  }
}
