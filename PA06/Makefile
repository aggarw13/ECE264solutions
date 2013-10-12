GCC = gcc
CFLAGS = -g -Wall -Wshadow
LIBS = -lm
OBJ = obj
TESTN := $(shell seq 1 5) 
#---------------------------------
pa06 : answer06.o pa06.o
	$(GCC) $(CFLAGS) answer06.o pa06.o -o pa06 

pa06.o : pa06.c pa06.h
	$(GCC) $(CFLAGS) -c pa06.c 

answer06.o : answer06.c pa06.h 
	$(GCC) $(CFLAGS) -c answer06.c 

clean:
	rm -rf pa06

TESTS := $(addprefix test,${TESTN})

testall: pa06
	./pa06 images/01-unnormalized-smile.ee264 outputs/output01

	./pa06 images/02-unnormalized-cat-chess.ee264 outputs/output02

	./pa06 images/03-unnormalized-hawkes-bay-NZ.ee264 outputs/output03

	./pa06 images/04-unnormalized-nelsonmandela.ee264 outputs/output04

	./pa06 images/05-unnormalized-sagan-stamp.ee264 outputs/output05

	diff -w outputs/output01 expected/01-smile.ppm
#	valgrind --tool=memory --leak-check = yes ./pa06 images/01-unnormalized-smile.ee264 outputs/output01

	valgrind --tool=memcheck --leak-check=full --verbose --log-file=outputs/memoutput1 ./pa06 images/01-unnormalized-smile.ee264 outputs/output01>/dev/null

	valgrind --tool=memcheck --leak-check=full --verbose --log-file=outputs/memoutput2 ./pa06 images/02-unnormalized-cat-chess.ee264 outputs/output02>/dev/null

	diff -w outputs/output03 expected/03-hawkes-bay-NZ.ppm

	valgrind --tool=memcheck --leak-check=full --verbose --log-file=outputs/memoutput3 ./pa06 images/03-unnormalized-hawkes-bay-NZ.ee264 outputs/output03>/dev/null

	diff -w outputs/output04 expected/04-nelsonmandela.ppm

	valgrind --tool=memcheck --leak-check=full --verbose --log-file=outputs/memoutput4 ./pa06 images/04-unnormalized-nelsonmandela.ee264 outputs/output04>/dev/null

	diff -w outputs/output05 expected/05-sagan-stamp.ppm

	valgrind --tool=memcheck --leak-check=full --verbose --log-file=outputs/memoutput5 ./pa06 images/05-unnormalized-sagan-stamp.ee264 outputs/output05>/dev/null
	
test06: pa06
	./pa06 images/corrupt-testcases/bad-comment-len.ee264 outputs/output01
	valgrind --tool=memcheck --leak-check=full --verbose --log-file=outputs/memoutput6 ./pa06 images/corrupt-testcases/bad-comment-len.ee264 outputs/output05>/dev/null

test07: pa06
	./pa06 images/corrupt-testcases/height0.ee264 outputs/output01	
	 valgrind --tool=memcheck --leak-check=full --verbose --log-file=outputs/memoutput7 ./pa06 images/corrupt-testcases/height0.ee264 outputs/output05>/dev/null

test08 : pa06
	 valgrind --tool=memcheck --leak-check=full --verbose --log-file=outputs/memoutput8 ./pa06 images/corrupt-testcases/width0.ee264 outputs/output05>/dev/null

test09 : pa06
	valgrind --tool=memcheck --leak-check=full --verbose --log-file=outputs/memoutput9 ./pa06 images/corrupt-testcases/big-width-height.ee264 outputs/output05>/dev/null

test10 : pa06
	valgrind --tool=memcheck --leak-check=full --verbose --log-file=outputs/memoutput10 ./pa06 images/corrupt-testcases/comment-has-no-null-byte.ee264 outputs/output05>/dev/null

test11 : pa06
	valgrind --tool=memcheck --leak-check=full --verbose --log-file=outputs/memoutput11 ./pa06 images/corrupt-testcases/check-magic-bits.ee264 outputs/output05>/dev/null

test12 : pa06
	valgrind --tool=memcheck --leak-check=full --verbose --log-file=outputs/memoutput12 ./pa06 images/corrupt-testcases/incomplete-header.ee264 outputs/output05>/dev/null

test13 : pa06
	valgrind --tool=memcheck --leak-check=full --verbose --log-file=outputs/memoutput13 ./pa06 images/corrupt-testcases/incomplete-image.ee264 outputs/output05>/dev/null

test14 : pa06
	valgrind --tool=memcheck --leak-check=full --verbose --log-file=outputs/memoutput14 ./pa06 images/corrupt-testcases/height-wrong.ee264 outputs/output05>/dev/null

