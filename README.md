# Описание
Реализация комплитора для ОО-языка на основе ситаксиса objective-c для JVM.

### Особенности:
- Только Строгая типизация 
- Отсутствие Рефлексии
- Отсутствие Объектов-классов

### Реализованные возможности

Возможности  |  Автор
------------- |--------
Локальные переменные встроенных типов данных (целые числа, дробные числа ,символы, строки) | Донцов Дмитрий 
Выражения с использованием локальных переменных, арифметических операций, операций сравнения и присваивания | Дмитрий Донцов
Одномерные статические массивы | Курносов Андрей ([@dryush](https://github.com/dryush))
Константы (числовые и строковые, с поддержкой спец.символов) | Курносов Андрей ([@dryush](https://github.com/dryush))
Развилки | Донцов Дмитрий 
Функции( Без заголовков, порядок объявления функций не важен ) | Курносов Андрей ([@dryush](https://github.com/dryush))
Работа с консолью ( класс NSScanner для ввода и print для вывода) | Курносов Андрей ([@dryush](https://github.com/dryush))
Поддержка классов, свойства, методы, наследование, полиморфизм, статические методы | Курносов Андрей ([@dryush](https://github.com/dryush))
Логические операции (И, ИЛИ, НЕ) | Донцов Дмитрий 

### Используемые технологии: 
Парсер: flex
Синтаксический анализатор: gnu bizon
Стековая машина: JVM

### Данный проект реализован в рамках курса "Теория формальных языков и методов трансляции" на направлении "Программная инженерия" Волгоградского Государственного Технического Университета
