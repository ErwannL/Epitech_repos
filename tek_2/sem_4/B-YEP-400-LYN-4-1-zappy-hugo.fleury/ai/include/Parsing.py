##
## EPITECH PROJECT, 2023
## B-YEP-400-LYN-4-1-zappy-hugo.fleury
## File description:
## Parsing
##

from sys import *

class Parsing:
    def __init__(self):
        self.args = {}
        self.parse_args()

    def print_usage(self):
        print("USAGE: ./zappy_ai -p port -n name -h machine")
        print("\tport\t\tis the port number")
        print("\tname\t\tis the name of the team")
        print("\tmachine\t\tis the name of the machine; localhost by default")

    def parse_args(self):
        if "-help" in argv:
            self.print_usage()
            exit(0)
        if len(argv) < 5:
            print("Missing arguments.", file=stderr)
            self.print_usage()
            exit(84)
        for i in range(1, len(argv), 2):
            arg = argv[i]
            value = argv[i+1]
            if arg == "-p":
                try:
                    self.args["port"] = int(value)
                except:
                    print("Invalid port number.", file=stderr)
                    exit(84)
            elif arg == "-n":
                self.args["name"] = value
            elif arg == "-h":
                self.args["machine"] = value
            else:
                print(f"Unknown argument: {arg}.", file=stderr)
                self.print_usage()
                exit(84)

        if "port" not in self.args:
            print("Missing argument: port.", file=stderr)
            exit(84)
        if "name" not in self.args:
            print("Missing argument: name.", file=stderr)
            exit(84)
