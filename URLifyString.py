def URLify(string):
    val = string.replace(" ", "%20")
    return val

string = "Mr Vishal Ambavade"
print(URLify(string))