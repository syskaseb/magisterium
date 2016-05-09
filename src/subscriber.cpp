#include <ros/ros.h>
#include <geometry_msgs/Twist.h>

// a callback function
void poseMessageReceived(const geometry_msgs::Twist &msg) {
    ROS_INFO_STREAM(std::setprecision(2) << std::fixed <<
                    "x=(" << msg.linear.x << ")" << " direction=" << msg.angular.z);
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "subscribe_to_pose");
    ros::NodeHandle nh;

    // create a subscriber object
    ros::Subscriber sub = nh.subscribe("chatter", 1000, &poseMessageReceived);

    // let ROS take over
    ros::spin();
}
