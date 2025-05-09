clear

echo "\nmake re\n"

make re

echo "\ntest with all numbers : \n"

echo "./crocus -n 0123456789 | cat -e\n"

./crocus -n 0123456789 | cat -e

echo "\ntest with one numbers : \n"

echo "./crocus -n 1 | cat -e\n"

./crocus -n 1 | cat -e

echo "\ntest return value with one numbers : \n"

echo "./crocus -n 1 ; echo $?\n"

./crocus -n 1 ; echo $?

echo "\ntest with a string : \n"

echo "./crocus -s "astek" -n "0453" | cat -e\n"

./crocus -s "astek" -n "0453" | cat -e

echo "\ntest with a string in numbers : \n"

echo "./crocus -n "astek" ; echo $?\n"

./crocus -n "astek" ; echo $?

echo "\ntest with non printable char (ex : tab): \n"

echo "./crocus -n 01789623698420 -s \tHello\t\t how are you?\t ; echo $?\n"

./crocus -n 01789623698420 -s "$(echo -ne "\tHello\t\t how are you?\t ")" ; echo $?

echo "\ntest with no arguments: \n"

echo "./crocus ; echo $?\n"

./crocus ; echo $?

echo "\nmake fclean\n"

make fclean
