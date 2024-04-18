# Write a shell script to change the priority of processes.

# -p changes the priority for the given pid
renice -n 5 -p $pid

# -u changes the priority of all the processes owned by the given user
renice -n 5 -u $user

# --pgrp changes the priority of all the processes belonging to the given process group
renice -n 5 -pgrp $process_group
