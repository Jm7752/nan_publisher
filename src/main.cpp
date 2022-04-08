#include <ros/ros.h>
#include <Eigen/Geometry>
#include <nav_msgs/Path.h>
#include <geometry_msgs/Point.h>
#include <geometry_msgs/Vector3.h>
#include <nav_msgs/Odometry.h>
#include <quadrotor_msgs/SO3Command.h>
#include <memory>

int main(int argc, char **argv)
{
	std::string vehicle="quadrotor";

    ros::init(argc,argv,"NAN_publisher");
    ros::NodeHandle n("~");
	n.getParam("/vehicle", vehicle);
	ros::Publisher so3_command_pub_ = n.advertise<quadrotor_msgs::SO3Command>(vehicle+"/so3_cmd", 10);
	while(ros::ok()) {
		ros::spinOnce();
		quadrotor_msgs::SO3Command::Ptr so3_command =
		boost::make_shared<quadrotor_msgs::SO3Command>();
		  so3_command->header.stamp = ros::Time::now();
		  so3_command->header.frame_id = "world";
		  so3_command->force.x = std::nan(""); //NAN
		  so3_command->force.y = std::nan("");
		  so3_command->force.z =  std::nan("");
		  so3_command->orientation.x = 0;
		  so3_command->orientation.y = 0;
		  so3_command->orientation.z = 0;
		  so3_command->orientation.w =1;
		  so3_command->angular_velocity.x = 0;
		  so3_command->angular_velocity.y =0;
		  so3_command->angular_velocity.z = 0;
		so3_command_pub_.publish(so3_command);

	}
    return 0;
}
