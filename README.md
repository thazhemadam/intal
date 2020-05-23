## Running Test Cases
* #### Using intal_sampletest.c
   If you want to use intal_sampletest.c for running testcases, presently, these are the steps to be followed.<br>
    1. Make sure in the makefile that to **intal_client** will get executed. 
    2. From the main directory of the repo, run ```bash ./scripts/run.sh```. 
   
* #### Using the custom test suite
  intal_sampletest.c can be tedious to work with or understand.<br>
  Presently, the custom test suite has been developed to work with the functions that do not require arrays as an argument. <br>
  Provision for those functions can be added later, too.<br>

  1. #### Using predefined testcases.
      If you want to use your own custom test cases for running test cases, presently, these are the steps to be followed.
       1. Make sure that the line in the makefile that corresponds to test_suite will get executed. 
       2. From the main directory of the repo, run ```bash ./scripts/test.sh --all``` <br>
  2. #### Defining custom testcases that must be run everytime.
      If you want to define custom testcases that must be run everytime ```bash ./scripts/test.sh --all``` is executed, enter your custom test case in scripts/tests.sh.<br>The pattern for entering the test cases is specified in test.sh, down below in a function.
  3. #### Running custom testcases once
      If you want to run a custom testcase and try it out just once, presently, these are the steps to be followed.
       1. Run ```make```
       2. Run ```./test_suite <operation>  <intal1> <intal2 (if applicable)>```

  4. For the manual page on test_suite, run ```./test_suite --help```
    ```
      Usage: $ ./test_suite <operation> <intal1> <intal2 (if applicable)>
      <num> : arbitrary length number with preceeding + or -
      <operation> : 
        -add : num1 + num2
        -diff : num1 - num2
        -mul : (num1)*(num2)
        -comp : num1 =/!= num2
        -mod : num1%num2
        -pow : (num1)^(num2)
        -gcd : gcd(num1, num2)
        -fib : (num1)th Fibonacci element
        -fact : (num1)!
        -bco : num1 C num2 
<br>  

## Using Valgrind<br>
While checking the code for memory errors/memory leaks with valgrind, it is recommended that intal_sampletest.c be used, since it accounts for freeing the variables being used as parameters as well.<br>
Unless you've a shell script that makes sure the commandline arguments aren't accounted for by valgrind by one way or another, please refrain from using it, since it may lead to erroneous results, and unnecessary confusion.<br>
If you want to run valgrind, presently, these are the steps to be followed.<br>
   1. Make sure in the makefile that to **intal_client** will get executed. 
   2. Run `make`
   3. Run `valgrind --leak-check=full -s ./intal_client` 

