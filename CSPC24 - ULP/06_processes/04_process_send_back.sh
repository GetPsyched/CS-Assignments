# Write a shell script to send back a process from foreground.

# Run a command externally and feed its pid into this script

# Storing the pid of the above command
pid=$1

# Emulating Ctrl-Z
kill -TSTP $pid

echo "Process paused!"

# Emulating bg command
kill -CONT $pid

echo "Process sent to background!"
