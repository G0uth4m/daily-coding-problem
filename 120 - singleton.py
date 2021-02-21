"""
This problem was asked by Microsoft.

Implement the singleton pattern with a twist. First, instead of storing one instance, store two instances. 
And in every even call of getInstance(), return the first instance and in every odd call of getInstance(), return the second instance.
"""

class Singleton:
    _instance = None

    def __init__(self):
        if Singleton._instance is None:
            Singleton._instance = self

    @staticmethod
    def getInstance():
        if Singleton._instance is None:
            Singleton()
        return Singleton._instance


class Singleton2:
    _instance1 = None
    _instance2 = None
    _is_even_call = False

    def __init__(self):
        if Singleton2._instance1 is None:
            Singleton2._instance1 = self
        elif Singleton2._instance2 is None:
            Singleton2._instance2 = self
    
    @staticmethod
    def getInstance():
        if not Singleton2._is_even_call:
            Singleton2._is_even_call = True
            return Singleton2._instance2
        else:
            Singleton2._is_even_call = False
            return Singleton2._instance1

a = Singleton2()
b = Singleton2()

c = a.getInstance()
d = a.getInstance()
e = a.getInstance()
f = a.getInstance()

print(c)
print(d)
print(e)
print(f)