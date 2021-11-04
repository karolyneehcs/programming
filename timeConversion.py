N = 140153;

minutos = N // 60
segundos = N - minutos * 60
horas = minutos // 60
minutos = minutos - horas * 60

print('{:.0f}:{:.0f}:{:.0f}'.format(horas, minutos, segundos))