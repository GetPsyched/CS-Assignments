# Write a shell script program to implement read, write, and execute permissions.

echo 'The name of all files having all permissions:'
# loop through all files in current directory
for file in *
    do
        # Is file?
        if [ -f $file ]
        then
            # Has read, write and execute perms?
            if [ -r $file -a -w $file -a -x $file ]
            then
                ls -l $file # Print the file
            fi
        fi
    done
