#!/bin/bash

echo "create screen, then run simulation"
# parameters: run, load, scheme, gap for flowlet, network scale, coreosp, and torosp
for run in 4 5 6
do 
  for load in 0.6 
  do
    for scheme in 0 1 2 3   
    do 
      for gap in 0.0001
      do
        for k in 12
        do
          for coreosp in 2
          do
            for torosp in 1
            do
          	    sleep 2
                screen -d -m -S FVL2$run$load$scheme$gap$k$coreosp$torosp /proj/expeditus/ns-allinone-3.10/ns-3.10/scratch/FVL2.sh $run $load $scheme $gap $k $coreosp $torosp
            done
          done
        done
      done
    done
  done
done
