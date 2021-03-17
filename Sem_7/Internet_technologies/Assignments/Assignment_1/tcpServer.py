import socket 
from threading import Thread 
from data import Data
dataStore = Data()

class ClientThread(Thread): 
    def __init__(self, conn, ip, designation): 
        Thread.__init__(self) 
        self.conn = conn
        self.ip = ip 
        self.designation = designation
 
    def run(self): 
        while True : 
            data = self.conn.recv(2048).decode()
            if data == 'quit':
                print("Client with IP " + self.ip + " has left")
                break
            response = self.handleRequest(data)
            self.conn.send(response.encode())
        
        self.conn.close()

    def handleRequest(self, data):
        request = data.split(' ')

        # Handling put requests
        if request[0] == 'put' and len(request) == 3:
            key = request[1]
            value = request[2]
            return dataStore.putData(key, value, self.ip)
        
        # Handling get requests
        elif request[0] == 'get' and len(request) == 2:
            key = request[1]
            # Check if key exists in data store
            if not dataStore.keyExists(key):
                return "Invalid key!"
            else:
                # If manager, anyone's data can be accessed
                if self.designation == 'manager': 
                    return dataStore.getData(key)
                
                else:
                    owner = dataStore.getOwner(key)
                    # Check if the owner is requesting the data
                    if owner == self.ip:
                        return dataStore.getData(key)
                    else: 
                        return "Unauthorised client"

        # Handling invalid requests:
        else :
            return "Invalid request"

class TCPServer:
    def __init__(self):
        self.ip = '0.0.0.0'
        self.port = 2004 
        self.server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM) 
        self.server_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1) 
        self.server_socket.bind((self.ip, self.port)) 
        self.startServer()

    # Function which accepts new connections and creates client threads
    def startServer(self):
        print("Starting server...")
        self.threads = []

        while True:
            # Wait for clients to establish connection
            self.server_socket.listen(4)

            # Accept connection request and show message
            (conn, address) = self.server_socket.accept() 
            ip = conn.recv(2048).decode()
            print("New TCP client with IP " + ip + " joined")

            # Ask for designation of the new client
            choice = input("Set designation: (1 for manager, 2 for guest) ")
            designation = 'manager' if choice == '1' else 'guest'
            
            # Create a thread for new client and run the thread
            new_thread = ClientThread(conn, ip, designation)
            new_thread.start()
            self.threads.append(new_thread)

        for thread in self.threads:
            thread.join()

if __name__ == '__main__':
    TCPServer()
        
