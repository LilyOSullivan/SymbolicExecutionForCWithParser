# IDEA: Provide a cleaning flag/option to remove all the files generated
#      by the parser. Maybe this should happen by default?

import argparse
import os
import shutil
import subprocess
import sys
import time

import pyautogui

# assert sys.platform == "win32", "Only Windows is supported"

parser = argparse.ArgumentParser()

parser.add_argument(
    "-preprocess",
    "-pp",
    required=False,
    default=False,
    action="store_true",
    help="Run only the CL preprocessor",
)


def path_to_dir(path):
    if path.endswith(".pl"):
        raise argparse.ArgumentTypeError(f"-prolog-path (-path): {path} points to a file, not a directory")
    if os.path.isdir(path):
        return path
    else:
        raise argparse.ArgumentTypeError(f"-prolog-path (-path):{path} is not a valid path")


parser.add_argument(
    "-prolog-path",
    "-path",
    type=path_to_dir,
    required=False,
    default="C:/Users/Person/Dropbox/Mac (2)/Documents/Github/SymbolicExecutionForCWithParser/Prolog",
    help="The path to the directory of the symbolic execution 'main' Prolog code",
)
parser.add_argument(
    "-file",
    "-f",
    type=str,
    required=False,
    default="sign",
    help="The name of the C file to be parsed, without the .c extension (default: sign)",
)
parser.add_argument(
    "-copy_only",
    "-c",
    required=False,
    default=False,
    action="store_true",
    help="Copy the files output by the parser without running ECLiPSe",
)
parser.add_argument(
    "-entire",
    "-e",
    required=False,
    default=False,
    action="store_true",
    help="ECLiPSe will be called after initially calling the parser, includes -copy_only(-c)",
)
parser.add_argument(
    "-function",
    "-fun",
    required=False,
    type=str,
    default="inspect",
    help="The entry function to be parsed (default: inspect))",
)

args = parser.parse_args()
# QUESTION: Maybe this can be allowed? Resulting in a -entire (-e) run
# This is currently an artificial limitation
assert not (
    args.copy_only is True and args.entire is True
), "-copy_only (-c) or -entire (-e) cannot be used together."


filename = args.file

# Remove .c extension if entered.
# The user is prompted not to do this in the help function
if filename.endswith(".c"):
    filename = filename[:-2]

assert os.system(f"cl /EP /P {filename}.c") == 0

if args.preprocess:
    sys.exit(0)

assert (
    os.system(
        rf".\LilyParser.exe C:\Users\Person\Desktop\ParserPlayground {filename} ."
    )
    == 0
)

if args.copy_only:
    old_path = f"./{filename}.pl"
    new_path = args.prolog_path
    shutil.copy(old_path, new_path)

    old_path = f"./{filename}.names"
    new_path = args.prolog_path
    shutil.copy(old_path, new_path)

    # This will only work for small examples
    old_path = f"./{filename}.c"
    new_path = args.prolog_path
    shutil.copy(old_path, new_path)

if not args.entire:
    sys.exit(0)

old_path = f"./{filename}.pl"
new_path = args.prolog_path
shutil.copy(old_path, new_path)

old_path = f"./{filename}.names"
new_path = args.prolog_path
shutil.copy(old_path, new_path)

terminal_process = subprocess.Popen(
    ["eclipse"],
    shell=True,
    cwd=args.prolog_path,
    creationflags=subprocess.DETACHED_PROCESS | subprocess.CREATE_NEW_PROCESS_GROUP,
    stdin=subprocess.PIPE,
    stderr=subprocess.PIPE,
)

time.sleep(2)
terminal = pyautogui.getWindowsWithTitle("eclipse")[0]
terminal.activate()
pyautogui.write(":- use_module(main).")
pyautogui.press("enter")
time.sleep(2)
print(f'main("{args.file}",{args.function}).')
pyautogui.write(f'main("{args.file}",{args.function}).')
pyautogui.press("enter")
time.sleep(2)
terminal.close()
terminal_process.kill()