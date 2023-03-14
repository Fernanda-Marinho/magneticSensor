#include <ros/ros.h>
#include <std_msgs/String.h>
#include <wiringPi.h>

#define SENSOR 29



int main(int argc, char **argv)
{
  ros::init(argc, argv, "main");
  ros::NodeHandle n;

  ros::Publisher pub = n.advertise<std_msgs::String>("campo_magnetico", 1000);

  wiringPiSetup();  
  pinMode(SENSOR, INPUT);
  while (ros::ok()) {
    std_msgs::String msg; 
    bool detecta = digitalRead(SENSOR);
    if (detecta){
      msg.data = "On";
      ROS_INFO("On(ROS_INFO)");
      delay(1000);
      pub.publish(msg);
    }
    else{
      msg.data = "Off";
      ROS_INFO("Off(ROS_INFO)");
      delay(1000); 
      pub.publish(msg);
    }
   ros::spinOnce(); 


  } 
  return 0;
}
