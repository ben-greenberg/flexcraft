//char RFF=1
//char RFS=2
//char RRS=4
//char RRR=8
//char LRR=16
//char LRS=32
//char LFS=64
//char LFF=128

#include <ros.h>
#include <std_msgs/UInt8.h>
#include <flexcraft_msgs/thrusters8.h>

ros::NodeHandle  nh;

void messageCb(const flexcraft_msgs::thrusters8& msg)
{ unsigned char thruster_control = msg.thrusters;

  if (thruster_control % 2)
    digitalWrite(6, HIGH);
  if ((thruster_control >> 1) % 2)
    digitalWrite(7, HIGH);
  if ((thruster_control >> 2) % 2)
    digitalWrite(8, HIGH);
  if ((thruster_control >> 3) % 2)
    digitalWrite(9, HIGH);
  if ((thruster_control >> 4) % 2)
    digitalWrite(10, HIGH);
  if ((thruster_control >> 5) % 2)
    digitalWrite(11, HIGH);
  if ((thruster_control >> 6) % 2)
    digitalWrite(12, HIGH);
  if ((thruster_control >> 7) % 2)
    digitalWrite(13, HIGH);

  //OFF
  delay(2000);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
 digitalWrite(13, LOW);
  delay(500);
}

ros::Subscriber<flexcraft_msgs::thrusters8> sub("thruster_one", &messageCb );

void setup()
{ pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  nh.initNode();
  nh.subscribe(sub);
}

void loop()
{
  nh.spinOnce();
  delay(1000);
}
