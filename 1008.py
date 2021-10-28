number = int(input("Number: "));
hour = int(input("Hours: "));
amount = float(input("Amount: "));

salary = hour * amount;
print(f'NUMBER = {number}');
print('SALARY = U$ {:.2f}'.format(salary));
print("\n");