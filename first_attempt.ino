#include <ros.h>
#include <std_msgs/String.h>

//Publishers
ros::NodeHandle node_left_temp;
ros::NodeHandle node_right_temp;
ros::NodeHandle node_left_volt;
ros::NodeHandle node_right_volt;
std_msgs::int data_left_temp; //not sure if it takes all types
std_msgs::int data_right_temp;
std_msgs::int data_left_volt;
std_msgs::int data_right_volt;
ros::Publisher left_temp("left temperature", data_left_temp);
ros::Publisher right_temp("right temperature", data_right_temp);
ros::Publisher left_voltage("left voltage", data_left_volt);
ros::Publisher right_voltage("right voltage", data_right_volt);

void setup() {
  node.initNode();
  node.advertise(left_temp);
  node.advertise(right_temp);
  node.advertise(left_voltage);
  node.advertise(right_voltage);
}



  
