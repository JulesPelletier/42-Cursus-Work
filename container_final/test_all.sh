#!/usr/bin/zsh

rm diff.txt

make -s fclean && make -s TESTER="1" NAMESPACE="ft"
echo "Timing for Tester Vector, NAMESPACE FT"
time ./container vector >> logft.txt
make -s fclean && make -s TESTER="1" NAMESPACE="std"
echo "Timing for Tester Vector, NAMESPACE STD"
time ./container vector >> logstd.txt

diff logft.txt logstd.txt >> diff.txt
rm logft.txt logstd.txt

make -s fclean && make -s TESTER="2" NAMESPACE="ft"
echo "Timing for Tester Stack, NAMESPACE FT"
time ./container stack >> logft.txt
make -s fclean && make -s TESTER="2" NAMESPACE="std"
echo "Timing for Tester Stack, NAMESPACE STD"
time ./container stack >> logstd.txt

diff logft.txt logstd.txt >> diff.txt
rm logft.txt logstd.txt


make -s fclean && make -s TESTER="3" NAMESPACE="ft"
echo "Timing for Tester Map, NAMESPACE FT"
time ./container map >> logft.txt
make -s fclean && make -s TESTER="3" NAMESPACE="std"
echo "Timing for Tester Map, NAMESPACE STD"
time ./container map >> logstd.txt

diff logft.txt logstd.txt >> diff.txt
rm logft.txt logstd.txt

make -s fclean && make -s TESTER="4" NAMESPACE="ft"
echo "Timing for Tester Extras, NAMESPACE FT"
time ./container extras >> logft.txt
make -s fclean && make -s TESTER="4" NAMESPACE="std"
echo "Timing for Tester Extras, NAMESPACE STD"
time ./container extras >> logstd.txt

diff logft.txt logstd.txt >> diff.txt
rm logft.txt logstd.txt
cat diff.txt