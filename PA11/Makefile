GCC = gcc
CFLAGS = -g -Wall -Wshadow
OBJS = pa11.o answer11.o
HDRS = pa11.h
TARGET = pa11
VALGRIND = valgrind --tool=memcheck --leak-check=full --verbose

#.PHONY: test cl
#clean environment test_ch01 test_ch02 test_ch03 test_ch04 test_ch05 test_ch06 t#est_bit01 test_bit02 test_bit03 test_bit04 test_bit05 test_bit06 test_bit07

pa11: $(OBJS) $(HDRS)
	$(GCC) $(CFLAGS) $(OBJS) -o $@

test: | test_ch01 test_ch02 test_ch03 test_ch04 test_ch05 test_ch06 test_bit01 test_bit02 test_bit03 test_bit04 test_bit05 test_bit06 test_bit07

test_sort1: $(TARGET) 
#	./$(TARGET) 2 123-456789AFBDEC 2          
#        diff expected/ch_expected/solution1 outputs/output_ch01
	$(VALGRIND) --log-file=outputs/memoutput_st1 ./pa11 2 123-456789AFBDEC 2 >outputs/st21
#        @bin/valgrind-checker.sh outputs/memoutput_ch01 

test_sort2: $(TARGET) 
#	./$(TARGET) 3 -23416785ABC9DEF           
#        diff expected/ch_expected/solution1 outputs/output_ch01
	$(VALGRIND) --log-file=outputs/memoutput_st2 ./pa11 3 -23416785ABC9DEF >outputs/st21
#        @bin/valgrind-checker.sh outputs/memoutput_ch01 

