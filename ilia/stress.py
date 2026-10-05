import random
import subprocess
import sys

def run_executable(binary_name, input_data):
    res = subprocess.run(
        [f"./{binary_name}"],
        input=input_data,
        text=True,
        capture_output=True,
        timeout=2
    )
    return res.stdout.strip()
