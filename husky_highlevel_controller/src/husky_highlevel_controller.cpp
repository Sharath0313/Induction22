#include<ros/ros.h>
#include<sensor_msgs/LaserScan.h>
#include<geometry_msgs/Twist.h>
#include<array>

float x=1;

void Callback(sensor_msgs::LaserScan msg)
{
    int len = msg.ranges.size() ;
    x = msg.ranges[len/2];
    ROS_INFO("%f",x);
    return ;
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "husky_highlevel_controller");
    ros::NodeHandle sk;
    ros::Subscriber sub = sk.subscribe("scan",10,Callback);
    ros::Publisher pub = sk.advertise<geometry_msgs::Twist>("joy_teleop/cmd_vel",10);
    ros::Rate loopRate(30);
    while(ros::ok())
    {
        geometry_msgs::Twist vel;
        vel.linear.x= 5*x ;
        pub.publish(vel);
        ros::spinOnce();
        loopRate.sleep();
        if(x<0.9)
        return 0;
    }
	// Your code here
    return 0;
}