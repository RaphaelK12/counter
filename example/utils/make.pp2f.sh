#!/bin/bash

pwd


mkdir out
g++ ../../src/counter/counter.body.hpp  -o ./out/counter.pp2f0.hpp -E
sed '/^#/ d'                    < ./out/counter.pp2f0.hpp > ./out/counter.pp2f1.hpp
astyle --options=./astyle.conf  < ./out/counter.pp2f1.hpp > ./out/counter.pp2f2.hpp
cat -s                          < ./out/counter.pp2f2.hpp > ./out/counter.pp2f3.hpp

rm  ./out/counter.pp2f4.hpp
cat                             < ../../src/counter/copyright.hpp     > ./out/counter.pp2f4.hpp
cat                             < ./out/counter.pp2f3.hpp            >> ./out/counter.pp2f4.hpp