/*S!
1
2
// This i s a ROS version of the standard " h e l l o , world"
// program .
3
4
5
// This header defines the standard ROS c l a s s e s .
#i n c l u d e <r o s / r o s . h>
6
i n t main ( i n t a r g c , c h a r ∗∗ a r g v ) {
// I n i t i a l i z e the ROS system .
r o s : : i n i t ( a r g c , argv , " h e l l o _ r o s " ) ;
7
8
9
10
// E s t a b l i s h t h i s program as a ROS node .
r o s : : NodeHandle nh ;
11
12
13
// Send some output as a l o g message .
ROS_INFO_STREAM( " H e l l o , ␣ROS ! " ) ;
*/
//this is a ros version of the standard "hello, world" program


//this header defines the standard ros classes
#include <ros/ros.h>
int main(int argc, char **argv) {
	//initialize the ros system
	ros::init(argc, argv, "hello_ros");

	//establish this program as a ros node
	ros::NodeHandle nh;

	//send some output as a log message
	ROS_INFO_STREAM("Hello, Ros:");
      
}

