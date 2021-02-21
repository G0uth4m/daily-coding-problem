"""
This problem was asked by Google.

Implement a file syncing algorithm for two computers over a low-bandwidth network. 
What if we know the files in the two computers are mostly the same?
"""

"""
We construct a merkle tree for both computers. The merkle tree represents the directory structure.
The leaves of the merkle tree represents actual files. The other nodes represent directories.
Each path from root to leaf represents the path location of the file.
Each node will store the hash of the file/directory. 
If a file is changed. It's hash changes. Therefore, it's ancestors hash also changes.
So, when the hash of the roots are different, we can conclude that there are changes in a file.
We follow the path where where the hash of the node is different which actually leads us to 
the file that had changes. 
"""
