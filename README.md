# Bit - A Simple Integer Manipulator

Bit is a simple C program that allows you to manipulate an integer value through a command-line interface. You can increment, decrement, output, reset, save, and load the integer value.

## Usage

Compile the program using a C compiler (e.g., gcc):

```bash
gcc Bit.c -o Bit
```

Run the compiled executable:

```bash
./Bit
```

The program will present a prompt `> ` where you can enter commands.

## Commands

| Command | Description                                                                                                                                   |
| ------- | --------------------------------------------------------------------------------------------------------------------------------------------- |
| `++`    | Increments the integer value by 1.                                                                                                            |
| `--`    | Decrements the integer value by 1.                                                                                                            |
| `out`   | Prints the current integer value to the console.                                                                                              |
| `reset` | Resets the integer value to 0.                                                                                                               |
| `save`  | Saves the current integer value to `Bit.bin`.                                                                                                |
| `load`  | Loads the integer value from `Bit.bin`.                                                                                                        |
| `q`     | Quits the program. Asks if you want to save. If you enter 'n', it quits without saving. Any other input saves before quitting (including 'y'). |

## Saving and Loading

The `save` command stores the current integer value in a file named `Bit.txt`. The `load` command reads the integer value from this same file.  If the file does not exist when loading, the value of `n` may be uninitialized.

## Example Session

```
> ++
> ++
> out
2
> --
> out
1
> save
> reset
> out
0
> load
> out
1
> q
Do you want to save (y/n): n
```

## File Description

*   `Bit.c`: The C source code for the Bit program.

### [License](LICENSE.md)

`Copyright (C) 2025 Rajveer Singh Saggu`
