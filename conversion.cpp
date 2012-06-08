#include "ros/ros.h"
#include "std_msgs/String.h"
#include <stdint.h>
#include <sstream>
#include "HT1632.h"
#include "HT1632.cpp"
#define mult 100

ros::Publisher pub_message;

void conv_callback_volt(std_msgs::float64 param) {
	std_msgs::uint16 var;
	var.data = static_cast<uint16_t>(param.data * mult);
	stringstream v;
	v << param;
	pub_message.publish(v.str());
}

void conv_callback_temp(std_msgs::float64 param) {
	std_msgs::uint16 var;
	var.data =  static_cast<uint16_t>(param.data * mult);
	stringstream t;
	t << param;
	pub_message.publish(t.str());
}

int main(int argc, char **argv) {
	ros::init(argc, argv, "matrixconversion");
	ros::NodeHandle node;
	
	pub_voltage = node.advertise<std_msgs::uint16>("voltage/int",1);
	pub_temp = node.advertise<std_msgs::uint16>("temp/int",1);
	pub_message = node.advertise<std::msgs:String>("topic",1);
	
	ros::Subscriber left_temp = node.subscribe("temperature/left",1,&conv_callback_temp);
	ros::Subscriber left_voltage = node.subscribe("voltage/left",1,&conv_callback_volt);
	ros::Rate loop_rate(1);
	
	while(ros::ok()) {
		conv_callback_volt(std_msgs::float64 para);
		conv_callback_temp(std_msgs::float64 para);
		ros::spinOnce();
		loop_rate.sleep();
	}
	
	return 0;
}