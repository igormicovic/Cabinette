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

def check_norm():
    answer = True
    usleep(100000)
    print(f"{BLUE}=== Norm check ==={RESET}")
    r = subprocess.run('ls', shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
    arr = r.stdout.strip().split("\n")
    for i, file_name in enumerate(arr, start=1):
        r1 = subprocess.run(f'norminette {file_name}', shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
        if r1.returncode == 0:
            print(f"{GREEN}{i}.[OK]{RESET}")
        else:
            print(f"{RED}{i}.[KO]{RESET}")
            print(f'{RED}norminette {file_name}{RESET}')
            answer = False
    return answer

def check_basic():
    answer = True
    usleep(100000)
    print(f"{BLUE}=== Basic test ==={RESET}")
    cmd = './pipex file1 cat "wc -l" file2'
    cmd2 = './pipex file1 cat "wc -c" file2'
    cmd3 = './pipex file1 cat "wc -w" file2'
    cmd4 = './pipex file1 "ls -a" "wc -l" file2'
    cmd5 = './pipex file1 "ls -l" "wc -c" file2'
    cmd6 = './pipex file1 "grep asdasdas" "cat" file2'
    r1 = subprocess.run("ls -a | wc -l", shell=True, capture_output=True, text=True)
    r2 = subprocess.run("ls -l | wc -c", shell=True, capture_output=True, text=True)
    subprocess.run(cmd, shell=True)
    
    usleep(50000)
    with open("file2", "r") as file:
        str = file.read().strip()

    if str == "10":
        print(f"{GREEN}1.[OK]{RESET}")
    else:
        print(f"{RED}1.[KO]{RESET}")
        print(f'{RED}testing:./pipex file1 cat "wc -l" file2{RESET}')
        answer = False
    subprocess.run(cmd2, shell=True)
    usleep(50000)
    with open("file2", "r") as file:
        str = file.read().strip()
    if str == "49":
        print(f"{GREEN}2.[OK]{RESET}")
    else:
        print(f"{RED}2.[KO]{RESET}")
        print(f'{RED}testing:./pipex file1 cat "wc -c" file2{RESET}')
        answer = False
    subprocess.run(cmd3, shell=True)
    usleep(50000)
    with open("file2", "r") as file:
        str = file.read().strip()
    if str == "10":
        print(f"{GREEN}3.[OK]{RESET}")
    else:
        print(f"{RED}3.[KO]{RESET}")
        print(f'{RED}testing:./pipex file1 cat "wc -w" file2{RESET}')
        answer = False
    subprocess.run(cmd4, shell=True)
    usleep(50000)
    with open("file2", "r") as file:
        str = file.read().strip()
    if str == r1.stdout.strip():
        print(f"{GREEN}4.[OK]{RESET}")
    else:
        print(f"{RED}4.[KO]{RESET}")
        print(f'{RED}testing:./pipex file1 "ls -a" "wc -l" file2{RESET}')
        answer = False
    subprocess.run(cmd5, shell=True)
    usleep(50000)
    with open("file2", "r") as file:
        str = file.read().strip()
    if str == r2.stdout.strip():
        print(f"{GREEN}5.[OK]{RESET}")
    else:
        print(f"{RED}5.[KO]{RESET}")
        print(f'{RED}testing:./pipex file1 "ls -l" "wc -c" file2{RESET}')
        answer = False
    subprocess.run(cmd6, shell=True)
    usleep(50000)
    with open("file2", "r") as file:
        str = file.read().strip()
    if str == "asdasdas":
        print(f"{GREEN}6.[OK]{RESET}")
    else:
        print(f"{RED}6.[KO]{RESET}")
        print(f'{RED}testing:./pipex file1 "grep asdasdas" "cat" file2{RESET}')
        answer = False
    
    return answer

def check_empty():

    answer = True
    usleep(100000)
    print(f"{BLUE}=== Check empty ==={RESET}")
    cmd = './pipex "" cat "wc -l" file2'
    cmd2 = './pipex file1 "" "wc -l" file2'
    cmd3 = './pipex file1 cat "" file2'
    cmd4 = './pipex "" "" "wc -l" file2'
    cmd5 = './pipex "" "" "" file2'
    cmd6 = './pipex file1 "" "" file2'
    cmd7 = './pipex "" cat "wc -l" ""'
    cmd8 = './pipex "" "" "wc -l" ""'
    cmd9 = './pipex file1 "" "wc -l" ""'
    cmd10 = './pipex file1 cat "" ""'
    cmd11 = './pipex file1 "" "" ""'
    cmd12 = './pipex "" "" "" ""'
    cmd13 = './pipex " " "" "" ""'
    cmd14 = './pipex "" " " "" ""'
    cmd15 = './pipex "" "" " " ""'
    cmd16 = './pipex "" "" "" " "'
    cmd17 = './pipex " " " " " " " "'
    cmd18 = './pipex file1 " " "wc -l" file2'
    rs = subprocess.run(cmd, shell=True, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    usleep(50000)
    
    if rs.returncode == 1:
        print(f"{GREEN}1.[OK]{RESET}")
    else:
        print(f"{RED}1.[KO]{RESET}")
        print(f'{RED}testing:./pipex "" cat "wc -l" file2{RESET}')
        answer = False
    rs2 = subprocess.run(cmd2, shell=True, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    usleep(50000)
    if rs2.returncode == 1:
        print(f"{GREEN}2.[OK]{RESET}")
    else:
        print(f"{RED}2.[KO]{RESET}")
        print(f'{RED}testing:./pipex file1 "" "wc -l" file2 {RESET}')
        answer = False
    rs3 = subprocess.run(cmd3, shell=True, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    usleep(50000)
    if rs3.returncode == 1:
        print(f"{GREEN}3.[OK]{RESET}")
    else:
        print(f"{RED}3.[KO]{RESET}")
        print(f'{RED}testing:./pipex file1 cat "" file2{RESET}')
        answer = False
    rs4 = subprocess.run(cmd4, shell=True, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    usleep(50000)
    if rs4.returncode == 1:
        print(f"{GREEN}4.[OK]{RESET}")
    else:
        print(f"{RED}4.[KO]{RESET}")
        print(f'{RED}testing:./pipex "" "" "wc -l" file2 {RESET}')
        answer = False
    rs5 = subprocess.run(cmd5, shell=True, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    usleep(50000)
    if rs5.returncode == 1:
        print(f"{GREEN}5.[OK]{RESET}")
    else:
        print(f"{RED}5.[KO]{RESET}")
        print(f'{RED}testing:./pipex "" "" "" file2 {RESET}')
        answer = False
    rs6 = subprocess.run(cmd6, shell=True, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    usleep(50000)
    if rs6.returncode == 1:
        print(f"{GREEN}6.[OK]{RESET}")
    else:
        print(f"{RED}6.[KO]{RESET}")
        print(f'{RED}testing:./pipex file1 "" "" file2{RESET}')
        answer = False
    rs7 = subprocess.run(cmd7, shell=True, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    usleep(50000)
    if rs7.returncode == 1:
        print(f"{GREEN}7.[OK]{RESET}")
    else:
        print(f"{RED}7.[KO]{RESET}")
        print(f'{RED}testing:./pipex "" cat "wc -l" ""{RESET}')
        answer = False
    rs8 = subprocess.run(cmd8, shell=True, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    usleep(50000)
    if rs8.returncode == 1:
        print(f"{GREEN}8.[OK]{RESET}")
    else:
        print(f"{RED}8.[KO]{RESET}")
        print(f'{RED}testing:./pipex "" "" "wc -l" ""{RESET}')   
        answer = False
    rs9 = subprocess.run(cmd9, shell=True, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    usleep(50000)
    if rs9.returncode == 1:
        print(f"{GREEN}9.[OK]{RESET}")
    else:
        print(f"{RED}9.[KO]{RESET}")
        print(f'{RED}testing:./pipex file1 "" "wc -l" ""{RESET}')
        answer = False
    rs10 = subprocess.run(cmd10, shell=True, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    usleep(50000)
    if rs10.returncode == 1:
        print(f"{GREEN}10.[OK]{RESET}")
    else:
        print(f"{RED}10.[KO]{RESET}")
        print(f'{RED}testing:./pipex file1 cat "" ""{RESET}')
        answer = False
    rs11 = subprocess.run(cmd11, shell=True, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    usleep(50000)
    if rs11.returncode == 1:
        print(f"{GREEN}11.[OK]{RESET}")
    else:
        print(f"{RED}11.[KO]{RESET}")
        print(f'{RED}testing:./pipex file1 "" "" ""{RESET}')
        answer = False
    rs12 = subprocess.run(cmd12, shell=True, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    usleep(50000)
    if rs12.returncode == 1:
        print(f"{GREEN}12.[OK]{RESET}")
    else:
        print(f"{RED}12.[KO]{RESET}")
        print(f'{RED}testing:./pipex "" "" "" ""{RESET}')
        answer = False
    rs13 = subprocess.run(cmd13, shell=True, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    usleep(50000)
    if rs13.returncode == 1:
        print(f"{GREEN}13.[OK]{RESET}")
    else:
        print(f"{RED}13.[KO]{RESET}")
        print(f'{RED}testing:./pipex " " "" "" ""{RESET}')
        answer = False
    rs14 = subprocess.run(cmd14, shell=True, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    usleep(50000)
    if rs14.returncode == 1:
        print(f"{GREEN}14.[OK]{RESET}")
    else:
        print(f"{RED}14.[KO]{RESET}")
        print(f'{RED}testing:./pipex "" " " "" ""{RESET}')
        answer = False
    rs15 = subprocess.run(cmd15, shell=True, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    usleep(50000)
    if rs15.returncode == 1:
        print(f"{GREEN}15.[OK]{RESET}")
    else:
        print(f"{RED}15.[KO]{RESET}")
        print(f'{RED}testing:./pipex "" "" " " ""{RESET}')
        answer = False
    rs16 = subprocess.run(cmd16, shell=True, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    usleep(50000)
    if rs16.returncode == 1:
        print(f"{GREEN}16.[OK]{RESET}")
    else:
        print(f"{RED}16.[KO]{RESET}")
        print(f'{RED}testing:./pipex "" "" "" " "{RESET}')
        answer = False
    rs17 = subprocess.run(cmd17, shell=True, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    usleep(50000)
    if rs17.returncode == 1:
        print(f"{GREEN}17.[OK]{RESET}")
    else:
        print(f"{RED}17.[KO]{RESET}")
        print(f'{RED}testing:./pipex " " " " " " " " (when arguments doesnt exist){RESET}')
        answer = False
    rs18 = subprocess.run(cmd18, shell=True, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    usleep(50000)
    if rs18.returncode == 1:
        print(f"{GREEN}18.[OK]{RESET}")
    else:
        print(f"{RED}18.[KO]{RESET}")
        print(f'{RED}testing:./pipex file1 " " "wc -l" file2 (when first cmd doesnt exist){RESET}')
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
        print(f'{RED}testing:./pipex file1 cat "wc -l" file3{RESET}')
        answer = False
    result = subprocess.run(cmd2, shell=True, capture_output=True, text=True)
    ex_out = "pipex: file: No such file or directory"
    pr_out = result.stderr.strip()
    if ex_out == pr_out:
        usleep(50000)
        print(f"{GREEN}2.[OK]{RESET}")
    else:
        usleep(50000)
        print(f"{RED}2.[KO]{RESET}")
        print(f'{RED}testing:./pipex file cat "wc -l" file3{RESET}')
        answer = False
    if os.path.exists("file3"):
        usleep(50000)
        print(f"{GREEN}3.[OK]{RESET}")
    else:
        usleep(50000)
        print(f"{RED}2.[KO]{RESET}")
        print(f'{RED}testing:./pipex file cat "wc -l" file3{RESET}')
        answer = False
    os.system(rm_cmd)
    r = subprocess.run(cmd3, shell=True, capture_output=True, text=True)
    if r.stderr.strip() == "pipex: f: command not found":
        usleep(50000)
        print(f"{GREEN}4.[OK]{RESET}")
    else:
        usleep(50000)
        print(f"{RED}4.[KO]{RESET}")
        print(f'{RED}testing:./pipex file1 f "wc -l" file2{RESET}')
        answer = False
    with open("file2", "r") as file:
        str = file.read().strip()
    if str == "0":
        usleep(50000)
        print(f"{GREEN}5.[OK]{RESET}")
    else:
        usleep(50000)
        print(f"{RED}5.[KO]{RESET}")
        print(f'{RED}testing:./pipex file1 f "wc -l" file2{RESET}')
        answer = False
    r2 = subprocess.run(cmd4, shell=True, capture_output=True, text=True)
    
    array = r2.stderr.strip().split("\n")
    if array[0] == "pipex: f: command not found" and array[1] == "pipex: f: command not found":
        usleep(50000)
        print(f"{GREEN}6.[OK]{RESET}")
    else:
        usleep(50000)
        print(f"{RED}6.[KO]{RESET}")
        print(f'{RED}testing:./pipex file1 f f file2{RESET}')
        answer = False
    with open("file2", "r") as file:
        str = file.read().strip()
    if str == "":
        usleep(50000)
        print(f"{GREEN}7.[OK]{RESET}")
    else:
        usleep(50000)
        print(f"{RED}7.[KO]{RESET}")
        print(f'{RED}testing:./pipex file1 f f file2{RESET}')
        answer = False
    r3 = subprocess.run(cmd5, shell=True, capture_output=True, text=True)
    if r3.stderr.strip() == "pipex: f: command not found":
        usleep(50000)
        print(f"{GREEN}8.[OK]{RESET}")
    else:
        usleep(50000)
        print(f"{RED}8.[KO]{RESET}")
        print(f'{RED}testing:./pipex file1 f "wc -l" file3{RESET}')
        answer = False
    if os.path.exists("file3"):
        usleep(50000)
        print(f"{GREEN}9.[OK]{RESET}")
    else:
        usleep(50000)
        print(f"{RED}9.[KO]{RESET}")
        print(f'{RED}testing:./pipex file1 f "wc -l" file3{RESET}')
        answer = False
    with open("file3", "r") as file:
        str = file.read().strip()
    if str == "0":
        usleep(50000)
        print(f"{GREEN}10.[OK]{RESET}")
    else:
        usleep(50000)
        print(f"{RED}10.[KO]{RESET}")
        print(f'{RED}testing:./pipex file1 f "wc -l" file3{RESET}')
        answer = False
    os.system(rm_cmd)
    r4 = subprocess.run(cmd6, shell=True, capture_output=True, text=True)
    array = r4.stderr.strip().split("\n")
    if array[0] == "pipex: f: command not found" and array[1] == "pipex: f: command not found":
        usleep(50000)
        print(f"{GREEN}11.[OK]{RESET}")
    else:
        usleep(50000)
        print(f"{RED}11.[KO]{RESET}")
        print(f'{RED}testing:./pipex file1 f f file3{RESET}')
        answer = False
    if os.path.exists("file3"):
        usleep(50000)
        print(f"{GREEN}12.[OK]{RESET}")
    else:
        usleep(50000)
        print(f"{RED}12.[KO]{RESET}")
        print(f'{RED}testing:./pipex file1 f f file3{RESET}')
        answer = False
    with open("file3", "r") as file:
        str = file.read().strip()
    if str == "":
        usleep(50000)
        print(f"{GREEN}13.[OK]{RESET}")
    else:
        usleep(50000)
        print(f"{RED}13.[KO]{RESET}")
        print(f'{RED}testing:./pipex file1 f f file3{RESET}')
        answer = False
    os.system(rm_cmd)
    r5 = subprocess.run(cmd7, shell=True, capture_output=True, text=True)
    array = r5.stderr.strip().split("\n")
    if array[0] == "pipex: file: No such file or directory" and array[1] == "pipex: f: command not found":
        usleep(50000)
        print(f"{GREEN}14.[OK]{RESET}")
    else:
        usleep(50000)
        print(f"{RED}14.[KO]{RESET}")
        print(f'{RED}testing:./pipex file cat f file3 (when file does not exist){RESET}')
        answer = False
    if os.path.exists("file3"):
        usleep(50000)
        print(f"{GREEN}15.[OK]{RESET}")
    else:
        usleep(50000)
        print(f"{RED}15.[KO]{RESET}")
        print(f'{RED}testing:./pipex file cat f file3 (when file does not exist){RESET}')
        answer = False
    with open("file3", "r") as file:
        str = file.read().strip()
    if str == "":
        usleep(50000)
        print(f"{GREEN}16.[OK]{RESET}")
    else:
        usleep(50000)
        print(f"{RED}16.[KO]{RESET}")
        print(f'{RED}testing:./pipex file cat f file3 (when file does not exist){RESET}')
        answer = False
    os.system(rm_cmd)
    r6 = subprocess.run(cmd8, shell=True, capture_output=True, text=True)
    array = r6.stderr.strip().split("\n")
    if array[0] == "pipex: file: No such file or directory" and array[1] == "pipex: f: command not found":
        usleep(50000)
        print(f"{GREEN}17.[OK]{RESET}")
    else:
        usleep(50000)
        print(f"{RED}17.[KO]{RESET}")
        print(f'{RED}testing:./pipex file f f file3 (when file and f command does not exist){RESET}')
        answer = False
    if os.path.exists("file3"):
        usleep(50000)
        print(f"{GREEN}18.[OK]{RESET}")
    else:
        usleep(50000)
        print(f"{RED}18.[KO]{RESET}")
        print(f'{RED}testing:./pipex file f f file3 (when file and f command does not exist){RESET}')
        answer = False
    with open("file3", "r") as file:
        str = file.read().strip()
    if str == "":
        usleep(50000)
        print(f"{GREEN}19.[OK]{RESET}")
    else:
        usleep(50000)
        print(f"{RED}19.[KO]{RESET}")
        print(f'{RED}testing:./pipex file f f file3 (when file and f command does not exist){RESET}')
        answer = False
    os.system(rm_cmd)
    r7 = subprocess.run(cmd4, shell=True, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    usleep(50000)
    if r7.returncode == 127:
        print(f"{GREEN}20.[OK]{RESET}")
    else:
        print(f"{RED}20.[KO]{RESET}")
        print(f'{RED}testing:./pipex file1 f f file2{RESET}')
        answer = False
    r8 = subprocess.run(cmd5, shell=True, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    usleep(50000)
    if r8.returncode == 0:
        print(f"{GREEN}21.[OK]{RESET}")
    else:
        print(f"{RED}21.[KO]{RESET}")
        print(f'{RED}testing:./pipex file1 f "wc -l" file3{RESET}')
        answer = False
    os.system(rm_cmd)
    r9 = subprocess.run(cmd6, shell=True, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    usleep(50000)
    if r9.returncode == 127:
        print(f"{GREEN}22.[OK]{RESET}")
    else:
        print(f"{RED}22.[KO]{RESET}")
        print(f'{RED}testing:./pipex file1 f f file3{RESET}')
        answer = False
    os.system(rm_cmd)
    r10 = subprocess.run(cmd7, shell=True, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    usleep(50000)
    if r10.returncode == 127:
        print(f"{GREEN}23.[OK]{RESET}")
    else:
        print(f"{RED}23.[KO]{RESET}")
        print(f'{RED}testing:./pipex file cat f file3{RESET}')
        answer = False
    os.system(rm_cmd)
    r11 = subprocess.run(cmd8, shell=True, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    usleep(50000)
    if r11.returncode == 127:
        print(f"{GREEN}24.[OK]{RESET}")
    else:
        print(f"{RED}24.[KO]{RESET}")
        print(f'{RED}testing:./pipex file f f file3{RESET}')
        answer = False
    os.system(rm_cmd)
    
    return answer

def check_exit_code():
    answer = True
    usleep(100000)
    print(f"{BLUE}=== Check exit code ==={RESET}")
    cmd = './pipex file1 cat "wc -l" file2' # 0
    cmd2 = './pipex file1 cat "wc -l" file3' # 0
    cmd3 = './pipex file1 cat f file2' # 127
    cmd4 = './pipex file1 f f file2' # 127
    cmd5 = './pipex file1 f "wc -l" file2' # 0
    cmd6 = './pipex file cat "wc -l" file2' # 0
    cmd7 = './pipex file cat "" file2' # 1
    cmd8 = './pipex file1 "" "wc -l" file2' # 1
    cmd9 = './pipex file1 " " " " file3' # 1
    cmd10 = './pipex file1 cat "wc -l"' # 1
    cmd11 = './pipex' # 1
    cmd12 = './pipex file1 "ls -l" "wc -lsa" file2' # 1
    cmd13 = './pipex file1 "ls -lsa" "wc -l" file2' # 0
    rm_cmd = 'rm -f file3'
    r = subprocess.run(cmd, shell=True, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    usleep(50000)
    if r.returncode == 0:
        print(f"{GREEN}1.[OK]{RESET}")
    else:
        print(f"{RED}1.[KO]{RESET}")
        print(f'{RED}./pipex file1 cat "wc -l" file2{RESET}')
        answer = False
    r2 = subprocess.run(cmd2, shell=True, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    usleep(50000)
    if r2.returncode == 0:
        print(f"{GREEN}2.[OK]{RESET}")
    else:
        print(f"{RED}2.[KO]{RESET}")
        print(f'{RED}./pipex file1 cat "wc -l" file3{RESET}')
        answer = False
    os.system(rm_cmd)
    r3 = subprocess.run(cmd3, shell=True, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    usleep(50000)
    if r3.returncode == 127:
        print(f"{GREEN}3.[OK]{RESET}")
    else:
        print(f"{RED}3.[KO]{RESET}")
        print(f'{RED}./pipex file1 cat f file2{RESET}')
        answer = False
    r4 = subprocess.run(cmd4, shell=True, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    usleep(50000)
    if r4.returncode == 127:
        print(f"{GREEN}4.[OK]{RESET}")
    else:
        print(f"{RED}4.[KO]{RESET}")
        print(f'{RED}./pipex file1 f f file2{RESET}')
        answer = False
    r5 = subprocess.run(cmd5, shell=True, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    usleep(50000)
    if r5.returncode == 0:
        print(f"{GREEN}5.[OK]{RESET}")
    else:
        print(f"{RED}5.[KO]{RESET}")
        print(f'{RED}./pipex file1 f "wc -l" file2{RESET}')
        answer = False
    r6 = subprocess.run(cmd6, shell=True, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    usleep(50000)
    if r6.returncode == 0:
        print(f"{GREEN}6.[OK]{RESET}")
    else:
        print(f"{RED}6.[KO]{RESET}")
        print(f'{RED}./pipex file cat "wc -l" file2{RESET}')
        answer = False
    r7 = subprocess.run(cmd7, shell=True, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    usleep(50000)
    if r7.returncode == 1:
        print(f"{GREEN}7.[OK]{RESET}")
    else:
        print(f"{RED}7.[KO]{RESET}")
        print(f'{RED}./pipex file cat "" file2{RESET}')
        answer = False
    r8 = subprocess.run(cmd8, shell=True, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    usleep(50000)
    if r8.returncode == 1:
        print(f"{GREEN}8.[OK]{RESET}")
    else:
        print(f"{RED}8.[KO]{RESET}")
        print(f'{RED}./pipex file1 "" "wc -l" file2{RESET}')
        answer = False
    r9 = subprocess.run(cmd9, shell=True, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    usleep(50000)
    if r9.returncode == 1:
        print(f"{GREEN}9.[OK]{RESET}")
    else:
        print(f"{RED}9.[KO]{RESET}")
        print(f'{RED}./pipex file1 " " " " file3{RESET}')
        answer = False
    os.system(rm_cmd)
    r10 = subprocess.run(cmd10, shell=True, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    usleep(50000)
    if r10.returncode == 1:
        print(f"{GREEN}10.[OK]{RESET}")
    else:
        print(f"{RED}10.[KO]{RESET}")
        print(f'{RED}./pipex file1 cat "wc -l"{RESET}')
        answer = False
    r11 = subprocess.run(cmd11, shell=True, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    usleep(50000)
    if r11.returncode == 1:
        print(f"{GREEN}11.[OK]{RESET}")
    else:
        print(f"{RED}11.[KO]{RESET}")
        print(f'{RED}./pipex{RESET}')
        answer = False
    r12 = subprocess.run(cmd13, shell=True, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    usleep(50000)
    if r12.returncode == 0:
        print(f"{GREEN}12.[OK]{RESET}")
    else:
        print(f"{RED}12.[KO]{RESET}")
        print(f'{RED}./pipex file1 "ls -lsa" "wc -l" file2{RESET}')
        answer = False
    r13 = subprocess.run(cmd12, shell=True, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    usleep(50000)
    if r13.returncode == 1:
        print(f"{GREEN}13.[OK]{RESET}")
    else:
        print(f"{RED}13.[KO]{RESET}")
        print(f'{RED}./pipex file1 "ls -l" "wc -lsa" file2{RESET}')
        answer = False
    return answer

def check_leaks():
    answer = True
    usleep(100000)
    print(f"{BLUE}=== Check leaks ==={RESET}")
    cmd = 'valgrind --leak-check=full ./pipex'
    cmd1 = 'valgrind --leak-check=full ./pipex file1 cat "wc -l" file2'
    cmd2 = 'valgrind --leak-check=full ./pipex file1 cat "wc -l" file3'
    cmd3 = 'valgrind --leak-check=full ./pipex file1 cat f file2'
    cmd4 = 'valgrind --leak-check=full ./pipex file1 f f file2'
    cmd5 = 'valgrind --leak-check=full ./pipex file1 f "wc -l" file2'
    cmd6 = 'valgrind --leak-check=full ./pipex file cat "wc -l" file2'
    cmd7 = 'valgrind --leak-check=full ./pipex file cat "" file2'
    cmd8 = 'valgrind --leak-check=full ./pipex file1 "" "wc -l" file2'
    cmd9 = 'valgrind --leak-check=full ./pipex file1 " " " " file3'
    cmd10 = 'valgrind --leak-check=full ./pipex file1 cat "wc -l"'
    cmd11 = 'valgrind --leak-check=full ./pipex file1 "ls -l" "wc -lsa" file2'
    cmd12 = 'valgrind --leak-check=full ./pipex file1 "ls -lsa" "wc -l" file2'
    rm_cmd = 'rm -f file3'
    expected = "0 errors from 0 contexts (suppressed: 0 from 0)"

    r = subprocess.run(cmd, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)

    with open("/dev/null", "w") as dev_null:
        subprocess.run(cmd, shell=True, stdout=dev_null, stderr=dev_null)

    leaks = r.stderr.strip().split('\n')
    l_s = leaks[-1]
    l_l = l_s.split("ERROR SUMMARY: ")[1]

    if l_l == expected:
        print(f"{GREEN}1.[MOK]{RESET}")
    else:
        print(f"{RED}1.[KO LEAKS]{RESET}")
        print(f'{RED}valgrind --leak-check=full ./pipex{RESET}')
        answer = False
    r1 = subprocess.run(cmd1, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
    with open("/dev/null", "w") as dev_null:
        subprocess.run(cmd1, shell=True, stdout=dev_null, stderr=dev_null)
    leaks = r1.stderr.strip().split('\n')
    l_s = leaks[-1]
    l_l = l_s.split("ERROR SUMMARY: ")[1]
    if l_l == expected:
        print(f"{GREEN}2.[MOK]{RESET}")
    else:
        print(f"{RED}2.[KO LEAKS]{RESET}")
        print(f'{RED}valgrind --leak-check=full ./pipex file1 cat "wc -l" file2{RESET}')
        answer = False
    r2 = subprocess.run(cmd2, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
    with open("/dev/null", "w") as dev_null:
        subprocess.run(cmd2, shell=True, stdout=dev_null, stderr=dev_null)
    leaks = r2.stderr.strip().split('\n')
    l_s = leaks[-1]
    l_l = l_s.split("ERROR SUMMARY: ")[1]
    if l_l == expected:
        print(f"{GREEN}3.[MOK]{RESET}")
    else:
        print(f"{RED}3.[KO LEAKS]{RESET}")
        print(f'{RED}valgrind --leak-check=full ./pipex file1 cat "wc -l" file3{RESET}')
        answer = False
    os.system(rm_cmd)
    r3 = subprocess.run(cmd3, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
    with open("/dev/null", "w") as dev_null:
        subprocess.run(cmd3, shell=True, stdout=dev_null, stderr=dev_null)
    leaks = r3.stderr.strip().split('\n')
    l_s = leaks[-1]
    l_l = l_s.split("ERROR SUMMARY: ")[1]
    if l_l == expected:
        print(f"{GREEN}4.[MOK]{RESET}")
    else:
        print(f"{RED}4.[KO LEAKS]{RESET}")
        print(f'{RED}valgrind --leak-check=full ./pipex file1 cat f file2{RESET}')
        answer = False
    r4 = subprocess.run(cmd4, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
    with open("/dev/null", "w") as dev_null:
        subprocess.run(cmd4, shell=True, stdout=dev_null, stderr=dev_null)
    leaks = r4.stderr.strip().split('\n')
    l_s = leaks[-1]
    l_l = l_s.split("ERROR SUMMARY: ")[1]
    if l_l == expected:
        print(f"{GREEN}5.[MOK]{RESET}")
    else:
        print(f"{RED}5.[KO LEAKS]{RESET}")
        print(f'{RED}valgrind --leak-check=full ./pipex file1 f f file2{RESET}')
        answer = False
    r5 = subprocess.run(cmd5, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
    with open("/dev/null", "w") as dev_null:
        subprocess.run(cmd5, shell=True, stdout=dev_null, stderr=dev_null)
    leaks = r5.stderr.strip().split('\n')
    l_s = leaks[-1]
    l_l = l_s.split("ERROR SUMMARY: ")[1]
    if l_l == expected:
        print(f"{GREEN}6.[MOK]{RESET}")
    else:
        print(f"{RED}6.[KO LEAKS]{RESET}")
        print(f'{RED}valgrind --leak-check=full ./pipex file1 f "wc -l" file2{RESET}')
        answer = False
    r6 = subprocess.run(cmd6, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
    with open("/dev/null", "w") as dev_null:
        subprocess.run(cmd6, shell=True, stdout=dev_null, stderr=dev_null)
    leaks = r6.stderr.strip().split('\n')
    l_s = leaks[-1]
    l_l = l_s.split("ERROR SUMMARY: ")[1]
    if l_l == expected:
        print(f"{GREEN}7.[MOK]{RESET}")
    else:
        print(f"{RED}7.[KO LEAKS]{RESET}")
        print(f'{RED}valgrind --leak-check=full ./pipex file cat "wc -l" file2{RESET}')
        answer = False
    r7 = subprocess.run(cmd7, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
    with open("/dev/null", "w") as dev_null:
        subprocess.run(cmd7, shell=True, stdout=dev_null, stderr=dev_null)
    leaks = r7.stderr.strip().split('\n')
    l_s = leaks[-1]
    l_l = l_s.split("ERROR SUMMARY: ")[1]
    r8 = subprocess.run(cmd8, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
    with open("/dev/null", "w") as dev_null:
        subprocess.run(cmd8, shell=True, stdout=dev_null, stderr=dev_null)
    leaks = r8.stderr.strip().split('\n')
    l_s = leaks[-1]
    l_l = l_s.split("ERROR SUMMARY: ")[1]
    if l_l == expected:
        print(f"{GREEN}8.[MOK]{RESET}")
    else:
        print(f"{RED}8.[KO LEAKS]{RESET}")
        print(f'{RED}valgrind --leak-check=full ./pipex file1 "" "wc -l" file2{RESET}')
        answer = False
    r9 = subprocess.run(cmd9, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
    with open("/dev/null", "w") as dev_null:
        subprocess.run(cmd9, shell=True, stdout=dev_null, stderr=dev_null)
    leaks = r9.stderr.strip().split('\n')
    l_s = leaks[-1]
    l_l = l_s.split("ERROR SUMMARY: ")[1]
    if l_l == expected:
        print(f"{GREEN}9.[MOK]{RESET}")
    else:
        print(f"{RED}9.[KO LEAKS]{RESET}")
        print(f'{RED}valgrind --leak-check=full ./pipex file1 " " " " file3{RESET}')
        answer = False
    os.system(rm_cmd)
    r10 = subprocess.run(cmd10, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
    with open("/dev/null", "w") as dev_null:
        subprocess.run(cmd10, shell=True, stdout=dev_null, stderr=dev_null)
    leaks = r10.stderr.strip().split('\n')
    l_s = leaks[-1]
    l_l = l_s.split("ERROR SUMMARY: ")[1]
    if l_l == expected:
        print(f"{GREEN}10.[MOK]{RESET}")
    else:
        print(f"{RED}10.[KO LEAKS]{RESET}")
        print(f'{RED}valgrind --leak-check=full ./pipex file1 cat "wc -l"{RESET}')
        answer = False
    r11 = subprocess.run(cmd11, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
    with open("/dev/null", "w") as dev_null:
        subprocess.run(cmd11, shell=True, stdout=dev_null, stderr=dev_null)
    leaks = r11.stderr.strip().split('\n')
    l_s = leaks[-1]
    l_l = l_s.split("ERROR SUMMARY: ")[1]
    if l_l == expected:
        print(f"{GREEN}11.[MOK]{RESET}")
    else:
        print(f"{RED}11.[KO LEAKS]{RESET}")
        print(f'{RED}valgrind --leak-check=full ./pipex file1 "ls -l" "wc -lsa" file2{RESET}')
        answer = False
    r12 = subprocess.run(cmd12, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
    with open("/dev/null", "w") as dev_null:
        subprocess.run(cmd12, shell=True, stdout=dev_null, stderr=dev_null)
    leaks = r12.stderr.strip().split('\n')
    l_s = leaks[-1]
    l_l = l_s.split("ERROR SUMMARY: ")[1]
    if l_l == expected:
        print(f"{GREEN}12.[MOK]{RESET}")
    else:
        print(f"{RED}12.[KO LEAKS]{RESET}")
        print(f'{RED}valgrind --leak-check=full ./pipex file1 "ls -lsa" "wc -l" file2{RESET}')
        answer = False

    return answer

def main():
    failed_tests = []
    test = True
    if not check_norm():
        test = False
        failed_tests.append("Norm check")
    if not check_basic():
        test = False
        failed_tests.append("Check basic")
    if not check_empty():
        test = False
        failed_tests.append("Check empty")
    if not check_file():
        test = False
        failed_tests.append("Check file")
    if not check_exit_code():
        test = False
        failed_tests.append("Check exit code")
    if not check_leaks():
        test = False
        failed_tests.append("Check leaks")
    if test:
        usleep(50000)
        print(f"{GREEN}\n[All tests passed]{RESET}")
    else:  
        usleep(50000)
        print(f"{RED}\nFailed tests:{RESET}")
        for test in failed_tests:
            print(f"{RED}[{test}]{RESET}")
    

if __name__ == "__main__":
    main()
    