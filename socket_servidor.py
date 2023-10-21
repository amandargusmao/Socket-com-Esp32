import socket
from colorama import Fore, Back, Style, init

init(autoreset=True)

HOST = "172.61.3.150"
PORT = 3000 
tcp = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
orig = (HOST, PORT)
tcp.bind(orig)
tcp.listen(1)

while True:
    con, client = tcp.accept() 
    print("\nIP e porta do cliente:", client) 
    dados = con.recv(1024)
    conversao = int(dados, 16)
    dados_int = int(conversao / 256) * 100 
    
    if dados_int > 1000:
        print (Fore.RED + "\nGás detectado!")
        print (Fore.YELLOW + "\nConcentração de gás: " + Fore.RED + "{} ppm".format(int(dados_int / 100) * 10))
        print (Fore.YELLOW + "Leitura do sensor: " + Fore.RED + "{}".format(dados_int))
    else:
        print (Fore.GREEN + "\nAmbiente seguro")
        print (Fore.YELLOW + "Leitura do sensor: " + Fore.GREEN + "{}".format(dados_int))
                
    print(" ")
