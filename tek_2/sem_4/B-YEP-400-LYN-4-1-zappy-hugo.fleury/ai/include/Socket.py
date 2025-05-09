##
## EPITECH PROJECT, 2023
## B-YEP-400-LYN-4-1-zappy-hugo.fleury
## File description:
## Socket
##

from socket import *
from sys import *

class Socket:

    # Init
    def __init__(self, host, port):
        self.socket = None
        self.host = host
        self.port = port
        self.temp_buffer = ""

    # Connect
    def connect(self):
        self.socket = socket(AF_INET, SOCK_STREAM)
        try:
            self.socket.connect((self.host, self.port))
        except:
            print("Error serveur connection", file=stderr)
            return 84
        return 0

    # Disconnect
    def disconnect(self):
        self.socket.close()

    # Send Message
    def send_msg(self, msg):
        self.socket.send(str.encode(msg + "\n"))

    def get_answer(self):
        if self.temp_buffer != "" and "\n" in self.temp_buffer:
            index = self.temp_buffer.index("\n") + 1
            substr = self.temp_buffer[:index]
            self.temp_buffer = self.temp_buffer[index:]
            print("got it ----" + self.temp_buffer)
            return substr
        else:
            return ""

    # Receive Message
    def rcv_msg(self):
        msg = self.get_answer()
        if msg != "":
            return msg
        else:
            self.temp_buffer += self.socket.recv(2048).decode()
            return ""
