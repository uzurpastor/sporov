#! /bin/bash 
set -v
      trap 'justonce' 2
      justonce() {
        echo "not yet"
        trap 2           # now reset it
        }

     while true; do
        echo -n "."
        sleep 1
     done