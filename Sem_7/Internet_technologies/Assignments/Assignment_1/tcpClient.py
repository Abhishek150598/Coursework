import socket 
import sys

class TCPClient:
    def __init__(self, ip):
        self.host = socket.gethostname()
        self.port = 2004
        self.client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM) 
        self.client_socket.connect((self.host, self.port))
        print("Starting client with IP address: " + ip)
        self.client_socket.send(ip.encode())
        self.startClient()

    def startClient(self):
        request = input("? ")
        while True:
            self.client_socket.send(request.encode())
            if request == 'quit':
                break    
            data = self.client_socket.recv(2048).decode()
            print(data)
            request = input("? ")

        self.client_socket.close() 

if __name__ == '__main__':
    TCPClient(sys.argv[1])