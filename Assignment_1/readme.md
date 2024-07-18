**Creative Coding II**

Prof. Dr.-Ing. Angela Brennecke | a.brennecke@filmuniversitaet.de | Film University Babelsberg *KONRAD WOLF*   
Anna Brauwers | anna.brauwers@filmuniversitaet.de | Film University Babelsberg *KONRAD WOLF*

---

# Assignments

You need 10 assignment pts in total to collect 50% of the course pts and to pass the course. You can collect 3 pts per assignment sheet.

## 1 Assignment - Setup

Form a team of two or maximium three to work on the assignments in a team. Create your own repository that you can use to commit, push and pull solutions. Share the repository link in the submission.

## 2 Assignment - Research | 1 pts

Checkout the code folder and make sure you can build and understand all examples in the 01_main and 02_types_vars folders. In the 02_types_vars folder, checkout the code for TODO directives. Follow the directions and implement an example in your team. Checkout the scope_exercises.md file and follow the directions there, too.

### Scope Exersices - Output and Observations

We're segmenting the output of the built "vector.cpp" script into four parts:

![Output](./img/cc2_AlMaAd_ass1_2_scope_exersices_img1.jpg)

1. The empty vector size right after "vec" was created. Then, after the first for-loop pushed rising numbers into 5 vector values the vector size outputs 5.

2. Two different methods are used to access each individual value of the vector array. The []-operator and the at() function alternate within one for-loop.

3. A freshly created vector operator counts through the same individual values in a whlile-loop and dereferences them while outputting.

4. The values of "vec" are getting removed starting from the beginning until the while-loop reaches the end of the array and the vector size is zero.

## 3 Assignment - Bug fixing | 1 pts

Checkout the errors folder and try to compile each example. Errors will occur. Without checking the soluion right away try to fix the errors and document what was wrong. 

**NOTE to Windows users**: You cannot use the Makefiles right away. You have to create a new project in Visual Studio Community and insert the source files and folders according to the folder structure in the example. Then try to build the examples and fix the code errors.

**NOTE to macOS users**: In order to use `Makefiles` and the `make command` on macOS you need to use the terminal, move to the corresponding folder in which the `Makefile` is located and type `make`.




## 4 Assignment - Creativity | 1 pts

Checkout the example in the ascii_art folder and build the application. Understand what is happening. Now be creative and extend the implementation by at least two more ascii arts. Make sure that you add a comprehensive code structure that includes header files for the function declarations, and include directory and a Makefile. Finally, allow the user of the application to choose between your ascii arts on the command line. Therefore, checkout the "std::cin" command for user input.