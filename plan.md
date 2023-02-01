# inbox

-   live demo!
    -   but, with git tags
-   gilded rose in C
-   rewind - show the refactoring demo again
-   approvals with a visual diff tool
    -   use a 'received' file
-   all combinations
-   coverage report using `gcov`
-   mutation testing
    -   use `mull`
-   pairwise testing
    -   use `jenny.c`
-   watch mode
    -   use `entr` file watcher
-   record demos
-   make room for discussions and reactions

# the narrative

-   the goal, the place we want to reach: the refactoring demo
    -   we want to support this refactoring style
-   get this code under some test
    -   hello world `int main() { printf("hello world!\n"); }`
        -   build script
        -   see the output on the command line
    -   testing framework
        -   with cli approvals
    -   call gilded rose
    -   setup coverage (lines hit count)
    -   review current coverage report
    -   some manual mutations break tests some don't
-   coverage
    -   build up coverage with combination approvals
        -   pause approvals
    -   add branches coverage
    -   build up the coverage again
    -   manual mutations break the test
        -   we saw this style in our ensemble work
-   mutations
    -   show simplified version
        -   function calls
        -   conditions
        -   some untested code
    -   run automatic mutation coverage
