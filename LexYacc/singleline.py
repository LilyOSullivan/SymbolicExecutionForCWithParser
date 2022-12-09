import sys
code = sys.stdin.read()
code = repr(code)
code = code[1:-1]
code = code.replace('"', r'\"')
print(code)

# Write hello to a file
with open("temp.txt", "w") as file:
    file.write(code)
# print(repr(sys.stdin.read()).replace('"','\"').strip("'"))