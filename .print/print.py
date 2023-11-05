import os
import argparse

def read_file(filename, write_filename="print.md"):
    with open(filename, 'r') as f:
        text = f.read()
    with open(write_filename, 'a') as f:
        # f.write("\n\\pagebreak\n")
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
            if not file.startswith("."):
                filename = os.path.join(folder, file)
                read_file(filename)
                print(filename)

with open(".print/print_list.txt", 'r') as f:
    print_list = f.read()
for filename in print_list.split('\n'):
    if filename != '':
        read_file(filename + '.cpp', write_filename="print_large.md")
        print(filename)
