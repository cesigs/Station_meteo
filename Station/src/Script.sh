#!/bin/sh

make fclean
echo "Compiling and creating exe file."
make
echo "Executing exe file."
./Exec
exit