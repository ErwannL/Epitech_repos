##
## EPITECH PROJECT, 2022
## B-SYN-200-LYN-2-1-palindrome-erwann.laplante
## File description:
## test_p_flag
##

clear

make

echo "\n[START]\n"

echo "[START B2]"

echo "\nneed to be :"
echo "1 leads to 1 in 0 iteration(s) in base 2\n"

./palindrome -n 1 -b 2

echo "\nneed to be :"
echo "2 leads to 3 in 1 iteration(s) in base 2\n"

./palindrome -n 2 -b 2

echo "\nneed to be :"
echo "3 leads to 3 in 0 iteration(s) in base 2\n"

./palindrome -n 3 -b 2

echo "\nneed to be :"
echo "4 leads to 5 in 1 iteration(s) in base 2\n"

./palindrome -n 4 -b 2

echo "\nneed to be :"
echo "5 leads to 5 in 0 iteration(s) in base 2\n"

./palindrome -n 5 -b 2

echo "\nneed to be :"
echo "6 leads to 9 in 1 iteration(s) in base 2\n"

./palindrome -n 6 -b 2

echo "\nneed to be :"
echo "7 leads to 7 in 0 iteration(s) in base 2\n"

./palindrome -n 7 -b 2

echo "\nneed to be :"
echo "8 leads to 9 in 1 iteration(s) in base 2\n"

./palindrome -n 8 -b 2

echo "\nneed to be :"
echo "9 leads to 9 in 0 iteration(s) in base 2\n"

./palindrome -n 9 -b 2

echo "\nneed to be :"
echo "10 leads to 15 in 1 iteration(s) in base 2\n"

./palindrome -n 10 -b 2

echo "\n[END B2]\n"

echo "[START B5]"

echo "\nneed to be :"
echo "1 leads to 1 in 0 iteration(s) in base 5\n"

./palindrome -n 1 -b 5

echo "\nneed to be :"
echo "2 leads to 2 in 0 iteration(s) in base 5\n"

./palindrome -n 2 -b 5

echo "\nneed to be :"
echo "3 leads to 3 in 0 iteration(s) in base 2\n"

./palindrome -n 3 -b 5

echo "\nneed to be :"
echo "4 leads to 4 in 0 iteration(s) in base 5\n"

./palindrome -n 4 -b 5

echo "\nneed to be :"
echo "5 leads to 6 in 1 iteration(s) in base 5\n"

./palindrome -n 5 -b 5

echo "\nneed to be :"
echo "6 leads to 6 in 0 iteration(s) in base 5\n"

./palindrome -n 6 -b 5

echo "\nneed to be :"
echo "7 leads to 7 in 0 iteration(s) in base 5\n"

./palindrome -n 7 -b 5

echo "\nneed to be :"
echo "8 leads to 24 in 1 iteration(s) in base 5\n"

./palindrome -n 8 -b 5

echo "\nneed to be :"
echo "9 leads to 36 in 2 iteration(s) in base 5\n"

./palindrome -n 9 -b 5

echo "\nneed to be :"
echo "10 leads to 12 in 1 iteration(s) in base 5\n"

./palindrome -n 10 -b 5

echo "\n[END B5]"

echo "\n[END]\n"

make fclean
