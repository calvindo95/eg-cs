import sys
from ctypes import *
import socket
import fcntl
import struct

lib_egc = cdll.LoadLibrary('build/source/lib_egc.so')

def egc(argc,argv):
    lib_egc.main(argc, argv)

def get_ip_address():
    s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    s.connect(("8.8.8.8", 80))
    return s.getsockname()[0]


LP_c_char = POINTER(c_char)

my_args = ["placeholder", "-a", "test", "-i", get_ip_address(), "-t", "Hello world! this is a test"]
argc = len(my_args)
argv = (LP_c_char * (argc + 1))()


for i, arg in enumerate(my_args):
    enc_arg = arg.encode('utf-8')   # encode to bytes
    argv[i] = create_string_buffer(enc_arg) # write bytes to argv list

egc(argc, argv)