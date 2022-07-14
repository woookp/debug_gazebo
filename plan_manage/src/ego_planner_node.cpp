#include <ros/ros.h>
#include <visualization_msgs/Marker.h>

#include <plan_manage/ego_replan_fsm.h>

using namespace ego_planner;

int main(int argc, char **argv)
{
  bool global_token = true;
  while(true){
//wait for pre_start process
    ros::init(argc, argv, "ego_planner_node");
    ros::NodeHandle nh("~");
    // nh.setParam("global_token",  global_token);
    ros::Rate loop_rate_listern(5);
    while(global_token){
      nh.getParam("global_token", global_token);
      loop_rate_listern.sleep();
    }
    EGOReplanFSM rebo_replan;
    rebo_replan.init(nh, global_token);
    // ros::Duration(1.0).sleep();
    ros::Rate loop_rate(60);
    while(ros::ok()){
      ros::spinOnce();
      loop_rate.sleep();
    }
    //is it necessary to destory nh?
  }
  return 0;
}

// #include <ros/ros.h>
// #include <csignal>
// #include <visualization_msgs/Marker.h>

// #include <plan_manage/ego_replan_fsm.h>

// using namespace ego_planner;

// void SignalHandler(int signal) {
//   if(ros::isInitialized() && ros::isStarted() && ros::ok() && !ros::isShuttingDown()){
//     ros::shutdown();
//   }
// }

// int main(int argc, char **argv) {

//   signal(SIGINT, SignalHandler);
//   signal(SIGTERM,SignalHandler);

//   ros::init(argc, argv, "ego_planner_node", ros::init_options::NoSigintHandler);
//   ros::NodeHandle nh("~");

//   EGOReplanFSM rebo_replan;

//   rebo_replan.init(nh);

//   // ros::Duration(1.0).sleep();
//   ros::AsyncSpinner async_spinner(4);
//   async_spinner.start();
//   ros::waitForShutdown();

//   return 0;
// }