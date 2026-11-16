CC := gcc
CFLAGS := -Wall -Wextra -Wpedantic -std=c11 -g -O0

.PHONY: all test4 clean

all:
	@echo "Available targets:"
	@echo "  make activity1_cli_basics.out"
	@echo "  make activity2_fsm_cli.out"
	@echo "  make activity3_modular_cli.out"
	@echo "  make activity4_application.out"
	@echo "  make activity4_tests.out"
	@echo "  make test4"
	@echo "  make clean"

activity1_cli_basics.out: activity1_cli_basics.c
	$(CC) $(CFLAGS) activity1_cli_basics.c -o $@

activity2_fsm_cli.out: activity2_fsm_cli.c
	$(CC) $(CFLAGS) activity2_fsm_cli.c -o $@

activity3_modular_cli.out: activity3_main.c activity3_input.c activity3_input.h activity3_calculator.c activity3_calculator.h
	$(CC) $(CFLAGS) activity3_main.c activity3_input.c activity3_calculator.c -o $@

activity4_application.out: activity4_main.c activity4_operations.c activity4_operations.h
	$(CC) $(CFLAGS) activity4_main.c activity4_operations.c -o $@

activity4_tests.out: activity4_test_operations.c activity4_operations.c activity4_operations.h
	$(CC) $(CFLAGS) activity4_test_operations.c activity4_operations.c -o $@

test4: activity4_tests.out
	./activity4_tests.out

clean:
	rm -f *.out *.o