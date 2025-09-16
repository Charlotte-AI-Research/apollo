import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/apollo/intro_ws/src/apollo_intro/install/apollo_intro'
