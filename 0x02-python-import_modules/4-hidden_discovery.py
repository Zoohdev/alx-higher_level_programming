#!/usr/bin/python3.8

import subprocess

def main():
    subprocess.run(["uncompyle6", "-o", ".", "hidden_4.pyc"])

    with open("hidden_4.py", "r") as f:
        lines = f.readlines()
        for line in lines:
            line = line.strip()
            if line and not line.startswith("__"):
                print(line.split()[1])

    subprocess.run(["rm", "hidden_4.py"])

if __name__ == "__main__":
    main()

