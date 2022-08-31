#!/usr/bin/zsh
rm diff.txt
make -s fclean && make -s TESTER="1" NAMESPACE="ft"
echo "Timing for Tester 1, NAMESPACE FT"
time ./container stack 1> logft.txt
cat  logft.txt
make -s fclean && make -s TESTER="1" NAMESPACE="std"
echo "Timing for Tester 1, NAMESPACE STD"
time ./container stack 1> logstd.txt
cat  logstd.txt


echo "Printing diffs if any"
diff logft.txt logstd.txt >> diff.txt
cat diff.txt

rm diff.txt
make -s fclean && make -s TESTER="1" NAMESPACE="ft"
echo "Timing for Tester 1, NAMESPACE FT"
time ./container vector 1> logft.txt
cat  logft.txt
make -s fclean && make -s TESTER="1" NAMESPACE="std"
echo "Timing for Tester 1, NAMESPACE STD"
time ./container vector 1> logstd.txt
cat  logstd.txt


echo "Printing diffs if any"
diff logft.txt logstd.txt >> diff.txt
cat diff.txt

rm diff.txt
make -s fclean && make -s TESTER="1" NAMESPACE="ft"
echo "Timing for Tester 1, NAMESPACE FT"
time ./container map 1> logft.txt
cat  logft.txt
make -s fclean && make -s TESTER="1" NAMESPACE="std"
echo "Timing for Tester 1, NAMESPACE STD"
time ./container map 1> logstd.txt
cat  logstd.txt


echo "Printing diffs if any"
diff logft.txt logstd.txt >> diff.txt
cat diff.txt

rm diff.txt
make -s fclean && make -s TESTER="1" NAMESPACE="ft"
echo "Timing for Tester 1, NAMESPACE FT"
time ./container extra 1> logft.txt
cat  logft.txt
make -s fclean && make -s TESTER="1" NAMESPACE="std"
echo "Timing for Tester 1, NAMESPACE STD"
time ./container extra 1> logstd.txt
cat  logstd.txt


echo "Printing diffs if any"
diff logft.txt logstd.txt >> diff.txt
cat diff.txt

rm diff.txt
make -s fclean && make -s TESTER="1" NAMESPACE="ft"
echo "Timing for Tester 1, NAMESPACE FT"
time ./container pelim 1> logft.txt
cat  logft.txt
make -s fclean && make -s TESTER="1" NAMESPACE="std"
echo "Timing for Tester 1, NAMESPACE STD"
time ./container pelim 1> logstd.txt
cat  logstd.txt


echo "Printing diffs if any"
diff logft.txt logstd.txt >> diff.txt
cat diff.txt