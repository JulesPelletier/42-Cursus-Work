
rm diff.txt

make -s fclean && make -s TESTER="1" NAMESPACE="ft"
echo "Timing for Tester 1, NAMESPACE FT"
time ./container 1> logft.txt
make -s fclean && make -s TESTER="1" NAMESPACE="std"
echo "Timing for Tester 1, NAMESPACE STD"
time ./container 1> logstd.txt

diff logft.txt logstd.txt >> diff.txt
rm logft.txt logstd.txt
cat diff.txt