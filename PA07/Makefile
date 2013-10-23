GCC = gcc
CFLAGS = -g -Wall -Wshadow
LIBS = -lm
OBJ = obj
TESTN := $(shell seq 1 5)
#---------------------------------
pa07 : answer07.o pa07.o
	$(GCC) $(CFLAGS) answer07.o pa07.o -o pa07

pa07.o : pa07.c pa07.h
	$(GCC) $(CFLAGS) -c pa07.c

answer07.o : answer07.c pa07.h
	$(GCC) $(CFLAGS) -c answer07.c

clean:
	rm -rf pa07

TESTS := $(addprefix test,${TESTN})

test00 : pa07
	./pa07 inputs/input0_A inputs/input0_B 
	valgrind --tool=memcheck --leak-check=full --verbose --show-reachable=yes --log-file=outputs/memoutput0 ./pa07 inputs/input0_A inputs/input0_B>outputs/output0
	diff -w expected/expected0 outputs/output0

test01 : pa07
	./pa07 inputs/input1_A inputs/input1_B
	valgrind --tool=memcheck --leak-check=full --verbose --show-reachable=yes --log-file=outputs/memoutput1 ./pa07 inputs/input1_A inputs/input1_B>outputs/output1
	diff -w expected/expected1 outputs/output1

test02 : pa07
	./pa07 inputs/input2_A inputs/input2_B
	valgrind --tool=memcheck --leak-check=full --verbose --show-reachable=yes --log-file=outputs/memoutput2 ./pa07 inputs/input2_A inputs/input2_B>outputs/output2
	diff -w expected/expected2 outputs/output2

test03 : pa07
	./pa07 inputs/input3_A inputs/input3_B
	valgrind --tool=memcheck --leak-check=full --verbose --show-reachable=yes --log-file=outputs/memoutput3 ./pa07 inputs/input3_A inputs/input3_B>outputs/output3
	diff -w expected/expected3 outputs/output3

test04 : pa07
	./pa07 inputs/input4_A inputs/input4_B
	valgrind --tool=memcheck --leak-check=full --verbose --show-reachable=yes --log-file=outputs/memoutput4 ./pa07 inputs/input4_A inputs/input4_B>outputs/output4
	diff -w expected/expected4 outputs/output4

test05 : pa07
	./pa07 inputs/input5_A inputs/input5_B
	valgrind --tool=memcheck --leak-check=full --verbose --show-reachable=yes --log-file=outputs/memoutput5 ./pa07 inputs/input5_A inputs/input5_B>outputs/output5
	diff -w expected/expected5 outputs/output5

test06 : pa07
	./pa07 inputs/input6_A inputs/input6_B
	valgrind --tool=memcheck --leak-check=full --verbose --show-reachable=yes --log-file=outputs/memoutput6 ./pa07 inputs/input6_A inputs/input6_B>outputs/output6
	diff -w expected/expected6 outputs/output6

test07 : pa07
	./pa07 inputs/input7_A inputs/input7_B
	valgrind --tool=memcheck --leak-check=full --verbose --show-reachable=yes --log-file=outputs/memoutput7 ./pa07 inputs/input7_A inputs/input7_B>outputs/output7
	diff -w expected/expected7 outputs/output7

test08 : pa07
	./pa07 inputs/input8_A inputs/input8_B
	valgrind --tool=memcheck --leak-check=full --verbose --show-reachable=yes --log-file=outputs/memoutput8 ./pa07 inputs/input8_A inputs/input8_B>outputs/output8
	diff -w expected/expected8 outputs/output8

test09 : pa07
	./pa07 inputs/input9_A inputs/input9_B
	valgrind --tool=memcheck --leak-check=full --verbose --show-reachable=yes --log-file=outputs/memoutput9 ./pa07 inputs/input9_A inputs/input9_B>outputs/output9
	diff -w expected/expected9 outputs/output9

test10: pa07
	./pa07 inputs/input10_A inputs/input10_B
	valgrind --tool=memcheck --leak-check=full --verbose --show-reachable=yes --log-file=outputs/memoutput10 ./pa07 inputs/input10_A inputs/input10_B>outputs/output10
	diff -w expected/expected10 outputs/output10
#testall : pa07
#	./pa07 images/02-unnormalized-cat-chess.ee264 outputs/output02
#
#	./pa07 images/03-unnormalized-hawkes-bay-NZ.ee264 outputs/output03
#
#	./pa07 images/04-unnormalized-nelsonmandela.ee264 outputs/output04
#
#	./pa07 images/05-unnormalized-sagan-stamp.ee264 outputs/output05
#
#	diff -w outputs/output01 expected/01-smile.ppm
##       valgrind --tool=memory --leak-check = yes ./pa06 images/01-unnormalized-#smile.ee264 outputs/output01
#
#	valgrind --tool=memcheck --leak-check=full --verbose --log-file=outputs/#memoutput1 ./pa06 images/01-unnormalized-smile.ee264 outputs/output01>/dev/null#
#
#	valgrind --tool=memcheck --leak-check=full --verbose --log-file=outputs/#memoutput2 ./pa06 images/02-unnormalized-cat-chess.ee264 outputs/output02>/dev/#null
#
#	diff -w outputs/output03 expected/03-hawkes-bay-NZ.ppm

testall : pa07 test00 test01 test02 test03 test04 test05 test06 test07 test08 test09 test10

