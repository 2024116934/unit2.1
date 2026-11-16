# Activity 1: Command-Line Interface Basics

This activity introduces the layout of a small menu-driven command-line application. The program works by calling functions to move between the main menu and each option.

## 1. Compile and run

Compile directly using GCC:

```bash
gcc activity1_cli_basics.c -o activity1_cli_basics.out
```

Alternatively, use Make:

```bash
make activity1_cli_basics.out
```

Then run:

```bash
./activity1_cli_basics.out
```

## 2. Follow the program flow

Try several options and follow the route through:

- `main_menu()`
- `get_user_input()`
- `select_menu_item()`
- the selected menu-item function
- `go_back_to_main()`

Notice that `go_back_to_main()` calls `main_menu()` again. This is manageable in a small example, but the control flow becomes harder to follow as more modes and transitions are added. Activity 2 will restructure the same application using a finite state machine.

## 3. Add the circle option

Add menu item 5, which calculates the area of a circle.

You must:

1. print option 5 in `print_main_menu()`;
2. add case 5 to `select_menu_item()`;
3. complete `menu_item_5()`;
4. ask the user to enter the radius;
5. calculate the area using `PI * radius * radius`;
6. print the radius and area to two decimal places;
7. call `go_back_to_main()` after displaying the result.

Use this output format:

```text
Area of circle with radius 10.00 = 314.16
```

Keep option 6 as the exit option.

## 4. Check your work

Run the program and confirm that:

- option 5 is displayed;
- selecting 5 runs the circle calculation;
- a radius of `10` produces approximately `314.16`;
- entering `b` returns to the menu;
- selecting 6 exits the program.

No automated test is supplied for this interactive activity - I have given ELEC2645 bot the day off!
