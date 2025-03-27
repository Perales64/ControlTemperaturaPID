import serial

# Configura el puerto serial
ser = serial.Serial('COM5', 115200)  

# Abre un archivo para guardar los datos
with open('Datos.txt', 'w') as file:
    while True:
        # Lee datos del puerto serial
        data = ser.readline()
        # Decodifica y guarda los datos en el archivo
        file.write(data.decode('utf-8').strip() + '\n')
        print(data.decode('utf-8').strip())