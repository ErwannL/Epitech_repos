##
## EPITECH PROJECT, 2022
## B-SYN-200-LYN-2-1-palindrome-erwann.laplante
## File description:
## test_bad_argument
##

clear

make

echo "[START]\n"

echo "\ntest 2 time imax\n"

./palindrome -n 8 -imax 7 -imax 4

echo "\ntest bad flag\n"

./palindrome -p 2 -a 8

echo "\ntest 2 time p\n"

./palindrome -p 8 -p 121

echo "\ntest 2 time imin\n"

./palindrome -n 8 -imin 7 -imin 4

echo "\ntest unreconize arg\n"

./palindrome -p 5 8

echo "\ntest no int after one flag\n"

./palindrome -p 5 -b toto

echo "\ntest 2 time n\n"

./palindrome -n 8 -n 121

echo "\ntest 2 time b\n"

./palindrome -n 8 -b 6 -b 8

echo "\ntest flag b < 2\n"

./palindrome -n 8 -b 1

echo "\ntest flag b > 10\n"

./palindrome -n 8 -b 11

echo "\ntest no p & no n\n"

./palindrome -b 8

echo "\ntest palindrome in base after p\n"

./palindrome -p 4782 -b 2

echo "\ntest imin > imax\n"

./palindrome -p 121 -imin 11 -imax 8

echo "\ntest n flag & p flag\n"

./palindrome -p 121 -n 8

echo "\n[END]\n"

make fclean
