# ELEC2645 Unit 2.1: Command-Line Applications, FSMs and Testing

These activities develop a simple command-line application in stages, progressing from a basic menu to a finite state machine, modular code and automated unit tests.

Work through the activities in order and follow the instructions in each activity’s Markdown file.

## Activities

1. [Command-Line Interface Basics](activity1_cli_basics.md)
2. [Finite State Machine](activity2_fsm_cli.md)
3. [Modular Code and Robust Input](activity3_modular_cli.md)
4. [Unit Testing](activity4_unit_tests.md)

The calculator examples are deliberately simple so that you can focus on the software structure. Your assessed Unit 2 project does not need to be a calculator.

## Build commands

Run `make` to display the available targets:

```bash
make
```

Build and run each activity using:

```bash
make activity1_cli_basics.out
./activity1_cli_basics.out
```

```bash
make activity2_fsm_cli.out
./activity2_fsm_cli.out
```

```bash
make activity3_modular_cli.out
./activity3_modular_cli.out
```

```bash
make activity4_application.out
./activity4_application.out
```

Build and run the Activity 4 unit tests using:

```bash
make test4
```

Remove generated files using:

```bash
make clean
```

## Run and Debug

The repository includes VS Code build tasks and Run and Debug configurations for each activity.

Open **Run and Debug**, select the required activity and press `F5`. The selected activity must compile before the debugger can start.

## Testing

Activities 1 to 3 include manual checks or testing tables in their guides.

Activity 4 introduces automated unit tests that call reusable functions directly without running the interactive command-line interface.

## Saving your work

Make sure your final changes have appeared in your GitHub repository before finishing the activities.
