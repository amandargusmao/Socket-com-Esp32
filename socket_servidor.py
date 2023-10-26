import socket
from colorama import Fore, Back, Style, init

init(autoreset=True)

servidor = "172.61.4.1"
porta = 3000 
tcp = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
origem_conexao = (servidor, porta)
tcp.bind(origem_conexao)
tcp.listen(1)

while True:
    con, client = tcp.accept() 
    print("\nIP e porta do cliente:", client) 
    
    dados_cliente = con.recv(1024)
    dados_convertidos = int(dados_cliente) 
        
    if dados_convertidos >= 930:
        print (Fore.RED + "\nGás detectado!")
        print (Fore.YELLOW + "Leitura do sensor: " + Fore.RED + "{}".format(dados_convertidos))
    else:
        print (Fore.GREEN + "\nAmbiente seguro")
        print (Fore.YELLOW + "Leitura do sensor: " + Fore.GREEN + "{}".format(dados_convertidos))
                
    print(" ")
