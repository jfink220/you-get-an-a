# You Get an A (C++)

You can find the instructions for this lab at [More Than Equations][more-than-equations]. Create a new repository on GitHub to house your code. Be sure to make the repository public so that I can view and grade it.

We will use [CMake][cmake] to build executables (e.g. tests, the driver program, the benchmarks, etc.). Additionally, we will use [Catch2][catch2] for unit testing and benchmarking.

## Building Executables With CMake

You can use CMake to compile and build the executables for the project. First, you need to create a `build/` directory in the project. The build directory will house all of the compiled files as well as the `Makefile` for the project. Note that we do NOT check the `build/` directory into version control since each person will have to regenerate the executables on their own machine.

```bash
mkdir build
cd build
```

Once you are inside of the build directory, you can run the following command to build all of the executables for the project:

```bash
cmake .. && make
```

## Testing the App

Any tests that you define in the `tests/` directory must have a corresponding entry in `CMakeLists.txt`. After you build executables using CMake, you can run the corresponding test files from within the `build/` directory.

## Running the App

The `main.cpp` file at the root of the project must have a corresponding entry in `CMakeLists.txt`. After you build executables using CMake, you can run the driver program from within the `build/` directory.

## Running Benchmarks

Benchmarking is provided with Catch2. You can write benchmarking assertions alongside test assertions right in your test files.

[catch2]: https://github.com/catchorg/Catch2
[cmake]: https://cmake.org/
[more-than-equations]: https://morethanequations.com/Computer-Science/Labs/You-Get-an-A

## How to Use Gradebook

The gradebook outputs its information in the console. You can use the gradebook and add input by adding code to the driver program as shown by the examples below.

First create a gradebook object:

```cpp
Gradebook gradebook;
```

You can add a student to the gradebook with the corresponding command which takes in the student's full name and their specific ID number respectively. The text given before the space will be assumed as the first name while the text after the space will be assumed as the last name of the student.

```cpp
gradebook.add_student("Joe James", "ABC124");
```

You can add an assignment to the gradebook with the corresponding command. This assignment will be added to all students without a specified grade for each student. The command takes in the assignment's name and the maximum score possible on the assignment respectively.

```cpp
gradebook.add_assignment("Quiz 1", 100);
```

You can then enter a grade for a student with the corresponding command. The command takes in the name of the student, the name of the assignment, and the grade that student received on the assignment (as long as this grade is less than the maximum grade possible and not negative) respectively.

```cpp
gradebook.enter_grade("Joe James", "Quiz 1", 99);
```

You can then get a detailed view and report of the grade book in the console through the corresponding command and a cout statement written in the main.cpp (driver) file.

```cpp
std::cout << gradebook.report();
```

The report would output text in the console as follows for the previous commands:

```bash

GRADEBOOK REPORT:

Last_Name, First_Name, Student_Id, Quiz 1, Average
James, Joe, ABC124, Quiz 1 (99/100), 99.000000
```

First all of the last names of the students are shown, then first names, then student ids, then all the assignments, and finally the average grades for that student. The average grades are calculated through considering the student's graded assignments and dividing their total points earned by the total points possible.
