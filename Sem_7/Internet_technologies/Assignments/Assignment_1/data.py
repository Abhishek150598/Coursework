class Data:
    def __init__(self):
        self.keyValueMap = {}

    def putData(self, key, value, owner):
        # If key is already present give error
        if key in self.keyValueMap.keys():
            return "Key already in use!"

        # Else put the key-value pair in map along with owner
        self.keyValueMap[key] = {
            'value': value,
            'owner': owner
        }

        return "Key-value pair entered successfully"

    # Function to check whether key exists
    def keyExists(self, key):
        return key in self.keyValueMap.keys()

    # Function to return owner of key
    def getOwner(self, key):
        return self.keyValueMap[key]['owner']

    # Function to return data corresponding to key
    def getData(self, key):
        return self.keyValueMap[key]['value']
