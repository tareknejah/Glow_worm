#ifndef MOTOR_STATUS_H
#define MOTOR_STATUS_H OCT_2014

#include <arduino.h>
#include <clearinghouse.h>

#define INCLUDE_PRINT 1

//************************************************************************
//*                      MOTOR_STATUS MESSAGE
//* Note that curent is passed from the Motor class as the integer
//* reading from the ADC.  If the reading in Volts is desired then
//* a conversion must be done elsewhere.
//************************************************************************

using namespace gw;

struct Motor_status_msg : public Message {
	// Data available from base class
	//      const char* name()
	//      int id()
	
	long  ct;
	int I;			//millivolts
	Time timestamp;
	    
    //minimal constructor
    Motor_status_msg() : Message("motor_status"), 
		ct(0), I(0.0), timestamp(0) {}
		
	//REQUIRED VIRTUAL VOID FROM BASE
	void update(Message* msg) {
		Motor_status_msg* ptr = static_cast<Motor_status_msg*>(msg);
		ct = ptr->ct;
		I = ptr->I;
		timestamp = ptr->timestamp;
	}
		
	#if INCLUDE_PRINT == 1
	//print
	void print() {
		Serial.print(F("{id:"));
		Serial.print(id());
        Serial.print(F(",name:"));
		Serial.print(name());
		Serial.print(F(",stamp:"));
		Serial.print(timestamp);
		Serial.print(F(",I:"));
		Serial.print(I);
		Serial.print(F(",ct:"));
		Serial.print(ct);
        Serial.println(F("}"));
	}
	#endif
		
};


#endif