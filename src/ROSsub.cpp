#include <stdint.h>
#include <ros/ros.h>
#include <std_msgs/Float64.h>
#include <std_msgs/UInt16.h>

#define mult 100

ros::Publisher pub_voltage;
ros::Publisher pub_temp;

void conv_callback_volt(std_msgs::Float64 param) {
	std_msgs::UInt16 var;
	var.data =  static_cast<uint16_t>(param.data * mult);
	pub_voltage.publish(var);
}

void conv_callback_temp(std_msgs::Float64 param) {
	std_msgs::UInt16 var;
	var.data =  static_cast<uint16_t>(param.data * mult);
	pub_temp.publish(var);
}

int main(int argc, char **argv) {
	ros::init(argc, argv, "matrixconversion");
	ros::NodeHandle node;
	
	pub_voltage = node.advertise<std_msgs::UInt16>("voltage/int",1);
	pub_temp = node.advertise<std_msgs::UInt16>("temp/int",1);
	
	ros::Subscriber left_temp = node.subscribe("temperature/left",1,&conv_callback_temp);
	ros::Subscriber left_voltage = node.subscribe("voltage/left",1,&conv_callback_volt);
	
	ros::spin();
	return 0;
}
