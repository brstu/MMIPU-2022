***<h1 align = "center">ВИДЫ ПЕРЕХОДНЫХ ПРОЦЕССОВ И ЧАСТОТНЫХ ХАРАКТЕРИСТИК ТИПОВЫХ ДИНАМИЧЕСКИХ ЗВЕНЬЕВ</a>***

<p align = "right"><font size = 4>
Выполнил: Кицило Р.Д.
</font></p>

## **Цель работы:**

<p align = "justify">
сформировать из собранной модели из Лаб№2, форму состоящую из 1-го блока.
</p>

## **Ход работы:**


## **Задание:**

<p align = "justify">
Сконструировать в simulink модель со структурой а также обратной связью. В применяемых придаточной функции и функции полюсов-нулей (Zero-Pole, Transfer Fcn) построить предаточные функции блокоов. Вычислить предаточную функцию и установить её характеристики.

</p>

<p align = "justify">
система с подключенной LTI-viewer:
</p>

![схема](images/main.png)

<p align = "justify">
Расчет сложной передаточной функции по формуле Мейсона:

P=-L1

Δ1=1 

W1= 10000*S^2/10000*S^4+12200*S^3+12257*S^2+10357*S+300

L2= -s/((s+0.03)(s+1))

Δ=1-L1-L2= (24157*S^2+10000*S^4+22200*S^3+20357*S+300)/(10000*S^4+12200*S^3+12257*S^2+10357*S+300)

получили функцию:

W= (P*Δ1)/Δ=10000s^2/10000s^4+22200s^3+24157s^2+20357s+300
</p>


<p align = "justify">
система полученная после вычислений:
</p>

![схема](images/main2.png)

<p align = "justify">
scope:
</p>

![scope](images/scope.png)

<p align = "justify">
LTI(step):
</p>

![step](images/ltistep.png)

<p align = "justify">
LTI(bode):
</p>

![bode](images/ltibode.png)
<p align = "justify">
LTI(bode-grid):
</p>

![step](images/ltibodegrid.png)
<p align = "justify">
LTI(impulse):
</p>

![step](images/ltiimpulse.png)
<p align = "justify">
LTI(nichols):
</p>

![step](images/ltinichols.png)

<p align = "justify">
LTI(nuqest):
</p>

![step](images/ltinuq.png)

<p align = "justify">
LTI(pole-zero):
</p>

![step](images/ltipole-zero.png)

<p align = "justify">
LTI(signal):
</p>

![step](images/ltisig.png)
## **Вывод:**

<p align = "justify">
Получены навыки построения моделей систем со сложной структурой с обратной связью, расчитанна сложная передаточная функция.

Работа проделана в 
Matlab 6.1.0.450 Release 12.1

</p>
