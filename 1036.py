import math;
a = float(input("A: "));
b = float(input("B: "));
c = float(input("C: "));

delta = b**2 - 4 * a * c;
if(delta<0 or a == 0):
  print("Impossivel calcular")
else:
  R1 = (-b + (math.sqrt(delta))) / (2 * a);
  R2 = (-b - (math.sqrt(delta))) / (2 * a);
  print('R1 = {:.5f}'.format(R1));
  print('R2 = {:.5f}'.format(R2));