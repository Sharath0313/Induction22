# Induction22
Husky example for Induction 22.

## Installation of Husky
Use the below command to install the simulation package
```
sudo apt-get install ros-noetic-husky-simulator
```

## Setup the environmental variable HUSKY_GAZEBO_DESCRIPTION
```
export HUSKY_GAZEBO_DESCRIPTION=$(rospack find husky_gazebo)/urdf/description.gazebo.xacro
```
`Note:` You need to setup this environmental if you use this again in new terminal.

## Run the simulation
```
roslaunch husky_gazebo husky_playpen.launch
```