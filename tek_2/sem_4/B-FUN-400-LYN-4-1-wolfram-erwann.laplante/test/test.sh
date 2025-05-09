##
## EPITECH PROJECT, 2023
## B-FUN-400-LYN-4-1-wolfram-erwann.laplante
## File description:
## test
##

echo -e "make"
make

echo -e "\ntest 0 args => ./wolfram"
./wolfram &> /dev/null
ret=$?
if [ $ret -eq 84 ]; then
    echo "[OK]"
else
    echo "[KO] -> 0 args need return 84"
fi

echo -e "\ntest 1 args => ./wolfram a"
./wolfram a &> /dev/null
ret=$?
if [ $ret -eq 84 ]; then
    echo "[OK]"
else
    echo "[KO] -> 1 args need return 84"
fi

echo -e "\ntest bad arg => ./wolfram a 0"
./wolfram a 0 &> /dev/null
ret=$?
if [ $ret -eq 84 ]; then
    echo "[OK]"
else
    echo "[KO] -> bad arg need return 84"
fi

echo -e "\ntest bad number => ./wolfram a b"
./wolfram a b &> /dev/null
ret=$?
if [ $ret -eq 84 ]; then
    echo "[OK]"
else
    echo "[KO] -> bad number need return 84"
fi

echo -e "\ntest bad rule => ./wolfram --rule 999"
./wolfram --rule 999 &> /dev/null
ret=$?
if [ $ret -eq 84 ]; then
    echo "[OK]"
else
    echo "[KO] -> bad rule need return 84"
fi

echo -e "\ntest no rule => ./wolfram --lines 10"
./wolfram --lines 10 &> /dev/null
ret=$?
if [ $ret -eq 84 ]; then
    echo "[OK]"
else
    echo "[KO] -> no rule need return 84"
fi

echo -e "\ncreate got directory"
mkdir test/got/

echo -e "\ninit test sujet"
./wolfram --rule 30 --lines 20 | cat -e > test/got/init_test.txt
diff test/got/init_test.txt test/expected/init_test.txt
ret=$?
if [ $ret -eq 0 ]; then
    echo "[OK]"
else
    echo "[KO] -> init test different"
fi

echo -e "\nstart test sujet"
./wolfram --rule 90 --lines 20 --start 100 | cat -e > test/got/start_test.txt
diff test/got/start_test.txt test/expected/start_test.txt
ret=$?
if [ $ret -eq 0 ]; then
    echo "[OK]"
else
    echo "[KO] -> start test different"
fi

echo -e "\nmove test sujet"
./wolfram --rule 30 --lines 10 --move 10 | cat -e > test/got/move_test.txt
diff test/got/move_test.txt test/expected/move_test.txt
ret=$?
if [ $ret -eq 0 ]; then
    echo "[OK]"
else
    echo "[KO] -> move test different"
fi

echo -e "\nremove got directory"
rm -rf test/got/

echo -e "\nmake fclean"
make fclean
