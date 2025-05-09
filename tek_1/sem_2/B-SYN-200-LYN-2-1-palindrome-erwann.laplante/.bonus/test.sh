##
## EPITECH PROJECT, 2022
## B-SYN-200-LYN-2-1-palindrome-erwann.laplante
## File description:
## test
##

clear

echo "\nexecute : make re\n"

make re

echo "\ntest : ./palindrome -n 4782 -b 10"
echo "need to be  : \n4782 leads to 46464 in 3 iteration(s) in base 10\n"

./palindrome -n 4782 -b 10

echo "\ntest : ./palindrome -n 64 -b 2"
echo "need to be  : \n64 leads to 65 in 1 iteration(s) in base 2\n"

./palindrome -n 64 -b 2

echo "\ntest : ./palindrome -n 4782 toto"
echo "need to be  : \ninvalid argument\n"

./palindrome -n 4782 toto

echo "\ntest : ./palindrome -p 363 -b 10"
echo "need to be  : \n3 leads to 363 in 6 iteration(s) in base 10"
echo "6 leads to 363 in 5 iteration(s) in base 10"
echo "12 leads to 363 in 4 iteration(s) in base 10"
echo "15 leads to 363 in 3 iteration(s) in base 10"
echo "21 leads to 363 in 4 iteration(s) in base 10"
echo "24 leads to 363 in 3 iteration(s) in base 10"
echo "30 leads to 363 in 4 iteration(s) in base 10"
echo "33 leads to 363 in 3 iteration(s) in base 10"
echo "39 leads to 363 in 2 iteration(s) in base 10"
echo "42 leads to 363 in 3 iteration(s) in base 10"
echo "48 leads to 363 in 2 iteration(s) in base 10"
echo "51 leads to 363 in 3 iteration(s) in base 10"
echo "57 leads to 363 in 2 iteration(s) in base 10"
echo "60 leads to 363 in 3 iteration(s) in base 10"
echo "66 leads to 363 in 2 iteration(s) in base 10"
echo "75 leads to 363 in 2 iteration(s) in base 10"
echo "84 leads to 363 in 2 iteration(s) in base 10"
echo "93 leads to 363 in 2 iteration(s) in base 10"
echo "132 leads to 363 in 1 iteration(s) in base 10"
echo "231 leads to 363 in 1 iteration(s) in base 10"
echo "330 leads to 363 in 1 iteration(s) in base 10"
echo "363 leads to 363 in 0 iteration(s) in base 10\n"

./palindrome -p 363 -b 10

echo "\ntest : ./palindrome -p 363 -b 10 -imin 6"
echo "need to be  : \n3 leads to 363 in 6 iteration(s) in base 10\n"

./palindrome -p 363 -b 10 -imin 6

echo "\ntest : ./palindrome -p 363 -b 10 -imin 7"
echo "need to be  : \nno solution\n"

./palindrome -p 363 -b 10 -imin 7

echo "\nexecute : make fclean\n"

make fclean
