#include "ros/ros.h"
#include "shutdown_service/shutdown.h"
#include <cstdlib>

int main(int argc, char **argv)
  {
    ros::init(argc, argv, "client");
    ros::NodeHandle n;
    ros::ServiceClient client = n.serviceClient<shutdown_service::shutdown>("shutdown");
    shutdown_service::shutdown srv;
    client.call(srv);
    
    return 0;
  }
