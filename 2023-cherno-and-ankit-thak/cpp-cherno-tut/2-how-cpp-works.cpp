/*

1. we write our code in bunch of source files and give it to a compiler to compile it
into a binary that could be a executable file .exe or a library as well.

Lets go in some more depth by example of a program
*/

#include<iostream> // here #include is a preprocessor statement .

/*
 A short note on preprocessor statments -

 Preprocessor statments do their work before compilation thats why they are called as preprocessor statements.
 Anything that starts with hash is most probably a preprocessor statement.
 Here what include will do is take a file and paste the content of that file here in this file.
 The file include pastes is called header file , will discuss more about it further in the course.
 Here iostream file contains the declaration for the function cout and other input/output fuinctions
*/

int main(){
    std::cout<<"Hello World"<<std::endl;
    std::cin.get();
}

/*
About main function - 

main function is the entrypoint for a cpp program.
code inside it executed by the compiler in sequence expects for branchin and switch statements and some other.
we can see its return type is int but we not return anything as it default returns 0 , it is only for main func.

<< ==> is overloaded opertor --> is just a function
*/

/*

Journey from main.cpp to main.exe -

it includes several stages -

1. Preprocessing the preprocessor directives/statements do their job like #include includes the header files
into the current cpp file.

2. Notes cpp files are always compiled.

3. Now compilation takes place , compiler takes cpp file compiles it intro machine code and gives us .obj file.

4. Linker -> very imp stage now all the functions/identifiers that we declare in our .cpp file and not defined are
resolved from different obj files and a linking takes place between all the files of the project to make the final
.exe application file.

5.Linker error -> if things that are declared there definitions not found at linking stage , linker throws linker error.

*/