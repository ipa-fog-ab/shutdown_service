#include "ros/ros.h"
#include "shutdown_service/shutdown.h"
#include <stdio.h>
#include <stdlib.h>


bool shutdown_function(shutdown_service::shutdown::Request  &req, shutdown_service::shutdown::Response &res)
  {
    system("shutdown -P now"); 
    return true;
  }

int main(int argc, char **argv)
  {
    ros::init(argc, argv, "server");
    ros::NodeHandle n;
    ros::ServiceServer service = n.advertiseService("shutdown", shutdown_function);
    ros::spin();

    return 0;

  }
