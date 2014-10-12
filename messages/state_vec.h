#ifndef STATE_VEC_H
#define STATE_VEC_H OCT_2014


#include <arduino.h>
#include <clearinghouse.h>

#define INCLUDE_PRINT 1

//************************************************************************
//*                        STATE VECTOR MESSAGE
//************************************************************************

using namespace gw;

struct State_vec_msg : public Message {
	// Data available from base class
	//      const char* name()
	//      int id()
	
	int theta;
	int theta_dot;
	int x;
	int x_dot;
    
    //minimal constructor
    State_vec_msg() : Message("state_vec"), 
		theta(0), theta_dot(0), x(0), x_dot(0) {}
		
	//REQUIRED VIRTUAL VOID FROM BASE
	void update(Message* msg) {
		State_vec_msg* ptr = static_cast<State_vec_msg*>(msg);
		theta = ptr->theta;
		theta_dot = ptr->theta_dot;
		x = ptr->x;
		x_dot = ptr->x_dot;
	}
		
	#if INCLUDE_PRINT == 1
	//print
	void print() {
		char buf[120];
		sprintf(buf, "{id:%d,name:%s,theta:%d,theta_dot:%d,x:%d,x_dot:%d}",
			id(), name(), theta, theta_dot, x, x_dot);
		Serial.println(buf);
	}
	#endif
		
};


#endif