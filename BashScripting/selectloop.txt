#!/bin/bash

PS3="Select a fruit: "
select fruit in apple banana cherry; do
    echo "You selected: $fruit"
    break
done
