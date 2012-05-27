#include <stdint.h>
#include <ros/ros.h>
#include <std_msgs/Float64.h>
#include <std_msgs/UInt16.h>

static ros::Publisher pub_voltage;
static ros::Publisher pub_temp;
static int multiplier;

static void conv_callback_volt(std_msgs::Float64 param) {
	std_msgs::UInt16 var;
	var.data =  static_cast<uint16_t>(param.data * multiplier);
	pub_voltage.publish(var);
}

static void conv_callback_temp(std_msgs::Float64 param) {
	std_msgs::UInt16 var;
	var.data =  static_cast<uint16_t>(param.data * multiplier);
	pub_temp.publish(var);
}

int main(int argc, char **argv) {
	ros::init(argc, argv, "conversion");
	ros::NodeHandle node, node_priv("~");

    node_priv.param("multiplier", multiplier, 100);
	
	pub_voltage = node.advertise<std_msgs::UInt16>("voltage/integer", 1);
	pub_temp = node.advertise<std_msgs::UInt16>("temperature/integer", 1);
	
	ros::Subscriber left_temp = node.subscribe("temperature/left", 1, &conv_callback_temp);
	ros::Subscriber left_voltage = node.subscribe("voltage/left", 1, &conv_callback_volt);
	
	ros::spin();
	return 0;
}
