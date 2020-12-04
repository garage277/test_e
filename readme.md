
## E. Биологический эксперимент

| . 					| . 
| --- 					| ---  
| Ограничение времени 	| 1 секунда
| Ограничение памяти 	| 64Mb
| Ввод 					| стандартный ввод или input.txt
| Вывод 				| стандартный вывод или output.txt

В биологическом институте Травиночка проводят эксперимент. Учёные хотят выяснить среднюю продолжительность жизни бактерии мимифиллы в зависимости от того, к какому поколению бактерия относится. Каждую минуту она производит две другие бактерии. Таким образом, популяцию мимифилл можно представить в виде бинарного дерева. В узлах дерева указаны числа — продолжительность жизни бактерии в часах. Помогите учёным узнать среднюю продолжительность жизни мимифиллы в зависимости от поколения.

Бактерия первого поколения прожила один час, бактерии второго поколения прожили по два и три часа, третьего — четыре, пять и шесть часов, четвертого — семь часов.

### Формат ввода

В первой строке записано количество бактерий n — целое число в диапазоне от 1 до 1000.

В следующих n строках через пробел записаны 4 числа: номер бактерии, количество прожитых ей часов, номера двух её потомков. Если одно или оба последних числа равны -1, значит потомок был один или их не было.

### Формат вывода

Нужно в одной строке вывести через пробел числа, каждое из которых равно средней продолжительности жизни бактерий на соответствующем уровне. Числа округляются до двух знаков после запятой согласно стандартным правилам округления.

### Пример 1

| Ввод 			| Вывод
| --- 			| ---
| 7				| 1.00 2.50 5.00 7.00
| 1 1 2 3		| 
| 2 2 4 5		| 
| 3 3 6 -1		| 
| 4 4 7 -1		| 
| 5 5 -1 -1		| 
| 6 6 -1 -1		| 
| 7 7 -1 -1		| 

### Пример 2

| Ввод 			| Вывод
| --- 			| ---
| 1				| 1.00
| 1 1 -1 -1 	| 

	

