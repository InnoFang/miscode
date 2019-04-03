#!/bin/bash
echo "Hello World !"
a = 3
b = 5
val = 'expr $a + $b'
echo "Total value : $val"

val = 'expr $a - $b'
echo "Total value : $val"

val = 'expr $a \* $b'
echo "Total value : $val"

val = 'expr $a / $b'
echo "Total value : $val"

if [ $a == $b ]
then 
    echo "a is equal to b"
fi
if [ $a != $b ]
then
    echo "a is not equal to b"
fi

counter = 0
while [ $counter -lt 100000 ]
do 
    counter = 'expr $counter + 1'
    echo
done