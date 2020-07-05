class WrapClass:
    def __init__(self, obj):
        self.coreObj = obj

    def wrapped_method1(self, arg1):
        value = "wrapped_method1: arg1=" + str(arg1)
        print(value)
        return value

    def wrapped_method2(self, arg1):
        value = "wrapped_method2: arg1=" + str(arg1)
        print(value)
        return value

    def __getattribute__(self, attr):
        try:
            val = super().__getattribute__(attr)
        except AttributeError:
            val = self.coreObj.__getattribute__(attr)
        if callable(val):
            return decorate(val)
        else:
            return val

def decorate(func):
    def wrapper(*args, **kw):
        print("... Enter decorate ... ")
        value = func(*args, **kw)
        print("... Exit decorate ... ")
        return value
    return wrapper


class coreClass:
    def __init__(self):
        self.coreVariable1 = 0

    def method1(self, arg1):
        value = "method1: arg1=" + str(arg1)
        print(value)
        return value

    def method2(self, arg1):
        value = "method2: arg1=" + str(arg1)
        print(value)
        return value


if __name__ == "__main__":
    coreC = coreClass()
    wrappedC = WrapClass(coreC)
    wrappedC.wrapped_method2(1)
    wrappedC.method1("b")
    coreC.method2("c")
