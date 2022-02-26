import os

def read_file(filename):
    with open(filename, 'r') as f:
        text = f.read()
    with open("print.md", 'a') as f:
        f.write("\n\\pagebreak\n")
        f.write("\n# " + filename + "\n")
        f.write("```cpp\n")
        f.write(text)
        f.write("\n```")

with open("README.md", 'r') as f:
    readme = f.read()
with open("print.md", 'w') as f:
    f.write(readme)
    f.write("\n")
for folder in os.listdir():
    if os.path.isdir(folder) and not folder.startswith("."):
        for file in os.listdir(folder):
            filename = os.path.join(folder, file)
            read_file(filename)
            print(filename)
