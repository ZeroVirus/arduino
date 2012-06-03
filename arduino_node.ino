#include <ros.h>
#include <std_msgs/Float64.h>
#include <std_msgs/UInt16.h>
#include <std_msgs/String.h>
#include <HT1632.h>

ros::NodeHandle node;
std_msgs::String strdata;
ros::Publisher message("message",&strdata);

void temp_callback(const std_msgs::UInt16& temp){
  char str[30];
  sprintf(str,"Temperature: %d",temp);
  strdata.data = str;
  //HT1632.drawImage(str, 9, 9, 9, 9, 0);
  //digitalWrite(13, HIGH-digitalRead(13));
  message.publish(&strdata);
}

void volt_callback(const std_msgs::UInt16& volt) {
  //char str[30];
  //sprintf(str,"Voltage: %d",volt);
  //HT1632.drawImage(str, 9, 9, 9, 9, 0);
  digitalWrite(13, HIGH-digitalRead(13));
}

ros::Subscriber<std_msgs::UInt16> temp("temperature/integer", &temp_callback);
ros::Subscriber<std_msgs::UInt16> volt("voltage/integer", &volt_callback);



void setup()
{
  pinMode(13, OUTPUT);
  node.initNode();
  node.advertise(message);
  node.subscribe(temp);
  node.subscribe(volt);
}

void loop()
{
  node.spinOnce();
  delay(1);
}
