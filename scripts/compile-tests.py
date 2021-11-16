from os import listdir
import subprocess

for f in listdir("tests/vulkan"):
    if f.endswith(".spv"):
        continue

    print(f"-- compiling test {f}")

    p = subprocess.run(["glslangValidator", f"tests/vulkan/{f}", "-H", "-o", f"tests/vulkan/{f}.spv"], shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    if p.returncode != 0:
        print(bytes.decode(p.stdout))
