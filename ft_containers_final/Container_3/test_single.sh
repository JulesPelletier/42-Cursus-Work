#!/usr/bin/zsh
rm diff.txt
make -s fclean && make -s TESTER="1" NAMESPACE="ft"
echo "Timing for Tester 1, NAMESPACE FT"
time ./container extras 1> logft.txt
cat  logft.txt
make -s fclean && make -s TESTER="1" NAMESPACE="std"
echo "Timing for Tester 1, NAMESPACE STD"
time ./container extras 1> logstd.txt
cat  logstd.txt


echo "Printing diffs if any"
diff logft.txt logstd.txt >> diff.txt
cat diff.txt