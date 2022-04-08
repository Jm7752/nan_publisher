# Running NAN publisher
The general idea of this is to publish NAN to ARPL quadrotor control if you don't know what that is you shouldnt be using this.

1. change the launch file sim.launch to /"VEHICLE NAME"
2. Motors On command
3. roslaunch nan_publisher sim.launch
4. This will flood the So3 command with NANS
