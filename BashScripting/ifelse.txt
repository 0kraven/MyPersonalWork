#!/bin/bash

if [ condition ]; then
    # Code to be executed if condition is true
else
    # Code to be executed if condition is false
fi




if [ "$name" == "Alice" ]; then
    echo "Hello, Alice!"
else
    echo "Hello, stranger!"
fi



if [ "$name" == "Alice" ]; then
    echo "Hello, Alice!"
elif [ "$name" == "Bob" ]; then
    echo "Hello, Bob!"
else
    echo "Hello, stranger!"
fi
