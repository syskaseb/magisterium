#include <ros/ros.h>
#include <geometry_msgs/Twist.h>

int main(int argc, char ** argv) {
    // init ROS
    ros::init(argc, argv, "publish_velocity");
    ros::NodeHandle nh;

    // create a publisher object
    ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("chatter", 1000);
    // seed random number generator
    srand((unsigned int) time(0));

    // loop at 2Hz until the node is shutdown
    ros::Rate rate(2);
    while(ros::ok) {
        //  create and fill in the message
        geometry_msgs::Twist msg;
        msg.linear.x = double(rand())/double(RAND_MAX);
        msg.angular.z = 2 * double(rand())/double(RAND_MAX) - 1;

        // publish the message
        pub.publish(msg);

        // send a message to rosout
        ROS_INFO_STREAM("Sending random velocity: " << " linear=" << msg.linear.x
                    << " angular=" << msg.angular.z);

        // wait until its time for another iteration
        rate.sleep();
    }
}
