SRCFOLDER := src/
OBJFOLDER := obj/
BINFOLDER := bin/
TESTFOLDER := test/
GCOVFOLDER := gcov_files/

CC := gcc
CFLAGS := -fPIC -fprofile-arcs -ftest-coverage -lgcov --coverage -I$(SRCFOLDER)

MAIN_OBJ := $(OBJFOLDER)main.o
TEST_OBJ := $(OBJFOLDER)test_utils.o

SRCS := $(wildcard $(SRCFOLDER)*.c) $(wildcard $(TESTFOLDER)*.c)
OBJS := $(patsubst %.c, $(OBJFOLDER)%.o, $(notdir $(SRCS)))

all: $(BINFOLDER)test_utils

$(BINFOLDER)main: $(MAIN_OBJ) $(filter-out $(TEST_OBJ), $(OBJS))
	$(CC) $(CFLAGS) $^ -o $@

$(BINFOLDER)test_utils: $(TEST_OBJ) $(filter-out $(MAIN_OBJ), $(OBJS))
	$(CC) $(CFLAGS) $^ -o $@

$(OBJFOLDER)%.o: $(SRCFOLDER)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJFOLDER)%.o: $(TESTFOLDER)%.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -rf $(OBJFOLDER)*
	rm -rf $(BINFOLDER)*
	rm -rf lcov-report
	rm -rf $(GCOVFOLDER)
	rm *.info

run:
	./bin/test_utils
	mkdir $(GCOVFOLDER)
	mv $(OBJFOLDER)*.gcno $(GCOVFOLDER)
	mv $(OBJFOLDER)*.gcda $(GCOVFOLDER)

.PHONY: coverage
coverage:
	mkdir lcov-report
	lcov --capture --directory $(GCOVFOLDER) --output-file coverage.info --rc lcov_branch_coverage=1
	genhtml --branch-coverage coverage.info --output-directory lcov-report


