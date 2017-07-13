/*
// This program p u b l i s h e s randomly − generated v e l o c i t y
// messages f o r t u r t l e s i m .
#i n c l u d e <r o s / r o s . h>
#i n c l u d e <geometry_msgs / Twist . h> // For geometry_msgs : : Twist
#i n c l u d e < s t d l i b . h> // For rand () and RAND_MAX

i n t main ( i n t a r g c , c h a r ∗∗ a r g v ) {
// I n i t i a l i z e the ROS system and become a node .
r o s : : i n i t ( a r g c , argv , " p u b l i s h _ v e l o c i t y " ) ;
r o s : : NodeHandle nh ;

// Create a p u b l i s h e r o b j e c t .
r o s : : P u b l i s h e r pub = nh . a d v e r t i s e <geometry_msgs : : Twist >(
" t u r t l e 1 /cmd_vel" , 1 0 0 0 ) ;

// Seed the random number generator .
s r a n d ( time ( 0 ) ) ;

// Loop at 2Hz u n t i l the node i s shut down.
r o s : : Rate r a t e ( 2 ) ;
w h i l e ( r o s : : ok ( ) ) {
// Create and f i l l in the message . The other four
// f i e l d s , which are ignored by turtlesim , d e f a u l t to 0.
geometry_msgs : : Twist msg ;
msg . l i n e a r . x = d o u b l e ( rand ( ) ) / d o u b l e (RAND_MAX) ;
msg . a n g u l a r . z = 2∗ d o u b l e ( rand ( ) ) / d o u b l e (RAND_MAX) − 1 ;

// Publish the message .
pub . p u b l i s h ( msg ) ;
// Send a message to rosout with the d e t a i l s .
ROS_INFO_STREAM( " Sending ␣random␣ v e l o c i t y ␣command : "
<< " ␣ l i n e a r=" << msg . l i n e a r . x
<< " ␣ a n g u l a r=" << msg . a n g u l a r . z ) ;
// Wait u n t i l i t ' s time f o r another i t e r a t i o n .
rate . sleep () ;
}
}

*/
//this program publishes randomly  generated velocity
// messages for turtlesim
#include<ros/ros.h>
#include<geometry_msgs/Twist.h>
#include<stdlib.h>

int main(int argc, char **argv) {
//initialize the ros system and become a node
ros::init(argc, argv, "publish_velocity");
ros::NodeHandle nh;
//create publisher object
ros::Publisher pub =nh.advertise<geometry_msgs::Twist>( "turtle1/cmd_vel",1000);
//seed the random number generator
srand(time(0));
//loop ar 2 hz untill the node is shut down
ros::Rate rate(2);
while(ros::ok()){
	//create and fill in the messsage . the other four
	//fields, which are ignored by turtlesim, default to 0.
geometry_msgs::Twist msg;
msg.linear.x=double(rand())/double(RAND_MAX);
msg.angular.z=2*double(rand())/double(RAND_MAX)-1;
//publish the message
pub.publish(msg);
//send a message to rosout with details
ROS_INFO_STREAM("Sending␣random␣velocity␣command:"
<<"␣linear="<<msg.linear.x
<<"␣angular="<<msg.angular.x);
//wait until it s time for another iteration
rate.sleep();

}
}