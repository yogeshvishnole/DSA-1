/*
What is segmentation fault error in cpp ?
It is a run time error , which is caught at runtime not at compile time and it occurs
when your program try to access the memory which is not allocated for your program.
FOr example -
You declare an array as -
int array[10];
and you want to access as -
cout<<array[2000];

here it is not your memory and you will get segmentation fault error. In different programming languages you will get differnet errors.
Ypu can try above program.

following gives seg fault errpr or runtime error -
a[-1]
a[10000000] because array in cpp only has max size of 10 raise to power 6 may be 5 somtimes.
*/