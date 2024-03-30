import subprocess
import os
import time


BLUE = '\033[94m'
GREEN = '\033[92m'
RED = '\033[91m'
RESET = '\033[0m'

def usleep(mlsec):
    sec = mlsec / 1000000.0
    time.sleep(sec)

def check_basic():
    answer = True
    usleep(100000)
    print(f"{BLUE}=== Basic test ==={RESET}")
    cmd = './pipex file1 cat "wc -l" file2'
    cmd2 = './pipex file1 cat "wc -c" file2'
    cmd3 = './pipex file1 cat "wc -w" file2'
    cmd4 = './pipex file1 "ls -a" "wc -l" file2'
    cmd5 = './pipex file1 "ls -l" "wc -c" file2'
    r1 = subprocess.run("ls -a | wc -l", shell=True, capture_output=True, text=True)
    r2 = subprocess.run("ls -l | wc -c", shell=True, capture_output=True, text=True)
    subprocess.run(cmd, shell=True)
    
    with open("file2", "r") as file:
        str = file.read().strip()

    if str == "10":
        usleep(50000)
        print(f"{GREEN}1.[OK]{RESET}")
    else:
        usleep(50000)
        print(f"{RED}1.[KO]{RESET}")
        answer = False
    subprocess.run(cmd2, shell=True)
    with open("file2", "r") as file:
        str = file.read().strip()
    if str == "49":
        usleep(50000)
        print(f"{GREEN}2.[OK]{RESET}")
    else:
        usleep(50000)
        print(f"{RED}2.[KO]{RESET}")
        answer = False
    subprocess.run(cmd3, shell=True)
    with open("file2", "r") as file:
        str = file.read().strip()
    if str == "10":
        usleep(50000)
        print(f"{GREEN}3.[OK]{RESET}")
    else:
        usleep(50000)
        print(f"{RED}3.[KO]{RESET}")
        answer = False
    subprocess.run(cmd4, shell=True)
    with open("file2", "r") as file:
        str = file.read().strip()
    if str == r1.stdout.strip():
        usleep(50000)
        print(f"{GREEN}4.[OK]{RESET}")
    else:
        usleep(50000)
        print(f"{RED}4.[KO]{RESET}")
        answer = False
    subprocess.run(cmd5, shell=True)
    with open("file2", "r") as file:
        str = file.read().strip()
    if str == r2.stdout.strip():
        usleep(50000)
        print(f"{GREEN}5.[OK]{RESET}")
    else:
        usleep(50000)
        print(f"{RED}5.[KO]{RESET}")
        answer = False
    
    return answer

def check_file():
    answer = True
    usleep(100000)
    print(f"{BLUE}=== Check file ==={RESET}")
    cmd = './pipex file1 cat "wc -l" file3'
    cmd2 = './pipex file cat "wc -l" file3'
    cmd3 = './pipex file1 f "wc -l" file2'
    cmd4 = './pipex file1 f f file2'
    cmd5 = './pipex file1 f "wc -l" file3'
    cmd6 = './pipex file1 f f file3'
    cmd7 = './pipex file cat f file3'
    cmd8 = './pipex file f f file3'
    rm_cmd = 'rm -f file3'
    subprocess.run(cmd, shell=True)
    if os.path.exists("file3"):
        usleep(50000)
        print(f"{GREEN}1.[OK]{RESET}")
        os.system(rm_cmd)
    else:
        usleep(50000)
        print(f"{RED}1.[KO]{RESET}")
        answer = False
    result = subprocess.run(cmd2, shell=True, capture_output=True, text=True)
    ex_out = "file: No such file or directory"
    pr_out = result.stderr.strip()
    if ex_out == pr_out:
        usleep(50000)
        print(f"{GREEN}2.[OK]{RESET}")
    else:
        usleep(50000)
        print(f"{RED}2.[KO]{RESET}")
        answer = False
    if os.path.exists("file3"):
        usleep(50000)
        print(f"{GREEN}3.[OK]{RESET}")
    else:
        usleep(50000)
        print(f"{RED}2.[KO]{RESET}")
        answer = False
    os.system(rm_cmd)
    r = subprocess.run(cmd3, shell=True, capture_output=True, text=True)
    if r.stderr.strip() == "f: command not found":
        usleep(50000)
        print(f"{GREEN}4.[OK]{RESET}")
    else:
        usleep(50000)
        print(f"{RED}4.[KO]{RESET}")
        answer = False
    with open("file2", "r") as file:
        str = file.read().strip()
    if str == "0":
        usleep(50000)
        print(f"{GREEN}5.[OK]{RESET}")
    else:
        usleep(50000)
        print(f"{RED}5.[KO]{RESET}")
        answer = False
    r2 = subprocess.run(cmd4, shell=True, capture_output=True, text=True)
    array = r2.stderr.strip().split("\n")
    if array[0] == "f: command not found" and array[1] == "f: command not found":
        usleep(50000)
        print(f"{GREEN}6.[OK]{RESET}")
    else:
        usleep(50000)
        print(f"{RED}6.[KO]{RESET}")
        answer = False
    with open("file2", "r") as file:
        str = file.read().strip()
    if str == "":
        usleep(50000)
        print(f"{GREEN}7.[OK]{RESET}")
    else:
        usleep(50000)
        print(f"{RED}7.[KO]{RESET}")
        answer = False
    r3 = subprocess.run(cmd5, shell=True, capture_output=True, text=True)
    if r3.stderr.strip() == "f: command not found":
        usleep(50000)
        print(f"{GREEN}8.[OK]{RESET}")
    else:
        usleep(50000)
        print(f"{RED}8.[KO]{RESET}")
        answer = False
    if os.path.exists("file3"):
        usleep(50000)
        print(f"{GREEN}9.[OK]{RESET}")
    else:
        usleep(50000)
        print(f"{RED}9.[KO]{RESET}")
        answer = False
    with open("file3", "r") as file:
        str = file.read().strip()
    if str == "0":
        usleep(50000)
        print(f"{GREEN}10.[OK]{RESET}")
    else:
        usleep(50000)
        print(f"{RED}10.[KO]{RESET}")
        answer = False
    os.system(rm_cmd)
    r4 = subprocess.run(cmd6, shell=True, capture_output=True, text=True)
    array = r4.stderr.strip().split("\n")
    if array[0] == "f: command not found" and array[1] == "f: command not found":
        usleep(50000)
        print(f"{GREEN}11.[OK]{RESET}")
    else:
        usleep(50000)
        print(f"{RED}11.[KO]{RESET}")
        answer = False
    if os.path.exists("file3"):
        usleep(50000)
        print(f"{GREEN}12.[OK]{RESET}")
    else:
        usleep(50000)
        print(f"{RED}12.[KO]{RESET}")
        answer = False
    with open("file3", "r") as file:
        str = file.read().strip()
    if str == "":
        usleep(50000)
        print(f"{GREEN}13.[OK]{RESET}")
    else:
        usleep(50000)
        print(f"{RED}13.[KO]{RESET}")
        answer = False
    os.system(rm_cmd)
    r5 = subprocess.run(cmd7, shell=True, capture_output=True, text=True)
    array = r5.stderr.strip().split("\n")
    if array[0] == "file: No such file or directory" and array[1] == "f: command not found":
        usleep(50000)
        print(f"{GREEN}14.[OK]{RESET}")
    else:
        usleep(50000)
        print(f"{RED}14.[KO]")
        print("testing:./pipex file cat f file3 (where file does not exist)"f"{RESET}")
        answer = False
    if os.path.exists("file3"):
        usleep(50000)
        print(f"{GREEN}15.[OK]{RESET}")
    else:
        usleep(50000)
        print(f"{RED}15.[KO]{RESET}")
        answer = False
    with open("file3", "r") as file:
        str = file.read().strip()
    if str == "":
        usleep(50000)
        print(f"{GREEN}16.[OK]{RESET}")
    else:
        usleep(50000)
        print(f"{RED}16.[KO]{RESET}")
        answer = False
    os.system(rm_cmd)
    r6 = subprocess.run(cmd8, shell=True, capture_output=True, text=True)
    array = r6.stderr.strip().split("\n")
    if array[0] == "file: No such file or directory" and array[1] == "f: command not found":
        usleep(50000)
        print(f"{GREEN}17.[OK]{RESET}")
    else:
        usleep(50000)
        print(f"{RED}17.[KO]")
        print("testing:./pipex file f f file3 (where file and f command does not exist)"f"{RESET}")
        answer = False
    if os.path.exists("file3"):
        usleep(50000)
        print(f"{GREEN}18.[OK]{RESET}")
    else:
        usleep(50000)
        print(f"{RED}18.[KO]{RESET}")
        answer = False
    with open("file3", "r") as file:
        str = file.read().strip()
    if str == "":
        usleep(50000)
        print(f"{GREEN}19.[OK]{RESET}")
    else:
        usleep(50000)
        print(f"{RED}19.[KO]{RESET}")
        answer = False
    os.system(rm_cmd)

    return answer

def main():
    test = True
    if not check_basic():
        test = False
    if not check_file():
        test = False
    if test:
        usleep(50000)
        print(f"{GREEN}\n[All tests passed]{RESET}")
    else:  
        usleep(50000)
        print(f"{RED}\n[Some tests failed]{RESET}")
    

if __name__ == "__main__":
    main()
