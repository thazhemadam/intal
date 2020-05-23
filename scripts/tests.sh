#!/bin/bash

YEL='\033[0;33m'
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m'

test()
{
    echo -e -n '\033[?7l'
    echo -e -n "[  ${YEL}RUNNING${NC} ] : [$1] -> [$2]"
    if [ "$($1)" = "$2" ]
    then echo -e "\r[  ${GREEN}PASSED${NC}  ]"
    else echo -e "\r[  ${RED}FAILED${NC}  ]"
    fi
    echo -e -n '\033[?7h'
}

runall()
{
    make

    if [ "$1" = "-all" ]
    then

# TESTING Addition
        echo -e "\nTesting Addition"

        test "./test_suite -add 12345 0" "12345"
        test "./test_suite -add 0 12345" "12345"
        test "./test_suite -add 12121 112121" "124242"
        test "./test_suite -add 12121 2121" "14242"
        test "./test_suite -add 13589 125554" "139143"
        test "./test_suite -add 1358889 125554" "1484443"

        test "./test_suite -add 23 90" "113"
        test "./test_suite -add 232342344324532234343232 45243243443543543324343545" "45475585787868075558686777"
        test "./test_suite -add 63211205501748764242 3215679098746826" "63214421180847511068"
        test "./test_suite -add 2897463853321498 894123538648920" "3791587391970418"
        test "./test_suite -add 379876456781628 0" "379876456781628"
        test "./test_suite -add 987512345 765429876" "1752942221"
        test "./test_suite -add 1 1" "2"
        test "./test_suite -add 0 0" "0"


# TESTING Subtraction
        echo -e "\nTesting Subtraction"

        test "./test_suite -diff 12345 0" "12345"
        test "./test_suite -diff 112121 12121" "100000"
        test "./test_suite -diff 12121 2121" "10000"
        test "./test_suite -diff 125554  13589" "111965"
        test "./test_suite -diff 1358889 125554" "1233335"

        test "./test_suite -diff  87654987234576 8543908723654" "79111078510922"
        test "./test_suite -diff  4999817 5000000" "183"
        test "./test_suite -diff  5476889 5476812" "77"

        test "./test_suite -diff 765498723987 0000000" "765498723987"
        test "./test_suite -diff 2897463853 321498" "2897142355"
        test "./test_suite -diff 874321348439876251 6543276890543" "874314805162985708"
        test "./test_suite -diff 1 1" "0"
        test "./test_suite -diff 0 0" "0"

# TESTING Multiplication
        echo -e "\nTesting Multiplication"

        test "./test_suite -mul 23769 0" "0"
        test "./test_suite -mul 769803498213 2365432609876" "1820918297869651292151588"
        test "./test_suite -mul 321679875 5437865321" "1749251836726114875"
        test "./test_suite -mul 432134567856984325675438 123456789765432189065" "53349946494295604316649129899725393042685470"
        test "./test_suite -mul  1209034065098706985403201 76540983021238904568790" "92540655848819583820775329961184533559190696790"
        test "./test_suite -mul 903509870698540 7654002189045687" "6915466528151010774566664196980"
        test "./test_suite -mul 87623490350987065698540 5400672190988904568798" "473225747615960454709926479480889995358154920"
        test "./test_suite -mul 87065698540985432121234 45321234654321788765465" "3945924953918442969209886643949877445072383810"
        test "./test_suite -mul 1 1" "1"
        test "./test_suite -mul 0 0" "0"
        
# TESTING Compare DONE
        echo -e "\nTesting Compare"

        test "./test_suite -comp 12345 12345" "0"
        test "./test_suite -comp 0 12345" "-1"
        test "./test_suite -comp 12121 112121" "-1"
        test "./test_suite -comp 12121 2121" "1"
        test "./test_suite -comp 13589 125554" "-1"
        test "./test_suite -comp 1358889 0125554" "1"
        test "./test_suite -comp 1358889 0125554" "1"
        test "./test_suite -comp 0 0" "0"


# TESTING Modulus
        echo -e "\nTesting Modulus"

        test "./test_suite -mod 654378297654 76654832145" "41139640494"
        test "./test_suite -mod 98766 8743212345" "98766"
        test "./test_suite -mod  321 54321" "321"
        test "./test_suite -mod  0 0" "0"
        test "./test_suite -mod 43298700321 675498321" "66807777"
        test "./test_suite -mod  765439875 645968839231" "765439875"
        test "./test_suite -mod 3218976564 5678321450" "3218976564"
        test "./test_suite -mod 1 1" "0"

# TESTING Power
        echo -e "\nTesting power"

        test "./test_suite -pow 43 34" "34508611856016952192871159710674768120457665758914571449"
        test "./test_suite -pow 678 4" "211309379856"
        test "./test_suite -pow 89 6" "496981290961"
        test "./test_suite -pow 15 9" "38443359375"
        test "./test_suite -pow 654378 1" "654378"
        test "./test_suite -pow 0 1" "0"
        test "./test_suite -pow 87 4" "57289761"
        test "./test_suite -pow 1 1" "1"
        test "./test_suite -pow 1 0" "1"


# TESTING GCD
        echo -e "\nTesting gcd"

        test "./test_suite -gcd 76543789 87664907" "1"
        test "./test_suite -gcd 76543789 153087578" "76543789"
        test "./test_suite -gcd 345 1005" "15"
        test "./test_suite -gcd 7696290 346725" "1005"
        test "./test_suite -gcd 4357689 8765490" "3"
        test "./test_suite -gcd  1 1" "1"
        test "./test_suite -gcd 0000473950765678936 43587654907827638" "2"
        test "./test_suite -gcd 0 0" "0"
        test "./test_suite -gcd 1 0" "1"
        test "./test_suite -gcd 0 1" "1"
        test "./test_suite -gcd 12431423514134 0" "12431423514134"
        test "./test_suite -gcd 0 322453643134" "322453643134"

        test "./test_suite -gcd 123231 123231" "123231"




# TESTING Fibonacci
        echo -e "\nTesting Fibonacci"

        test "./test_suite -fib 102" "927372692193078999176"
        test "./test_suite -fib 101" "573147844013817084101"
        test "./test_suite -fib 100" "354224848179261915075"
        test "./test_suite -fib 99" "218922995834555169026"
        test "./test_suite -fib 98" "135301852344706746049"
        test "./test_suite -fib 97" "83621143489848422977"
        test "./test_suite -fib 96" "51680708854858323072"
        test "./test_suite -fib 95" "31940434634990099905"
        test "./test_suite -fib 94" "19740274219868223167"
        test "./test_suite -fib 93" "12200160415121876738"
        test "./test_suite -fib 92" "7540113804746346429"
        test "./test_suite -fib 91" "4660046610375530309"
        test "./test_suite -fib 90" "2880067194370816120"
        test "./test_suite -fib 0" "0"
        test "./test_suite -fib 1" "1"
        test "./test_suite -fib 2" "1"


# TESTING Factorial
        echo -e "\nTesting Factorial"

        test "./test_suite -fact 9" "362880"
        test "./test_suite -fact 1" "1"
        test "./test_suite -fact 0" "1"
        test "./test_suite -fact 0019" "121645100408832000"
        test "./test_suite -fact 10" "3628800"
        test "./test_suite -fact 25" "15511210043330985984000000"
        test "./test_suite -fact 32" "263130836933693530167218012160000000"
        test "./test_suite -fact 17" "355687428096000"

# TESTING Binary Coefficient
        # echo -e "\nTesting Binary Coefficient"

        test "./test_suite -bco 80 50" "8871412534840453463008"
        # test "./test_suite -bco 25236914 456987" "11532941618118"
        # test "./test_suite -bco 0325102353 632114" "205501748764242"
        # test "./test_suite -bco 02897463853 321498" "931528833811794"
        # test "./test_suite -bco 13589 0" "0"
        # test "./test_suite -bco 000000000001358889 0125554698" "170614898010522"
        # test "./test_suite -bco 1 1" "1"


    fi
    rm ./test_suite
    rm ./*.o
}

runall $1 | less -r