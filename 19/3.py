import os

i = 1
while i < 2000:
  print("\npage num " + str(i))
  val = os.system('./tlb ' + str(i) + ' ' + str(10000))
  i *= 2
