from matplotlib import pyplot
from matplotlib import style

time = []
y_per_time = []
e_per_time = []
u_per_time = []

work_file = open('work_data.csv', 'r')
for line in work_file.readlines():
    line = line.replace('\n', '')
    line_parts = line.split(';')
    time.append(int(line_parts[0]))
    y_per_time.append(float(line_parts[1]))
    e_per_time.append(float(line_parts[2]))
    u_per_time.append(float(line_parts[3]))

style.use('ggplot')
pyplot.figure(figsize=(240, 20), dpi=80)

pyplot.plot(time, u_per_time, 'r')
pyplot.plot(time, e_per_time, 'g')
pyplot.plot(time, y_per_time, 'b')
pyplot.xlabel('time')

pyplot.grid(True)
pyplot.show()
