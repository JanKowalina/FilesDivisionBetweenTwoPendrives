# Files Division Between Two Pendrives

This program divides a set of files between two pendrives based on their sizes. It sorts the files in ascending order of their pendrive sizes and then divides them into two pendrives such that the total size of the files in each pendrive does not exceed a given pendrive size.

## How to Compile and Run

To compile the code, use the following command:

```
g++ -o FilesDivisionBetweenTwoPendrives FilesDivisionBetweenTwoPendrives.cpp
```

To run the program, use the following command:

```
./FilesDivisionBetweenTwoPendrives
```

## Input

The program expects the following input format:

```
<file_number> <pendrive_size>
<size1_1> <size2_1>
<size1_2> <size2_2>
...
```

- `<file_number>`: The number of files to be divided.
- `<pendrive_size>`: The maximum size of each pendrive.
- `<size1_i>`: The pendrive size of the i-th file.
- `<size2_i>`: The size of the i-th file.

Example input:

```
4 7
323 1
10 2
87438 5
99 6
```

## Output

The program outputs the division of files between the two pendrives. The output format is as follows:

```
<number_of_files>
1: <file_sizes_in_pendrive_1>
2: <file_sizes_in_pendrive_2>
```

- `<number_of_files>`: The total number of files divided between the pendrives.
- `<file_sizes_in_pendrive_1>`: The sizes of the files in the first pendrive.
- `<file_sizes_in_pendrive_2>`: The sizes of the files in the second pendrive.

Example output:

```
3
1: 323 10
2: 87438
```

In this example, three files are divided between the pendrives. The first pendrive contains files with sizes 323 and 10, while the second pendrive contains a file with size 87438.
