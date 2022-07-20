import sys
import math

argv = sys.argv[1]
normals = [float(i) for i in argv.split(',')]
total = math.sqrt(sum(i ** 2 for i in normals))
unit_normals = [i / total for i in normals]

print("Drag below")
print(f'{unit_normals[0]},{unit_normals[1]},{unit_normals[2]}')
