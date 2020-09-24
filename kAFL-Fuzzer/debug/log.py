# log.py
#
# Implemented functions for debugging and logging
# Written by Juhyun Song

# Experimental
from kafl_fuzz import LOGQ

# debug print flag (todo: make selectable)
DEBUG_FLOW = False
DEBUG_STATE = False
DEBUG_SHOW_QUEUE = False
DEBUG_SHOW_PAYLOAD = True

DEBUG_HAVOC_MAX = 32

# random append stage flag (todo: seperate to dispatcher)
RAND_APPEND = True
APPEND_AMOUNT = 2

# prefix
EXCEPT_PREFIX = '\033[1;31m[EXCEPT]\033[0m '
ERROR_PREFIX = '\033[1;31m[EXCEPT]\033[0m '
FLOW_PREFIX = '\033[1;31m[FLOW]\033[0m '
WARN_PREFIX = '\033[1;31m[WARNING]\033[0m '
KAFL_PREFIX = '\033[1;34m[KAFL]\033[0m '
INFO_PREFIX = '\033[1;32m[INFO]\033[0m '
YELLOW_PREFIX = '\033[1;33m[DEBUG]\033[0m '

WORKDIR = '/home/user/kAFL/out/'


def debug_info(msg):
    data = INFO_PREFIX + msg
    # print(data)

def debug_kafl(msg, newline=False):
    if newline:
        print('\n' + KAFL_PREFIX + msg)
    else:
        print(KAFL_PREFIX + msg)

def debug_flow(msg):
    data = FLOW_PREFIX + msg
    # print(data)

def debug_warn(msg):
    print(WARN_PREFIX + msg)

def debug_error(msg):
    print(ERROR_PREFIX + msg)

def debug_except(msg):
    print(EXCEPT_PREFIX + msg)

def debug(msg, newline=False):
    if newline:
        data = msg
    else:
        data = msg
    # print(data)
    LOGQ.put(data + '\n')
    