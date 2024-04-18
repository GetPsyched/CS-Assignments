# Write a shell script program to explore the options of the grep command

#!/bin/bash
grep -G {\$\w+} sample.html
# grep -v -c -i -E -R -n -f