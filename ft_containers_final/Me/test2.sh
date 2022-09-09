#!/usr/bin/zsh
make -s fclean && make -s TESTER="1" NAMESPACE="ft"
echo "Timing for Tester 1, NAMESPACE FT"
time ./container map 2> logft.txt
make -s fclean && make -s TESTER="1" NAMESPACE="std"
echo "Timing for Tester 1, NAMESPACE STD"
time ./container map 2> logstd.txt

diff logft.txt logstd.txt > file
cat file