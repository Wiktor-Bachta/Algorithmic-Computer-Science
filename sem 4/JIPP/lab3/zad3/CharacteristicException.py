class CharacteristicException(Exception):
    def __init__(self, message="CharacteristicException"):
        self.message = message
        super().__init__(self.message)