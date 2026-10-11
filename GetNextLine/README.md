*This activity has been created as part of the 42 curriculum by hhailat.*

# Get Next Line (GNL)

## Description
**Get Next Line** is a foundational project at 42 that challenges students to write a function in C returning a line read from a file descriptor. Whether the data comes from a file, standard input, or a network socket, the function must be able to read it incrementally, line by line, without losing any data or leaking memory.

The primary goal of this project is to introduce students to a concept that will become crucial throughout the curriculum: **static variables** (or equivalent state management in languages without them) and memory management handling varying buffer sizes (`BUFFER_SIZE`).

---

## Algorithm Explanation and Justification

### The Core Problem
When reading from a file descriptor using the `read()` system call, you read in chunks defined by `BUFFER_SIZE`. However, lines do not neatly align with `BUFFER_SIZE` boundaries. A single read might contain multiple lines, part of a line, or end mid-word, and subsequent reads must pick up precisely where the previous one left off.

### Selected Algorithm: Static Buffer Accumulation
The solution implemented in this project relies on a **persistent static buffer (or "stash")** paired with a dynamic string-concatenation approach:

1. **Stash Inspection:** Before calling `read()`, the function checks if the static variable already contains a newline character (`\n`). If it does, there is no need to read from the file descriptor yet.
2. **Reading in a Loop:** If no newline is found, a temporary buffer is allocated, and `read()` is invoked in a loop until a newline is encountered or End-Of-File (EOF) is reached.
3. **Data Accumulation:** Each chunk read is concatenated to the static accumulator (stash) using custom string manipulation functions (`ft_strjoin`, `ft_strchr`, etc.).
4. **Line Extraction:** Once a newline or EOF is identified, the line up to the newline (inclusive) is extracted into a newly allocated string to be returned to the caller.
5. **Remainder Preservation:** The remainder of the text after the newline is sliced and saved back into the static variable so it is preserved for the next invocation of `get_next_line`.

### Justification
* **Efficiency:** By utilizing a static variable, we avoid redundant system calls by keeping leftover bytes in memory.
* **Flexibility:** The algorithm handles any positive `BUFFER_SIZE` (whether it is 1 byte, 42 bytes, or 1000000 bytes) gracefully.
* **Memory Safety:** Every allocation is checked against failure, and intermediate buffers are systematically freed to prevent memory leaks.

---

## Instructions

### Prerequisites
* A C compiler (e.g., `gcc`).
* Make (optional, but recommended for automation).

### Compilation
To compile the project and test it, you can include `get_next_line.c` and its utility files along with your test `main.c` file. Ensure you define the `BUFFER_SIZE` macro during compilation:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl_test
```

### Execution
Run the compiled binary, passing a text file as an argument or piping input into it:

```bash
./gnl_test file.txt
```

---

## Resources & AI Usage

### Classic References
* [Stack over flow](https://stackoverflow.com/)
* [Youtube Channel](https://youtube.com/@CodeVault)
* Articles and tutorials on static variables and memory leaks in 42 projects (e.g., Gitbook guides by 42 peers).

### AI Usage Disclosure
* **Tasks Performed with AI:** AI was utilized to help structure this README, format markdown guidelines, and draft clear explanations of the state-tracking algorithm. 
* **Parts of the Activity:** AI did not write the core C source code or logic for `get_next_line`, ensuring that the implementation remains entirely original and compliant with the 42 Honor Code. AI assistance was strictly limited to technical documentation and conceptual structuring of the algorithm write-up.