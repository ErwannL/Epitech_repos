def text_to_binary(input_text):
    binary_result = ""
    for char in input_text:
        if char == ' ':
            binary_result += '0'
        elif char == '\t':
            binary_result += '1'
        elif char == 'o':
            binary_result += ' '
    return binary_result

def binary_to_txt(binary_input):
    try:
        decimal_value = int(binary_input, 2)
    except ValueError as e:
        return -1
    char_result = chr(decimal_value)
    return char_result

def main():
    input_file = open('valerian_creds.txt', 'r')
    lines = input_file.readlines()

    for line in lines:
        binary_output = text_to_binary(line)
        txt_output = binary_to_txt(binary_output)
        if txt_output != -1:
            print(txt_output, end="")
        else:
            print("")

if __name__ == "__main__":
    main()
