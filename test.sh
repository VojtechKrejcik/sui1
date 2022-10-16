#!/bin/bash
make
if [ $? -eq 0 ]; then
   echo -e "\033[0;32m MAKE OK \033[0;33m"
   clear
else
   echo -e "\033[0;31m MAKE FAIL! \033[0;33m"
fi
echo -e "\033[0m IS IT OK?:"
echo -e "====================================================================================="
echo -n "A*n: "
./fc-sui --easy-mode 30 --solver a_star --heuristic nb_not_home 5 3
if [ $? -eq 0 ]; then
   echo -e "\033[0;32m OK \033[0m"
else
   echo -e "\033[0;31m FAIL \033[0m"
fi
echo -n "A*s: "
./fc-sui --easy-mode 60 --solver a_star --heuristic student 5 4
if [ $? -eq 0 ]; then
   echo -e "\033[0;32m OK \033[0m"
else
   echo -e "\033[0;31m FAIL \033[0m"
fi
echo -e "====================================================================================="


COUNTER1=0
echo -e "\033[0;33m Batch 1"
./fc-sui 1 1 --solver a_star --heuristic student  --easy-mode 140 
if [ $? -eq 0 ]; then
   echo -e "\033[0;32m OK \033[0;33m"
   let COUNTER1++
else
   echo -e "\033[0;31m FAIL \033[0;33m"
fi
./fc-sui 1 2 --solver a_star --heuristic student  --easy-mode 140
if [ $? -eq 0 ]; then
   echo -e "\033[0;32m OK \033[0;33m"
   let COUNTER1++
else
   echo -e "\033[0;31m FAIL \033[0;33m"
fi
./fc-sui 1 3 --solver a_star --heuristic student  --easy-mode 140
if [ $? -eq 0 ]; then
   echo -e "\033[0;32m OK \033[0;33m"
   let COUNTER1++
else
   echo -e "\033[0;31m FAIL \033[0;33m"
fi
./fc-sui 1 4 --solver a_star --heuristic student  --easy-mode 140
if [ $? -eq 0 ]; then
   echo -e "\033[0;32m OK \033[0;33m"
   let COUNTER1++
else
   echo -e "\033[0;31m FAIL \033[0;33m"
fi
./fc-sui 1 5 --solver a_star --heuristic student  --easy-mode 140
if [ $? -eq 0 ]; then
   echo -e "\033[0;32m OK \033[0;33m"
   let COUNTER1++
else
   echo -e "\033[0;31m FAIL \033[0;33m"
fi
./fc-sui 1 6 --solver a_star --heuristic student  --easy-mode 140
if [ $? -eq 0 ]; then
   echo -e "\033[0;32m OK \033[0;33m"
   let COUNTER1++
else
   echo -e "\033[0;31m FAIL \033[0;33m"
fi
./fc-sui 1 7 --solver a_star --heuristic student  --easy-mode 140
if [ $? -eq 0 ]; then
   echo -e "\033[0;32m OK \033[0;33m"
   let COUNTER1++
else
   echo -e "\033[0;31m FAIL \033[0;33m"
fi
./fc-sui 1 8 --solver a_star --heuristic student  --easy-mode 140
if [ $? -eq 0 ]; then
   echo -e "\033[0;32m OK \033[0;33m"
   let COUNTER1++
else
   echo -e "\033[0;31m FAIL \033[0;33m"
fi
./fc-sui 1 9 --solver a_star --heuristic student  --easy-mode 140
if [ $? -eq 0 ]; then
   echo -e "\033[0;32m OK \033[0;33m"
   let COUNTER1++
else
   echo -e "\033[0;31m FAIL \033[0;33m"
fi
./fc-sui 1 10 --solver a_star --heuristic student  --easy-mode 140
if [ $? -eq 0 ]; then
   echo -e "\033[0;32m OK \033[0;33m"
   let COUNTER1++
else
   echo -e "\033[0;31m FAIL \033[0;33m"
fi

echo -e "\033[0;32m $COUNTER1 Passed \033[0;35m"

echo -e "\033[0m====================================================================================="
COUNTER2=0
echo -e "\033[0;35m Batch 2"
./fc-sui 1 10 --solver a_star --heuristic student  --easy-mode 140
if [ $? -eq 0 ]; then
   echo -e "\033[0;32m OK \033[0;35m"
   let COUNTER2++
else
   echo -e "\033[0;31m FAIL \033[0;35m"
fi
./fc-sui 1 20 --solver a_star --heuristic student  --easy-mode 140
if [ $? -eq 0 ]; then
   echo -e "\033[0;32m OK \033[0;35m"
   let COUNTER2++
else
   echo -e "\033[0;31m FAIL \033[0;35m"
fi
./fc-sui 1 30 --solver a_star --heuristic student  --easy-mode 140
if [ $? -eq 0 ]; then
   echo -e "\033[0;32m OK \033[0;35m"
   let COUNTER2++
else
   echo -e "\033[0;31m FAIL \033[0;35m"
fi
./fc-sui 1 40 --solver a_star --heuristic student  --easy-mode 140
if [ $? -eq 0 ]; then
   echo -e "\033[0;32m OK \033[0;35m"
   let COUNTER2++
else
   echo -e "\033[0;31m FAIL \033[0;35m"
fi
./fc-sui 1 50 --solver a_star --heuristic student  --easy-mode 140
if [ $? -eq 0 ]; then
   echo -e "\033[0;32m OK \033[0;35m"
   let COUNTER2++
else
   echo -e "\033[0;31m FAIL \033[0;35m"
fi
./fc-sui 1 60 --solver a_star --heuristic student  --easy-mode 140
if [ $? -eq 0 ]; then
   echo -e "\033[0;32m OK \033[0;35m"
   let COUNTER2++
else
   echo -e "\033[0;31m FAIL \033[0;35m"
fi
./fc-sui 1 70 --solver a_star --heuristic student  --easy-mode 140
if [ $? -eq 0 ]; then
   echo -e "\033[0;32m OK \033[0;35m"
   let COUNTER2++
else
   echo -e "\033[0;31m FAIL \033[0;35m"
fi
./fc-sui 1 80 --solver a_star --heuristic student  --easy-mode 140
if [ $? -eq 0 ]; then
   echo -e "\033[0;32m OK \033[0;35m"
   let COUNTER2++
else
   echo -e "\033[0;31m FAIL \033[0;35m"
fi
./fc-sui 1 90 --solver a_star --heuristic student  --easy-mode 140
if [ $? -eq 0 ]; then
   echo -e "\033[0;32m OK \033[0;35m"
   let COUNTER2++
else
   echo -e "\033[0;31m FAIL \033[0;35m"
fi
./fc-sui 1 100 --solver a_star --heuristic student --easy-mode 140
if [ $? -eq 0 ]; then
   echo -e "\033[0;32m OK \033[0;35m"
   let COUNTER2++
else
   echo -e "\033[0;31m FAIL \033[0;35m"
fi
echo -e "\033[0;32m $COUNTER2 Passed \033[0;35m"


COUNTER3=0
echo -e "\033[0m====================================================================================="
echo -e "\033[0;34m Batch 3"
./fc-sui 1 11 --solver a_star --heuristic student  --easy-mode 140
if [ $? -eq 0 ]; then
   echo -e "\033[0;32m OK \033[0;34m"
   let COUNTER3++
else
   echo -e "\033[0;31m FAIL \033[0;34m"
fi
./fc-sui 1 12 --solver a_star --heuristic student  --easy-mode 140
if [ $? -eq 0 ]; then
   echo -e "\033[0;32m OK \033[0;34m"
   let COUNTER3++
else
   echo -e "\033[0;31m FAIL \033[0;34m"
fi
./fc-sui 1 13 --solver a_star --heuristic student  --easy-mode 140
if [ $? -eq 0 ]; then
   echo -e "\033[0;32m OK \033[0;34m"
   let COUNTER3++
else
   echo -e "\033[0;31m FAIL \033[0;34m"
fi
./fc-sui 1 14 --solver a_star --heuristic student  --easy-mode 140
if [ $? -eq 0 ]; then
   echo -e "\033[0;32m OK \033[0;34m"
   let COUNTER3++
else
   echo -e "\033[0;31m FAIL \033[0;34m"
fi
./fc-sui 1 15 --solver a_star --heuristic student  --easy-mode 140
if [ $? -eq 0 ]; then
   echo -e "\033[0;32m OK \033[0;34m"
   let COUNTER3++
else
   echo -e "\033[0;31m FAIL \033[0;34m"
fi
./fc-sui 1 16 --solver a_star --heuristic student  --easy-mode 140
if [ $? -eq 0 ]; then
   echo -e "\033[0;32m OK \033[0;34m"
   let COUNTER3++
else
   echo -e "\033[0;31m FAIL \033[0;34m"
fi
./fc-sui 1 17 --solver a_star --heuristic student  --easy-mode 140
if [ $? -eq 0 ]; then
   echo -e "\033[0;32m OK \033[0;34m"
   let COUNTER3++
else
   echo -e "\033[0;31m FAIL \033[0;34m"
fi
./fc-sui 1 18 --solver a_star --heuristic student  --easy-mode 140
if [ $? -eq 0 ]; then
   echo -e "\033[0;32m OK \033[0;34m"
   let COUNTER3++
else
   echo -e "\033[0;31m FAIL \033[0;34m"
fi
./fc-sui 1 19 --solver a_star --heuristic student  --easy-mode 140
if [ $? -eq 0 ]; then
   echo -e "\033[0;32m OK \033[0;34m"
   let COUNTER3++
else
   echo -e "\033[0;31m FAIL \033[0;34m"
fi
./fc-sui 1 21 --solver a_star --heuristic student --easy-mode 140
if [ $? -eq 0 ]; then
   echo -e "\033[0;32m OK \033[0;34m"
   let COUNTER3++
else
   echo -e "\033[0;31m FAIL \033[0;34m"
fi
echo -e "\033[0;32m $COUNTER Passed \033[0;35m"

echo -e "\033[0m"

echo -e "====================================================================================="
echo -e "\033[0;33m Batch 1 $COUNTER1 Passed \033[0m"
echo -e "\033[0;35m Batch 2 $COUNTER2 Passed \033[0m"
echo -e "\033[0;34m Batch 3 $COUNTER3 Passed \033[0m"
echo -e "====================================================================================="