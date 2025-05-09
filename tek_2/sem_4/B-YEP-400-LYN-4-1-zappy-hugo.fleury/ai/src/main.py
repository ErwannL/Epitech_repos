##
## EPITECH PROJECT, 2023
## B-YEP-400-LYN-4-1-zappy-hugo.fleury
## File description:
## main
##

from Parsing import *
from Player import *
from rules import *
import select
import os
import time

debug = False

def take_position(seen: str, player: Player):
    if (seen[0] != '[' or seen[-1] != '\n'):
        seen = player.send_look()
    for object in seen.split(",")[0].split(" "):
        if object == "" or object == "[" or object == "]" or object == "player":
            continue
        elif object == "food" or player.backpack[object] < max_needed[object]:
            player.send_take(object)
    return player

def are_you_dead(str: str):
    if str == "dead\n":
        print("You are dead looser!")
        #exit(84)

def printData(parser: Parsing):
    print('Port:', parser.args.get("port"))
    print('Name:', parser.args.get("name"))
    print('Machine:', parser.args.get("machine", "localhost"))

def check_evolving(player: Player):
    dict = {}
    for key, value in player.backpack.items():
        if (needed_to_evolve[player.level][key] > value):
            dict[key] = needed_to_evolve[player.level][key] - player.backpack[key]
    if debug == True : print("DEBUG => 4 - est ce que j'ai les ressources ?")
    if debug == True : print(f"DEBUG => need : {dict}")
    return dict

def move(player: Player, case_to_go: int):
    my_complement = None
    my_x = None

    for x in range(9):
        terme = x ** 2 + x
        complement = case_to_go - terme

        if my_complement is None or abs(complement) <= abs(my_complement):
            my_complement = complement
            my_x = x

    if debug == True : print(f"DEBUG => move : {my_x, my_complement}")
    for _ in range(my_x):
        rep = player.send_forward()
        are_you_dead(rep)
        seen = player.send_look()
        are_you_dead(seen)
        take_position(seen, player)
    if my_complement < 0:
        rep = player.send_left()
        are_you_dead(rep)
    if my_complement > 0:
        rep = player.send_right()
        are_you_dead(rep)
    for _ in range(abs(my_complement)):
        rep = player.send_forward()
        are_you_dead(rep)
        seen = player.send_look()
        are_you_dead(seen)
        take_position(seen, player)

def looking_for_ress(player: Player, seen: list, list_need: dict, count: int):
    cases = seen.strip("[] ").split(", ")
    for i, case in enumerate(cases):
        case = case.split()
        for need in list_need:
            if need in case:
                move(player, i)
                seen = player.send_look()
                take_position(seen, player)
                return list_need
    res = player.send_right()

    count = count + 1
    if (count == 4):
        count = 0
        res = player.send_left()
        for i in range(player.level + 1):
            rep = player.send_forward()
    seen = player.send_look()
    return looking_for_ress(player, seen, list_need, count)

def spawn(player: Player, unu : int):
    if (player.backpack["food"] >= 1 and player.level == 2 and unu > 0 and player.son != 1):
        print("--------------------------- New player -------------------------", file=stderr)
        pid = os.fork()
        if (pid == 0):
            rep = player.send_spawn_friend()
            player.son = 1
            return rep
        else:
            start()
            exit()
    return "can't do"

def evolve(player: Player):
    nbr_player = 0

    seen = player.send_look()
    unu = ord(player.send_unused_slots()[0]) - 48
    for object in seen.split(",")[0].split(" "):
        if object == "player":
            nbr_player += 1
    if (player.backpack["food"] >= 2 and player.level == 2 and unu > 0 and player.son != 1):
        spawn(player, unu)
        return
    if (nbr_player != needed_to_evolve[player.level]["player"]):
        player.send_broadcast(str(player.level))
        return
    if (nbr_player > needed_to_evolve[player.level]["player"]):
        player.send_right()
        player.send_forward()
        return
    for obj in player.backpack:
        if obj != "food":
            for _ in range(needed_to_evolve[player.level][obj]):
                player.send_drop(obj)

    print(str(player.pid) + "   #################### WE RE ALL HERE LETS BEGIN, " + str(player.level), file=stderr)
    rep = player.send_evolve()
    if rep == "ko\n":
        print(str(player.pid) + " result => KO Evolution", file=stderr)
        return
    print(str(player.pid) + " result => evolution succeeded", file=stderr)

def synchro_inv(player: Player, inv: str):
    print("\n\n" + inv + "\n\n")
    # Nettoyer la chaîne de caractères en supprimant les caractères indésirables
    inv = inv.replace("[ ", "").replace(" ]", "").replace("\n", "")   

    # Diviser la chaîne de caractères en une liste de paires clé-valeur
    inv = inv.split(", ")   

    for nv in inv:
        # Diviser chaque paire clé-valeur en clé et valeur en utilisant l'espace comme séparateur
        key, value = nv.split(' ')

        # Mettre à jour la clé correspondante dans le dictionnaire avec la nouvelle valeur convertie en entier
        player.backpack[key] = int(value)
        

def checking(player: Player):
    while (player.level != 8):
        synchro_inv(player, player.send_inventory())
        seen = player.send_look()
        nbr_player = 0
        for object in seen.split(",")[0].split(" "):
            if object == "player":
                nbr_player += 1
        if (nbr_player == 1):
            player.nomove = 0
        if (player.backpack["food"] <= 5):
                looking_for_ress(player, seen, {"food" : 3}, 0)
        if (player.status == "active"):
            dir = check_evolving(player)
            if (dir == {}):
                evolve(player)
            else :
                dir = looking_for_ress(player, seen, dir, 0)
        elif (player.status == "tracking"):
            for obj in seen.split(",")[0].split(" "):
                if (obj == player and player.nomove == 0):
                    player.nomove = 1


    print("U WON GG ///////////////////////////////////////////////////////////////////////////")
    return

def start():
    parser = Parsing()
    printData(parser)

    player = Player()
    if player.connect(parser.args) == 84:
        exit(84)

    print(player.backpack)

    checking(player)

    player.disconnect()
    exit(0)

if __name__ == '__main__':
    start()
