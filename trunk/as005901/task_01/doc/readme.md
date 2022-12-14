***<h1 align = "center">Лабораторная работа №1 «Моделирование контролируемого объекта»</a>***

<font size = 3>
<p align = "right">
Выполнил: Абоимов И.В.</p>
<p align = "right">
Проверил: Иванюк Д.С.</p>
</font>

## **Цель работы:**

<p aling = "justify">
имеется некоторый объект, которым можно управлять, и мы хотим контролировать его температуру, которая описывается следующим уравнением:
</p>

![поместите md-файл с файлами изображений](pictures/dif_ur.png)

<p align = "justify">
Где R, C – некоторые константы, Y0 – комнатная температура (примем равной 24,5), у(t) – входящая температура, f(t) = u(t) – входящее тепло.
Решением ДУ выступает:
</p>

![поместите md-файл с файлами изображений](pictures/models.png)

## **Анализ уравнений:**

<p align = "justify">
Коэффициенты "а" из первого и второго уравнений имеют одно и тоже значение, поскольку они стоят при одних и тех же членах рекуррентной функции (т.е. при y(t)). При этом коэффициенты "b" из первого и второго уравнений являются разными коэффициентами для двух фикций, поскольку стоят при разных членах функции. При этом коэффициент "b" из первого уравнения равен коэффициенту "c" из второго уравнения, так как коэффициенты находятся при одних и тех же членах функции (т.е. при u(t)).
</p>
<p align = "justify">
Для получения более-менее «красивых» значений нужно, чтобы коэффициенты "a" и "с" были на порядки больше коэффициентов "b" и "d".  
</p>

## **Код программы:**

Исходный код программы находящийся по пути trunk\as005901\task_01\src.  
<p align = "justify">
Результаты работы программы также представлены в отдельном файле - results.txt - помещённом по тому же пути
</p>

## **Результаты работы программы:**
  
результаты работы программы  
![поместите md-файл с файлами изображений](pictures/prog_work.png)
  
сохранённые результаты в файле  
![поместите md-файл с файлами изображений](pictures/results_in_file.png)
  
строим график по точкам  
вводим точки  
![поместите md-файл с файлами изображений](pictures/points.png)
  
график  
![поместите md-файл с файлами изображений](pictures/graphik.png)
  
## **Вывод**

<p align = "justify">
сымитировали (поскольку u(t) мы задавали сами) контроль температуры объекта. Построили графики для двух моделей, благодаря чему можем их сравнивать их результаты более удобно и эффективно. При этом результаты нелинейной функции должны быть более точными.  
</p>