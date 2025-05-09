##
## EPITECH PROJECT, 2022
## B-SYN-200-LYN-2-1-palindrome-erwann.laplante
## File description:
## test_p_flag
##

clear

make

echo "[START]\n"

echo "\nneed to be :"
echo "1 leads to 1 in 0 iteration(s) in base 2\n"

./palindrome -p 1 -b 2

echo "\nneed to be :"
echo "invalid argument\n"

./palindrome -p 2 -b 2

echo "\nneed to be :"
echo "1 leads to 3 in 2 iteration(s) in base 2
2 leads to 3 in 1 iteration(s) in base 2
3 leads to 3 in 0 iteration(s) in base 2\n"

./palindrome -p 3 -b 2

echo "\nneed to be :"
echo "invalid argument\n"

./palindrome -p 4 -b 2

echo "\nneed to be :"
echo "4 leads to 5 in 1 iteration(s) in base 2
5 leads to 5 in 0 iteration(s) in base 2\n"

./palindrome -p 5 -b 2

echo "\nneed to be :"
echo "invalid argument\n"

./palindrome -p 6 -b 2

echo "\nneed to be :"
echo "7 leads to 7 in 0 iteration(s) in base 2\n"

./palindrome -p 7 -b 2

echo "\nneed to be :"
echo "invalid argument\n"

./palindrome -p 8 -b 2

echo "\nneed to be :"
echo "1 leads to 9 in 4 iteration(s) in base 2
2 leads to 9 in 3 iteration(s) in base 2
3 leads to 9 in 2 iteration(s) in base 2
6 leads to 9 in 1 iteration(s) in base 2
8 leads to 9 in 1 iteration(s) in base 2
9 leads to 9 in 0 iteration(s) in base 2\n"

./palindrome -p 9 -b 2

echo "\nneed to be :"
echo "invalid argument\n"

./palindrome -p 10 -b 2

echo "\n[END]\n"

make fclean
