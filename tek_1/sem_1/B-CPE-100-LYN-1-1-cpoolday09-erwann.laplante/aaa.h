struct info_param
{
    int length; // parameter 's length
    char *str; // parameter 's address
    char *copy; // parameter 's copy
    char ** word_array; // the result of my_str_to_word_array(str)
};