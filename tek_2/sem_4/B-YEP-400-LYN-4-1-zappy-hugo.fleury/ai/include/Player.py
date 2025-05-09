##
## EPITECH PROJECT, 2023
## B-YEP-400-LYN-4-1-zappy-hugo.fleury
## File description:
## Player
##

from Socket import *
from re import *
from rules import *
from os import *
from random import *

def verify_format(str: str):
    # Vérifier si la chaîne correspond à "CLIENT-NUM\n"
    if match(r'^\d+\n$', str):
        return 1
    # Vérifier si la chaîne correspond à "CLIENT-NUM\nX Y\n"
    elif match(r'^\d+\n\d+( \d+)*\n$', str):
        return 3
    else:
        return 84

class Player:
    def __init__(self):
        self.socket = None
        self.backpack = {
            "food": 9,
            "linemate": 0,
            "deraumere": 0,
            "sibur": 0,
            "mendiane": 0,
            "phiras": 0,
            "thystame": 0
        }
        self.status = "active"
        self.timer = 126
        self.name = ""
        self.level = 1
        self.son = 0
        self.pid = randint(0, 1000)
        self.loop = 0
        self.emetter = 0
        self.nomove = 0
        self.info = 0

    def connect(self, args):
        try:
            port = int(args.get("port"))
        except:
            print("Invalid port", file=stderr)
            return 84
        try:
            self.socket = Socket(args.get("machine", "localhost"), port)
        except:
            print("Error in connection", file=stderr)
            return 84
        if (self.socket.connect() == 84):
            return 84
        self.rcv_msg()
        self.send_msg(args.get("name"))
        x = self.rcv_msg()
        y = verify_format(x)
        if y == 84:
            return 84
        elif y == 1:
            self.rcv_msg()
        return 0

    def send_msg(self, msg):
        print("send at " + str(self.pid) + " and lvl = " + str(self.level) + " : " + msg)
        self.socket.send_msg(msg)

    def receive_mess(self, msg : str):
        if (self.backpack["food"] <= 5):
            return msg
        msg = msg.replace('message ', '')
        msg = msg.replace(' ', '', 1)
        msg = msg.split(",")
        dir = ord(msg[0][0]) - 48
        print("dir is = " + msg[0][0] + " and lvl is = " + msg[1][0])
        if (self.level == ord(msg[1][0]) - 48 and self.son != 0):
            self.handle_broadcast(dir)
        return msg

    def rcv_msg(self):
        msg = self.socket.rcv_msg()
        while (len(msg) == 0 or msg[-1] != '\n'):
            msg = msg + self.socket.rcv_msg()
        if (msg[0] == 'm' and msg[-1] == '\n'):
                if (self.nomove == 0):
                    self.receive_mess(msg)
        if (msg[0] == 'C'):
            self.level = int(msg[-2])
            print(str(self.pid) + msg, file=stderr)
            self.status = "active"
            self.nomove = 0
            self.emetter = 0
        print("rcv at " + str(self.pid) + " and lvl = " + str(self.level) + ": " + msg, end="")
        return msg

    def wait_message(self, string : str, output : str):
        for mess in string.split(","):
            if (mess[0] == output[0]):
                return output
        rep = self.rcv_msg()
        return self.wait_message(str, rep)

    def disconnect(self):
        self.socket.disconnect()

    def dead(self):
        print( str(self.pid) + "  UR DEAD FUCKING EXPLAIN URSELF : Status =" + self.status, file=stderr)
        for key, value in self.backpack.items():
            print(key + ": " + str(value))
        exit()

    def send_forward(self):
        self.send_msg("Forward")
        self.timer -= 7
        while self.timer <= 0:
            self.backpack["food"] -= 1
            self.timer += 126
        while (True):
            rep = self.rcv_msg()
            if (rep == "ok\n"):
                break
            if (rep == "dead\n"):
                self.dead()
                break
        return rep

    def send_right(self):
        self.send_msg("Right")
        self.timer -= 7
        while self.timer <= 0:
            self.backpack["food"] -= 1
            self.timer += 126
        while (True):
            rep = self.rcv_msg()
            if (rep == "ok\n"):
                break
            if (rep == "dead\n"):
                self.dead()
                break
        return rep

    def send_left(self):
        self.send_msg("Left")
        self.timer -= 7
        while self.timer <= 0:
            self.backpack["food"] -= 1
            self.timer += 126
        while (True):
            rep = self.rcv_msg()
            if (rep == "ok\n"):
                break
            if (rep == "dead\n"):
                self.dead()
                break
        return rep

    def send_look(self):
        self.send_msg("Look")
        self.timer -= 7
        while self.timer <= 0:
            self.backpack["food"] -= 1
            self.timer += 126
        rep = self.rcv_msg()
        while (len(rep) == 0 or rep[2] != 'p'):
            rep = self.rcv_msg()
        return rep

    def send_inventory(self):
        self.send_msg("Inventory")
        self.timer -= 1
        while self.timer <= 0:
            self.backpack["food"] -= 1
            self.timer += 126
        rep = self.rcv_msg()
        while (len(rep) == 0 or rep[2] != 'f'):
            rep = self.rcv_msg()
        return rep

    def send_broadcast(self, msg):
        self.send_msg(f"Broadcast {msg}")
        self.timer -= 7
        while self.timer <= 0:
            self.backpack["food"] -= 1
            self.timer += 126
        while (True):
            rep = self.rcv_msg()
            if (rep == "ok\n"):
                break
            if (rep == "dead\n"):
                self.dead()
                break
        return rep

    def send_unused_slots(self):
        self.send_msg("Connect_nbr")
        while (True):
            print("in it")
            rep = self.rcv_msg()
            if (ord(rep[0]) >= 48 and ord(rep[0]) <= 57):
                break
            if (rep == "dead\n"):
                self.dead()
                break
        return rep

    def send_spawn_friend(self):
        self.send_msg("Fork")
        self.timer -= 42
        while self.timer <= 0:
            self.backpack["food"] -= 1
            self.timer += 126
        while (True):
            rep = self.rcv_msg()
            if (rep == "ok\n"):
                break
            if (rep == "dead\n"):
                self.dead()
                break
        return rep

    def send_take(self, obj):
        self.send_msg(f"Take {obj}")
        self.timer -= 7
        while self.timer <= 0:
            self.backpack["food"] -= 1
            self.timer += 126
        while (True):
            rep = self.rcv_msg()
            if (rep == "ok\n" or rep == "ko\n"):
                break
            if (rep == "dead\n"):
                self.dead()
                break
        if rep == "ok\n":
            self.backpack[obj] += 1
        return rep

    def send_drop(self, obj):
        self.send_msg(f"Set {obj}")
        self.timer -= 7
        while self.timer <= 0:
            self.backpack["food"] -= 1
            self.timer += 126
        while (True):
            rep = self.rcv_msg()
            if (rep == "ok\n" or rep == "ko\n"):
                break
            if (rep == "dead\n"):
                self.dead()
                break
        if rep == "ok\n":
            self.backpack[obj] -= 1
        return rep

    def send_evolve(self):
        self.send_msg("Incantation")
        self.timer -= 300
        while self.timer <= 0:
            self.backpack["food"] -= 1
            self.timer += 126
        while (True):
            rep = self.rcv_msg()
            if (rep[0] == 'E'):
                break
            if (rep == "ko\n"):
                return rep
            if (rep == "dead\n"):
                self.dead()
                break
        while (True):
            rep = self.rcv_msg()
            if (rep[0] == 'C'):
                break
            if (rep == "ko\n"):
                return rep
            if (rep == "dead\n"):
                self.dead()
                break
        return rep

    def take_position_player(self, seen: str, only_food: bool = False):
        try:
            for object in seen.split(",")[0].split(" "):
                if object == "" or object == "[" or object == "]" or object == "player":
                    continue
                elif object == "food" or (self.backpack[object] < max_needed[object] and only_food is False):
                    self.send_take(object)
            return self
        except:
            return self
    
    def move(self, case_to_go: int):
        my_complement = None
        my_x = None

        for x in range(9):
            terme = x ** 2 + x
            complement = case_to_go - terme

            if my_complement is None or abs(complement) <= abs(my_complement):
                my_complement = complement
                my_x = x

        for _ in range(my_x):
            rep = self.send_forward()
            seen = self.send_look()
            self.take_position_player(seen)
        if my_complement < 0:
            rep = self.send_left()
        if my_complement > 0:
            rep = self.send_right()
        for _ in range(abs(my_complement)):
            rep = self.send_forward()
            seen = self.send_look()
            self.take_position_player(seen)

    def looking_for_ress(self, seen: list, list_need: dict, count: int):
        cases = seen.strip("[] ").split(", ")
        for i, case in enumerate(cases):
            case = case.split()
            for need in list_need:
                if need in case:
                    self.move(i)
                    seen = self.send_look()
                    self.take_position_player(seen)
                    return list_need
        res = self.send_right()

        count = count + 1
        if (count == 4):
            count = 0
            res = self.send_left()
            for i in range(self.level + 1):
                rep = self.send_forward()
        seen = self.send_look()
        return self.looking_for_ress(seen, list_need, count)

    def handle_broadcast(self, dir: int):
        print(str(self.pid) +" &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&")
        if self.status == "active":
            self.status = "tracking"
        if dir == 1:
            self.send_forward()
            seen = self.send_look()
            self.take_position_player(seen, True)
        elif dir == 2:
            self.send_forward()
            seen = self.send_look()
            self.take_position_player(seen, True)
            self.send_left()
            self.send_forward()
            seen = self.send_look()
            self.take_position_player(seen, True)
            self.send_right()
        elif dir == 3:
            self.send_left()
            self.send_forward()
            seen = self.send_look()
            self.take_position_player(seen, True)
            self.send_right()
        elif dir == 4:
            self.send_left()
            self.send_forward()
            seen = self.send_look()
            self.take_position_player(seen, True)
            self.send_left()
            self.send_forward()
            seen = self.send_look()
            self.take_position_player(seen, True)
            self.send_left()
            self.send_left()
        elif dir == 5:
            self.send_left()
            self.send_left()
            self.send_forward()
            seen = self.send_look()
            self.take_position_player(seen, True)
            self.send_left()
            self.send_left()
        elif dir == 6:
            self.send_right()
            self.send_forward()
            seen = self.send_look()
            self.take_position_player(seen, True)
            self.send_right()
            self.send_forward()
            seen = self.send_look()
            self.take_position_player(seen, True)
            self.send_right()
            self.send_right()
        elif dir == 7:
            self.send_right()
            self.send_forward()
            seen = self.send_look()
            self.take_position_player(seen, True)
            self.send_left()
        elif dir == 8:
            self.send_forward()
            seen = self.send_look()
            self.take_position_player(seen, True)
            self.send_right()
            self.send_forward()
            seen = self.send_look()
            self.take_position_player(seen, True)
            self.send_left()
        else:
            return 0
        return 84