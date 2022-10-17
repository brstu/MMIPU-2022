# Лабораторная работа №1 "Моделирование контролируемого объекта"  
Выполнил: Дубяга А.А.  
Проверил: Иванюк Д.С.  
## Цель работы:  
Написать программу, которая будет моделировать изменение температуры некоторого контролируемого объекта. Температура нашего объекта описывается следующим дифференциальным уравнение:  
![main_eq](/tasks/task_01/images/main_eq.png)  
Где τ – время (дискретные моменты 1,2,3...n); y_t – температура на входе; f_t – тепло на входе; RC – некоторые константы.  
Данное дифференциальное уравнение преобразуется в следующие два уравнения:   
![sub_eq](/tasks/task_01/images/sub_eq.png)  
Первое из них - линейная модель изменения температуры, второе - нелинейная модель.  
## Ход работы  
В программе (lab1.cpp) использоются следующие константы:  
a, b_l - для линейной модели;  
a, b_nl, c, d - для нелинейной модели;  
В ходе многочисленного тестирования программы были подобраны следующие значения констант: a = 1, b_l = 0.9, b_nl = 0.0000000009, c = 0.05, d = 0.1.  
За моделирование по линейной модели отвечает функция LinearMod, за моделирование по нелинейной модели отвечает NonLinearMod, за изменение теплоты f_tMod.  
### Работа программы и результаты: 
Сначала программа предлагает пользователю ввести начальное значение температуры, начальное значение теплоты и время (дискретные моменты). После чего предложит выбрать по какой из моделей будет изменяться температура. Данные, полученные в результате выполнения будут записаны в текстовый файл (linear.txt или nonlinear.txt, в зависимости от выбранного пользователем варианта).  
Пример моделирования температуры по линейной модели:  
![linearinput](/trunk/as005910/task_01/doc/image/linearinput.png)  
![linearoutput](/trunk/as005910/task_01/doc/image/linearoutput.png)  
Пример моделирования температуры по нелинейной модели: 
![nonlinearinput](/trunk/as005910/task_01/doc/image/nonlinearinput.png)  
![nonlinearoutput](/trunk/as005910/task_01/doc/image/nonlinearoutput.png)  
По данным, полученным в приведенных выше случаях, построим графики:  
![graphs](/trunk/as005910/task_01/doc/image/graphs.png)  
## Дополнение  
Добавил ещё один файл lab1_dlc.cpp. В нём я немного изменил идею работы программы. В отличие от lab1.cpp, тут пользователь задаёт не количество дискретных моментов, а целевое значение температуры. Программа моделирует изменение температуры до заданного пользователем значения (если последнее полученное значение меньше целевого, а следующее будет уже больше - пользователь будет об этом уведомлён, а запись данных остановлена).  
### Работа дополнения и результаты:  
Пример моделирования температуры по линейной модели:  
![linearinput](/trunk/as005910/task_01/doc/image/linearinput_dlc.png)  
![linearoutput](/trunk/as005910/task_01/doc/image/linearoutput_dlc.png)  
Пример моделирования температуры по нелинейной модели: 
![nonlinearinput](/trunk/as005910/task_01/doc/image/nonlinearinput_dlc.png)  
![nonlinearoutput](/trunk/as005910/task_01/doc/image/nonlinearoutput_dlc.png)  
В результате можно сравнить необходимое количество времени (дискретных моментов), необходимое для достижения целевого значения температуры.
## Вывод
В ходе выполнения лабораторной работы написал программу, моделирующую изменение температуры некоторого контролируемого объекта.