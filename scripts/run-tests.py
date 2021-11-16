from os import listdir, getcwd
import subprocess

PATH_TO_LIELLA = None
with open("tmp/path-to-liella", encoding="utf8") as f:
    PATH_TO_LIELLA = f.readline()

CWD = getcwd()
for f in listdir("tests/vulkan"):
    if not f.endswith(".spv"):
        continue
    print(f"-- running test {f}")

    p = subprocess.run([PATH_TO_LIELLA, f"{CWD}/tests/vulkan/{f}", f"{CWD}/tmp/vulkan/{f}"], shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    if p.returncode != 0:
        print(bytes.decode(p.stdout))