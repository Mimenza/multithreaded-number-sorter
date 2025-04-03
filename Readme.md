# Multithreaded Number Sorter

This repository contains a multithreaded program written in C that generates unique random numbers, sorts them into odd and even lists, and processes them using multiple threads. The program is designed to demonstrate multithreading, memory management, and efficient data handling in C.

## Features

- **Multithreading**: Utilizes `pthread` to create and manage threads for parallel processing.
- **Dynamic Memory Management**: Allocates and frees memory dynamically for arrays, linked lists, and thread-specific data.
- **Linked Lists**: Implements linked lists to store and manage sorted numbers.
- **Configuration File**: Reads program configuration (e.g., number of threads, numbers per thread) from a `.txt` file.
- **Error Handling**: Includes error handling for invalid inputs, memory allocation failures, and file operations.

## Technologies Used

- **C Programming Language**: Core implementation of the program.
- **POSIX Threads (pthread)**: For multithreading support.
- **Makefile**: To automate the build process.
- **Standard Libraries**: Includes libraries like `<stdio.h>`, `<stdlib.h>`, `<pthread.h>`, and others for various functionalities.

## File Structure

```
multithreaded-number-sorter/
├── srcs/                # Source files
├── incs/                # Header files
├── objs/                # Compiled object files (generated during build)
├── test.txt             # Example configuration file
├── Makefile             # Build automation
└── Readme.md            # Project documentation
```

## How to Build and Run

### Prerequisites

- A C compiler (e.g., `gcc`).
- Make utility (`make`).
- A Unix-like environment (Linux, macOS, or WSL on Windows).

### Steps to Execute

1. **Clone the Repository**:
   ```bash
   git clone git@github.com:Mimenza/multithreaded-number-sorter.git
   cd multithreaded-number-sorter
   ```

2. **Prepare the Configuration File**:
   Ensure you have a configuration file (e.g., `test.txt`) with the following format:
   ```
   numbers_per_thread = <number>
   thread_num = <number>
   ```

3. **Build the Program**:
   Run the following command to compile the program:
   ```bash
   make
   ```

4. **Run the Program**:
   - To display the help message:
     ```bash
     ./mns -h
     ```
     or

     ```bash
     ./mns --help
     ```
   - To specify the configuration file:
     ```bash
     ./mns -f test.txt
     ```
     or

     ```bash
     ./mns --file test.txt
     ```

5. **Clean Up**:
   To remove compiled files and the executable, run:
   ```bash
   make clean    # Removes object files
   make fclean   # Removes object files and the executable
   ```

6. **Rebuild**:
   To clean and rebuild the program, use:
   ```bash
   make re
   ```

## Example Output

When executed, the program will:
1. Generate unique random numbers.
2. Sort them into odd and even lists.
3. Display the configuration and results.

Example:
```
Configuration:
  numbers_per_thread = 10
  thread_num = 2

Odd list:
[0] 1
[1] 3
[2] 5
...

Even list:
[0] 2
[1] 4
[2] 6
...
```

## Error Handling

- **Invalid Configuration**: The program will terminate if the configuration file is missing or contains invalid values.
- **Memory Allocation Failures**: Proper error messages are displayed if memory allocation fails.
- **File Errors**: Errors are reported if the configuration file is missing or has an incorrect format.
