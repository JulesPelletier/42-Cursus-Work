#! /bin/bash

S1="================================================================================"
S2="--------------------------------------------------------------------------------"
GREEN="\033[38;2;57;181;74m"
RED="\033[38;2;222;56;43m"
BLUE="\033[38;2;34;183;235m"
YELLOW="\033[38;2;255;176;0m"
PURPLE="\033[38;2;255;105;180m"
RESET="\033[0m"

comp()
{
	printf "\n\n"
	diff -s out1 res1; 
	if [[ $? == 0 ]] ; then
  		printf "$GREEN"" OK\n$RESET"
	else
  		printf "$RED"" KO\n$RESET"
	fi
}

printf "$YELLOW$S1\n\n"
echo "██████  ██ ██████  ███████ ██   ██     ████████ ███████ ███████ ████████ ███████ ██████  "
echo "██   ██ ██ ██   ██ ██       ██ ██         ██    ██      ██         ██    ██      ██   ██ "
echo "██████  ██ ██████  █████     ███          ██    █████   ███████    ██    █████   ██████  "
echo "██      ██ ██      ██       ██ ██         ██    ██           ██    ██    ██      ██   ██ "
echo "██      ██ ██      ███████ ██   ██        ██    ███████ ███████    ██    ███████ ██   ██ "
printf "\n$S1$RESET\n"
printf "$BLUE"; make -C ../ all; printf "$RESET"

printf "$YELLOW$S1$RESET\n"
printf "$PURPLE""test 1.1 : < infile grep hello | wc -l > outfile$RESET\n"
printf "$PURPLE$S2$RESET\n"
< test1 grep hello | wc -l > out1 2> out1
../pipex test1 "grep hello" "wc -l" res1 2> res1
printf "$BLUE""Input\n""$RESET"
cat test1
printf "\n"
printf "$BLUE""\nMy Res : \n""$RESET"
cat res1
printf "$PURPLE""\nTest Res : \n""$RESET"
cat out1
comp out1 res1
rm out1 res1

printf "$YELLOW$S1$RESET\n"
printf "$PURPLE""test 1.2 : < infile grep he | wc -l > outfile$RESET\n"
printf "$PURPLE$S2$RESET\n"
< test1 grep he | wc -l > out1 2> out1
../pipex test1 "grep he" "wc -l" res1 2> res1
printf "$BLUE""My Input\n""$RESET"
cat test1
printf "\n"
printf "$BLUE""\nMy Res : \n""$RESET"
cat res1
printf "$PURPLE""\nTest Res : \n""$RESET"
cat out1
comp out1 res1
rm out1 res1

printf "$YELLOW$S1$RESET\n"
printf "$PURPLE""test 1.3 : < infile grep hel | wc -l > outfile$RESET\n"
printf "$PURPLE$S2$RESET\n"
< test1 grep hel | wc -l > out1 2> out1
../pipex test1 "grep hel" "wc -l" res1 2> res1
printf "$BLUE""My Input\n""$RESET"
cat test1
printf "\n"
printf "$BLUE""\nMy Res : \n""$RESET"
cat res1
printf "$PURPLE""\nTest Res : \n""$RESET"
cat out1
comp out1 res1
rm out1 res1

printf "$YELLOW$S1$RESET\n"
printf "$PURPLE""test 1.4 : < infile grep heworld | wc -l > outfile$RESET\n"
printf "$PURPLE$S2$RESET\n"
< test1 grep heworld | wc -l > out1 2> out1
../pipex test1 "grep heworld" "wc -l" res1 2> res1
printf "$BLUE""My Input\n""$RESET"
cat test1
printf "\n"
printf "$BLUE""\nMy Res : \n""$RESET"
cat res1
printf "$PURPLE""\nTest Res : \n""$RESET"
cat out1
comp out1 res1
rm out1 res1

printf "$YELLOW$S1$RESET\n" 
printf "$PURPLE""test 2.1 : < infile grep J | tr -d '_' > outfile$RESET\n"
printf "$PURPLE$S2$RESET\n"
< test2 grep J | tr -d '_' > out1 2> out1
../pipex "test2" "grep J" "tr -d '_'" res1 2> res1
printf "$BLUE""My Input\n""$RESET"
cat test2
printf "\n"
printf "$BLUE""\nMy Res : \n""$RESET"
cat res1
printf "$PURPLE""\nTest Res : \n""$RESET"
cat out1
comp out1 res1
rm out1 res1

printf "$YELLOW$S1$RESET\n" 
printf "$PURPLE""test 2.2 : < infile tail -1 | tr -d '_' > outfile$RESET\n"
printf "$PURPLE$S2$RESET\n"
< test2 tail -1 | tr -d '_' > out1 2> out1
../pipex "test2" "tail -1" "tr -d '_'" res1 2> res1
printf "$BLUE""My Input\n""$RESET"
cat test2
printf "\n"
printf "$BLUE""\nMy Res : \n""$RESET"
cat res1
printf "$PURPLE""\nTest Res : \n""$RESET"
cat out1
printf "\n"
comp out1 res1
rm out1 res1

printf "$YELLOW$S1$RESET\n" 
printf "$PURPLE""test Ultime 1 : < infile head -2 | tr -d ':;_' > outfile$RESET\n"
printf "$PURPLE$S2$RESET\n"
< test3 head -2 | tr -d ':;_' > out1 2> out1
../pipex "test3" "head -2" "tr -d ':;_'" res1 2> res1
printf "$BLUE""My Input\n""$RESET"
cat test3
printf "\n"
printf "$BLUE""\nMy Res : \n""$RESET"
cat res1
printf "$PURPLE""\nTest Res : \n""$RESET"
cat out1
comp out1 res1
rm out1 res1

printf "$YELLOW$S1$RESET\n" 
printf "$PURPLE""test Ultime 2 : < infile grep V | tr -d '_' > outfile$RESET\n"
printf "$PURPLE$S2$RESET\n"
< test3 grep V | tr -d '_' > out1 2> out1
../pipex "test3" "grep V" "tr -d '_'" res1 2> res1
printf "$BLUE""My Input\n""$RESET"
cat test3
printf "\n"
printf "$BLUE""\nMy Res : \n""$RESET"
cat res1
printf "$PURPLE""\nTest Res : \n""$RESET"
cat out1
comp out1 res1
rm out1 res1

printf "$YELLOW$S1$RESET\n" 
printf "$PURPLE""test Ultime 3.1 : < infile grep V | tr -d '_:' > outfile$RESET\n"
printf "$PURPLE$S2$RESET\n"
< test3 grep V | tr -d '_:' > out1 2> out1
../pipex "test3" "grep V" "tr -d '_:'" res1 2> res1
printf "$BLUE""My Input\n""$RESET"
cat test3
printf "\n"
printf "$BLUE""\nMy Res : \n""$RESET"
cat res1
printf "$PURPLE""\nTest Res : \n""$RESET"
cat out1
comp out1 res1
rm out1 res1

printf "$YELLOW$S1$RESET\n" 
printf "$PURPLE""test Ultime 3.2 : < infile grep V | cut -c 4-10 > outfile$RESET\n"
printf "$PURPLE$S2$RESET\n"
< test3 grep V | cut -c 4-10 > out1 2> out1
../pipex "test3" "grep V" "cut -c 4-10" res1 2> res1
printf "$BLUE""My Input\n""$RESET"
cat test3
printf "\n"
printf "$BLUE""\nMy Res : \n""$RESET"
cat res1
printf "$PURPLE""\nTest Res : \n""$RESET"
cat out1
comp out1 res1
rm out1 res1

printf "$YELLOW$S1$RESET\n" 
printf "$PURPLE""test Ultime 4.1 : < infile grep T | tr -d '_' > outfile$RESET\n"
printf "$PURPLE$S2$RESET\n"
< test3 grep T | tr -d '_' > out1 2> out1
../pipex "test3" "grep T" "tr -d '_'" res1 2> res1
printf "$BLUE""My Input\n""$RESET"
cat test3
printf "\n"
printf "$BLUE""\nMy Res : \n""$RESET"
cat res1
printf "$PURPLE""\nTest Res : \n""$RESET"
cat out1
comp out1 res1
rm out1 res1

printf "$YELLOW$S1$RESET\n" 
printf "$PURPLE""test Ultime 4.2 : < infile grep T | tr -d '-:' > outfile$RESET\n"
printf "$PURPLE$S2$RESET\n"
< test3 grep T | tr -d ':' > out1 2> out1
../pipex "test3" "grep T" "tr -d ':'" res1 2> res1
printf "$BLUE""My Input\n""$RESET"
cat test3
printf "\n"
printf "$BLUE""\nMy Res : \n""$RESET"
cat res1
printf "$PURPLE""\nTest Res : \n""$RESET"
cat out1
comp out1 res1
rm out1 res1

printf "$YELLOW$S1$RESET\n" 
printf "$PURPLE""test Ultime 4.3 : < infile grep T | tr -d ')' > outfile$RESET\n"
printf "$PURPLE$S2$RESET\n"
< test3 grep T | tr -d ')' > out1 2> out1
../pipex "test3" "grep T" "tr -d ')'" res1 2> res1
printf "$BLUE""My Input\n""$RESET"
cat test3
printf "\n"
printf "$BLUE""\nMy Res : \n""$RESET"
cat res1
printf "$PURPLE""\nTest Res : \n""$RESET"
cat out1
comp out1 res1
rm out1 res1

printf "$YELLOW$S1$RESET\n" 
printf "$PURPLE""test Ultime 4.4 : < infile grep T | tr -d '_)-:' > outfile$RESET\n"
printf "$PURPLE$S2$RESET\n"
< test3 grep T | tr -d '_)-:' > out1 2> out1
../pipex "test3" "grep T" "tr -d '_)-:'" res1 2> res1
printf "$BLUE""My Input\n""$RESET"
cat test3
printf "\n"
printf "$BLUE""\nMy Res : \n""$RESET"
cat res1
printf "$PURPLE""\nTest Res : \n""$RESET"
cat out1
comp out1 res1
rm out1 res1

printf "$YELLOW$S1$RESET\n" 
printf "$PURPLE""test Ultime 5.1 : < infile cat | cat  > outfile$RESET\n"
printf "$PURPLE$S2$RESET\n"
< test4 cat | cat  > out1 2> out1
../pipex "test4" "cat" "cat" res1 2> res1
printf "$BLUE""My Input\n""$RESET"
cat test4
printf "\n"
printf "$BLUE""\nMy Res : \n""$RESET"
cat res1
printf "$PURPLE""\nTest Res : \n""$RESET"
cat out1
comp out1 res1
rm out1 res1

printf "$YELLOW$S1$RESET\n" 
printf "$PURPLE""test Ultime 5.2 : < infile cat | head  > outfile$RESET\n"
printf "$PURPLE$S2$RESET\n"
< test4 cat | head  > out1 2> out1
../pipex "test4" "cat" "head" res1 2> res1
printf "$BLUE""My Input\n""$RESET"
cat test4
printf "\n"
printf "$BLUE""\nMy Res : \n""$RESET"
cat res1
printf "$PURPLE""\nTest Res : \n""$RESET"
cat out1
comp out1 res1
rm out1 res1

printf "$YELLOW$S1$RESET\n" 
printf "$PURPLE""test Ultime 5.3 : < infile cat | tail -5  > outfile$RESET\n"
printf "$PURPLE$S2$RESET\n"
< test4 cat | tail -5  > out1 2> out1
../pipex "test4" "cat" "tail -5" res1 2> res1
printf "$BLUE""Input\n""$RESET"
cat test4
printf "\n"
printf "$BLUE""\nMy Res : \n""$RESET"
cat res1
printf "$PURPLE""\nTest Res : \n""$RESET"
cat out1
comp out1 res1
rm out1 res1

printf "$YELLOW$S1$RESET\n" 
printf "$PURPLE""Test Error 1 (command error) : < infile notexisting | tail -5  > outfile$RESET\n"
printf "$PURPLE$S2$RESET\n"
< test4 notexisting | tail -5  > out1 2> out1
../pipex "test4" "notexisting" "tail -5" res1 2> res1
printf "$BLUE""Input\n""$RESET"
cat test4
printf "\n"
printf "$BLUE""\nMy Res : \n""$RESET"
cat res1
rm out1 res1

printf "$YELLOW$S1$RESET\n" 
printf "$PURPLE""Test Error 2 (file error) : < notexistign cat | cat  > outfile$RESET\n"
printf "$PURPLE$S2$RESET\n"
< notexisting cat | cat  > out1 2> out1
../pipex "notexisting" "cat" "cat" res1 2> res1
printf "$BLUE""Input\n""$RESET"
cat test4
printf "\n"
printf "$BLUE""\nMy Res : \n""$RESET"
cat res1
rm out1 res1

printf "$YELLOW$S1$RESET\n" 
printf "$PURPLE""Test Error 3 (not enough arguments) : < test1 cat | > outfile$RESET\n"
printf "$PURPLE$S2$RESET\n"
< test1 cat | > out1 2> out1
../pipex "test1" "cat" 2> res1
printf "$BLUE""Input\n""$RESET"
cat test4
printf "\n"
printf "$BLUE""\nMy Res : \n""$RESET"
cat res1
rm out1 res1

printf "$YELLOW$S1$RESET\n" 
printf "$PURPLE""Test Error 4 (command error) : < infile cat | notexisting  > outfile$RESET\n"
printf "$PURPLE$S2$RESET\n"
< test4 ls | notexisting  > out1 2> out1
../pipex "test4" "ls" "notexisting" res1 2> res1
printf "$BLUE""Input\n""$RESET"
cat test4
printf "\n"
printf "$BLUE""\nMy Res : \n""$RESET"
cat res1
rm out1 res1